#include "MainViewController.h"
#include "../Views/MainView.h"

void MainViewController::viewDidLoad()
{
	view->bottomBar.gainSlider.setValue(engine.getGain(), dontSendNotification);

	view->toolbar.menuButton.onClick = [this]
	{
		view->showSideNavBar();
	};

	view->toolbar.viewButton.onClick = [this]
	{
		if (view->toolbar.viewButton.getToggleState())
		{
			showLibrary();
		}
		else
		{
			showBanks();
		}
	};

	view->sideNavbarBackground.onClick = [this]
	{
		view->hideSideNavBar();
	};
	view->addButton.onClick = [this]
	{
		loadFile();
		showLibrary();
	};
	view->sideNavbar.importFolderButton.onClick = [this]
	{
		importDirectory();
		showLibrary();
		view->hideSideNavBar();
	};

	view->bottomBar.talkoverButton.onClick = [this]
	{
		engine.toggleTalkOver();
		view->bottomBar.talkoverButton.setToggleState(!view->bottomBar.talkoverButton.getToggleState(), dontSendNotification);
	};

	view->bottomBar.gainSlider.onValueChange = [this]
	{
		engine.setGain(static_cast<float>(view->bottomBar.gainSlider.getValue()));
	};

	view->sideNavbar.settingsButton.onClick = [this]
	{
		engine.DebugState();
	};

	view->sideNavbar.saveFolderButton.onClick = [this]
	{
		exportFile();
	};

	view->sideNavbar.openFolderButton.onClick = [this]
	{
		importFile();
	};
}

void MainViewController::showLibrary()
{
	const auto current = dynamic_cast<LibraryViewController *>(contentController.get());
	if (current == nullptr)
	{
		contentController = std::make_unique<LibraryViewController>(engine);
		contentController->init();
		view->setContentView(contentController->getView());
		view->toolbar.viewButton.setToggleState(false, dontSendNotification);
		view->showActionButton();
		view->bottomBar.hideNavigation();
	}
}

void MainViewController::showBanks()
{
	const auto current = dynamic_cast<BankViewController *>(contentController.get());
	if (current == nullptr)
	{
		contentController = std::make_unique<BankViewController>(engine);
		contentController->init();
		view->setContentView(contentController->getView());
		view->toolbar.viewButton.setToggleState(true, dontSendNotification);
		view->hideActionButton();
		view->bottomBar.showNavigation();
	}
}


void MainViewController::loadView()
{
	view = std::make_unique<MainView>();
}

void MainViewController::loadFile()
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	fileChooser = std::make_unique<FileChooser>("Please select the audio file you want to load...",
		File::getSpecialLocation(File::userHomeDirectory),
		engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::canSelectMultipleItems | FileBrowserComponent::openMode |
		FileBrowserComponent::canSelectFiles,
		[this](const FileChooser &chooser)
	{
		auto results = chooser.getURLResults();
		for (const auto& result : results)
		{
			if (result.isLocalFile())
			{
				engine.loadAudioFile(result.getLocalFile());
			}
		}
	});
}

void MainViewController::importFile()
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	fileChooser = std::make_unique<FileChooser>("Please select the soundboard file you want to load...",
		File::getSpecialLocation(File::userHomeDirectory),
		"*.usdb", useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
		[this](const FileChooser &chooser)
	{
		auto results = chooser.getURLResults();
		for (const auto& result : results)
		{
			if (result.isLocalFile())
			{
				engine.openFile(result.getLocalFile());
				showLibrary();
				view->hideSideNavBar();
			}
		}
	});
}

void MainViewController::exportFile()
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	fileChooser = std::make_unique<FileChooser>("Please select the soundboard file you want to save...",
		File::getSpecialLocation(File::userHomeDirectory),
		"*.usdb", useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles,
		[this](const FileChooser &chooser)
	{
		auto results = chooser.getURLResults();
		for (const auto& result : results)
		{
			if (result.isLocalFile())
			{
				engine.saveFile(result.getLocalFile());
				view->hideSideNavBar();
			}
		}
	});
}

void MainViewController::importDirectory()
{
	const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

	Logger::outputDebugString(engine.audioFormatManager.getWildcardForAllFormats());

	fileChooser = std::make_unique<FileChooser>("Please select the directory you want to import...",
		File::getSpecialLocation(File::userHomeDirectory),
		engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion);

	fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories,
		[this](const FileChooser &chooser)
	{
		auto results = chooser.getURLResults();
		for (const auto& result : results)
		{
			if (result.isLocalFile())
			{
				engine.importDirectory(result.getLocalFile());
			}
		}
	});
}

