/*
  ==============================================================================

  SamplePlayer.h
  Author:  Daniel Lindenfelser

  ==============================================================================
  */

#ifndef SAMPLEPLAYER_H_INCLUDED
#define SAMPLEPLAYER_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>
#include <juce_audio_formats/juce_audio_formats.h>
#include <juce_audio_utils/juce_audio_utils.h>

using namespace juce;

class Player : private MultiTimer,
               public ChangeBroadcaster {
public:
    Player(int index, const File& audioFile, AudioFormatManager* formatManager, AudioThumbnailCache* thumbnailCache, TimeSliceThread &timeSliceThread);
    ~Player() override;

    String getTitle();

    void play();
    void pause();
    void stop();

    bool isPlaying();
    bool isPaused();
    bool isStopped();
    bool isPlayed();

    void setLooping(bool value);
    bool isLooping();

    float getProgress();
    String getProgressString(bool remaining = true);

    void setFadeTime(int seconds);
    void startFadeOut();
    bool isFadingOut();
    void startFadeIn();
    bool isFadingIn();
    bool isFading();
    void cancelFading();

    void timerCallback(int timerID) override;

    void setGain(float newGain);
    float getGain();

    enum PlayerState {
        Error = -1,
        Ready = 0,
        Stopped = 1,
        Playing = 2,
        Paused = 3,
        Played = 4
    };

    PlayerState getState();
    AudioSource* getAudioSource();
    AudioThumbnail* getThumbnail();

    void setIndex(int value);
    int getIndex();
private:
    static const int UpdateTimerId = 0;
    static const int FadeTimerId = 1;

    void update();
    void loadFileIntoTransport(const File& audioFile);

    int playerIndex;
    TimeSliceThread &timeSliceThread;
    String title;
    PlayerState playerState;
    float fadeGain;
    float fadeGainBackup;
    float fadeGainSteps;
    int fadeSeconds;
    bool fadeOut;
    bool fadeIn;
    CriticalSection fadeCriticalSection;
    float process;
    AudioFormatManager* audioFormatManager;
    AudioThumbnailCache* thumbnailCache;
    ScopedPointer<AudioThumbnail> thumbnail;
    ScopedPointer<AudioTransportSource> transportSource;
    AudioSourcePlayer audioSourcePlayer;
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};

#endif // AUDIOFILE_H_INCLUDED
