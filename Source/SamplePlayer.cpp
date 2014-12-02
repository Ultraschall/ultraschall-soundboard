/*
  ==============================================================================

    SamplePlayer.cpp
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "SamplePlayer.h"

SamplePlayer::SamplePlayer(const File &audioFile, AudioFormatManager *formatManager)
        : timeSliceThread("SamplePlayer " + audioFile.getFileNameWithoutExtension()),
          title(audioFile.getFileNameWithoutExtension()),
          playerState(Stopped),
          fadeOutGain(1.0f),
          fadeOutGainBackup(1.0f),
          fadeOutGainSteps(0.1f),
          fadeOutSeconds(4),
          fadeOut(false),
          process(0.0f),
          audioFormatManager(formatManager),
          transportSource(new AudioTransportSource()) {
    timeSliceThread.startThread(3);
    audioSourcePlayer.setSource(transportSource);
    loadFileIntoTransport(audioFile);
    startTimer(UpdateTimerId, 50);
    startTimer(FadeOutTimerId, 100);
}

SamplePlayer::~SamplePlayer() {
    removeAllChangeListeners();
    stopTimer(UpdateTimerId);
    stopTimer(FadeOutTimerId);
    transportSource->setSource(nullptr);
    audioSourcePlayer.setSource(nullptr);
    transportSource->removeAllChangeListeners();
    transportSource = nullptr;
}

void SamplePlayer::loadFileIntoTransport(const File &audioFile) {
    // unload the previous file source and delete it..
    transportSource->stop();
    transportSource->setSource(nullptr);
    currentAudioFileSource = nullptr;

    AudioFormatReader *reader = audioFormatManager->createReaderFor(audioFile);

    if (reader != nullptr) {
        currentAudioFileSource = new AudioFormatReaderSource(reader, true);

        // ..and plug it into our transport source
        transportSource->setSource(currentAudioFileSource,
                32768, // tells it to buffer this many samples ahead
                &timeSliceThread, // this is the background thread to use for reading-ahead
                reader->sampleRate); // allows for sample rate correction
    }
}

void SamplePlayer::update() {
    double current = transportSource->getNextReadPosition();
    double length = transportSource->getTotalLength();
    double progress = (current / length);
    process = (float) progress;
    if (progress >= 1.0) {
        progress = 1.0;
        transportSource->stop();
        transportSource->setPosition(0);
        playerState = Played;
        sendChangeMessage();
    }
}

void SamplePlayer::timerCallback(int timerID) {
    if (timerID == UpdateTimerId) {
        update();
        return;
    }
    if (timerID == FadeOutTimerId) {
        if (fadeOut) {
            fadeOutGain = fadeOutGain - fadeOutGainSteps;
            if (fadeOutGain <= 0) {
                fadeOut = false;
                transportSource->stop();
                transportSource->setPosition(0);
                playerState = Played;
                fadeOutGain = fadeOutGainBackup;
                update();
                sendChangeMessage();
            }
            transportSource->setGain(fadeOutGain);
        }
    }
}

void SamplePlayer::startFadeOut() {
    if (isPlaying()) {
        fadeOut = true;
        fadeOutGainBackup = transportSource->getGain();
        fadeOutGain = transportSource->getGain();
        fadeOutGainSteps = fadeOutGainBackup / fadeOutSeconds / 10.0f;
        sendChangeMessage();
    }
}

void SamplePlayer::stop() {
    transportSource->stop();
    transportSource->setPosition(0);
    if (isLooping()) {
        fadeOut = false;
        fadeOutGain = fadeOutGainBackup;
    }
    playerState = Stopped;
    update();
    sendChangeMessage();
}

void SamplePlayer::play() {
    if (!fadeOut) {
        transportSource->start();
        playerState = Playing;
        sendChangeMessage();
    }
}

void SamplePlayer::pause() {
    if (!fadeOut) {
        transportSource->stop();
        playerState = Paused;
        sendChangeMessage();
    }
}

float SamplePlayer::getProgress() {
    return process;
}

void SamplePlayer::setFadeOutTime(int seconds) {
    fadeOutSeconds = seconds;
}

bool SamplePlayer::isLooping() {
    return currentAudioFileSource->isLooping();
}

void SamplePlayer::setLooping(bool value) {
    if (isPlaying() && !value) {
        int64 nextReadPosition = transportSource->getNextReadPosition();
        currentAudioFileSource->setLooping(false);
        transportSource->setNextReadPosition(nextReadPosition);
        return;
    }
    currentAudioFileSource->setLooping(value);
    sendChangeMessage();
}

String SamplePlayer::getTitle() {
    return title;
}

String SamplePlayer::getProgressString(bool remaining) {
    if (!remaining) {
        Time time(1971, 0, 0, 0, 0, (int) transportSource->getCurrentPosition());
        return time.toString(false, true, true, true);
    } else {
        Time time(1971, 0, 0, 0, 0, (int) (transportSource->getLengthInSeconds() - transportSource->getCurrentPosition()));
        return "-" + time.toString(false, true, true, true);
    }
}

float SamplePlayer::getGain() {
    return transportSource->getGain();
}

void SamplePlayer::setGain(float newGain) {
    transportSource->setGain(newGain);
}

SamplePlayer::PlayerState SamplePlayer::getState() {
    return playerState;
}

AudioSource *SamplePlayer::getAudioSource() {
    return transportSource;
}

bool SamplePlayer::isStopped() {
    return playerState == Stopped;
}

bool SamplePlayer::isPlayed() {
    return playerState == Played;
}

bool SamplePlayer::isPlaying() {
    return playerState == Playing;
}

bool SamplePlayer::isPaused() {
    return playerState == Paused;
}

bool SamplePlayer::isFadingOut() {
    return fadeOut;
}
