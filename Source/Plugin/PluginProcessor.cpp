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
SoundboardAudioProcessor::SoundboardAudioProcessor() : masterGain(1.0f), duckPercentage(0.33f), duckEnabled(false), fadeOutSeconds(6)
{
    locked = false;
    defaultLookAndFeel = new LookAndFeel_Ultraschall();
    awesomeLookAndFeel = new LookAndFeel_Ultraschall_Awesome();

    Logger::setCurrentLogger(logger = FileLogger::createDefaultAppLogger(ProjectInfo::projectName, String(ProjectInfo::projectName) + ".txt", String(ProjectInfo::projectName) + " " + String(ProjectInfo::versionString)));

    // Internal OSC Parameter
    oscManager.addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/ui/theme"), true);
    
    oscManager.addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/receive/enabled"), true);
    oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/setup/osc/receive/host"), true);
    oscManager.addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/receive/port"), true);
    
    oscManager.addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/remote/enabled"), true);
    oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/setup/osc/remote/host"), true);
    oscManager.addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/remote/port"), true);
    
    oscManager.addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/repeater/enabled"), true);
    oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/setup/osc/repeater/host"), true);
    oscManager.addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/repeater/port"), true);
    
    // OSC Parameter
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/fadeout"));
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/gain"));
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/duck/percentage"));
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/duck/fade"));
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/duck/gain"), true);
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/duck/enabled"));
    oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/stopall"));

    for (int index = 0; index < MaximumSamplePlayers; index++) {
        String indexString = String(index + 1);
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/play"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/pause"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/stop"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/trigger"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/ftrigger"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/loop"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/fadeout"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/fadein"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/fade"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/gain"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/done"));
        oscManager.addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/progress"));
        oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/player/" + indexString + "/title"));
        oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/player/" + indexString + "/time"));
        oscManager.addOscParameter(new OscStringParameter("/ultraschall/soundboard/player/" + indexString + "/remaining"));
    }

    // OSC Setup done not listen to all events here
    oscManager.addOscParameterListener(this, ".+");

    playersLocked = true;
    formatManager.registerBasicFormats();
    thumbnailCache = new AudioThumbnailCache(MaximumSamplePlayers);

    PropertiesFile::Options options;
    options.applicationName = JucePlugin_Name;
    options.filenameSuffix = "properties";
    options.folderName = "UltraschallSoundboard";
    options.osxLibrarySubFolder = "Application Support";
    propertiesFile = new PropertiesFile(options);
    fallbackProperties = new PropertySet();
    fallbackProperties->setValue(CurrentProgramIndexIdentifier.toString(), var(255));

    fallbackProperties->setValue(OscReceiveEnabledIdentifier.toString(), var(false));
    fallbackProperties->setValue(OscReceivePortNumberIdentifier.toString(), var(8050));

    fallbackProperties->setValue(OscRemoteEnabledIdentifier.toString(), var(false));
    fallbackProperties->setValue(OscRemoteHostnameIdentifier.toString(), "127.0.0.1");
    fallbackProperties->setValue(OscRemotePortNumberIdentifier.toString(), var(9050));

    fallbackProperties->setValue(OscRepeaterEnabledIdentifier.toString(), var(false));
    fallbackProperties->setValue(OscRepeaterHostnameIdentifier.toString(), "127.0.0.1");
    fallbackProperties->setValue(OscRepeaterPortNumberIdentifier.toString(), var(8000));

    fallbackProperties->setValue(WindowWidthIdentifier.toString(), var(380));
    fallbackProperties->setValue(WindowHeightIdentifier.toString(), var(320));

    fallbackProperties->setValue(FadeIdentifier.toString(), var(6));
    fallbackProperties->setValue(DuckingIdentifier.toString(), var(0.33f));
    fallbackProperties->setValue(DuckingFadeIdentifier.toString(), var(1.0f));

    fallbackProperties->setValue(ThemeIdentifier.toString(), var(static_cast<int>(ThemeTomorrowNightEighties)));

    propertiesFile->setFallbackPropertySet(fallbackProperties);

    oscManager.setOscParameterValue("/ultraschall/soundboard/duck/percentage",
            propertiesFile->getValue(DuckingIdentifier));
    oscManager.setOscParameterValue("/ultraschall/soundboard/duck/fade",
            propertiesFile->getValue(DuckingFadeIdentifier));
    oscManager.setOscParameterValue("/ultraschall/soundboard/fadeout",
            propertiesFile->getValue(FadeIdentifier));

    SwitchTheme(static_cast<Themes>(propertiesFile->getIntValue(ThemeIdentifier)));

    fadeOutRange.start = 1.0;
    fadeOutRange.end = 30.0;
    fadeOutRange.interval = 1.0;
    fadeOutRange.skew = 0.5;

    duckEnvelope.setTime(1.0f);

    // delay osc server start
    startTimer(TimerOscServerDelay, 1000 * 1);
    startTimer(TimerMidiEvents, 20);
}

