#include "MidiEngine.h"

MidiEngine::MidiEngine(Engine & engine) : engine(engine) {
}

void MidiEngine::handleMidiMessages(MidiBuffer & midiMessages) {
	MidiBuffer processedMidi;
	int time;
	MidiMessage m;

	for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(m, time);)
	{
		inputBuffer.addEvent(m, time);
		processedMidi.addEvent(m, time);
	}

	midiMessages.swapWith(processedMidi);
	triggerAsyncUpdate();
}

void MidiEngine::handleAsyncUpdate()
{
	int time;
	MidiMessage m;
	for (MidiBuffer::Iterator i(inputBuffer); i.getNextEvent(m, time);)
	{

	}
}
