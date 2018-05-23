#include "Player.h"

Player::Player(const Identifier &id)
        : identifier(id),
          playerState(player_idle),
          fadeState(fade_idle),
          timeSliceThread("Player: " + id.toString()) {
    timeSliceThread.startThread();
    audioTransportSource = std::make_unique<AudioTransportSource>();
}

Player::~Player() {
    audioTransportSource->stop();
    audioTransportSource->setSource(nullptr);
}

void Player::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    mySampleRate = sampleRate;
    audioTransportSource->prepareToPlay(samplesPerBlockExpected, sampleRate);
    previousGain = currentGain;
}

void Player::releaseResources() {
    audioTransportSource->releaseResources();
}

void Player::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
    audioTransportSource->getNextAudioBlock(bufferToFill);

    auto *leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    auto *rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample) {
        const auto level = adsr.process();
        leftBuffer[sample] = leftBuffer[sample] * level;
        rightBuffer[sample] = rightBuffer[sample] * level;
    }

    if (currentGain == previousGain) {
        bufferToFill.buffer->applyGain(currentGain);
    } else {
        bufferToFill.buffer->applyGainRamp(0, bufferToFill.buffer->getNumSamples(), previousGain, currentGain);
        previousGain = currentGain;
    }

    if (progress != 1) {
        progress = audioTransportSource->getCurrentPosition() / audioTransportSource->getLengthInSeconds();
        if (progress >= 1) {
            progress = 1;
            playerState = player_played;
            sendChangeMessage();
        }

        switch (adsr.getState()) {
            case ADSR::envState::env_attack:
                if (fadeState != fade_in) {
                    fadeState = fade_in;
                    sendChangeMessage();
                }
                break;
            case ADSR::envState::env_release:
                if (fadeState != fade_out) {
                    fadeState = fade_out;
                    sendChangeMessage();
                }
                break;
            case ADSR::envState::env_decay:
            case ADSR::envState::env_sustain:
            case ADSR::envState::env_idle:
            default:
                if (fadeState != fade_idle) {
                    fadeState = fade_idle;
                    sendChangeMessage();
                }
                break;
        }
    }
}

bool Player::loadFileIntoTransport(const File &audioFile,
                                   AudioFormatManager *audioFormatManager,
                                   AudioThumbnailCache *audioThumbnailCache) {
    audioTransportSource->stop();
    audioTransportSource->setSource(nullptr);

    auto reader = audioFormatManager->createReaderFor(audioFile);

    if (reader == nullptr) {
        playerState = player_error;
        return false;
    }

    audioFormatReaderSource = std::make_unique<AudioFormatReaderSource>(reader, true);

    audioTransportSource->setSource(audioFormatReaderSource.get(), 32768, &timeSliceThread, reader->sampleRate);

    thumbnail = std::make_unique<AudioThumbnail>(4096, *audioFormatManager, *audioThumbnailCache);
    thumbnail->setSource(new FileInputSource(audioFile));

    playerState = player_ready;
    sendChangeMessage();
    return true;
}

int64 Player::getTotalLength() const {
    if (audioFormatReaderSource == nullptr) {
        return 0;
    }
    return audioFormatReaderSource->getTotalLength();
}

void Player::setGain(float value) {
    currentGain = gainRange.convertFrom0to1(value);
}

float Player::getGain() {
    return gainRange.convertTo0to1(currentGain);
}

void Player::fadeIn() {
    adsr.setAttackRate(static_cast<float>((mySampleRate / 1000) * attackMs));
    adsr.gate(1);
    audioTransportSource->start();
    playerState = player_playing;
    sendChangeMessage();
}

void Player::fadeOut() {
    adsr.setReleaseRate(static_cast<float>((mySampleRate / 1000) * releaseMs));
    adsr.gate(0);
    sendChangeMessage();
}

void Player::pause() {
    audioTransportSource->stop();
    playerState = player_paused;
    sendChangeMessage();
}

void Player::play() {
    adsr.setAttackRate(0);
    adsr.gate(1);
    audioTransportSource->start();
    playerState = player_playing;
    sendChangeMessage();
}

void Player::stop() {
    audioTransportSource->stop();
    audioTransportSource->setPosition(0);
    adsr.gate(0);
    adsr.reset();
    playerState = player_stopped;
    sendChangeMessage();
}

void Player::setLooping(bool looping) {
    audioFormatReaderSource->setLooping(looping);
    sendChangeMessage();
}

bool Player::isLooping() {
    return audioFormatReaderSource->isLooping();
}


