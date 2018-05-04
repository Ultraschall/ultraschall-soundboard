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

class Library : public AudioSource {
public:
	Library();

	~Library() {
	    mixer.removeAllInputs();
	    players.clear(true);
	}

	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

	void releaseResources() override;

	void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;

	void loadAudioFile(File file);

	Player* playerWithIdentifier(Identifier id);
	Player* playerAtIndex(int index) {
		return players[index];
	}

	void DebugState();

	AudioFormatManager audioFormatManager;
	AudioThumbnailCache audioThumbnailCache;
	UndoManager undoManager;
private:
	MixerAudioSource mixer;
	OwnedArray<Player> players;
	juce::ValueTree state;
	std::unique_ptr<PlayerList> playersState;
};
