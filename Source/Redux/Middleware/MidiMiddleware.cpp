#include "MidiMiddleware.h"

ActionObject MidiMiddleware::dispatch(const ActionObject & action, Store & store) {
	auto n = next.lock();
	auto result = n ? n->dispatch(action, store) : action;
	return result;
}

void MidiMiddleware::handleMidiMessages(MidiBuffer & midiMessages) {
	MidiBuffer processedMidi;
	int time;
	MidiMessage m;

	for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(m, time);) {
		inputBuffer.addEvent(m, time);
		processedMidi.addEvent(m, time);
	}

	midiMessages.swapWith(processedMidi);
	triggerAsyncUpdate();
}

void MidiMiddleware::handleAsyncUpdate() {
	int time;
	MidiMessage m;
	for (MidiBuffer::Iterator i(inputBuffer); i.getNextEvent(m, time);) {

	}
}
