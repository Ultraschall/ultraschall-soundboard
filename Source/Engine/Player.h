#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ADSR.h"

class Player : public AudioSource, public ChangeBroadcaster
{
  public:
    explicit Player(const Identifier &id);

    ~Player() override;

    // AudioSource
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    // File
    bool loadFileIntoTransport(const File &audioFile,
                               AudioFormatManager *audioFormatManager,
                               AudioThumbnailCache *audioThumbnailCache);

    // Player Transport Functions
    void play();

    void stop();

    void pause();

    void fadeIn();

    void fadeOut();

    void setGain(float value);

    float getGain();

    int64 getTotalLength() const;

    Identifier identifier;

    enum PlayerState
    {
        player_error = -1,
        player_ready = 0,
        player_stopped = 1,
        player_playing = 2,
        player_paused = 3,
        player_played = 4,
        player_idle = 255
    };
    PlayerState playerState{player_idle};
    double progress{0};
    enum FadeState
    {
        fade_in = 1,
        fade_out = 2,
        fade_idle = 255
    };
    FadeState fadeState{fade_idle};

    bool isLooping();

    void setLooping(bool looping);

    std::shared_ptr<AudioThumbnail> thumbnail;

  private:
    float currentGain{1.0f};
    float previousGain{1.0f};
    NormalisableRange<float> gainRange{
        Decibels::decibelsToGain<float>(-180),
        Decibels::decibelsToGain<float>(0),
        0,
        Decibels::decibelsToGain<float>(-12)};

    double mySampleRate{0.0};
    int attackMs{3000};
    int releaseMs{3000};

    TimeSliceThread timeSliceThread;

    std::unique_ptr<AudioTransportSource> audioTransportSource;
    std::unique_ptr<AudioFormatReaderSource> audioFormatReaderSource;

    ADSR adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};
