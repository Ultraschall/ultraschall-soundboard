#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Engine.h"

class MidiEngine : private AsyncUpdater {
public:
	MidiEngine(Engine &engine);
	void handleMidiMessages(MidiBuffer &midiMessages);
private:
	void handleAsyncUpdate() override;

	MidiBuffer inputBuffer;
	Engine &engine;
};