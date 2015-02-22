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
    fallbackProperties->setValue(CurrentProgramIndexIdentifier.toString(), var(255));

    fallbackProperties->setValue(OscReciveEnabledIdentifier.toString(), var(false));
    fallbackProperties->setValue(OscRecivePortNumberIdentifier.toString(), var(8050));

    fallbackProperties->setValue(OscRemoteEnabledIdentifier.toString(), var(false));
    fallbackProperties->setValue(OscRemoteHostnameIdentifier.toString(), "localhost");
    fallbackProperties->setValue(OscRemotePortNumberIdentifier.toString(), var(9050));
    fallbackProperties->setValue(OscRemoteIsTouchOscIdentifier.toString(), var(false));

    fallbackProperties->setValue(WindowWidthIdentifier.toString(), var(380));
    fallbackProperties->setValue(WindowHeightIdentifier.toString(), var(320));

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

    startTimer(TimerMidiEvents, 20);
}

SoundboardAudioProcessor::~SoundboardAudioProcessor()
{
    stopTimer(TimerOscRefresh);
    stopTimer(TimerOscServerDelay);
    stopTimer(TimerMidiEvents);
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

int SoundboardAudioProcessor::getNumParameters()
{
    return GlobalParameterCount + (MaximumSamplePlayers * PlayerParameterCount);
}

float SoundboardAudioProcessor::getParameter(int index)
{
    if (index < GlobalParameterCount) {
        switch (index) {
        case GlobalParameterFadeOut:
            return fadeOutRange.convertTo0to1(fadeOutSeconds);
        default:
            break;
        }
    }

    int playerIndex = (index - GlobalParameterCount) / PlayerParameterCount;
    int playerParameterIndex = (index - GlobalParameterCount) % PlayerParameterCount;

    if (playerIndex >= samplePlayers.size()) {
        return 0;
    }

    switch (playerParameterIndex) {
    case PlayerParameterGain:
        return samplePlayers[playerIndex]->getGain();
    default:
        break;
    }

    return 0;
}

void SoundboardAudioProcessor::setParameter(int index, float newValue)
{
    if (index < GlobalParameterCount) {
        switch (index) {
        case GlobalParameterFadeOut:
            fadeOutSeconds = (int)fadeOutRange.convertFrom0to1(newValue);
            for (int index = 0; index < samplePlayers.size(); index++) {
                SamplePlayerAtIndex(index)->setFadeOutTime(fadeOutSeconds);
            }
            return;
        }
    }

    int playerIndex = (index - GlobalParameterCount) / PlayerParameterCount;
    int playerParameterIndex = (index - GlobalParameterCount) % PlayerParameterCount;

    if (playerIndex >= samplePlayers.size()) {
        return;
    }

    switch (playerParameterIndex) {
    case PlayerParameterGain:
        samplePlayers[playerIndex]->setGain(newValue);
    default:
        break;
    }
}

const String SoundboardAudioProcessor::getParameterName(int index)
{
    if (index < GlobalParameterCount) {
        switch (index) {
        case GlobalParameterFadeOut:
            return "Ausblendzeit:";
        default:
            return "-";
        }
    }

    int playerIndex = (index - GlobalParameterCount) / PlayerParameterCount;
    int playerParameterIndex = (index - GlobalParameterCount) % PlayerParameterCount;

    if (playerIndex >= samplePlayers.size()) {
        return "-";
    }

    switch (playerParameterIndex) {
    case PlayerParameterGain:
        return "Player " + String(playerIndex + 1) + " Gain";
    default:
        break;
    }

    return "-";
}

const String SoundboardAudioProcessor::getParameterText(int index)
{
    if (index < GlobalParameterCount) {
        switch (index) {
        case GlobalParameterFadeOut:
            return String(fadeOutSeconds) + "s";
        default:
            return String::empty;
        }
    }

    int playerIndex = (index - GlobalParameterCount) / PlayerParameterCount;
    int playerParameterIndex = (index - GlobalParameterCount) % PlayerParameterCount;

    if (playerIndex >= samplePlayers.size()) {
        return String::empty;
    }

    switch (playerParameterIndex) {
    case PlayerParameterGain:
        return String(SamplePlayerAtIndex(playerIndex)->getGain());
    default:
        break;
    }

    return String::empty;
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
                                                 const String& /*newName*/) {}

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
    if (!midiMessages.isEmpty()) {
        const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
        midiBuffer.addEvents(midiMessages, midiMessages.getFirstEventTime(), -1, 0);
    }
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

    updateHostDisplay();

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
    setParameterNotifyingHost(GlobalParameterFadeOut, fadeOutRange.convertTo0to1(seconds));
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
                                    SamplePlayerAtIndex(index)->setLooping(value != 0.0f);
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
                    } else if (messageSplit[3] == "stopall") {
                        for (int index = 0; index < samplePlayers.size(); index++) {
                            SamplePlayerAtIndex(index)->stop();
                        }
                    }
                }
            }
        }
        catch (osc::Exception& /*e*/) {
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
    else if (timerID == TimerMidiEvents) {
        if (!midiBuffer.isEmpty()) {
            MidiBuffer midiMessages;
            {
                const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
                midiMessages = midiBuffer;
                midiBuffer.clear();
            }
            MidiBuffer::Iterator iterator(midiMessages);
            MidiMessage midiMessage(0xf0);
            int sample = 0;
            while (iterator.getNextEvent(midiMessage, sample)) {
                if (midiMessage.isNoteOnOrOff()) {
                    int index = midiMessage.getNoteNumber();
                    int function = index / 24;
                    int playerIndex = index % 24;
                    if (playerIndex < samplePlayers.size()) {
                        if (midiMessage.isNoteOn()) {
                            switch (function) {
                            case PlayStop:
                                if (!SamplePlayerAtIndex(playerIndex)->isPlaying()) {
                                    SamplePlayerAtIndex(playerIndex)->play();
                                }
                                else {
                                    SamplePlayerAtIndex(playerIndex)->stop();
                                }
                                break;
                            case PlayPause:
                                if (!SamplePlayerAtIndex(playerIndex)->isPlaying()) {
                                    SamplePlayerAtIndex(playerIndex)->play();
                                }
                                else {
                                    SamplePlayerAtIndex(playerIndex)->pause();
                                }
                                break;
                            case PlayFadeOut:
                                if (!SamplePlayerAtIndex(playerIndex)->isPlaying()) {
                                    SamplePlayerAtIndex(playerIndex)->play();
                                }
                                else {
                                    SamplePlayerAtIndex(playerIndex)->startFadeOut();
                                }
                                break;
                            case HoldAndPlay:
                                if (!SamplePlayerAtIndex(playerIndex)->isPlaying()) {
                                    SamplePlayerAtIndex(playerIndex)->play();
                                }
                                break;
                            }
                        }
                        else if (midiMessage.isNoteOff()) {
                            switch (function) {
                            case HoldAndPlay:
                                if (SamplePlayerAtIndex(playerIndex)->isPlaying()) {
                                    SamplePlayerAtIndex(playerIndex)->stop();
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void SoundboardAudioProcessor::setGain(int playerIndex, float value)
{
    if (playerIndex >= samplePlayers.size()) {
        return;
    }

    int parameterIndex = GlobalParameterCount + (playerIndex * PlayerParameterCount);
    setParameterNotifyingHost(parameterIndex, value);
}

int SoundboardAudioProcessor::getWindowWidth()
{
    return propertiesFile->getIntValue(WindowWidthIdentifier.toString());
}
void SoundboardAudioProcessor::storeWindowWidth(int width)
{
    propertiesFile->setValue(WindowWidthIdentifier.toString(), var(width));
}
int SoundboardAudioProcessor::getWindowHeight()
{
    return propertiesFile->getIntValue(WindowHeightIdentifier.toString());
}
void SoundboardAudioProcessor::storeWindowHeight(int height)
{
    propertiesFile->setValue(WindowHeightIdentifier.toString(), var(height));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundboardAudioProcessor();
}
