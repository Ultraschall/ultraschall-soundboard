/*
  ==============================================================================

	Library.h
	Created: 27 Apr 2018 4:22:31pm
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include <vector>
#include "JuceHeader.h"
#include "Player.h"
#include "../Models/Identifier.h"
#include "../Models/PlayerModel.h"

class Engine : public AudioSource {
public:
	Engine();

	~Engine() {
	    mixer.removeAllInputs();
	    players.clear(true);
		audioFormatManager.clearFormats();
		audioThumbnailCache.clear();
	}

	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

	void releaseResources() override;

	void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

	void loadAudioFile(File file);

	Player* playerWithIdentifier(Identifier id);
	Player* playerAtIndex(int index) {
		return players[index];
	}

	void DebugState() const;

	AudioFormatManager audioFormatManager;
	AudioThumbnailCache audioThumbnailCache;
	UndoManager undoManager;
    juce::ValueTree state;

	private:
	MixerAudioSource mixer;
	OwnedArray<Player> players;
};
