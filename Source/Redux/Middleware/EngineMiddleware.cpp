#include "EngineMiddleware.h"
#include "../Actions/ApplicationActions.h"
#include "../Actions/LibraryActions.h"

EngineMiddleware::EngineMiddleware(Engine & engine) : engine(engine) {
	
}

ActionObject EngineMiddleware::dispatch(const ActionObject &action, Store &store) {
	if (action.type == AddDirectory) {
		AsyncAddDirectory(store);
		return action;
	}
	else if (action.type == EnableEngineSync) {
		EnableSync(store, engine);
	}
	else if (action.type == DisableEngineSync) {
		DisableSync(store);
	}

	if (engine.dispatch(action, store)) { return action; }

	auto n = next.lock();
	auto result = n ? n->dispatch(action, store) : action;
	return result;
}

void EngineMiddleware::EnableSync(Store &store, Engine &engine)
{
	jassert(engineSync == nullptr);
	engineSync = std::make_unique<EngineSync>(store, engine);
	engineSync->startTimer(17);
}

void EngineMiddleware::DisableSync(Store &store)
{
	engineSync->stopTimer();
	engineSync = nullptr;
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
											 store.dispatch(FileReadyAction(uuid.toDashedString(), f.getFileName(), f.getFullPathName()));

											 //	model.uuid = uuid.toDashedString();
//	model.path = file.getFullPathName();
//	model.title = file.getFileName();
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