SoundboardAudioProcessor::~SoundboardAudioProcessor()
{
    oscManager.removeOscParameterListener(this);
    mixerAudioSource.removeAllInputs();
    players.clear();
    
    oscManager.removeOscParameter(".+");
    stopTimer(TimerOscServerDelay);
    stopTimer(TimerMidiEvents);
    propertiesFile->saveIfNeeded();
    propertiesFile = nullptr;
    fallbackProperties = nullptr;

    thumbnailCache = nullptr;

    defaultLookAndFeel = nullptr;
    awesomeLookAndFeel = nullptr;
    
    Logger::setCurrentLogger(nullptr);
    logger = nullptr;
    FontAwesome::deleteInstance();
}

//==============================================================================
const String SoundboardAudioProcessor::getName() const
{
    return JucePlugin_Name;
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
        players.clear();
        auto editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
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

void SoundboardAudioProcessor::changeProgramName(int /*index*/, const String& /*newName*/)
{
}

//==============================================================================
void SoundboardAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mixerAudioSource.prepareToPlay(samplesPerBlock, sampleRate);
    duckEnvelope.setSampleRate(static_cast<float>(sampleRate));
}

void SoundboardAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    mixerAudioSource.releaseResources();
}

void SoundboardAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages) {
    if (!midiMessages.isEmpty()) {
        const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
        midiBuffer.addEvents(midiMessages, midiMessages.getFirstEventTime(), -1, 0);
    }

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i) {
        buffer.clear(i, 0, buffer.getNumSamples());
    }

    AudioSampleBuffer output(getNumOutputChannels(), buffer.getNumSamples());
    sourceChannelInfo.buffer = &output;
    sourceChannelInfo.startSample = 0;
    sourceChannelInfo.numSamples = output.getNumSamples();
    mixerAudioSource.getNextAudioBlock(sourceChannelInfo);

    for (int channel = 0; channel < getNumOutputChannels(); ++channel) {
        buffer.addFrom(channel, 0, output, channel, 0, sourceChannelInfo.numSamples);
    }

    if (duckEnvelope.getState()) {
        float gain = 1.0f;
        for (int sample = 0; sample < output.getNumSamples(); ++sample) {
            gain = duckEnvelope.tick() * masterGain;
            for (int channel = 0; channel < getNumOutputChannels(); ++channel) {
                buffer.setSample(channel, sample, gain * buffer.getSample(channel, sample));
            }
        }
        getOscManager()->setOscParameterValue("/ultraschall/soundboard/duck/gain", gain);
    } else if (duckEnabled) {
        buffer.applyGain(duckPercentage * masterGain);
    } else {
        buffer.applyGain(masterGain);
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
    for (int index = 0; index < numPlayers(); index++) {
        if (playerAtIndex(index)) {
            program.setProperty(PlayerGainIdentifier.toString() + String(index), playerAtIndex(index)->getGain(), nullptr);
        }
    }
    ScopedPointer<XmlElement> xml(program.createXml());
    copyXmlToBinary(*xml, destData);
}

void SoundboardAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    if (locked) {
        return;
    }
    ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    auto program = ValueTree::fromXml(*xmlState);
    if (program.isValid()) {
        auto directoryString = program.getProperty(DirectoryIdentifier, String::empty).toString();
        if (directoryString != String::empty) {
            currentProgramIndex = ProgramNumberCustom;
            File directory(directoryString);
            if (directory.exists()) {
                auto editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
                if (editor != nullptr) {
                    editor->preload();
                }
                openDirectory(directory);
            }
        }
        for (int index = 0; index < numPlayers(); index++) {
            if (playerAtIndex(index)) {
                float gain = program.getProperty(PlayerGainIdentifier.toString() + String(index));
                playerAtIndex(index)->setGain(gain);
                updatePlayerState(index);
            }
        }
    }
}

