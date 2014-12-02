/*
 ==============================================================================
 
 PluginProcessor.cpp
 Author:  Daniel Lindenfelser
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "LookAndFeel.h"
#include "OscServer.h"

//==============================================================================
SoundboardAudioProcessor::SoundboardAudioProcessor()
    : mFadeOutSeconds(6)
{
    LookAndFeel::setDefaultLookAndFeel(mLookAndFeel = new LookAndFeel_Ultraschall());
    formatManager.registerBasicFormats();

    PropertiesFile::Options options;
    options.applicationName = JucePlugin_Name;
    options.filenameSuffix = "properties";
    options.folderName = "UltraschallSoundboard";
    options.osxLibrarySubFolder = "Application Support";
    mPropertiesFile = new PropertiesFile(options);
    mFallbackProperties = new PropertySet();
    mFallbackProperties->setValue(CurrentProgramIndexIdentifier.toString(), 255);

    mFallbackProperties->setValue(OscReciveEnabledIdentifier.toString(), false);
    mFallbackProperties->setValue(OscRecivePortNumberIdentifier.toString(), 8050);

    mFallbackProperties->setValue(OscRemoteEnabledIdentifier.toString(), false);
    mFallbackProperties->setValue(OscRemoteHostnameIdentifier.toString(), "localhost");
    mFallbackProperties->setValue(OscRemotePortNumberIdentifier.toString(), 9050);
    mFallbackProperties->setValue(OscRemoteIsTouchOscIdentifier.toString(), false);

    mPropertiesFile->setFallbackPropertySet(mFallbackProperties);

    mFadeOutRange.start = 1.0;
    mFadeOutRange.end = 30.0;
    mFadeOutRange.interval = 1.0;
    mFadeOutRange.skew = 0.5;

    SamplePlayerState.start = 1;
    SamplePlayerState.end = 5;
    SamplePlayerState.interval = 1.0;
    oscServer = new OscServer(this);
    // delay osc server start
    startTimer(TimerOscServerDelay, 1000 * 5);
    startTimer(TimerOscRefresh, 100);
}

SoundboardAudioProcessor::~SoundboardAudioProcessor()
{
    stopTimer(TimerOscRefresh);
    stopTimer(TimerOscServerDelay);
    mPropertiesFile->save();
    oscServer = nullptr;
    mLookAndFeel = nullptr;
    mPropertiesFile = nullptr;
    mFallbackProperties = nullptr;
}

//==============================================================================
const String SoundboardAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SoundboardAudioProcessor::getNumParameters()
{
    return 1;
}

float SoundboardAudioProcessor::getParameter(int index)
{
    return 0;
}

void SoundboardAudioProcessor::setParameter(int index, float newValue)
{
}

const String SoundboardAudioProcessor::getParameterName(int index)
{
    return String();
}

const String SoundboardAudioProcessor::getParameterText(int index)
{
    return String();
}

const String SoundboardAudioProcessor::getInputChannelName(int channelIndex) const
{
    return String(channelIndex + 1);
}

const String SoundboardAudioProcessor::getOutputChannelName(int channelIndex) const
{
    return String(channelIndex + 1);
}

bool SoundboardAudioProcessor::isInputChannelStereoPair(int /*index*/) const
{
    return true;
}

bool SoundboardAudioProcessor::isOutputChannelStereoPair(int /*index*/) const
{
    return true;
}

bool SoundboardAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool SoundboardAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool SoundboardAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SoundboardAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SoundboardAudioProcessor::getNumPrograms()
{
    return 1;
}

int SoundboardAudioProcessor::getCurrentProgram()
{
    return currentProgramIndex;
}

void SoundboardAudioProcessor::setCurrentProgram(int index)
{
    currentProgramIndex = index;
    if (index == ProgramNumberCustom)
        return;
    if (index == ProgramNumberInit) {
        currentDirectory = "";
        currentProgramIndex = ProgramNumberCustom;
        mixerAudioSource.removeAllInputs();
        samplePlayers.clear();
        SoundboardAudioProcessorEditor* editor = (SoundboardAudioProcessorEditor*)getActiveEditor();
        if (editor != nullptr) {
            editor->refresh();
        }
        updateHostDisplay();
    }
}

const String SoundboardAudioProcessor::getProgramName(int index)
{
    if (index == ProgramNumberInit)
        return "Init";
    return "Custom";
}

