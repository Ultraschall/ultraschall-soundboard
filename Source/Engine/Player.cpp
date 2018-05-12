#include "Player.h"

void Player::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    audioTransportSource->prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Player::releaseResources()
{
    audioTransportSource->releaseResources();
}

void Player::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
    audioTransportSource->getNextAudioBlock(bufferToFill);
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
