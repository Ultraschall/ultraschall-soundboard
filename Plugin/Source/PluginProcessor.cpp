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
SoundboardAudioProcessor::SoundboardAudioProcessor() : fadeOutSeconds(6)
{
    addOscParameter(new OscFloatParameter("/ultraschall/soundboard/gain"));
    addOscParameter(new OscFloatParameter("/ultraschall/soundboard/fadeout"));

    for (int index = 0; index < MaximumSamplePlayers; index++)
    {
        String indexString = String(index + 1);
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/play"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/pause"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/stop"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/trigger"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/ftrigger"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/loop"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/fadeout"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/gain"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/done"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/progress"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/title"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/time"));
        addOscParameter(new OscFloatParameter("/ultraschall/soundboard/player/" + indexString + "/remaining"));
    }

    addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/ui/theme"), true);
    
    addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/repeater/enabled"), true);
    addOscParameter(new OscStringParameter("/ultraschall/soundboard/setup/osc/repeater/host"), true);
    addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/repeater/port"), true);

    addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/remote/enabled"), true);
    addOscParameter(new OscStringParameter("/ultraschall/soundboard/setup/osc/remote/host"), true);
    addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/remote/port"), true);

    addOscParameter(new OscBooleanParameter("/ultraschall/soundboard/setup/osc/receive/enabled"), true);
    addOscParameter(new OscIntegerParameter("/ultraschall/soundboard/setup/osc/receive/port"), true);

    defaultLookAndFeel = new LookAndFeel_Ultraschall();
    awesomeLookAndFeel = new LookAndFeel_Ultraschall_Awesome();

    playersLocked = true;
    formatManager.registerBasicFormats();
    thumbnailCache = new AudioThumbnailCache(MaximumSamplePlayers);

    PropertiesFile::Options options;
    options.applicationName     = JucePlugin_Name;
    options.filenameSuffix      = "properties";
    options.folderName          = "UltraschallSoundboard";
    options.osxLibrarySubFolder = "Application Support";
    propertiesFile     = new PropertiesFile(options);
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

    fallbackProperties->setValue(ThemeIdentifier.toString(), var(static_cast<int>(ThemeTomorrowNightEighties)));

    propertiesFile->setFallbackPropertySet(fallbackProperties);

    setOscParameterValue("/ultraschall/soundboard/setup/ui/theme", propertiesFile->getIntValue(ThemeIdentifier, static_cast<int>(ThemeTomorrowNightEighties)));

    fadeOutRange.start    = 1.0;
    fadeOutRange.end      = 30.0;
    fadeOutRange.interval = 1.0;
    fadeOutRange.skew     = 0.5;

    // delay osc server start
    startTimer(TimerOscServerDelay, 1000 * 1);
    startTimer(TimerMidiEvents, 20);
    
    addOscParameterListener(this, ".+");
}

