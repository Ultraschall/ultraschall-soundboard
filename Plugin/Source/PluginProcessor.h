/*
 ==============================================================================

 PluginProcessor.h
 Author:  Daniel Lindenfelser

 ==============================================================================
 */

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "JuceHeader.h"
#include "Player.h"

class LookAndFeel_Ultraschall;

static const Identifier DirectoryIdentifier("Directory");
static const Identifier CurrentDirectoryIdentifier("CurrentDirectory");
static const Identifier CurrentProgramIndexIdentifier("CurrentProgramIndex");

static const Identifier WindowWidthIdentifier("WindowWidth");
static const Identifier WindowHeightIdentifier("WindowHeight");

static const Identifier ThemeIdentifier("Theme");

static const Identifier OscReceiveEnabledIdentifier("OscReceiveEnabled");
static const Identifier OscReceivePortNumberIdentifier("OscReceivePortNumber");

static const Identifier OscRepeaterEnabledIdentifier("OscRepeaterEnabled");
static const Identifier OscRepeaterHostnameIdentifier("OscRepeaterHostname");
static const Identifier OscRepeaterPortNumberIdentifier("OscRepeaterPortNumber");

static const Identifier OscRemoteEnabledIdentifier("OscRemoteEnabled");
static const Identifier OscRemoteHostnameIdentifier("OscRemoteHostname");
static const Identifier OscRemotePortNumberIdentifier("OscRemotePortNumber");

class SoundboardAudioProcessor : public AudioProcessor, public OscProcessor, public MultiTimer, public OscParameterListener
{
public:
    SoundboardAudioProcessor();
    ~SoundboardAudioProcessor();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock(AudioSampleBuffer &, MidiBuffer &) override;

    AudioProcessorEditor *createEditor() override;
    bool hasEditor() const override;

    const String getName() const override;

    const String getInputChannelName(int channelIndex) const override;
    const String getOutputChannelName(int channelIndex) const override;
    bool         isInputChannelStereoPair(int index) const override;
    bool         isOutputChannelStereoPair(int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;

    bool   silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    int          getNumPrograms() override;
    int          getCurrentProgram() override;
    void         setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void         changeProgramName(int index, const String &newName) override;

    void getStateInformation(MemoryBlock &destData) override;
    void setStateInformation(const void *data, int sizeInBytes) override;

    int numPlayers();
    Player *playerAtIndex(int index);

    void openDirectory(File directory);

    bool isLoocked()
    {
        return playersLocked;
    }

    int  getFadeOutSeconds();
    void setFadeOutSeconds(int seconds);

    // MultiTimer
    void timerCallback(int timerID) override;

    // Properties
    PropertiesFile *getPropertiesFile()
    {
        return propertiesFile;
    }

    // Parameter Helper
    void setGain(int playerIndex, float value);
    int  getWindowWidth();
    void storeWindowWidth(int width);
    int  getWindowHeight();
    void storeWindowHeight(int height);

    // Maximum Number of Sampler Slots
    static const int MaximumSamplePlayers = 24;

    // OscParameterListener
    void handleOscParameterMessage(OscParameter *parameter) override;

private:
    // Init Program Number
    static const int ProgramNumberInit   = 0;
    static const int ProgramNumberCustom = 255;

    // Timer Ids
    static const int TimerOscServerDelay = 0;
    static const int TimerMidiEvents     = 3;

    // Audio IO
    OwnedArray<Player>                 players;
    AudioFormatManager                 formatManager;
    ScopedPointer<AudioThumbnailCache> thumbnailCache;
    AudioSourceChannelInfo             sourceChannelInfo;
    MixerAudioSource                   mixerAudioSource;
    bool playersLocked;

    int                      fadeOutSeconds;
    NormalisableRange<float> fadeOutRange;

    // Settings
    int                           currentProgramIndex;
    String                        currentDirectory;
    ScopedPointer<PropertySet>    fallbackProperties;
    ScopedPointer<PropertiesFile> propertiesFile;   
    
    // MIDI
    MidiBuffer      midiBuffer;
    CriticalSection midiCriticalSection;

    enum MidiFunction
    {
        PlayStop = 0, PlayPause = 1, PlayFadeOut = 2, HoldAndPlay = 3
    };
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessor)
};

#endif // PLUGINPROCESSOR_H_INCLUDED
