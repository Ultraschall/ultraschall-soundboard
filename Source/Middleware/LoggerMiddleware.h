#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Middleware.h"

class LoggerMiddleware : public Middleware {
public:
	ActionObject dispatch(const ActionObject &action, Store store) override {
		Logger::outputDebugString("[ACTION] " + action.type.toString() + " args: " + action.args.toXmlString());
		Logger::outputDebugString("[PRE] <-- " + store.getState().toXmlString());
		auto n = next.lock();
		auto result = n ? n->dispatch(action, store) : action;
		Logger::outputDebugString("[POST] --> " + store.getState().toXmlString());
		return result;
	}
};
