#pragma once

#include "JuceHeader.h"
#include "../Middleware.h"

class OscMiddleware : public Middleware, private OSCReceiver, private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback> {
public:
	OscMiddleware();
	ActionObject dispatch(const ActionObject &action, Store &store) override;
private:
	void oscMessageReceived(const OSCMessage &message) override;
};
