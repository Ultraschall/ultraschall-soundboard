#pragma once

#include "JuceHeader.h"
#include "Player.h"

class Engine : public AudioSource
{
public:
    Engine();

    ~Engine() override
    {
        mixer.removeAllInputs();
        players.clear(true);
        audioFormatManager.clearFormats();
        audioThumbnailCache.clear();
    }

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

    void loadAudioFile(const File& file);

    void importDirectory(const File& directory);

    void newBank();

	void newPlaylist();

    Player *playerWithIdentifier(Identifier id);

    Player *playerAtIndex(int index) const
    {
        return players[index];
    }

    void DebugState() const;

    AudioFormatManager audioFormatManager;
    AudioThumbnailCache audioThumbnailCache;
    UndoManager undoManager;
    ValueTree state;

	void setGain(float value)
	{
		currentGain = gainRange.convertFrom0to1(value);
	}

	float getGain() const
	{
		return gainRange.convertTo0to1(currentGain);
	}

	void toggleTalkOver()
	{
		talkOver.setAttackRate((currentSampleRate / 1000) * talkOverFadeMs);
		talkOver.setReleaseRate((currentSampleRate / 1000) * talkOverFadeMs);
		talkOverState = !talkOverState;
		talkOver.gate(talkOverState);
	}

	void openFile(const File& file)
	{
		XmlDocument xmlDocument(file);
		const std::unique_ptr<XmlElement> xml(xmlDocument.getDocumentElement());
		undoManager.clearUndoHistory();
		mixer.removeAllInputs();
		players.clear(true);
		audioThumbnailCache.clear();
		state = ValueTree::fromXml(*xml);
	}

	void saveFile(const File& file) const
	{
		const std::unique_ptr<XmlElement> xml(state.createXml());
		xml->writeToFile(file, String{});
	}

private:
	double currentSampleRate{0};
	float currentGain{ 1.0f };
	float previousGain{ 1.0f };
	NormalisableRange<float> gainRange{ Decibels::decibelsToGain<float>(-180), Decibels::decibelsToGain<float>(0), 0, Decibels::decibelsToGain<float>(-12) };

	ADSR talkOver;
	bool talkOverState{ true };
	int talkOverFadeMs{ 250 };
	NormalisableRange<float> talkOverRange{ Decibels::decibelsToGain<float>(-30), 1.0f};

    MixerAudioSource mixer;
    OwnedArray<Player> players;
};
