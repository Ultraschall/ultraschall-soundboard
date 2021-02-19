#pragma once

#include <map>

#include "JuceHeader.h"
#include "Player.h"
#include "../Store/Store.h"

class Engine : public AudioSource, public ChangeListener {
public:
	Engine();

	~Engine() override;

	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
	void releaseResources() override;
	void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;
	
	bool loadAudioFile(Identifier id, const File &file);
	void openFile(const File &file);
	void saveFile(const File &file) const;

	void setGain(float value);
	void toggleMuteState();
	void toggleTalkOver();

	void playerLooping(const Identifier &uuid, bool looping);
	void playerToggleLooping(const Identifier &uuid);
	void playerFadeOut(const Identifier &uuid);
	void playerFadeIn(const Identifier &uuid);
	void playerPlay(const Identifier &uuid);
	void playerPause(const Identifier &uuid);
	void playerStop(const Identifier &uuid);

	void changeListenerCallback(ChangeBroadcaster *source) override;
	void sync(Store &store);

	AudioFormatManager audioFormatManager;
	AudioThumbnailCache audioThumbnailCache;
private:
	Player *playerWithIdentifier(const Identifier &id);

	Array<Identifier> playersToUpdate;

	double currentSampleRate{ 0 };
    int currentSamplesPerBlockExpected{ 0 };
	float currentGain{ 1.0f };
	float previousGain{ 1.0f };
	NormalisableRange<float> gainRange{ Decibels::decibelsToGain<float>(-180), Decibels::decibelsToGain<float>(0), 0, Decibels::decibelsToGain<float>(-12) };

	Envelope talkOver;
	bool talkOverState{ true };
	int talkOverFadeMs{ 500 };
	NormalisableRange<float> talkOverRange{ Decibels::decibelsToGain<float>(-30), 1.0f };

	bool muteState{ false };

	MixerAudioSource mixer;
	std::map<Identifier, std::unique_ptr<Player>> players;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Engine)
};