void SoundboardAudioProcessor::changeProgramName(int /*index*/, const String& newName)
{
}

//==============================================================================
void SoundboardAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mixerAudioSource.prepareToPlay(samplesPerBlock, sampleRate);
}

void SoundboardAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void SoundboardAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    AudioSampleBuffer output(getNumOutputChannels(), buffer.getNumSamples());
    sourceChannelInfo.buffer = &output;
    sourceChannelInfo.startSample = 0;
    sourceChannelInfo.numSamples = output.getNumSamples();
    mixerAudioSource.getNextAudioBlock(sourceChannelInfo);

    for (int channel = 0; channel < getNumOutputChannels(); ++channel) {
        buffer.copyFrom(channel, 0, output, channel, 0, sourceChannelInfo.numSamples);
    }
}

//==============================================================================
bool SoundboardAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* SoundboardAudioProcessor::createEditor()
{
    return new SoundboardAudioProcessorEditor(*this);
}

//==============================================================================
void SoundboardAudioProcessor::getStateInformation(MemoryBlock& destData)
{
    ValueTree program("UltraschallSoundboardProgram");
    program.setProperty(DirectoryIdentifier, currentDirectory, nullptr);
    ScopedPointer<XmlElement> xml(program.createXml());
    copyXmlToBinary(*xml, destData);
}

void SoundboardAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    ValueTree program = ValueTree::fromXml(*xmlState);
    if (program.isValid()) {
        String directoryString = program.getProperty(DirectoryIdentifier, String::empty).toString();
        if (directoryString != String::empty) {
            currentProgramIndex = ProgramNumberCustom;
            File directory(directoryString);
            if (directory.exists()) {
                openDirectory(directory);
            }
        }
    }
}

void SoundboardAudioProcessor::openDirectory(File directory)
{
    oscSendReset();
    currentDirectory = directory.getFullPathName();
    mixerAudioSource.removeAllInputs();
    samplePlayers.clear();
    DirectoryIterator iterator(directory, false);
    int count = 0;
    while (iterator.next()) {
        if (formatManager.findFormatForFileExtension(iterator.getFile().getFileExtension()) != nullptr
            && count <= MaximumSamplePlayers) {
            SamplePlayer* audioFile = new SamplePlayer(iterator.getFile(), &formatManager);
            audioFile->addChangeListener(this);
            samplePlayers.add(audioFile);
            mixerAudioSource.addInputSource(audioFile->getAudioSource(), false);
        }
        count++;
    }
    SoundboardAudioProcessorEditor* editor = (SoundboardAudioProcessorEditor*)getActiveEditor();
    if (editor != nullptr) {
        editor->refresh();
    }
    mPropertiesFile->setValue(CurrentProgramIndexIdentifier.toString(), currentProgramIndex);
    mPropertiesFile->setValue(CurrentDirectoryIdentifier.toString(), currentDirectory);
    for (int index = 0; index < samplePlayers.size(); index++) {
        oscSendPlayerConfig(index);
    }
}

