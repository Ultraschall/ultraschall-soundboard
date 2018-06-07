#include "MainViewController.h"

MainViewController::MainViewController(Engine &engine) : ViewController(engine)
{

}

void MainViewController::loadView() {
    view = std::make_unique<MainView>();
}

void MainViewController::viewDidLoad() {
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
		engine.debugState();
	};

    view->addFileButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
        addFile();
    };

    view->addDirectoryButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
        addDirectory();
    };

    view->loadProjectFileButton.onClick = [this] {
        view->hideExtendedFloatingActionButtons();
        loadProjectFile();
    };
}

void MainViewController::showLibrary() {
    const auto current = dynamic_cast<LibraryViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<LibraryViewController>(engine);
        contentController->init();
        view->setContentView(contentController->getView());
    }
}

void MainViewController::addDirectory() {
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
                        showLibrary();
                    }
                }
            });
}

void MainViewController::addFile() {
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
                        showLibrary();
                    }
                }
            });
}

void MainViewController::loadProjectFile() {
    const auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

    fileChooser = std::make_unique<FileChooser>("Please select the Soundboard Project file you want to load...",
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
                    }
                }
            });
}
