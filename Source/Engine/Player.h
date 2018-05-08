/*
  ==============================================================================

	Player.h
	Created: 27 Apr 2018 4:22:21pm
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ADSR.h"

class Player : public AudioSource {
public:
    Player(Identifier identifier)
            : timeSliceThread("Audio: " + identifier.toString())

    {
        timeSliceThread.startThread();
        audioTransportSource.reset(new AudioTransportSource());
    }

	~Player() {
		audioTransportSource->stop();
		audioTransportSource->setSource(nullptr);

		audioFormatReaderSource.release();
		audioTransportSource.release();
	}

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    bool loadFileIntoTransport(const File &audioFile, AudioFormatManager* audioFormatManager);

    void play() {
        audioTransportSource->start();
    }

    Identifier getIdentifier() {
        return identifier;
    }

    enum PlayerState {
        Error = -1,
        Ready = 0,
        Stopped = 1,
        Playing = 2,
        Paused = 3,
        Played = 4
    };
private:
    PlayerState playerState;
    TimeSliceThread timeSliceThread;

    Identifier identifier;

    std::unique_ptr<AudioTransportSource> audioTransportSource;
    std::unique_ptr<AudioFormatReaderSource> audioFormatReaderSource;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};