//==============================================================================
void SoundboardAudioProcessor::openDirectory(File directory)
{
    playersLocked = true;
    currentDirectory = directory.getFullPathName();
    mixerAudioSource.removeAllInputs();
    players.clear();
    DirectoryIterator iterator(directory, true);
    auto count = 0;
    while (iterator.next()) {
        if (formatManager.findFormatForFileExtension(iterator.getFile().getFileExtension()) != nullptr
            && count < MaximumSamplePlayers) {
            Player* audioFile = new Player(count, iterator.getFile(), &formatManager, thumbnailCache);
            if (audioFile->getState() != Player::Error) {
                audioFile->addChangeListener(this);
                players.add(audioFile);
                audioFile->setFadeTime(fadeOutSeconds);
                mixerAudioSource.addInputSource(audioFile->getAudioSource(), false);
            }
            else {
                delete audioFile;
            }
        }
        count++;
    }
    playersLocked = false;

    updateHostDisplay();

    auto editor = static_cast<SoundboardAudioProcessorEditor*>(getActiveEditor());
    if (editor != nullptr) {
        editor->refresh();
    }
    propertiesFile->setValue(CurrentProgramIndexIdentifier.toString(), currentProgramIndex);
    propertiesFile->setValue(CurrentDirectoryIdentifier.toString(), currentDirectory);
    if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier)) {
        for (int index = 0; index < numPlayers(); index++) {
            updatePlayerState(index);
        }
    }
}

//==============================================================================
int SoundboardAudioProcessor::numPlayers()
{
    return players.size();
}

Player* SoundboardAudioProcessor::playerAtIndex(int index)
{
    return (index < numPlayers()) ? players[index] : nullptr;
}

//==============================================================================
void SoundboardAudioProcessor::setFadeOutSeconds(int seconds)
{
    for (int index = 0; index < numPlayers(); index++) {
        if (playerAtIndex(index)) {
            playerAtIndex(index)->setFadeTime(seconds);
        }
    }
    propertiesFile->setValue(FadeIdentifier.toString(), var(seconds));
}

void SoundboardAudioProcessor::setGain(int playerIndex, float value)
{
    if (playerIndex >= numPlayers()) {
        return;
    }
    playerAtIndex(playerIndex)->setGain(value);
}

