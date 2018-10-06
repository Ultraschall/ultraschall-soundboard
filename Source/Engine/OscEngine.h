#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Engine.h"

class OSCEngine : private OSCReceiver, private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
	OSCEngine(Engine &engine);
private:
	void oscMessageReceived(const OSCMessage& message) override;
	void showConnectionErrorMessage(const String& messageText);

	Engine &engine;
};