void SoundboardAudioProcessor::oscSendPlayerState(int index)
{
    SamplePlayer* samplePlayer = SamplePlayerAtIndex(index);
    String address = "/ultraschall/soundboard/player/" + String(index + 1) + "/";

    char buffer[1024];
    osc::OutboundPacketStream p(buffer, 1024);

    p << osc::BeginBundleImmediate

      << osc::BeginMessage((address + "play").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

      << osc::BeginMessage((address + "trigger").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

      << osc::BeginMessage((address + "pause").toRawUTF8())
      << samplePlayer->isPaused() << osc::EndMessage

      << osc::BeginMessage((address + "stop").toRawUTF8())
      << samplePlayer->isStopped() << osc::EndMessage

      << osc::BeginMessage((address + "fadeout").toRawUTF8())
      << samplePlayer->isFadingOut() << osc::EndMessage

      << osc::BeginMessage((address + "loop").toRawUTF8())
      << samplePlayer->isLooping() << osc::EndMessage

      << osc::BeginMessage((address + "done").toRawUTF8())
      << samplePlayer->isPlayed() << osc::EndMessage
    
    << osc::BeginMessage((address + "progress").toRawUTF8())
    << samplePlayer->getProgress() << osc::EndMessage
    
    << osc::BeginMessage((address + "time").toRawUTF8())
    << samplePlayer->getProgressString(false).toRawUTF8() << osc::EndMessage
    
    << osc::BeginMessage((address + "remaining").toRawUTF8())
    << samplePlayer->getProgressString(true).toRawUTF8() << osc::EndMessage
    
    << osc::BeginMessage((address + "gain").toRawUTF8())
    << samplePlayer->getGain() << osc::EndMessage

      << osc::EndBundle;

    oscServer->sendMessage(p);
}

void SoundboardAudioProcessor::oscSendPlayerConfig(int index)
{
    SamplePlayer* samplePlayer = SamplePlayerAtIndex(index);
    String address = "/ultraschall/soundboard/player/" + String(index + 1) + "/";

    char buffer[1024];
    osc::OutboundPacketStream p(buffer, 1024);

    p << osc::BeginBundleImmediate

      << osc::BeginMessage((address + "play").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

      << osc::BeginMessage((address + "pause").toRawUTF8())
      << samplePlayer->isPaused() << osc::EndMessage

      << osc::BeginMessage((address + "stop").toRawUTF8())
      << samplePlayer->isStopped() << osc::EndMessage

      << osc::BeginMessage((address + "fadeout").toRawUTF8())
      << samplePlayer->isFadingOut() << osc::EndMessage

      << osc::BeginMessage((address + "loop").toRawUTF8())
      << samplePlayer->isLooping() << osc::EndMessage

      << osc::BeginMessage((address + "done").toRawUTF8())
      << samplePlayer->isPlayed() << osc::EndMessage

      << osc::BeginMessage((address + "progress").toRawUTF8())
      << samplePlayer->getProgress() << osc::EndMessage

      << osc::BeginMessage((address + "title").toRawUTF8())
      << samplePlayer->getTitle().toRawUTF8() << osc::EndMessage

      << osc::BeginMessage((address + "time").toRawUTF8())
      << samplePlayer->getProgressString(false).toRawUTF8() << osc::EndMessage

      << osc::BeginMessage((address + "remaining").toRawUTF8())
      << samplePlayer->getProgressString(true).toRawUTF8() << osc::EndMessage

      << osc::BeginMessage((address + "gain").toRawUTF8())
      << samplePlayer->getGain() << osc::EndMessage

      << osc::EndBundle;

    oscServer->sendMessage(p);
}
void SoundboardAudioProcessor::oscSendPlayerUpdate()
{
    for (int index = 0; index < samplePlayers.size(); index++) {
        SamplePlayer* samplePlayer = SamplePlayerAtIndex(index);
        String address = "/ultraschall/soundboard/player/" + String(index + 1) + "/";

        if (samplePlayer->isPlaying()) {
            char buffer[1024];
            osc::OutboundPacketStream p(buffer, 1024);

            p << osc::BeginBundleImmediate

              << osc::BeginMessage((address + "progress").toRawUTF8())
              << samplePlayer->getProgress() << osc::EndMessage

              << osc::BeginMessage((address + "time").toRawUTF8())
              << samplePlayer->getProgressString(false).toRawUTF8() << osc::EndMessage

              << osc::BeginMessage((address + "remaining").toRawUTF8())
              << samplePlayer->getProgressString(true).toRawUTF8() << osc::EndMessage

              << osc::BeginMessage((address + "gain").toRawUTF8())
              << samplePlayer->getGain() << osc::EndMessage

              << osc::EndBundle;

            oscServer->sendMessage(p);
        }
    }
}
void SoundboardAudioProcessor::oscSendReset()
{
    for (int index = 0; index < MaximumSamplePlayers; index++) {
        String address = "/ultraschall/soundboard/player/" + String(index + 1) + "/";
        char buffer[1024];
        osc::OutboundPacketStream p(buffer, 1024);

        p << osc::BeginBundleImmediate

          << osc::BeginMessage((address + "play").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "pause").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "stop").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "trigger").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "fadeout").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "loop").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "done").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "progress").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::BeginMessage((address + "title").toRawUTF8())
          << "Off" << osc::EndMessage

          << osc::BeginMessage((address + "time").toRawUTF8())
          << "00:00:00" << osc::EndMessage

          << osc::BeginMessage((address + "remaining").toRawUTF8())
          << "-00:00:00" << osc::EndMessage

          << osc::BeginMessage((address + "gain").toRawUTF8())
          << 0 << osc::EndMessage

          << osc::EndBundle;
        oscServer->sendMessage(p);
    }
}

