#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Middleware.h"
#include "../../Engine/Engine.h"

class EngineMiddleware : public Middleware {
public:
	explicit EngineMiddleware(Engine &engine);

	ActionObject dispatch(const ActionObject &action, Store &store) override;
	void playerDispatch(const ActionObject & action);
private:
	Engine &engine;
	std::unique_ptr<FileChooser> fileChooser {nullptr};

	void AsyncAddFileOrDirectory(Store &store);

	class EngineSync : public Timer {
	public:
		EngineSync(Store &store, Engine &engine) : store(store), engine(engine) {}
		void timerCallback() override;
	private:
		Store &store;
		Engine &engine;
	};
    class AsyncFileLoader: public AsyncUpdater {
    public:
        AsyncFileLoader(Store &store, Engine &engine, Array<URL> &files) : store(store), engine(engine), files(files) {}
        void handleAsyncUpdate() override;
    private:
        void loadFile(const File &file);
        Store &store;
        Engine &engine;
        Array<URL> files;
    };
    
	std::unique_ptr<EngineSync> engineSync {nullptr};
    std::unique_ptr<AsyncFileLoader> fileLoader {};
};
