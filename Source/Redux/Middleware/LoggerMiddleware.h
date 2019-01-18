#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Middleware.h"

class LoggerMiddleware : public Middleware {
public:
	ActionObject dispatch(const ActionObject &action, Store &store) override {
        Logger::outputDebugString("[DISPATCH]");
        Logger::outputDebugString("[PRE ACTION DUMP]");
        Logger::outputDebugString(store.getState().toXmlString());
        Logger::outputDebugString("[ACTION] " + action.type.toString());
        Logger::outputDebugString("[ARGUMENTS]");
        Logger::outputDebugString(action.args.toXmlString());
		auto n = next.lock();
		auto result = n ? n->dispatch(action, store) : action;
        Logger::outputDebugString("[POST ACTION DUMP]");
        Logger::outputDebugString(store.getState().toXmlString());
        Logger::outputDebugString("[DONE]");
		return result;
	}
};
