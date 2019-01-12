#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Middleware.h"
#include "../../Engine/Engine.h"

class EngineMiddleware : public Middleware {
public:
	EngineMiddleware(Engine &engine);

	ActionObject dispatch(const ActionObject &action, Store &store) override;
private:
	Engine &engine;
	std::unique_ptr<FileChooser> fileChooser;

	void EnableSync(Store &store, Engine &engine);
	void DisableSync(Store &store);
	void AsyncAddDirectory(Store &store);

	class EngineSync : public Timer {
	public:
		EngineSync(Store &store, Engine &engine) : store(store), engine(engine) {}
		void timerCallback() override;
	private:
		Store &store;
		Engine &engine;
	};
	std::unique_ptr<EngineSync> engineSync;
};