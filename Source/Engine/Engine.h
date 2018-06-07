#pragma once

#include "JuceHeader.h"
#include "Player.h"
#include "../Models/Identifier.h"
#include "../Models/PlayerModel.h"

class Engine : public AudioSource, public ChangeListener, public Timer
{
public:
    Engine();

    ~Engine() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    void loadAudioFile(const File& file);

    void importDirectory(const File& directory);

    void newBank();

	void newPlaylist();

    Player *playerWithIdentifier(const Identifier &id);

    ValueTree playerStateWithIdentifier(const Identifier &id);

    void debugState() const;

	void setGain(float value);

	float getGain() const;

	void toggleTalkOver();

	void openFile(const File& file);

	void saveFile(const File& file) const;

	void playerLooping(const Identifier &uuid, bool looping);

	void playerFadeOut(const Identifier &uuid);

	void playerFadeIn(const Identifier &uuid);

	void playerPlay(const Identifier &uuid);

	void playerPause(const Identifier &uuid);

	void playerStop(const Identifier &uuid);

    void changeListenerCallback (ChangeBroadcaster* source) override;
	void syncState(ValueTree state, Player* player);

    void timerCallback() override;

    AudioFormatManager audioFormatManager;
    AudioThumbnailCache audioThumbnailCache;
    UndoManager undoManager;
    ValueTree state;
private:
    Array<Identifier> playersToUpdate;

	double currentSampleRate{0};
	float currentGain{ 1.0f };
	float previousGain{ 1.0f };
	NormalisableRange<float> gainRange{ Decibels::decibelsToGain<float>(-180), Decibels::decibelsToGain<float>(0), 0, Decibels::decibelsToGain<float>(-12) };

	ADSR talkOver;
	bool talkOverState{ true };
	int talkOverFadeMs{ 500 };
	NormalisableRange<float> talkOverRange{ Decibels::decibelsToGain<float>(-30), 1.0f};

    MixerAudioSource mixer;
    std::vector<std::unique_ptr<Player>> players;
};
