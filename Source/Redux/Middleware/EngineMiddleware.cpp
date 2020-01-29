#include "EngineMiddleware.h"
#include "../Actions/Actions.h"

EngineMiddleware::EngineMiddleware(Engine & engine) : engine(engine) {
    const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();
    
    fileChooser = std::make_unique<FileChooser>("Please select the audio file or directory you want to load...",
                                                File::getSpecialLocation(File::userMusicDirectory),
                                                engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);
}

ActionObject EngineMiddleware::dispatch(const ActionObject &action, Store &store) {
	if (action.type == AddFileOrDirectory) {
		AsyncAddFileOrDirectory(store);
		return action;
	}
	
	if (action.type == EnableEngineSync) {
		jassert(engineSync == nullptr);
		engineSync = std::make_unique<EngineSync>(store, engine);
		engineSync->startTimerHz(60);
	}
	else if (action.type == DisableEngineSync) {
		engineSync->stopTimer();
		engineSync = nullptr;
	}

	playerDispatch(action);

	auto n = next.lock();
	auto result = n ? n->dispatch(action, store) : action;
	return result;
}

void EngineMiddleware::playerDispatch(const ActionObject & action)
{
	auto uuid = action.args.getProperty(IDs::player_id);
	if (action.type == PlayerPlay) {
		engine.playerPlay(Identifier(uuid));
	}
	else if (action.type == PlayerStop) {
		engine.playerStop(Identifier(uuid));
	}
	else if (action.type == PlayerPause) {
		engine.playerPause(Identifier(uuid));
	}
	else if (action.type == PlayerFadeIn) {
		engine.playerFadeIn(Identifier(uuid));
	}
	else if (action.type == PlayerFadeOut) {
		engine.playerFadeOut(Identifier(uuid));
	}
	else if (action.type == PlayerToggleLooping) {
		engine.playerToggleLooping(Identifier(uuid));
	}
}

void EngineMiddleware::AsyncAddFileOrDirectory(Store & store)
{
    fileChooser->launchAsync(FileBrowserComponent::openMode
                             | FileBrowserComponent::canSelectFiles
                             | FileBrowserComponent::canSelectDirectories
                             | FileBrowserComponent::canSelectMultipleItems,
		[&](const FileChooser &chooser) {
			auto results = chooser.getURLResults();
            fileLoader = std::make_unique<EngineMiddleware::AsyncFileLoader>(store, engine, results);
            fileLoader->triggerAsyncUpdate();
		});
}

void EngineMiddleware::EngineSync::timerCallback()
{
	engine.sync(store);
}

void EngineMiddleware::AsyncFileLoader::handleAsyncUpdate() {
    for (const auto &result : files)
    {
        if (result.isLocalFile())
        {
            store.dispatch(ShowViewAction("library"));
            
            auto file = result.getLocalFile();
            if (file.isDirectory()) {
                auto child_files = file.findChildFiles(File::findFiles, true);
                for (auto &child_file : child_files) {
                    Uuid uuid;
                    auto id = Identifier(uuid.toDashedString());
                    
                    if (engine.loadAudioFile(id, child_file)) {
                        store.dispatch(FileReadyAction(uuid.toDashedString(), child_file.getFileName(), child_file.getFullPathName()));
                    }
                }
            } else {
                Uuid uuid;
                auto id = Identifier(uuid.toDashedString());
                
                if (engine.loadAudioFile(id, file)) {
                    store.dispatch(FileReadyAction(uuid.toDashedString(), file.getFileName(), file.getFullPathName()));
                }
            }
        }
    }
}
