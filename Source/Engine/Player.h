#pragma once

#include <memory>
#include "JuceHeader.h"
#include "ADSR.h"

class Player : public AudioSource {
public:
    explicit Player(const Identifier& id)
		: playerState(Idle), timeSliceThread("Audio: " + id.toString()),
		  identifier(id)

	{
		timeSliceThread.startThread();
		audioTransportSource = std::make_unique<AudioTransportSource>();
	}

	~Player() {
		audioTransportSource->stop();
		audioTransportSource->setSource(nullptr);
	}

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    bool loadFileIntoTransport(const File &audioFile, AudioFormatManager* audioFormatManager, AudioThumbnailCache *audioThumbnailCache);

    void play() const
    {
        audioTransportSource->start();
    }

	void stop() const
	{
		audioTransportSource->stop();
		audioTransportSource->setPosition(0);
	}

	void pause() const
	{
		audioTransportSource->stop();
	}

	Identifier getIdentifier() const
	{
        return identifier;
    }

    enum PlayerState {
        Error = -1,
        Ready = 0,
        Stopped = 1,
        Playing = 2,
        Paused = 3,
        Played = 4,
		Idle = 128
    };

    std::unique_ptr<AudioThumbnail> thumbnail;

private:
    PlayerState playerState;
    TimeSliceThread timeSliceThread;

	Identifier identifier;

    std::unique_ptr<AudioTransportSource> audioTransportSource;
    std::unique_ptr<AudioFormatReaderSource> audioFormatReaderSource;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};
