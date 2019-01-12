#include "MainViewController.h"
#include "../../Redux/Actions/Actions.h"

MainViewController::MainViewController(std::shared_ptr<Store> store) : ViewController(store), model(store->getState().getChildWithName(IDs::APPLICATION))
{
}

void MainViewController::loadView()
{
    view = std::make_unique<MainView>();
}

void MainViewController::viewDidLoad()
{
    view->setShowKeyboardFocus(false);
    view->navigationDrawer.viewList.onClick = [this] {
        view->navigationDrawer.viewList.setToggleState(true, dontSendNotification);
        view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
        view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);

        view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.settings.setToggleState(false, dontSendNotification);
    };
    view->navigationDrawer.viewGrid.onClick = [this] {
        view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
        view->navigationDrawer.viewGrid.setToggleState(true, dontSendNotification);
        view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);

        view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.settings.setToggleState(false, dontSendNotification);
    };
    view->navigationDrawer.viewPlaylist.onClick = [this] {
        view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
        view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
        view->navigationDrawer.viewPlaylist.setToggleState(true, dontSendNotification);

        view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.settings.setToggleState(false, dontSendNotification);
    };

    view->navigationDrawer.settings.onClick = [this] {
    };

    view->addFileButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
		store->dispatch(AddFileAction());
    };

    view->addDirectoryButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
		store->dispatch(AddDirectoryAction());
    };

    view->loadProjectFileButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
		store->dispatch(OpenProjectAction());
    };

    view->bottomBar.volumeSlider.onValueChange = [this] {
		store->dispatch(SetGainAction(static_cast<float>(view->bottomBar.volumeSlider.getValue())));
    };

    view->bottomBar.talkoverButton.onClick = [this] {
		store->dispatch(ToggleTalkOverAction());
    };

    view->bottomBar.muteButton.onClick = [this] {
		store->dispatch(ToggleMuteAction());
	};

	view->bottomBar.volumeSlider.setValue(model.master_gain, dontSendNotification);
	view->bottomBar.talkoverButton.setToggleState(model.talkover, dontSendNotification);
	view->bottomBar.muteButton.setToggleState(model.mute, dontSendNotification);

	model.state.addListener(this);
}

void MainViewController::viewDidUnload() {
	model.state.removeListener(this);
}

void MainViewController::showLibrary()
{
    const auto current = dynamic_cast<LibraryViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<LibraryViewController>(store);
        contentController->init();
        view->setContentView(contentController->getView());
    }
}

void MainViewController::addDirectory()
{
//    const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();
//
//    Logger::outputDebugString(engine.audioFormatManager.getWildcardForAllFormats());
//
//    fileChooser = std::make_unique<FileChooser>("Please select the directory you want to import...",
//                                                File::getSpecialLocation(File::userHomeDirectory),
//                                                engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);
//
//    fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories,
//                             [this](const FileChooser &chooser) {
//                                 auto results = chooser.getURLResults();
//                                 for (const auto &result : results)
//                                 {
//                                     if (result.isLocalFile())
//                                     {
//                                         engine.importDirectory(result.getLocalFile());
//                                         showLibrary();
//                                     }
//                                 }
//                             });
}

void MainViewController::addFile()
{
//    const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();
//
//    fileChooser = std::make_unique<FileChooser>("Please select the audio file you want to load...",
//                                                File::getSpecialLocation(File::userHomeDirectory),
//                                                engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);
//
//    fileChooser->launchAsync(FileBrowserComponent::canSelectMultipleItems | FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
//                             [this](const FileChooser &chooser) {
//                                 auto results = chooser.getURLResults();
//                                 for (const auto &result : results)
//                                 {
//                                     if (result.isLocalFile())
//                                     {
//                                         engine.loadAudioFile(result.getLocalFile());
//                                         showLibrary();
//                                     }
//                                 }
//                             });
}

void MainViewController::loadProjectFile()
{
//    const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();
//
//    fileChooser = std::make_unique<FileChooser>("Please select the Soundboard Project file you want to load...",
//                                                File::getSpecialLocation(File::userHomeDirectory),
//                                                "*.usdb", useNativeVersion);
//
//    fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
//                             [this](const FileChooser &chooser) {
//                                 auto results = chooser.getURLResults();
//                                 for (const auto &result : results)
//                                 {
//                                     if (result.isLocalFile())
//                                     {
//                                         engine.openFile(result.getLocalFile());
//                                         showLibrary();
//                                     }
//                                 }
//                             });
}

void MainViewController::valueTreePropertyChanged(ValueTree &treeWhosePropertyHasChanged, const Identifier &property) {
	if (treeWhosePropertyHasChanged == model.state) {
		if (property == IDs::application_master_gain ||
			property == IDs::application_talkover ||
			property == IDs::application_mute ||
			property == IDs::application_view) {
			triggerAsyncUpdate();
		}
	}		
}

void MainViewController::handleAsyncUpdate()
{
	view->bottomBar.volumeSlider.setValue(model.master_gain, dontSendNotification);
	view->bottomBar.talkoverButton.setToggleState(model.talkover, dontSendNotification);
	view->bottomBar.muteButton.setToggleState(model.mute, dontSendNotification);
	if (model.view != "main") {
		showLibrary();
	}
}

