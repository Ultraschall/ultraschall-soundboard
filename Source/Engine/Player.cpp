/*
  ==============================================================================

	Player.cpp
	Created: 27 Apr 2018 4:22:22pm
	Author:  danlin

  ==============================================================================
*/

#include "Player.h"
#include <memory>

void Player::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    audioTransportSource->prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Player::releaseResources() {
    audioTransportSource->releaseResources();
}

void Player::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
    audioTransportSource->getNextAudioBlock(bufferToFill);
}

bool Player::loadFileIntoTransport(const File &audioFile, AudioFormatManager *audioFormatManager, AudioThumbnailCache *audioThumbnailCache) {
    audioTransportSource->stop();
    audioTransportSource->setSource(nullptr);
    audioFormatReaderSource.reset(nullptr);

    auto reader = audioFormatManager->createReaderFor(audioFile);

    if (reader != nullptr)
    {
        audioFormatReaderSource = std::make_unique<AudioFormatReaderSource>(reader, true);

        audioTransportSource->setSource(audioFormatReaderSource.get(), 32768, &timeSliceThread, reader->sampleRate);

        thumbnail = std::make_unique<AudioThumbnail>(audioFormatReaderSource->getTotalLength() / 512, *audioFormatManager, *audioThumbnailCache);
        thumbnail->setSource(new FileInputSource(audioFile));

        playerState = Stopped;
        return true;
    }
    else
    {
        playerState = Error;
        return false;
    }
}
