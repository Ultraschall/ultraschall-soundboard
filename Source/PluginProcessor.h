/*
 ==============================================================================
 
 PluginProcessor.h
 Author:  Daniel Lindenfelser
 
 ==============================================================================
 */

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SamplePlayer.h"

class LookAndFeel_Ultraschall;

static const Identifier DirectoryIdentifier("Directory");
static const Identifier CurrentDirectoryIdentifier("CurrentDirectory");
static const Identifier CurrentProgramIndexIdentifier("CurrentProgramIndex");

static const Identifier OscLocalPortNumberIdentifier("OscLocalPortNumber");
static const Identifier OscRemoteHostnameIdentifier("OscRemoteHostname");
static const Identifier OscRemotePortNumberIdentifier("OscRemotePortNumber");
static const Identifier OscRemotePortNumberIdentifier("OscSendEnabled");
static const Identifier OscRemotePortNumberIdentifier("OscReciveEnabled");

class SoundboardAudioProcessor : public AudioProcessor,
                                 public ChangeListener {
    // Global Parameter Numbers
    static const int GlobalParameterFadeOutTime = 0;
    static const int GlobalParameterCount = 1;

    // SamplePlayer Parameter Numbers
    static const int SamplePlayerParameterStatus = 0;
    static const int SamplePlayerParameterPlay = 1;
    static const int SamplePlayerParameterPause = 2;
    static const int SamplePlayerParameterStop = 3;
    static const int SamplePlayerParameterLoop = 4;
    static const int SamplePlayerParameterFadeOut = 5;
    static const int SamplePlayerParameterProcess = 6;
    static const int SamplePlayerParameterGain = 7;
    static const int SamplePlayerParameterCount = 8;

    // Maximum Number of Sampler Slots
    static const int MaximumSamplePlayers = 25;

    // Init Program Number
    static const int ProgramNumberInit = 0;
    static const int ProgramNumberCustom = 255;
public:
    SoundboardAudioProcessor();

    ~SoundboardAudioProcessor();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;

    void releaseResources() override;

    void processBlock(AudioSampleBuffer &, MidiBuffer &) override;

    AudioProcessorEditor *createEditor() override;

    bool hasEditor() const override;

    const String getName() const override;

    int getNumParameters() override;

    float getParameter(int index) override;

    void setParameter(int index, float newValue) override;

    const String getParameterName(int index) override;

    const String getParameterText(int index) override;

    const String getInputChannelName(int channelIndex) const override;

    const String getOutputChannelName(int channelIndex) const override;

    bool isInputChannelStereoPair(int index) const override;

    bool isOutputChannelStereoPair(int index) const override;

    bool acceptsMidi() const override;

    bool producesMidi() const override;

    bool silenceInProducesSilenceOut() const override;

    double getTailLengthSeconds() const override;

    int getNumPrograms() override;

    int getCurrentProgram() override;

    void setCurrentProgram(int index) override;

    const String getProgramName(int index) override;

    void changeProgramName(int index, const String &newName) override;

    void getStateInformation(MemoryBlock &destData) override;

    void setStateInformation(const void *data, int sizeInBytes) override;

    int numAudioFiles();

    SamplePlayer *SamplePlayerAtIndex(int index);

    void openDirectory(File directory);

    int getFadeOutSeconds();

    void setFadeOutSeconds(int seconds);

    int samplerPlayerParameterIndex(int index, int parameter) {
        return (index * SamplePlayerParameterCount) + parameter;
    }

    void samplePlayerPlay(int index) {
        setParameterNotifyingHost(samplerPlayerParameterIndex(index, SamplePlayerParameterPlay), 1.0f);
    }

    void samplePlayerPause(int index) {
        setParameterNotifyingHost(samplerPlayerParameterIndex(index, SamplePlayerParameterPause), 1.0f);
    }

    void samplePlayerStop(int index) {
        setParameterNotifyingHost(samplerPlayerParameterIndex(index, SamplePlayerParameterStop), 1.0f);
    }

    void samplePlayerFadeOut(int index) {
        setParameterNotifyingHost(samplerPlayerParameterIndex(index, SamplePlayerParameterFadeOut), 1.0f);
    }

    void samplePlayerLoop(int index) {
        setParameterNotifyingHost(samplerPlayerParameterIndex(index, SamplePlayerParameterLoop), 1.0f);
    }

    // ChangeListener
    void changeListenerCallback(ChangeBroadcaster *source);
private:
    ScopedPointer<LookAndFeel> mLookAndFeel;

    // Audio IO
    OwnedArray<SamplePlayer> samplePlayers;
    AudioFormatManager formatManager;
    AudioSourceChannelInfo sourceChannelInfo;
    MixerAudioSource mixerAudioSource;

    // Global Parameter
    int mFadeOutSeconds;
    NormalisableRange<float> mFadeOutRange;
    NormalisableRange<float> SamplePlayerState;

    // Settings
    int currentProgramIndex;
    String currentDirectory;
    ScopedPointer<PropertySet> mFallbackProperties;
    ScopedPointer<PropertiesFile> mPropertiesFile;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessor)
};

#endif // PLUGINPROCESSOR_H_INCLUDED
