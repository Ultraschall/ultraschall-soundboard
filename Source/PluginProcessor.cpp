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
SoundboardAudioProcessor::SoundboardAudioProcessor() : mFadeOutSeconds(6) {
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
    mPropertiesFile->setFallbackPropertySet(mFallbackProperties);

    mFadeOutRange.start = 1.0;
    mFadeOutRange.end = 30.0;
    mFadeOutRange.interval = 1.0;
    mFadeOutRange.skew = 0.5;

    SamplePlayerState.start = 1;
    SamplePlayerState.end = 5;
    SamplePlayerState.interval = 1.0;
}

SoundboardAudioProcessor::~SoundboardAudioProcessor() {
    mPropertiesFile->save();
    mLookAndFeel = nullptr;
    mPropertiesFile = nullptr;
    mFallbackProperties = nullptr;
}

//==============================================================================
const String SoundboardAudioProcessor::getName() const {
    return JucePlugin_Name;
}

int SoundboardAudioProcessor::getNumParameters() {
    return GlobalParameterCount + MaximumSamplePlayers * SamplePlayerParameterCount;
}

float SoundboardAudioProcessor::getParameter(int index) {
    if (index < GlobalParameterCount) {
        switch (index) {
            case 0:
                return mFadeOutRange.convertTo0to1(mFadeOutSeconds);
            default:
                break;
        }
    }

    int samplerIndex = (index - GlobalParameterCount) / SamplePlayerParameterCount;
    int samplerParameterIndex = (index - GlobalParameterCount) % SamplePlayerParameterCount;

    if (samplerIndex >= samplePlayers.size()) {
        return 0;
    }

    switch (samplerParameterIndex) {
        case SamplePlayerParameterStatus: {

        };
            return samplePlayers[samplerIndex]->isPlaying() ? 1.0f : 0.0f;
        case SamplePlayerParameterPause:
            return samplePlayers[samplerIndex]->isPaused() ? 1.0f : 0.0f;
        case SamplePlayerParameterStop:
            return samplePlayers[samplerIndex]->isStopped() || samplePlayers[samplerIndex]->isPlayed() ? 1.0f : 0.0f;
        case SamplePlayerParameterFadeOut:
            return samplePlayers[samplerIndex]->isFadingOut() ? 1.0f : 0.0f;
        case SamplePlayerParameterLoop:
            return samplePlayers[samplerIndex]->isLooping() ? 1.0f : 0.0f;
        case SamplePlayerParameterGain:
            return samplePlayers[samplerIndex]->getGain();
        case SamplePlayerParameterProcess:
            return samplePlayers[samplerIndex]->getProgress();
        default:
            break;
    }
    return 0;
}

void SoundboardAudioProcessor::setParameter(int index, float newValue) {
    if (index < GlobalParameterCount) {
        switch (index) {
            case GlobalParameterFadeOutTime:
                mFadeOutSeconds = (int) mFadeOutRange.convertFrom0to1(newValue);
                return;
        }
    }

    int samplerIndex = (index - GlobalParameterCount) / SamplePlayerParameterCount;
    int samplerParameterIndex = (index - GlobalParameterCount) % SamplePlayerParameterCount;

    if (samplerIndex >= samplePlayers.size()) {
        return;
    }
    switch (samplerParameterIndex) {
        case SamplePlayerParameterPlay:
            if (newValue > 0) {
                if (!samplePlayers[samplerIndex]->isPlaying()) {
                    samplePlayers[samplerIndex]->play();
                }
            }
            break;
        case SamplePlayerParameterPause:
            if (newValue > 0) {
                if (samplePlayers[samplerIndex]->isPlaying()) {
                    samplePlayers[samplerIndex]->pause();
                }
            }
            break;
        case SamplePlayerParameterStop:
            if (newValue > 0) {
                if (samplePlayers[samplerIndex]->isPlaying()) {
                    samplePlayers[samplerIndex]->stop();
                }
            }
            break;
        case SamplePlayerParameterFadeOut:
            if (newValue > 0) {
                samplePlayers[samplerIndex]->startFadeOut();
            }
            break;
        case SamplePlayerParameterLoop:
            samplePlayers[samplerIndex]->setLooping(newValue > 0.5f);
            break;
        case SamplePlayerParameterGain:
            samplePlayers[samplerIndex]->setGain(newValue);
            break;
        default:
            break;
    }
}

const String SoundboardAudioProcessor::getParameterName(int index) {
    if (index < GlobalParameterCount) {
        switch (index) {
            case GlobalParameterFadeOutTime:
                return "Ausblendzeit: ";
            default:
                return "-";
        }
    }

    int samplerIndex = (index - GlobalParameterCount) / SamplePlayerParameterCount;
    int samplerParameterIndex = (index - GlobalParameterCount) % SamplePlayerParameterCount;

    if (samplerIndex >= samplePlayers.size()) {
        return "-";
    }
    switch (samplerParameterIndex) {
        case SamplePlayerParameterPlay:
            return "Play S" + String(samplerIndex);
        case SamplePlayerParameterPause:
            return "Pause S" + String(samplerIndex);
        case SamplePlayerParameterStop:
            return "Stop S" + String(samplerIndex);
        case SamplePlayerParameterFadeOut:
            return "FadeOut S" + String(samplerIndex);
        case SamplePlayerParameterLoop:
            return "Loop S" + String(samplerIndex);
        case SamplePlayerParameterGain:
            return "Gain S" + String(samplerIndex);
        case SamplePlayerParameterProcess:
            return "Progress S" + String(samplerIndex);
        default:
            break;
    }
    return "-";
}

