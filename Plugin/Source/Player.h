/*
  ==============================================================================

  SamplePlayer.h
  Author:  Daniel Lindenfelser

  ==============================================================================
  */

#ifndef SAMPLEPLAYER_H_INCLUDED
#define SAMPLEPLAYER_H_INCLUDED

#include "JuceHeader.h"

class Player : private MultiTimer, public ChangeBroadcaster, public OscParameterListener
{
public:
    Player(int index, const File &audioFile,
           AudioFormatManager *formatManager,
           AudioThumbnailCache *thumbnailCache,
           OscProcessor &);
    ~Player();

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

    float  getProgress();
    String getProgressString(bool remaining = true);

    void setFadeOutTime(int seconds);
    void startFadeOut();
    bool isFadingOut();

    void timerCallback(int timerID) override;

    void  setGain(float newGain);
    float getGain();

    enum PlayerState
    {
        Error = -1, Ready = 0, Stopped = 1, Playing = 2, Paused = 3, Played = 4
    };

    PlayerState getState();
    AudioSource    *getAudioSource();
    AudioThumbnail *getThumbnail();

    void setIndex(int value);
    int  getIndex();
    
    // ChangeListener
    void handleOscParameterMessage(OscParameter *parameter) override;
private:
    static const int UpdateTimerId  = 0;
    static const int FadeOutTimerId = 1;

    void update();
    void loadFileIntoTransport(const File &audioFile);

    int             playerIndex;
    TimeSliceThread timeSliceThread;
    String          title;
    PlayerState     playerState;
    float           fadeOutGain;
    float           fadeOutGainBackup;
    float           fadeOutGainSteps;
    int             fadeOutSeconds;
    bool            fadeOut;
    float           process;
    AudioFormatManager  *audioFormatManager;
    AudioThumbnailCache *thumbnailCache;
    ScopedPointer<AudioThumbnail>          thumbnail;
    ScopedPointer<AudioTransportSource>    transportSource;
    AudioSourcePlayer                      audioSourcePlayer;
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
    OscProcessor &processor; JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Player)
};

#endif // AUDIOFILE_H_INCLUDED

