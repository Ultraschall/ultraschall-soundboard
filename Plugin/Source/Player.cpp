/*
  ==============================================================================

  SamplePlayer.cpp
  Author:  Daniel Lindenfelser

  ==============================================================================
  */

#include "Player.h"

Player::Player(int index, const File &audioFile,
               AudioFormatManager *formatManager,
               AudioThumbnailCache *thumbnailCache,
               OscProcessor &p) : playerIndex(index),
                                  timeSliceThread("Player: " + audioFile.getFileNameWithoutExtension()),
                                  title(audioFile.getFileNameWithoutExtension()),
                                  playerState(Stopped),
                                  fadeOutGain(1.0f),
                                  fadeOutGainBackup(1.0f),
                                  fadeOutGainSteps(0.1f),
                                  fadeOutSeconds(4),
                                  fadeOut(false),
                                  process(0.0f),
                                  audioFormatManager(formatManager),
                                  thumbnailCache(thumbnailCache),
                                  transportSource(new AudioTransportSource()),
                                  processor(p)
{
    timeSliceThread.startThread(3);
    audioSourcePlayer.setSource(transportSource);
    loadFileIntoTransport(audioFile);
    startTimer(UpdateTimerId, 50);
    startTimer(FadeOutTimerId, 100);
    
    p.addOscParameterListener(this, "/ultraschall/soundboard/player/"  + String(playerIndex) + "/.+");
}

Player::~Player()
{
    thumbnail->removeAllChangeListeners();
    thumbnail->clear();
    removeAllChangeListeners();
    stopTimer(UpdateTimerId);
    stopTimer(FadeOutTimerId);
    thumbnail->setSource(nullptr);
    thumbnail = nullptr;
    transportSource->setSource(nullptr);
    audioSourcePlayer.setSource(nullptr);
    transportSource->removeAllChangeListeners();
    transportSource = nullptr;
}

void Player::loadFileIntoTransport(const File &audioFile)
{
    transportSource->stop();
    transportSource->setSource(nullptr);
    currentAudioFileSource = nullptr;

    auto reader = audioFormatManager->createReaderFor(audioFile);

    if (reader != nullptr)
    {
        currentAudioFileSource = new AudioFormatReaderSource(reader, true);

        transportSource->setSource(currentAudioFileSource, 32768, &timeSliceThread, reader->sampleRate);

        thumbnail = new AudioThumbnail(1024, *audioFormatManager, *thumbnailCache);
        thumbnail->setSource(new FileInputSource(audioFile));
        playerState = Ready;
    }
    else
    {
        playerState = Error;
    }
}

AudioThumbnail *Player::getThumbnail()
{
    return thumbnail;
}

void Player::update()
{
    process = static_cast<float>(transportSource->getCurrentPosition() / transportSource->getLengthInSeconds());
    if (process >= 1.0f)
    {
        process = 1.0f;
        transportSource->stop();
        transportSource->setPosition(0);
        playerState = Played;
    }
    if (static_cast<float>(processor.getOscParameter("/ultraschall/soundboard/player/" + String(playerIndex) + "/progress")->getValue()) != process) {
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/progress", process);
    }
}

void Player::timerCallback(int timerID)
{
    if (timerID == UpdateTimerId)
    {
        update();
        return;
    }
    if (timerID == FadeOutTimerId)
    {
        if (fadeOut)
        {
            fadeOutGain = fadeOutGain - fadeOutGainSteps;
            if (fadeOutGain <= 0)
            {
                fadeOut = false;
                transportSource->stop();
                transportSource->setPosition(0);
                playerState = Played;
                fadeOutGain = fadeOutGainBackup;
                update();
            }
            transportSource->setGain(fadeOutGain);
        }
    }
}

void Player::startFadeOut()
{
    if (isPlaying())
    {
        fadeOut           = true;
        fadeOutGainBackup = transportSource->getGain();
        fadeOutGain       = transportSource->getGain();
        fadeOutGainSteps  = fadeOutGainBackup / fadeOutSeconds / 10.0f;
    }
}

void Player::stop()
{
    if (isFadingOut())
    {
        stopTimer(FadeOutTimerId);
        fadeOut     = false;
        fadeOutGain = fadeOutGainBackup;
        transportSource->setGain(fadeOutGain);
    }
    transportSource->stop();
    transportSource->setPosition(0);
    playerState = Stopped;
    update();
    sendChangeMessage();
}

void Player::play()
{
    if (!fadeOut)
    {
        transportSource->start();
        playerState = Playing;
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/stop", false);
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/pause", false);
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/done", false);
    }
}

void Player::pause()
{
    if (!fadeOut)
    {
        transportSource->stop();
        playerState = Paused;
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/stop", false);
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/pause", false);
        processor.setOscParameterValue("/ultraschall/soundboard/player/" + String(playerIndex) + "/done", false);
    }
}

float Player::getProgress()
{
    return process;
}

void Player::setFadeOutTime(int seconds)
{
    fadeOutSeconds = seconds;
}

bool Player::isLooping()
{
    return currentAudioFileSource->isLooping();
}

void Player::setLooping(bool value)
{
    if (isPlaying() && !value)
    {
        auto nextReadPosition = transportSource->getNextReadPosition();
        currentAudioFileSource->setLooping(false);
        transportSource->setNextReadPosition(nextReadPosition);
        return;
    }
    currentAudioFileSource->setLooping(value);
    sendChangeMessage();
}

String Player::getTitle()
{
    return title;
}

String Player::getProgressString(bool remaining)
{
    if (!remaining)
    {
        Time time(1971, 0, 0, 0, 0, static_cast<int>(transportSource->getCurrentPosition()));
        return time.toString(false, true, true, true);
    }
    Time
            time(1971,
                 0,
                 0,
                 0,
                 0,
                 static_cast<int>(transportSource->getLengthInSeconds() - transportSource->getCurrentPosition()));
    return "-" + time.toString(false, true, true, true);
}

float Player::getGain()
{
    return transportSource->getGain();
}

void Player::setGain(float newGain)
{
    transportSource->setGain(newGain);
}

Player::PlayerState Player::getState()
{
    return playerState;
}

AudioSource *Player::getAudioSource()
{
    return transportSource;
}

bool Player::isStopped()
{
    return playerState == Stopped;
}

bool Player::isPlayed()
{
    return playerState == Played;
}

bool Player::isPlaying()
{
    return playerState == Playing;
}

bool Player::isPaused()
{
    return playerState == Paused;
}

bool Player::isFadingOut()
{
    return fadeOut;
}

void Player::setIndex(int value)
{
    playerIndex = value;
    processor.removeOscParameterListener(this);
    processor.addOscParameterListener(this, "/ultraschall/soundboard/player/"  + String(playerIndex) + "/.+");
}

int Player::getIndex()
{
    return playerIndex;
}

void Player::handleOscParameterMessage(OscParameter *parameter)
{
    String address = parameter->getAddress();
    float value = parameter->getValue();
    if (address.startsWith("/ultraschall/soundboard/player/" + String(playerIndex))) {
        if (address.endsWith("/play")) {
            if (value == 1.0) {
                play();
            }
        }
        else if (address.endsWith("/pause")) {
            if (value == 1.0) {
                pause();
            }
        }
        else if (address.endsWith("/stop")) {
            if (value == 1.0) {
                stop();
            }
        }
        else if (address.endsWith("/tigger")) {
            if (value == 1.0) {
                if (isPlayed()) {
                    stop();
                } else {
                    play();
                }
            }
        }
    }
}
