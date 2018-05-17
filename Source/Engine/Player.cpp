#include "Player.h"

void Player::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mySampleRate = sampleRate;
    audioTransportSource->prepareToPlay(samplesPerBlockExpected, sampleRate);
	previousGain = currentGain;
}

void Player::releaseResources()
{
    audioTransportSource->releaseResources();
}

void Player::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
    audioTransportSource->getNextAudioBlock(bufferToFill);

    auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);

    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
    {
	    const auto level = adsr.process();
        leftBuffer[sample]  = leftBuffer[sample] * level;
        rightBuffer[sample] = rightBuffer[sample] * level;
    }

	if (currentGain == previousGain)
	{
		bufferToFill.buffer->applyGain(currentGain);
	}
	else
	{
		bufferToFill.buffer->applyGainRamp(0, bufferToFill.buffer->getNumSamples(), previousGain, currentGain);
		previousGain = currentGain;
	}
}

bool Player::loadFileIntoTransport(const File &audioFile, AudioFormatManager *audioFormatManager,
                                   AudioThumbnailCache *audioThumbnailCache)
{
    audioTransportSource->stop();
    audioTransportSource->setSource(nullptr);

    auto reader = audioFormatManager->createReaderFor(audioFile);

    if (reader == nullptr)
    {
        playerState = Error;
        return false;
    }

    audioFormatReaderSource = std::make_unique<AudioFormatReaderSource>(reader, true);

    audioTransportSource->setSource(audioFormatReaderSource.get(), 32768, &timeSliceThread, reader->sampleRate);

    thumbnail = std::make_unique<AudioThumbnail>(4096, *audioFormatManager, *audioThumbnailCache);
    thumbnail->setSource(new FileInputSource(audioFile));

    playerState = Stopped;
    return true;
}