SoundboardAudioProcessor::~SoundboardAudioProcessor()
{
    removeOscParameter(".+");
    stopTimer(TimerOscServerDelay);
    stopTimer(TimerMidiEvents);
    propertiesFile->save();
    propertiesFile     = nullptr;
    fallbackProperties = nullptr;

    thumbnailCache = nullptr;

    defaultLookAndFeel = nullptr;
    awesomeLookAndFeel = nullptr;
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
    if (index == ProgramNumberInit)
    {
        currentDirectory    = "";
        currentProgramIndex = ProgramNumberCustom;
        mixerAudioSource.removeAllInputs();
        players.clear();
        auto editor = static_cast<SoundboardAudioProcessorEditor *>(getActiveEditor());
        if (editor != nullptr)
        {
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

void SoundboardAudioProcessor::changeProgramName(int /*index*/, const String & /*newName*/)
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

void SoundboardAudioProcessor::processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages)
{
    if (!midiMessages.isEmpty())
    {
        const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
        midiBuffer.addEvents(midiMessages, midiMessages.getFirstEventTime(), -1, 0);
    }
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear(i, 0, buffer.getNumSamples());
    }

    AudioSampleBuffer output(getNumOutputChannels(), buffer.getNumSamples());
    sourceChannelInfo.buffer      = &output;
    sourceChannelInfo.startSample = 0;
    sourceChannelInfo.numSamples  = output.getNumSamples();
    mixerAudioSource.getNextAudioBlock(sourceChannelInfo);

    for (int channel = 0; channel < getNumOutputChannels(); ++channel)
    {
        buffer.copyFrom(channel, 0, output, channel, 0, sourceChannelInfo.numSamples);
    }
}

//==============================================================================
bool SoundboardAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor *SoundboardAudioProcessor::createEditor()
{
    return new SoundboardAudioProcessorEditor(*this);
}

//==============================================================================
void SoundboardAudioProcessor::getStateInformation(MemoryBlock &destData)
{
    ValueTree program("UltraschallSoundboardProgram");
    program.setProperty(DirectoryIdentifier, currentDirectory, nullptr);
    ScopedPointer<XmlElement> xml(program.createXml());
    copyXmlToBinary(*xml, destData);
}

void SoundboardAudioProcessor::setStateInformation(const void *data, int sizeInBytes)
{
    ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    auto                      program = ValueTree::fromXml(*xmlState);
    if (program.isValid())
    {
        auto directoryString = program.getProperty(DirectoryIdentifier, String::empty).toString();
        if (directoryString != String::empty)
        {
            currentProgramIndex = ProgramNumberCustom;
            File directory(directoryString);
            if (directory.exists())
            {
                openDirectory(directory);
            }
        }
    }
}

void SoundboardAudioProcessor::openDirectory(File directory)
{
    playersLocked = true;
    if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier))
    {

    }
    currentDirectory        = directory.getFullPathName();
    mixerAudioSource.removeAllInputs();
    players.clear();
    DirectoryIterator iterator(directory, false);
    auto count = 0;
    while (iterator.next())
    {
        if (formatManager.findFormatForFileExtension(iterator.getFile().getFileExtension()) != nullptr
            && count < MaximumSamplePlayers)
        {
            auto audioFile = new Player(count + 1, iterator.getFile(), &formatManager, thumbnailCache, *this);
            if (audioFile->getState() == Player::Error)
            {
                delete audioFile;
                break;
            }
            players.add(audioFile);
            audioFile->setFadeOutTime(fadeOutSeconds);
            mixerAudioSource.addInputSource(audioFile->getAudioSource(), false);
        }
        count++;
    }
    playersLocked = false;

    updateHostDisplay();

    auto editor = static_cast<SoundboardAudioProcessorEditor *>(getActiveEditor());
    if (editor)
    {
        editor->refresh();
    }
    propertiesFile->setValue(CurrentProgramIndexIdentifier.toString(), currentProgramIndex);
    propertiesFile->setValue(CurrentDirectoryIdentifier.toString(), currentDirectory);
    if (propertiesFile->getBoolValue(OscRemoteEnabledIdentifier))
    {
        for (int index = 0; index < numPlayers(); index++)
        {

        }
    }
}

int SoundboardAudioProcessor::numPlayers()
{
    return players.size();
}

Player *SoundboardAudioProcessor::playerAtIndex(int index)
{
    return players[index];
}

void SoundboardAudioProcessor::setFadeOutSeconds(int seconds)
{

}

int SoundboardAudioProcessor::getFadeOutSeconds()
{
    return fadeOutSeconds;
}

