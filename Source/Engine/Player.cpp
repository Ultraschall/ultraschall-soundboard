#include "Player.h"

Player::Player(const Identifier &id)
    : identifier(id),
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

	for (auto sample = 0; sample < bufferToFill.numSamples; ++sample) {
        const auto level = envelope.process();

		if (envelope.getState() == Envelope::env_sustain) {
			continue;
        }

        for (int i = 0; i < bufferToFill.buffer->getNumChannels(); ++i) {
            bufferToFill.buffer->applyGain(i, sample, 1, level);
        }
	}

    if (currentGain == previousGain) {
        bufferToFill.buffer->applyGain(currentGain);
    } else {
        bufferToFill.buffer->applyGainRamp(0, bufferToFill.buffer->getNumSamples(), previousGain, currentGain);
        previousGain = currentGain;
    }

    if (progress != 1) {
        auto needUpdate = false;
        if (playerState == PlayerState::player_playing) {
            needUpdate = true;
        }

        progress = audioTransportSource->getCurrentPosition() / audioTransportSource->getLengthInSeconds();
        if (progress >= 1) {
            progress = 1;
            playerState = PlayerState::player_played;
            needUpdate = true;
        }

        switch (envelope.getState()) {
            case Envelope::envState::env_attack:
                if (fadeState != FadeState::fade_in) {
                    fadeState = FadeState::fade_in;
                    needUpdate = true;
                }
                break;
            case Envelope::envState::env_release:
                if (fadeState != FadeState::fade_out) {
                    fadeState = FadeState::fade_out;
                    needUpdate = true;
                }
                break;
            case Envelope::envState::env_decay:
            case Envelope::envState::env_sustain:
            case Envelope::envState::env_idle:
            default:
                if (fadeState != FadeState::fade_idle) {
                    fadeState = FadeState::fade_idle;
                    needUpdate = true;
                }
                break;
        }
        if (needUpdate) {
            sendChangeMessage();
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
        playerState = Player::PlayerState::player_error;
        return false;
    }

    audioFormatReaderSource = std::make_unique<AudioFormatReaderSource>(reader, true);

    audioTransportSource->setSource(audioFormatReaderSource.get(), 32768, &timeSliceThread, reader->sampleRate);

    int sourceSamplesPerThumbnailSample = int(audioFormatReaderSource->getTotalLength() / 512);
    thumbnail = std::make_unique<AudioThumbnail>(sourceSamplesPerThumbnailSample, *audioFormatManager, *audioThumbnailCache);
    thumbnail->addChangeListener(this);
    thumbnail->setSource(new FileInputSource(audioFile));

    playerState = PlayerState::player_ready;
	setGain(1.0f);
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
    envelope.setAttackRate(static_cast<float>((mySampleRate / 1000) * attackMs));
    envelope.gate(1);
    audioTransportSource->start();
    playerState = PlayerState::player_playing;
    sendChangeMessage();
}

void Player::fadeOut() {
    envelope.setReleaseRate(static_cast<float>((mySampleRate / 1000) * releaseMs));
    envelope.gate(0);
    sendChangeMessage();
}

void Player::pause() {
    audioTransportSource->stop();
    playerState = PlayerState::player_paused;
    sendChangeMessage();
}

void Player::play() {
    envelope.setAttackRate(0);
    envelope.gate(1);
    audioTransportSource->start();
    playerState = PlayerState::player_playing;
    sendChangeMessage();
}

void Player::stop() {
    audioTransportSource->stop();
    audioTransportSource->setPosition(0);
    envelope.gate(0);
    envelope.reset();
    if (playerState != PlayerState::player_played) {
        playerState = PlayerState::player_stopped;
    } else {
        playerState = PlayerState::player_ready;
        progress = 0;
    }
    sendChangeMessage();
}

void Player::setLooping(bool looping) {
    audioFormatReaderSource->setLooping(looping);
    sendChangeMessage();
}

bool Player::isLooping() {
    return audioFormatReaderSource->isLooping();
}

void Player::changeListenerCallback (ChangeBroadcaster* source) {
    auto changedThumbnail = dynamic_cast<AudioThumbnail*>(source);
    if (changedThumbnail == nullptr) {
        return;
    }
    if (changedThumbnail->isFullyLoaded()) {
        MemoryOutputStream thumbnailBuffer{thumbnailData, false};
        changedThumbnail->saveTo(thumbnailBuffer);
        thumbnailFullyLoaded = true;
    }
}

bool Player::isThumbnailFullyLoaded() {
    return thumbnailFullyLoaded;
}
