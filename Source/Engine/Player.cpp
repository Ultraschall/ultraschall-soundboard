/*
  ==============================================================================

	Player.cpp
	Created: 27 Apr 2018 4:22:22pm
	Author:  danlin

  ==============================================================================
*/

#include "Player.h"

void Player::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    audioTransportSource->prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Player::releaseResources() {
    audioTransportSource->releaseResources();
}

void Player::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
    audioTransportSource->getNextAudioBlock(bufferToFill);
}

bool Player::loadFileIntoTransport(const File &audioFile, AudioFormatManager *audioFormatManager) {
    audioTransportSource->stop();
    audioTransportSource->setSource(nullptr);
    audioFormatReaderSource.reset(nullptr);

    auto reader = audioFormatManager->createReaderFor(audioFile);

    if (reader != nullptr)
    {
        audioFormatReaderSource.reset(new AudioFormatReaderSource(reader, true));

        audioTransportSource->setSource(audioFormatReaderSource.get(), 32768, &timeSliceThread, reader->sampleRate);

        playerState = Stopped;
        return true;
    }
    else
    {
        playerState = Error;
        return false;
    }
}
