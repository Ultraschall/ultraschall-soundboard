#pragma once

#include <memory>
#include "JuceHeader.h"
#include "ADSR.h"

class Player : public AudioSource
{
public:
    explicit Player(const Identifier &id)
            : playerState(Idle), timeSliceThread("Audio: " + id.toString()),
              identifier(id)
    {
        timeSliceThread.startThread();
        audioTransportSource = std::make_unique<AudioTransportSource>();
        adsr.setAttackRate(1.0f);
        adsr.setDecayRate(0.0f);
        adsr.setSustainLevel(1.0f);
        adsr.setReleaseRate(1.0f);
        adsr.reset();
    }

    ~Player() override
    {
        audioTransportSource->stop();
        audioTransportSource->setSource(nullptr);
    }

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    bool loadFileIntoTransport(const File &audioFile, AudioFormatManager *audioFormatManager,
                               AudioThumbnailCache *audioThumbnailCache);

    void play()
    {
        adsr.setAttackRate(1);
        adsr.gate(1);
        audioTransportSource->start();
    }

    void stop()
    {
        audioTransportSource->stop();
        audioTransportSource->setPosition(0);
        adsr.gate(0);
        adsr.reset();
    }

    void pause() const
    {
        audioTransportSource->stop();
    }

    void fadeIn() {
        adsr.setAttackRate(mySampleRate * attackMs);
        adsr.gate(1);
        audioTransportSource->start();
    }

    void fadeOut() {
        adsr.setReleaseRate(mySampleRate * releaseMs);
        adsr.gate(0);
    }

    Identifier getIdentifier() const
    {
        return identifier;
    }

    enum PlayerState
    {
        Error = -1,
        Ready = 0,
        Stopped = 1,
        Playing = 2,
        Paused = 3,
        Played = 4,
        Idle = 128
    };

    std::unique_ptr<AudioThumbnail> thumbnail;

    int64 getTotalLength()
    {
        if (audioFormatReaderSource == nullptr)
        {
            return 0;
        }
        return audioFormatReaderSource->getTotalLength();
    }
private:
    float gain{1.0f};
    double mySampleRate{0.0};
    int attackMs{10};
    int releaseMs{10};

    PlayerState playerState;
    TimeSliceThread timeSliceThread;

    Identifier identifier;

    std::unique_ptr<AudioTransportSource> audioTransportSource;
    std::unique_ptr<AudioFormatReaderSource> audioFormatReaderSource;

    ADSR adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};