const String SoundboardAudioProcessor::getParameterText(int index) {
    if (index < GlobalParameterCount) {
        switch (index) {
            case 0:
                return String(mFadeOutSeconds) + "s";
            default:
                return String();
        }
    }

    int samplerIndex = (index - GlobalParameterCount) / SamplePlayerParameterCount;
    int samplerParameterIndex = (index - GlobalParameterCount) % SamplePlayerParameterCount;

    if (samplerIndex >= samplePlayers.size()) {
        return String();
    }

    switch (samplerParameterIndex) {
        case SamplePlayerParameterPlay:
            return samplePlayers[samplerIndex]->isPlaying() ? "Off" : "On";
        case SamplePlayerParameterPause:
            return samplePlayers[samplerIndex]->isPaused() ? "Off" : "On";
        case SamplePlayerParameterStop:
            return samplePlayers[samplerIndex]->isStopped() ? "Off" : "On";
        case SamplePlayerParameterFadeOut:
            return samplePlayers[samplerIndex]->isFadingOut() ? "Off" : "On";
        case SamplePlayerParameterLoop:
            return samplePlayers[samplerIndex]->isLooping() ? "Off" : "On";
        case SamplePlayerParameterGain:
            return String(samplePlayers[samplerIndex]->getGain());
        case SamplePlayerParameterProcess:
            return samplePlayers[samplerIndex]->getProgressString(false);
        default:
            break;
    }
    return String();
}

const String SoundboardAudioProcessor::getInputChannelName(int channelIndex) const {
    return String(channelIndex + 1);
}

const String SoundboardAudioProcessor::getOutputChannelName(int channelIndex) const {
    return String(channelIndex + 1);
}

bool SoundboardAudioProcessor::isInputChannelStereoPair(int /*index*/) const {
    return true;
}

bool SoundboardAudioProcessor::isOutputChannelStereoPair(int /*index*/) const {
    return true;
}

bool SoundboardAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool SoundboardAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool SoundboardAudioProcessor::silenceInProducesSilenceOut() const {
    return false;
}

double SoundboardAudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

int SoundboardAudioProcessor::getNumPrograms() {
    return 1;
}

int SoundboardAudioProcessor::getCurrentProgram() {
    return currentProgramIndex;
}

void SoundboardAudioProcessor::setCurrentProgram(int index) {
    currentProgramIndex = index;
    if (index == ProgramNumberCustom)
        return;
    if (index == ProgramNumberInit) {
        currentDirectory = "";
        currentProgramIndex = ProgramNumberCustom;
        mixerAudioSource.removeAllInputs();
        samplePlayers.clear();
        SoundboardAudioProcessorEditor *editor = (SoundboardAudioProcessorEditor *) getActiveEditor();
        if (editor != nullptr) {
            editor->refresh();
        }
        updateHostDisplay();
    }
}

const String SoundboardAudioProcessor::getProgramName(int index) {
    if (index == ProgramNumberInit)
        return "Init";
    return "Custom";
}

void SoundboardAudioProcessor::changeProgramName(int /*index*/, const String &newName) {
}

//==============================================================================
void SoundboardAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mixerAudioSource.prepareToPlay(samplesPerBlock, sampleRate);
}

void SoundboardAudioProcessor::releaseResources() {
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void SoundboardAudioProcessor::processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages) {
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
bool SoundboardAudioProcessor::hasEditor() const {
    return true;
}

AudioProcessorEditor *SoundboardAudioProcessor::createEditor() {
    return new SoundboardAudioProcessorEditor(*this);
}

//==============================================================================
void SoundboardAudioProcessor::getStateInformation(MemoryBlock &destData) {
    ValueTree program("UltraschallSoundboardProgram");
    program.setProperty(DirectoryIdentifier, currentDirectory, nullptr);
    ScopedPointer<XmlElement> xml(program.createXml());
    copyXmlToBinary(*xml, destData);
}

void SoundboardAudioProcessor::setStateInformation(const void *data, int sizeInBytes) {
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

void SoundboardAudioProcessor::openDirectory(File directory) {
    currentDirectory = directory.getFullPathName();
    mixerAudioSource.removeAllInputs();
    samplePlayers.clear();
    DirectoryIterator iterator(directory, false);
    int count = 0;
    while (iterator.next()) {
        if (formatManager.findFormatForFileExtension(iterator.getFile().getFileExtension()) != nullptr
                && count <= MaximumSamplePlayers) {
            SamplePlayer *audioFile = new SamplePlayer(iterator.getFile(), &formatManager);
            audioFile->addChangeListener(this);
            samplePlayers.add(audioFile);
            mixerAudioSource.addInputSource(audioFile->getAudioSource(), false);
        }
        count++;
    }
    SoundboardAudioProcessorEditor *editor = (SoundboardAudioProcessorEditor *) getActiveEditor();
    if (editor != nullptr) {
        editor->refresh();
    }
    mPropertiesFile->setValue(CurrentProgramIndexIdentifier.toString(), currentProgramIndex);
    mPropertiesFile->setValue(CurrentDirectoryIdentifier.toString(), currentDirectory);
    updateHostDisplay();
}

void SoundboardAudioProcessor::changeListenerCallback(ChangeBroadcaster *source) {
    updateHostDisplay();
}

int SoundboardAudioProcessor::numAudioFiles() {
    return samplePlayers.size();
}

SamplePlayer *SoundboardAudioProcessor::SamplePlayerAtIndex(int index) {
    return samplePlayers[index];
}

void SoundboardAudioProcessor::setFadeOutSeconds(int seconds) {
    setParameterNotifyingHost(0, mFadeOutRange.convertTo0to1(seconds));
}

int SoundboardAudioProcessor::getFadeOutSeconds() {
    return mFadeOutSeconds;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new SoundboardAudioProcessor();
}