void SoundboardAudioProcessor::timerCallback(int timerID)
{
    if (timerID == TimerOscServerDelay)
    {
        stopTimer(TimerOscServerDelay);
        
        setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/host", propertiesFile->getValue(OscRepeaterHostnameIdentifier));
        setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/port", propertiesFile->getIntValue(OscRepeaterPortNumberIdentifier));
        setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/enabled", propertiesFile->getBoolValue(OscRepeaterEnabledIdentifier));
        
        setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/host", propertiesFile->getValue(OscRemoteHostnameIdentifier));
        setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/port", propertiesFile->getIntValue(OscRemotePortNumberIdentifier));
        setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/enabled", propertiesFile->getBoolValue(OscRemoteEnabledIdentifier));
        
        setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/port", propertiesFile->getIntValue(OscReceivePortNumberIdentifier));
        setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/enabled", propertiesFile->getBoolValue(OscReceiveEnabledIdentifier));
    }
    else if (timerID == TimerMidiEvents)
    {
        if (!midiBuffer.isEmpty())
        {
            MidiBuffer           midiMessages;
            {
                const GenericScopedLock<CriticalSection> myScopedLock(midiCriticalSection);
                midiMessages = midiBuffer;
                midiBuffer.clear();
            }
            MidiBuffer::Iterator iterator(midiMessages);
            MidiMessage          midiMessage(0xf0);
            auto                 sample = 0;
            while (iterator.getNextEvent(midiMessage, sample))
            {
                if (midiMessage.isNoteOnOrOff())
                {
                    auto index       = midiMessage.getNoteNumber();
                    auto function    = index / 24;
                    auto playerIndex = index % 24;
                    if (playerIndex < numPlayers())
                    {
                        if (midiMessage.isNoteOn())
                        {
                            switch (function)
                            {
                                case PlayStop:
                                    if (!playerAtIndex(playerIndex)->isPlaying())
                                    {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else
                                    {
                                        playerAtIndex(playerIndex)->stop();
                                    }
                                    break;
                                case PlayPause:
                                    if (!playerAtIndex(playerIndex)->isPlaying())
                                    {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else
                                    {
                                        playerAtIndex(playerIndex)->pause();
                                    }
                                    break;
                                case PlayFadeOut:
                                    if (!playerAtIndex(playerIndex)->isPlaying())
                                    {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    else
                                    {
                                        playerAtIndex(playerIndex)->startFadeOut();
                                    }
                                    break;
                                case HoldAndPlay:
                                    if (!playerAtIndex(playerIndex)->isPlaying())
                                    {
                                        playerAtIndex(playerIndex)->play();
                                    }
                                    break;
                            }
                        }
                        else if (midiMessage.isNoteOff())
                        {
                            switch (function)
                            {
                                case HoldAndPlay:
                                    if (playerAtIndex(playerIndex)->isPlaying())
                                    {
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

void SoundboardAudioProcessor::setGain(int playerIndex, float value)
{
    if (playerIndex >= numPlayers())
    {
        return;
    }
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

void SoundboardAudioProcessor::handleOscParameterMessage(OscParameter *parameter) {
    if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/host")) {
        getOscServer()->setBridgeHostname(parameter->getValue().toString());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/port"))
    {
        getOscServer()->setBridgeHostname(parameter->getValue());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/enabled"))
    {
        getOscServer()->setBridgeEnabled(parameter->getValue());
    }

    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/host"))
    {
        getOscServer()->setRemoteHostname(parameter->getValue().toString());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/port"))
    {
        getOscServer()->setRemotePortNumber(parameter->getValue());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/enabled"))
    {
        getOscServer()->setRemoteEnabled(parameter->getValue());
    }
    
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/receive/port"))
    {
        propertiesFile->setValue(OscReceivePortNumberIdentifier.toString(), parameter->getValue());
        getOscServer()->setLocalPortNumber(parameter->getValue());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/receive/enabled"))
    {
        if (parameter->getValue())
        {
            getOscServer()->listen();
        } else
        {
            getOscServer()->stopListening();
        }
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/ui/theme")) {
        SwitchTheme(static_cast<Themes>(static_cast<int>(parameter->getValue())));
        getActiveEditor()->sendLookAndFeelChange();
        propertiesFile->setValue(ThemeIdentifier.toString(), parameter->getValue());
    }

    Logger::outputDebugString("Internal Command: " + parameter->getAddress() + " " + parameter->getValue().toString());
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor *JUCE_CALLTYPE createPluginFilter()
{
    return new SoundboardAudioProcessor();
}
