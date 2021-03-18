/*
  ==============================================================================

  SamplePlayer.cpp
  Author:  Daniel Lindenfelser

  ==============================================================================
  */

#include "Player.h"

Player::Player(int index, const File &audioFile, AudioFormatManager *formatManager, AudioThumbnailCache *thumbnailCache, TimeSliceThread& timeSliceThread)
                                : playerIndex(index), 
                                  timeSliceThread(timeSliceThread),
                                  playerState(Ready),
                                  fadeGain(1.0f),
                                  fadeGainBackup(1.0f),
                                  fadeGainSteps(0.1f),
                                  fadeSeconds(6),
                                  fadeOut(false),
                                  fadeIn(false),
                                  process(0.0f),
                                  audioFormatManager(formatManager),
                                  thumbnailCache(thumbnailCache),
                                  thumbnail(nullptr),
                                  transportSource(new AudioTransportSource())
{
    timeSliceThread.startThread(3);
    audioSourcePlayer.setSource(transportSource);
    loadFileIntoTransport(audioFile);
    startTimer(UpdateTimerId, 50);
    startTimer(FadeTimerId, 100);
}

Player::~Player()
{
    stopTimer(UpdateTimerId);
    stopTimer(FadeTimerId);
    
    removeAllChangeListeners();
    
    if(transportSource != nullptr)
    {
        transportSource->removeAllChangeListeners();
        transportSource->setSource(nullptr);
    }

    if(thumbnail != nullptr)
    {
        thumbnail->removeAllChangeListeners();
        thumbnail->setSource(nullptr);
    }
    
    audioSourcePlayer.setSource(nullptr);

    currentAudioFileSource = nullptr;
    transportSource = nullptr;
    thumbnail = nullptr;
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
        playerState = Stopped;
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
    if (isPlaying()) {
        sendChangeMessage();
    }

    if (process >= 1.0f) {
        process = 1.0f;
        transportSource->stop();
        transportSource->setPosition(0);
        playerState = Played;
        sendChangeMessage();
    }
    if (isFading()) {
        if (!isPlaying()) {
            cancelFading();
        }
    }
}

void Player::timerCallback(int timerID)
{
    if (timerID == UpdateTimerId)
    {
        update();
        return;
    }
    if (timerID == FadeTimerId)
    {
        if (isFading()) {
            if (fadeOut) {
                fadeGain = fadeGain - fadeGainSteps;
                if (fadeGain <= 0) {
                    fadeOut = false;
                    pause();
                    fadeGain = fadeGainBackup;
                    transportSource->setGain(fadeGainBackup);
                    update();
                    sendChangeMessage();
                    return;
                }
                transportSource->setGain(fadeGain);
            } else if (fadeIn) {
                if (!transportSource->isPlaying()) {
                    transportSource->start();
                }
                fadeGain = fadeGain + fadeGainSteps;
                if (fadeGain >= fadeGainBackup) {
                    fadeIn = false;
                    playerState = Playing;
                    fadeGain = fadeGainBackup;
                    transportSource->setGain(fadeGainBackup);
                    update();
                    sendChangeMessage();
                    return;
                }
                transportSource->setGain(fadeGain);
            }
            update();
            sendChangeMessage();
        }
    }
}

void Player::startFadeOut()
{
    if (isPlaying())
    {
        fadeOut           = true;
        fadeGainBackup = transportSource->getGain();
        fadeGain = transportSource->getGain();
        fadeGainSteps = fadeGainBackup / fadeSeconds / 10.0f;
    }
}

void Player::startFadeIn()
{
    if (!isPlaying())
    {
        fadeGainBackup = transportSource->getGain();
        fadeGain = 0;
        float fade = fadeSeconds;
        if (!isLooping()) {
            if (transportSource->getLengthInSeconds() < fade) {
                fade = float(transportSource->getLengthInSeconds());
                if (fade <= 0) {
                    fade = 0.1f;
                }
            }
        }
        fadeGainSteps = fadeGainBackup / fade / 10.0f;
        transportSource->setGain(0.0);
        fadeIn = true;
        playerState = Playing;
    }
}

void Player::stop()
{
    cancelFading();
    transportSource->stop();
    transportSource->setPosition(0);
    playerState = Stopped;
    update();
    sendChangeMessage();
}

void Player::play()
{
    if (!isFading())
    {
        transportSource->start();
        playerState = Playing;
    }
}

void Player::pause()
{
    if (!isFading())
    {
        transportSource->stop();
        playerState = Paused;
    }
}

float Player::getProgress()
{
    return process;
}

void Player::setFadeTime(int seconds)
{
    fadeSeconds = seconds;
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
    Time time(1971, 0, 0, 0, 0, static_cast<int>(transportSource->getLengthInSeconds() - transportSource->getCurrentPosition()));
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
}

int Player::getIndex()
{
    return playerIndex;
}

#if JUCE_UNIT_TESTS
class PlayerTest : public UnitTest {
public:
    PlayerTest() : UnitTest ("Ultraschall: Player") {}
    
	void initialise() {
        formatManager = new AudioFormatManager();
        thumbnailCache = new AudioThumbnailCache(thumbnailCacheSize);
        
        formatManager->registerBasicFormats();
	}

	void shutdown() {
        formatManager = nullptr;
        thumbnailCache = nullptr;
	}

    void initPlayerTest() {
        beginTest("init player");
//        ScopedPointer<File> dummy = new File();
//        ScopedPointer<Player> player = new Player(1, *dummy, formatManager, thumbnailCache);
//        player = nullptr;
//        dummy = nullptr;
        expect(false, "internal crash");
    }
    
    void loadFileTest() {
        beginTest("load file");
        expect(false, "Not implemented");
    }
    
    void playTest() {
        beginTest("play player");
        expect(false, "Not implemented");
    }
    
    void pauseTest() {
        beginTest("pause player");
        expect(false, "Not implemented");
    }
    
    void stopTest() {
        beginTest("stop player");
        expect(false, "Not implemented");
    }

	void runTest() {
//		initPlayerTest();
//
//        loadFileTest();
//
//        playTest();
//        pauseTest();
//        stopTest();
	}
    
private:
    ScopedPointer<AudioFormatManager> formatManager;
    ScopedPointer<AudioThumbnailCache> thumbnailCache;
    const int thumbnailCacheSize = 5;
};

static PlayerTest playerTest;
#endif

bool Player::isFadingIn() {
    return fadeIn;
}

bool Player::isFading() {
    return fadeOut || fadeIn;
}

void Player::cancelFading() {
    if (isFading())
    {
        fadeOut     = false;
        fadeIn      = false;
        fadeGain = fadeGainBackup;
        transportSource->setGain(fadeGain);
        update();
    }
}