int SoundboardAudioProcessor::getFadeOutSeconds()
{
    return fadeOutSeconds;
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
void SoundboardAudioProcessor::timerCallback(int timerID)
{
    if (timerID == TimerOscServerDelay) {
        stopTimer(TimerOscServerDelay);
        
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/host",
                             propertiesFile->getValue(OscRepeaterHostnameIdentifier));
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/port",
                             propertiesFile->getIntValue(OscRepeaterPortNumberIdentifier));
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/enabled",
                             propertiesFile->getValue(OscRepeaterEnabledIdentifier));
        
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/host",
                             propertiesFile->getValue(OscRemoteHostnameIdentifier));
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/port",
                             propertiesFile->getIntValue(OscRemotePortNumberIdentifier));
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/enabled",
                             propertiesFile->getValue(OscRemoteEnabledIdentifier));

        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/host",
                SystemStats::getComputerName());
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/port",
                             propertiesFile->getIntValue(OscReceivePortNumberIdentifier));
        oscManager.setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/enabled",
                             propertiesFile->getValue(OscReceiveEnabledIdentifier));
        
    } else if (timerID == TimerMidiEvents) {
        if (!midiBuffer.isEmpty()) {
            MidiBuffer midiMessages;
            {
                const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
                midiMessages = midiBuffer;
                midiBuffer.clear();
            }
            MidiBuffer::Iterator iterator(midiMessages);
            MidiMessage midiMessage(0xf0);
            auto sample = 0;
            while (iterator.getNextEvent(midiMessage, sample)) {
                if (midiMessage.isNoteOnOrOff()) {
                    auto index = midiMessage.getNoteNumber();
                    auto function = index / 24;
                    auto playerIndex = index % 24;
                    if (playerIndex < numPlayers()) {
                        if (midiMessage.isNoteOn()) {
                            switch (function) {
                                case PlayStop:
                                    if (!playerAtIndex(playerIndex)->isPlaying()) {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else {
                                        playerAtIndex(playerIndex)->stop();
                                    }
                                    break;
                                case PlayPause:
                                    if (!playerAtIndex(playerIndex)->isPlaying()) {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else {
                                        playerAtIndex(playerIndex)->pause();
                                    }
                                    break;
                                case PlayFadeOut:
                                    if (!playerAtIndex(playerIndex)->isPlaying()) {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else {
                                        playerAtIndex(playerIndex)->startFadeOut();
                                    }
                                    break;
                                case HoldAndPlay:
                                    if (!playerAtIndex(playerIndex)->isPlaying()) {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    break;
                            }
                        }
                        else if (midiMessage.isNoteOff()) {
                            switch (function) {
                                case HoldAndPlay:
                                    if (playerAtIndex(playerIndex)->isPlaying()) {
                                        playerAtIndex(playerIndex)->stop();
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

void SoundboardAudioProcessor::updatePlayerState(int playerIndex) {
    auto addressBase = "/ultraschall/soundboard/player/" + String(playerIndex + 1);
    auto player = playerAtIndex(playerIndex);
    oscManager.setOscParameterValue(addressBase + "/play", player->isPlaying(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/pause", player->isPaused(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/stop", player->isStopped(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/trigger", player->isPlaying(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/ftrigger", player->isPlaying(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/fadeout", player->isFadingOut(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/fadein", player->isFadingIn(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/fade", player->isFading(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/loop", player->isLooping(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/done", player->isPlayed(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/progress", player->getProgress(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/title", player->getTitle(), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/time", player->getProgressString(false), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/remaining", player->getProgressString(true), OscParameter::dontSendParameterNotification);
    oscManager.setOscParameterValue(addressBase + "/gain", player->getGain(), OscParameter::dontSendParameterNotification);
}
//==============================================================================
void SoundboardAudioProcessor::handleOscParameterMessage(OscParameter* parameter)
{
    //Logger::outputDebugString("Command: " + parameter->getAddress() + " " + parameter->getValue().toString());
    if (parameter->addressMatch("/ultraschall/soundboard/player/\\d+/.+")) {
        std::regex re("/ultraschall/soundboard/player/(\\d+)/.+");
        std::smatch match;
        std::string result;
        const std::string search = parameter->getAddress().toStdString();
        if (std::regex_search(search, match, re) && match.size() > 1) {
            result = match.str(1);
        } else {
            return;
        }
        int playerIndex = String(result).getIntValue();
        playerIndex--;
        if (!playerAtIndex(playerIndex))
            return;
        
        if (parameter->addressMatch(".+/play$")) {
            if (parameter->getValue()) {
                if (!playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->play();
                }
            }
        } else if (parameter->addressMatch(".+/stop$")) {
            if (parameter->getValue()) {
                playerAtIndex(playerIndex)->stop();
            }
        } else if (parameter->addressMatch(".+/pause$")) {
            if (parameter->getValue()) {
                if (!playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->pause();
                }
            }
        } else if (parameter->addressMatch(".+/trigger$")) {
            if (parameter->getValue()) {
                if (!playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->play();
                }
            }
            else {
                if (playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->stop();
                }
            }
        } else if (parameter->addressMatch(".+/ftrigger$")) {
            if (parameter->getValue()) {
                if (!playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->play();
                }
            }
            else {
                if (playerAtIndex(playerIndex)->isFading()) {
                    playerAtIndex(playerIndex)->stop();
                } else if (playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->startFadeOut();
                } else if (!playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->startFadeIn();
                }
            }
        } else if (parameter->addressMatch(".+/loop$")) {
            playerAtIndex(playerIndex)->setLooping(parameter->getValue());
        } else if (parameter->addressMatch(".+/fadeout$")) {
            if (parameter->getValue()) {
                if (playerAtIndex(playerIndex)->isPlaying()) {
                    playerAtIndex(playerIndex)->startFadeOut();
                }
            }
        } else if (parameter->addressMatch(".+/fadein$")) {
            if (parameter->getValue()) {
                if (playerAtIndex(playerIndex)->isStopped()) {
                    playerAtIndex(playerIndex)->startFadeIn();
                }
            }
        } else if (parameter->addressMatch(".+/gain$")) {
            playerAtIndex(playerIndex)->setGain(parameter->getValue());
        }
    } else if (parameter->addressMatch("/ultraschall/soundboard/player/stopall$")) {
        if (parameter->getValue()) {
            for (int index = 0; index < numPlayers(); index++) {
                Player *player = playerAtIndex(index);
                if (player) {
                    if (player->isPlaying()) {
                        player->stop();
                    }
                }
            }
        }
    } else if (parameter->addressMatch("/ultraschall/soundboard/fadeout$")) {
        setFadeOutSeconds(static_cast<int>(parameter->getValue()));
    } else if (parameter->addressMatch("/ultraschall/soundboard/gain$")) {
        masterGain = static_cast<float>(parameter->getValue());
    } else if (parameter->addressMatch("/ultraschall/soundboard/duck/percentage$")) {
        setDuckingPercentage(static_cast<float>(parameter->getValue()));
    } else if (parameter->addressMatch("/ultraschall/soundboard/duck/fade")) {
        setDuckingFade(static_cast<float>(parameter->getValue()));
    } else if (parameter->addressMatch("/ultraschall/soundboard/duck/enabled$")) {
        bool value = static_cast<bool>(parameter->getValue());
        if (value) {
            duckEnvelope.setValue(1.0f);
            duckEnvelope.setTarget(duckPercentage);
        } else {
            duckEnvelope.setValue(duckPercentage);
            duckEnvelope.setTarget(1.0f);
        }
        duckEnabled = value;
    } else if (parameter->addressMatch("/ultraschall/soundboard/setup/.+")) {
        if (parameter->addressMatch(".+/osc/receive/enabled$")) {
            auto value = static_cast<bool>(parameter->getValue());
            propertiesFile->setValue(OscReceiveEnabledIdentifier.toString(), value);
            if (value) {
                oscManager.getOscServer()->listen();
            } else {
                oscManager.getOscServer()->stopListening();
            }
        } else if (parameter->addressMatch(".+/osc/receive/port$")) {
            auto value = static_cast<int>(parameter->getValue());
            propertiesFile->setValue(OscReceivePortNumberIdentifier.toString(), value);
            oscManager.getOscServer()->setLocalPortNumber(value);
        } else if (parameter->addressMatch(".+/osc/remote/enabled$")) {
            auto value = static_cast<bool>(parameter->getValue());
            propertiesFile->setValue(OscRemoteEnabledIdentifier.toString(), value);
            oscManager.getOscServer()->setRemoteEnabled(value);
        } else if (parameter->addressMatch(".+/osc/remote/host$")) {
            auto value = parameter->getValue().toString();
            propertiesFile->setValue(OscRemoteHostnameIdentifier.toString(), value);
            oscManager.getOscServer()->setRemoteHostname(value);
        } else if (parameter->addressMatch(".+/osc/remote/port$")) {
            auto value = static_cast<int>(parameter->getValue());
            propertiesFile->setValue(OscRemotePortNumberIdentifier.toString(), value);
            oscManager.getOscServer()->setRemotePortNumber(value);
        } else if (parameter->addressMatch(".+/osc/repeater/enabled$")) {
            auto value = static_cast<bool>(parameter->getValue());
            propertiesFile->setValue(OscRepeaterEnabledIdentifier.toString(), value);
            oscManager.getOscServer()->setBridgeEnabled(value);
        } else if (parameter->addressMatch(".+/osc/repeater/host$")) {
            auto value = parameter->getValue().toString();
            propertiesFile->setValue(OscRepeaterHostnameIdentifier.toString(), value);
            oscManager.getOscServer()->setBridgeHostname(value);
        } else if (parameter->addressMatch(".+/osc/repeater/port$")) {
            auto value = static_cast<int>(parameter->getValue());
            propertiesFile->setValue(OscRepeaterPortNumberIdentifier.toString(), value);
            oscManager.getOscServer()->setBridgePortNumber(value);
        } else if (parameter->addressMatch(".+/ui/theme$")) {
            auto value = static_cast<int>(parameter->getValue());
            propertiesFile->setValue(ThemeIdentifier.toString(), value);
            SwitchTheme(static_cast<Themes>(value));
            auto editor = getActiveEditor();
            if (editor) {
                editor->setLookAndFeel(defaultLookAndFeel);
            }
        }
    }
}

OscManager* SoundboardAudioProcessor::getOscManager() {
    return &oscManager;
}

void SoundboardAudioProcessor::changeListenerCallback(ChangeBroadcaster* source) {
    auto player = static_cast<Player*>(source);
    if (player) {
        int playerIndex = players.indexOf(player);
        updatePlayerState(playerIndex);
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundboardAudioProcessor();
}

void SoundboardAudioProcessor::setDuckingPercentage(float percentage) {
    duckPercentage = percentage;
    propertiesFile->setValue(DuckingIdentifier.toString(), var(percentage));
}

void SoundboardAudioProcessor::setDuckingFade(float seconds) {
    duckFade = seconds;
    propertiesFile->setValue(DuckingFadeIdentifier.toString(), var(seconds));
}
