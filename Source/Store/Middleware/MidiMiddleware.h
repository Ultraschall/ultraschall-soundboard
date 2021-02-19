#pragma once

#include "JuceHeader.h"
#include "../Middleware.h"

class MidiMiddleware : public Middleware, private AsyncUpdater {
public:
    MidiMiddleware() {}
	ActionObject dispatch(const ActionObject &action, Store &store) override;
	void handleMidiMessages(MidiBuffer &midiMessages);
    
private:
	void handleAsyncUpdate() override;
    
    MidiBuffer inputBuffer;
};
