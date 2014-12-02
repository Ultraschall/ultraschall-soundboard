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

using namespace danlin;

class LookAndFeel_Ultraschall;

static const Identifier DirectoryIdentifier("Directory");
static const Identifier CurrentDirectoryIdentifier("CurrentDirectory");
static const Identifier CurrentProgramIndexIdentifier("CurrentProgramIndex");

static const Identifier OscReciveEnabledIdentifier("OscReciveEnabled");
static const Identifier OscRecivePortNumberIdentifier("OscRecivePortNumber");

static const Identifier OscRemoteEnabledIdentifier("OscRemoteEnabled");
static const Identifier OscRemoteHostnameIdentifier("OscRemoteHostname");
static const Identifier OscRemotePortNumberIdentifier("OscRemotePortNumber");
static const Identifier OscRemoteIsTouchOscIdentifier("OscRemoteIsTouchOsc");

class SoundboardAudioProcessor : public AudioProcessor,
                                 public ChangeListener,
                                 public OscMessageListener,
                                 public MultiTimer {
    // Maximum Number of Sampler Slots
    static const int MaximumSamplePlayers = 25;

    // Init Program Number
    static const int ProgramNumberInit = 0;
    static const int ProgramNumberCustom = 255;

    // Timer Ids
    static const int TimerOscServerDelay = 0;
    static const int TimerOscRefresh = 1;

public:
    SoundboardAudioProcessor();

    ~SoundboardAudioProcessor();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;

    void releaseResources() override;

    void processBlock(AudioSampleBuffer&, MidiBuffer&) override;

    AudioProcessorEditor* createEditor() override;

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

    void changeProgramName(int index, const String& newName) override;

    void getStateInformation(MemoryBlock& destData) override;

    void setStateInformation(const void* data, int sizeInBytes) override;

    int numAudioFiles();

    SamplePlayer* SamplePlayerAtIndex(int index);

    void openDirectory(File directory);

    int getFadeOutSeconds();

    void setFadeOutSeconds(int seconds); 

    void startOscServer()
    {
        oscServer->listen();
    }

    // ChangeListener
    void changeListenerCallback(ChangeBroadcaster* source);

    // OscMessageListener
    void handleOscMessage(osc::ReceivedPacket packet);
                                     void oscSendPlayerState(int index);
                                     void oscSendPlayerConfig(int index);
                                     void oscSendPlayerUpdate();
                                     void oscSendReset();
                                     
    // MultiTimer
    void timerCallback(int timerID);

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

    // OSC
    ScopedPointer<OscServer> oscServer;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessor)
};

#endif // PLUGINPROCESSOR_H_INCLUDED
