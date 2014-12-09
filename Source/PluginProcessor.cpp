/*
 ==============================================================================

 PluginProcessor.cpp
 Author:  Daniel Lindenfelser

 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "LookAndFeel.h"

//==============================================================================
SoundboardAudioProcessor::SoundboardAudioProcessor()
    : fadeOutSeconds(6)
{
    playersLock = true;
    LookAndFeel::setDefaultLookAndFeel(mLookAndFeel = new LookAndFeel_Ultraschall());
    formatManager.registerBasicFormats();

    PropertiesFile::Options options;
    options.applicationName = JucePlugin_Name;
    options.filenameSuffix = "properties";
    options.folderName = "UltraschallSoundboard";
    options.osxLibrarySubFolder = "Application Support";
    propertiesFile = new PropertiesFile(options);
    fallbackProperties = new PropertySet();
    fallbackProperties->setValue(CurrentProgramIndexIdentifier.toString(), 255);

    fallbackProperties->setValue(OscReciveEnabledIdentifier.toString(), false);
    fallbackProperties->setValue(OscRecivePortNumberIdentifier.toString(), 8050);

    fallbackProperties->setValue(OscRemoteEnabledIdentifier.toString(), false);
    fallbackProperties->setValue(OscRemoteHostnameIdentifier.toString(),
                                 "localhost");
    fallbackProperties->setValue(OscRemotePortNumberIdentifier.toString(), 9050);
    fallbackProperties->setValue(OscRemoteIsTouchOscIdentifier.toString(),
                                 false);

    propertiesFile->setFallbackPropertySet(fallbackProperties);

    propertiesFile->addChangeListener(this);

    fadeOutRange.start = 1.0;
    fadeOutRange.end = 30.0;
    fadeOutRange.interval = 1.0;
    fadeOutRange.skew = 0.5;

    oscServer = new OscServer(this);
    settingsComponent = new OscSettings(propertiesFile, oscServer);
    // delay osc server start
    startTimer(TimerOscServerDelay, 1000 * 1);
}

SoundboardAudioProcessor::~SoundboardAudioProcessor()
{
    stopTimer(TimerOscRefresh);
    stopTimer(TimerOscServerDelay);
    propertiesFile->save();
    oscServer = nullptr;
    mLookAndFeel = nullptr;
    propertiesFile = nullptr;
    fallbackProperties = nullptr;
}

//==============================================================================
const String SoundboardAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SoundboardAudioProcessor::getNumParameters() { return 1; }

float SoundboardAudioProcessor::getParameter(int index) { return 0; }

void SoundboardAudioProcessor::setParameter(int index, float newValue) {}

const String SoundboardAudioProcessor::getParameterName(int index)
{
    return String();
}

const String SoundboardAudioProcessor::getParameterText(int index)
{
    return String();
}

const String
SoundboardAudioProcessor::getInputChannelName(int channelIndex) const
{
    return String(channelIndex + 1);
}

const String
SoundboardAudioProcessor::getOutputChannelName(int channelIndex) const
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

double SoundboardAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SoundboardAudioProcessor::getNumPrograms() { return 1; }

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
        oscSendReset();
    }
}

const String SoundboardAudioProcessor::getProgramName(int index)
{
    if (index == ProgramNumberInit)
        return "Init";
    return "Custom";
}

void SoundboardAudioProcessor::changeProgramName(int /*index*/,
                                                 const String& newName) {}

//==============================================================================
void SoundboardAudioProcessor::prepareToPlay(double sampleRate,
                                             int samplesPerBlock)
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

void SoundboardAudioProcessor::processBlock(AudioSampleBuffer& buffer,
                                            MidiBuffer& midiMessages)
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
        buffer.copyFrom(channel, 0, output, channel, 0,
                        sourceChannelInfo.numSamples);
    }
}

//==============================================================================
bool SoundboardAudioProcessor::hasEditor() const { return true; }

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

void SoundboardAudioProcessor::setStateInformation(const void* data,
                                                   int sizeInBytes)
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
    playersLock = true;
    if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
        oscSendReset();
    }
    currentDirectory = directory.getFullPathName();
    mixerAudioSource.removeAllInputs();
    samplePlayers.clear();
    DirectoryIterator iterator(directory, false);
    int count = 0;
    while (iterator.next()) {
        if (formatManager.findFormatForFileExtension(
                iterator.getFile().getFileExtension()) != nullptr && count <= MaximumSamplePlayers) {
            Player* audioFile = new Player(iterator.getFile(), &formatManager);
            samplePlayers.add(audioFile);
            if (audioFile->getState() == Player::Error) {
                samplePlayers.removeObject(audioFile);
                break;
            }
            audioFile->setFadeOutTime(fadeOutSeconds);
            audioFile->addChangeListener(this);
            mixerAudioSource.addInputSource(audioFile->getAudioSource(), false);
        }
        count++;
    }
    playersLock = false;
    SoundboardAudioProcessorEditor* editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
    if (editor) {
        editor->refresh();
    }
    propertiesFile->setValue(CurrentProgramIndexIdentifier.toString(),
                             currentProgramIndex);
    propertiesFile->setValue(CurrentDirectoryIdentifier.toString(),
                             currentDirectory);
    if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
        for (int index = 0; index < samplePlayers.size(); index++) {
            oscSendPlayerConfig(index);
        }
    }
}

void SoundboardAudioProcessor::openSettings()
{
    SoundboardAudioProcessorEditor* editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
    if (editor) {
        editor->addAndMakeVisible(settingsComponent);
        settingsComponent->setBounds(0, 0, editor->getWidth(), editor->getHeight());
    }
}

