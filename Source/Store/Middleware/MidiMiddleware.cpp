#include "MidiMiddleware.h"

ActionObject MidiMiddleware::dispatch(const ActionObject & action, Store & store) {
	auto n = next.lock();
	auto result = n ? n->dispatch(action, store) : action;
	return result;
}

void MidiMiddleware::handleMidiMessages(MidiBuffer & midiMessages) {
    
    for (const auto metadata : midiMessages)
    {
        const auto msg = metadata.getMessage();
        inputBuffer.addEvent(msg, metadata.samplePosition);
    }
     
    midiMessages.clear();
	triggerAsyncUpdate();
}

void MidiMiddleware::handleAsyncUpdate() {
    for (const auto metadata : inputBuffer)
    {
        const auto msg = metadata.getMessage();
        Logger::outputDebugString("[MIDI] Message: " + msg.getDescription());
    }
}
