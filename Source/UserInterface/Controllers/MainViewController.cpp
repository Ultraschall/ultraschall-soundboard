#include "MainViewController.h"
#include "../../Store/Actions/Actions.h"

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
        const auto _ = store->dispatch(ShowViewAction("library"));
    };
    view->navigationDrawer.viewGrid.onClick = [this] {
        const auto _ = store->dispatch(ShowViewAction("bank"));
    };
    view->navigationDrawer.viewPlaylist.onClick = [this] {
        const auto _ = store->dispatch(ShowViewAction("playlist"));
    };

	view->navigationDrawer.midiSettings.onClick = [this] {
		view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);

		view->navigationDrawer.midiSettings.setToggleState(true, dontSendNotification);
		view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.settings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.close();
        const auto _ = store->dispatch(ShowViewAction("settings_midi"));
	};
	view->navigationDrawer.oscSettings.onClick = [this] {
		view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);

		view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.oscSettings.setToggleState(true, dontSendNotification);
		view->navigationDrawer.settings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.close();
        const auto _ = store->dispatch(ShowViewAction("settings_osc"));
	};
    view->navigationDrawer.settings.onClick = [this] {
		view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
		view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);

		view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
		view->navigationDrawer.settings.setToggleState(true, dontSendNotification);
		view->navigationDrawer.close();
        const auto _ = store->dispatch(ShowViewAction("settings"));
    };

    view->addFileOrDirectoryButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
        const auto _ = store->dispatch(AddFileOrDirectoryAction());
    };

    view->loadProjectFileButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
        const auto _ = store->dispatch(OpenProjectAction());
    };

    view->bottomBar.volumeSlider.onValueChange = [this] {
        const auto _ = store->dispatch(SetGainAction(static_cast<float>(view->bottomBar.volumeSlider.getValue())));
    };

    view->bottomBar.talkoverButton.onClick = [this] {
        const auto _ = store->dispatch(ToggleTalkOverAction());
    };

    view->bottomBar.muteButton.onClick = [this] {
        const auto _ = store->dispatch(ToggleMuteAction());
	};

	view->bottomBar.volumeSlider.setValue(model.master_gain, dontSendNotification);
	view->bottomBar.talkoverButton.setToggleState(model.talkover, dontSendNotification);
	view->bottomBar.muteButton.setToggleState(model.mute, dontSendNotification);

	model.state.addListener(this);
    triggerAsyncUpdate();
}

void MainViewController::viewDidUnload() {
	model.state.removeListener(this);
}

void MainViewController::showLibrary()
{
    const auto current = dynamic_cast<LibraryViewController *>(contentController.get());
    if (current == nullptr)
    {
        view->navigationDrawer.viewList.setToggleState(true, dontSendNotification);
        view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
        view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);
        
        view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
        view->navigationDrawer.settings.setToggleState(false, dontSendNotification);

        view->floatingActionButton.setVisible(true);

        contentController = std::make_unique<LibraryViewController>(store);
        contentController->init();
        view->setContentView(contentController->getView());
    }
}

void MainViewController::showBank()
{
    view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
    view->navigationDrawer.viewGrid.setToggleState(true, dontSendNotification);
    view->navigationDrawer.viewPlaylist.setToggleState(false, dontSendNotification);
    
    view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
    view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
    view->navigationDrawer.settings.setToggleState(false, dontSendNotification);

    view->floatingActionButton.setVisible(false);

    const auto current = dynamic_cast<BankViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<BankViewController>(store);
        contentController->init();
        view->setContentView(contentController->getView());
    }
}

void MainViewController::showPlaylist()
{
    view->navigationDrawer.viewList.setToggleState(false, dontSendNotification);
    view->navigationDrawer.viewGrid.setToggleState(false, dontSendNotification);
    view->navigationDrawer.viewPlaylist.setToggleState(true, dontSendNotification);
    
    view->navigationDrawer.midiSettings.setToggleState(false, dontSendNotification);
    view->navigationDrawer.oscSettings.setToggleState(false, dontSendNotification);
    view->navigationDrawer.settings.setToggleState(false, dontSendNotification);

    view->floatingActionButton.setVisible(false);

    const auto current = dynamic_cast<PlaylistViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<PlaylistViewController>(store);
        contentController->init();
        view->setContentView(contentController->getView());
    }
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
    if (model.view == "library") {
        showLibrary();
    } else if (model.view == "bank") {
        showBank();
    } else if (model.view == "playlist") {
        showPlaylist();
    }
}