void SoundboardAudioProcessor::oscSendPlayerState(int index)
{
    Player* samplePlayer = SamplePlayerAtIndex(index);
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

      << osc::BeginMessage((address + "trigger").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

      << osc::BeginMessage((address + "ftrigger").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

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
    Player* samplePlayer = SamplePlayerAtIndex(index);
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

      << osc::BeginMessage((address + "trigger").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

      << osc::BeginMessage((address + "ftrigger").toRawUTF8())
      << samplePlayer->isPlaying() << osc::EndMessage

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
        Player* samplePlayer = SamplePlayerAtIndex(index);
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

          << osc::BeginMessage((address + "play").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "pause").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "stop").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "trigger").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "ftrigger").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "fadeout").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "loop").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "done").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "progress").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::BeginMessage((address + "title").toRawUTF8()) << "Off"
          << osc::EndMessage

          << osc::BeginMessage((address + "time").toRawUTF8()) << "00:00:00"
          << osc::EndMessage

          << osc::BeginMessage((address + "remaining").toRawUTF8()) << "-00:00:00"
          << osc::EndMessage

          << osc::BeginMessage((address + "gain").toRawUTF8()) << 0
          << osc::EndMessage

          << osc::EndBundle;
        oscServer->sendMessage(p);
    }
}

void
SoundboardAudioProcessor::changeListenerCallback(ChangeBroadcaster* source)
{
    if (source == propertiesFile) {
        if (propertiesFile->getBoolValue(OscReciveEnabledIdentifier)) {
            if (!oscServer->isThreadRunning()) {
                oscServer->setLocalPortNumber(
                    propertiesFile->getIntValue(OscRecivePortNumberIdentifier));
                oscServer->listen();
            }
        }
        else {
            if (oscServer->isThreadRunning()) {
                oscServer->stopListening();
            }
        }
        oscServer->setRemoteHostname(
            propertiesFile->getValue(OscRemoteHostnameIdentifier));
        oscServer->setRemotePortNumber(
            propertiesFile->getIntValue(OscRemotePortNumberIdentifier));
        return;
    }
    Player* samplePlayer = static_cast<Player*>(source);
    if (samplePlayer != nullptr) {
        if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
            int index = samplePlayers.indexOf(samplePlayer);
            oscSendPlayerState(index);
        }
        SoundboardAudioProcessorEditor* editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
        if (editor) {
            editor->refreshTable();
        }
    }
}

int SoundboardAudioProcessor::numAudioFiles() { return samplePlayers.size(); }

Player* SoundboardAudioProcessor::SamplePlayerAtIndex(int index)
{
    return samplePlayers[index];
}

void SoundboardAudioProcessor::setFadeOutSeconds(int seconds)
{
    fadeOutSeconds = seconds;
    for (int index = 0; index < samplePlayers.size(); index++) {
        SamplePlayerAtIndex(index)->setFadeOutTime(fadeOutSeconds);
    }
}

int SoundboardAudioProcessor::getFadeOutSeconds() { return fadeOutSeconds; }

void SoundboardAudioProcessor::handleOscMessage(osc::ReceivedPacket packet)
{
    if (propertiesFile->getBoolValue(OscReciveEnabledIdentifier)) {
        oscReceived++;
        try {
            if (packet.IsBundle()) {
                osc::ReceivedBundle bundle(packet);
            }
            else {
                osc::ReceivedMessage message(packet);
                if (String(message.AddressPattern())
                        .startsWith("/ultraschall/soundboard/")) {
                    StringArray messageSplit = StringArray::fromTokens(
                        String(message.AddressPattern()), "/", "");
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
                                        if (!SamplePlayerAtIndex(index)->isPlaying()) {
                                            SamplePlayerAtIndex(index)->play();
                                        }
                                    }
                                    else {
                                        if (SamplePlayerAtIndex(index)->isPlaying()) {
                                            SamplePlayerAtIndex(index)->stop();
                                        }
                                    }
                                }
                                else if (command == "ftrigger") {
                                    float value = (arg++)->AsFloat();
                                    if (value) {
                                        if (!SamplePlayerAtIndex(index)->isPlaying()) {
                                            SamplePlayerAtIndex(index)->play();
                                        }
                                    }
                                    else {
                                        if (SamplePlayerAtIndex(index)->isFadingOut()) {
                                            SamplePlayerAtIndex(index)->stop();
                                        }
                                        else if (SamplePlayerAtIndex(index)->isPlaying()) {
                                            SamplePlayerAtIndex(index)->startFadeOut();
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
                            for (int index = 0; index < samplePlayers.size(); index++) {
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
}

void SoundboardAudioProcessor::timerCallback(int timerID)
{
    if (timerID == TimerOscServerDelay) {
        stopTimer(TimerOscServerDelay);
        oscServer->setLocalPortNumber(
            propertiesFile->getIntValue(OscRecivePortNumberIdentifier));
        if (propertiesFile->getBoolValue(OscReciveEnabledIdentifier)) {
            oscServer->listen();
        }
        oscServer->setRemoteHostname(
            propertiesFile->getValue(OscRemoteHostnameIdentifier));
        oscServer->setRemotePortNumber(
            propertiesFile->getIntValue(OscRemotePortNumberIdentifier));
        if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
            oscSendReset();
        }
        startTimer(TimerOscRefresh, 100);
    }
    else if (timerID == TimerOscRefresh) {
        if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
            oscSendPlayerUpdate();
        }
        oscReceived = 0;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundboardAudioProcessor();
}
