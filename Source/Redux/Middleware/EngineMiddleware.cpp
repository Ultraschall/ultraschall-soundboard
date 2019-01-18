#include "EngineMiddleware.h"
#include "../Actions/Actions.h"

EngineMiddleware::EngineMiddleware(Engine & engine) : engine(engine) {

}

ActionObject EngineMiddleware::dispatch(const ActionObject &action, Store &store) {
	if (action.type == AddDirectory) {
		AsyncAddDirectory(store);
		return action;
	}
	else if (action.type == AddFile) {
		AsyncAddFile(store);
		return action;
	}
	else if (action.type == EnableEngineSync) {
		jassert(engineSync == nullptr);
		engineSync = std::make_unique<EngineSync>(store, engine);
		engineSync->startTimer(100);
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

void EngineMiddleware::AsyncAddDirectory(Store &store)
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	Logger::outputDebugString(engine.audioFormatManager.getWildcardForAllFormats());

	fileChooser = std::make_unique<FileChooser>("Please select the directory you want to import...",
		File::getSpecialLocation(File::userHomeDirectory),
		engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories,
		[&](const FileChooser &chooser) {
			auto results = chooser.getURLResults();
			for (const auto &result : results)
			{
				if (result.isLocalFile())
				{
					auto files = result.getLocalFile().findChildFiles(File::findFiles, true);
					for (auto &f : files) {
						Uuid uuid;
						auto id = Identifier(uuid.toDashedString());
						if (engine.loadAudioFile(id, f)) {
							store.dispatch(FileReadyAction(uuid.toDashedString(), f.getFileName(), f.getFullPathName()));
						}
					}
				}
			}
			store.dispatch(ShowViewAction("library"));
		});
}

void EngineMiddleware::AsyncAddFile(Store & store)
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	fileChooser = std::make_unique<FileChooser>("Please select the audio file you want to load...",
		File::getSpecialLocation(File::userHomeDirectory),
		engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::canSelectMultipleItems | FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
		[&](const FileChooser &chooser) {
			auto results = chooser.getURLResults();
			for (const auto &result : results)
			{
				if (result.isLocalFile())
				{
					auto file = result.getLocalFile();
					Uuid uuid;
					auto id = Identifier(uuid.toDashedString());
					if (engine.loadAudioFile(id, file)) {
						store.dispatch(FileReadyAction(uuid.toDashedString(), file.getFileName(), file.getFullPathName()));
					}

				}
			}
			store.dispatch(ShowViewAction("library"));
		});
}

void EngineMiddleware::EngineSync::timerCallback()
{
	engine.sync(store);
}
