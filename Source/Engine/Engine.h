#pragma once

#include <map>

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Player.h"
#include "../Redux/Store.h"

class Engine : public AudioSource, public ChangeListener {
public:
	Engine();

	~Engine() override;

	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
	void releaseResources() override;
	void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

	void loadAudioFile(const File &file);
	void importDirectory(const File &directory);
	void openFile(const File &file);
	void saveFile(const File &file) const;

	void setGain(float value);
	void toggleMuteState();
	void toggleTalkOver();

	void playerLooping(const Identifier &uuid, bool looping);
	void playerFadeOut(const Identifier &uuid);
	void playerFadeIn(const Identifier &uuid);
	void playerPlay(const Identifier &uuid);
	void playerPause(const Identifier &uuid);
	void playerStop(const Identifier &uuid);

	void changeListenerCallback(ChangeBroadcaster *source) override;
	bool dispatch(const ActionObject &action, Store &store);
	void sync(Store &store);

	AudioFormatManager audioFormatManager;
	AudioThumbnailCache audioThumbnailCache;
private:
	Player *playerWithIdentifier(const Identifier &id);

	Array<Identifier> playersToUpdate;

	double currentSampleRate{ 0 };
	float currentGain{ 1.0f };
	float previousGain{ 1.0f };
	NormalisableRange<float> gainRange{ Decibels::decibelsToGain<float>(-180), Decibels::decibelsToGain<float>(0), 0, Decibels::decibelsToGain<float>(-12) };

	ADSR talkOver;
	bool talkOverState{ true };
	int talkOverFadeMs{ 500 };
	NormalisableRange<float> talkOverRange{ Decibels::decibelsToGain<float>(-30), 1.0f };

	bool muteState{ false };

	MixerAudioSource mixer;
	std::map<Identifier, std::unique_ptr<Player>> players;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Engine)
};
