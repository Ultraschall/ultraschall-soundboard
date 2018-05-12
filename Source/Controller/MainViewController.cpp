#include "MainViewController.h"
#include "../Views/MainView.h"

void MainViewController::viewDidLoad()
{
    view->toolbar.menuButton.onClick = [this]
    {
        view->showSideNavBar();
    };
    view->toolbar.viewButton.onClick = [this]
    {
        if (view->toolbar.viewButton.getToggleState() == true)
        {
            showLibrary();
        } else
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
}

void MainViewController::showLibrary()
{
    auto current = dynamic_cast<LibraryViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<LibraryViewController>(engine);
        contentController->init();
        view->setContentView(contentController->getView());
        view->toolbar.viewButton.setToggleState(false, NotificationType::dontSendNotification);
        view->showActionButton();
    }
}

void MainViewController::showBanks()
{
    auto current = dynamic_cast<BankViewController *>(contentController.get());
    if (current == nullptr)
    {
        contentController = std::make_unique<BankViewController>(engine);
        contentController->init();
        view->setContentView(contentController->getView());
        view->toolbar.viewButton.setToggleState(true, NotificationType::dontSendNotification);
        view->hideActionButton();
    }
}


void MainViewController::loadView()
{
    view = std::make_unique<MainView>();
}

void MainViewController::loadFile()
{
    auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

    fileChooser.reset(new FileChooser("Please select the audio file you want to load...",
                                      File::getSpecialLocation(File::userHomeDirectory),
                                      engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion));

    fileChooser->launchAsync(FileBrowserComponent::canSelectMultipleItems | FileBrowserComponent::openMode |
                             FileBrowserComponent::canSelectFiles,
                             [this](const FileChooser &chooser)
                             {
                                 auto results = chooser.getURLResults();
                                 for (auto result : results)
                                 {
                                     if (result.isLocalFile())
                                     {
                                         engine.loadAudioFile(result.getLocalFile());
                                     }
                                 }
                             });
}

void MainViewController::importDirectory()
{

    auto useNativeVersion = FileChooser::isPlatformDialogAvailable();

    Logger::getCurrentLogger()->outputDebugString(engine.audioFormatManager.getWildcardForAllFormats());

    fileChooser.reset(new FileChooser("Please select the directory you want to import...",
                                      File::getSpecialLocation(File::userHomeDirectory),
                                      engine.audioFormatManager.getWildcardForAllFormats(), useNativeVersion));

    fileChooser->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories,
                             [this](const FileChooser &chooser)
                             {
                                 auto results = chooser.getURLResults();
                                 for (auto result : results)
                                 {
                                     if (result.isLocalFile())
                                     {
                                         engine.importDirectory(result.getLocalFile());
                                     }
                                 }
                             });
}