void SoundboardAudioProcessor::changeListenerCallback(ChangeBroadcaster* source)
{
    SamplePlayer* samplePlayer = static_cast<SamplePlayer*>(source);
    if (samplePlayer) {
        int index = samplePlayers.indexOf(samplePlayer);
        oscSendPlayerState(index);
    }
}

int SoundboardAudioProcessor::numAudioFiles()
{
    return samplePlayers.size();
}

SamplePlayer* SoundboardAudioProcessor::SamplePlayerAtIndex(int index)
{
    return samplePlayers[index];
}

void SoundboardAudioProcessor::setFadeOutSeconds(int seconds)
{
    setParameterNotifyingHost(0, mFadeOutRange.convertTo0to1(seconds));
}

int SoundboardAudioProcessor::getFadeOutSeconds()
{
    return mFadeOutSeconds;
}

void SoundboardAudioProcessor::handleOscMessage(osc::ReceivedPacket packet)
{
    try {
        if (packet.IsBundle()) {
            osc::ReceivedBundle bundle(packet);
        }
        else {
            osc::ReceivedMessage message(packet);
            if (String(message.AddressPattern()).startsWith("/ultraschall/soundboard/")) {
                StringArray messageSplit = StringArray::fromTokens(String(message.AddressPattern()), "/", "");
                osc::ReceivedMessage::const_iterator arg = message.ArgumentsBegin();
                if (messageSplit[3] == "player") {
                    int index = messageSplit[4].getIntValue();
                    index--;
                    if (SamplePlayerAtIndex(index)) {
                        if (index >= 0 && index < MaximumSamplePlayers) {
                            String command = messageSplit[5];
                            if (command == "play") {
                                float value = (arg++)->AsFloat();
                                if (value) {
                                    if (!SamplePlayerAtIndex(index)->isPlaying()) {
                                        SamplePlayerAtIndex(index)->play();
                                    }
                                }
                            }
                            else if (command == "pause") {
                                float value = (arg++)->AsFloat();
                                if (value) {
                                    if (SamplePlayerAtIndex(index)->isPlaying()) {
                                        SamplePlayerAtIndex(index)->pause();
                                    }
                                }
                            }
                            else if (command == "stop") {
                                float value = (arg++)->AsFloat();
                                if (value) {
                                    SamplePlayerAtIndex(index)->stop();
                                }
                            }
                            else if (command == "trigger") {
                                float value = (arg++)->AsFloat();
                                if (value) {
                                    if (SamplePlayerAtIndex(index)->isPlaying()) {
                                        SamplePlayerAtIndex(index)->stop();
                                    }
                                    else {
                                        SamplePlayerAtIndex(index)->play();
                                    }
                                }
                            }
                            else if (command == "loop") {
                                float value = (arg++)->AsFloat();
                                SamplePlayerAtIndex(index)->setLooping(value);
                            }
                            else if (command == "fadeout") {
                                float value = (arg++)->AsFloat();
                                if (value) {
                                    if (SamplePlayerAtIndex(index)->isPlaying()) {
                                        SamplePlayerAtIndex(index)->startFadeOut();
                                    }
                                }
                            }
                            else if (command == "gain") {
                                float value = (arg++)->AsFloat();
                                SamplePlayerAtIndex(index)->setGain(value);
                            }
                        }
                    }
                }
                else if (messageSplit[3] == "fadeout") {
                    if (messageSplit[4] == "seconds") {
                        int value = (arg++)->AsInt32();
                        for (int index = 0; index <= samplePlayers.size(); index++) {
                            SamplePlayerAtIndex(index)->setFadeOutTime(value);
                        }
                    }
                }
            }
        }
    }
    catch (osc::Exception& e) {
        // any parsing errors such as unexpected argument types, or
        // missing arguments get thrown as exceptions.
        std::cout << "error while parsing message:" << std::endl;
    }
}

void SoundboardAudioProcessor::timerCallback(int timerID)
{
    if (timerID == TimerOscServerDelay) {
        stopTimer(TimerOscServerDelay);
        startOscServer();
        oscServer->setRemoteHostname("192.168.178.25");
        oscServer->setRemotePortNumber(9050);
        if (oscServer->connect()) {
            oscSendReset();
        }
    }
    else if (timerID == TimerOscRefresh) {
        oscSendPlayerUpdate();
    }
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundboardAudioProcessor();
}
