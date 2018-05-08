/*
  ==============================================================================

    MainViewController.cpp
    Created: 27 Apr 2018 4:35:25pm
    Author:  danlin

  ==============================================================================
*/

#include "MainViewController.h"
#include "../Views/MainView.h"

void MainViewController::viewDidLoad() {
    view->toolbar.menuButton.onClick = [this] {
        view->showSideNavBar();
    };
    view->toolbar.viewButton.onClick = [this] {
        if(view->toolbar.viewButton.getToggleState() == true) {
            showLibrary();
        } else {
            showBanks();
        }
    };
    view->sideNavbarBackground.onClick = [this] {
        view->hideSideNavBar();
    };
	view->addButton.onClick = [this] {
		showLibrary();
		loadFile();
	};
}

void MainViewController::showLibrary() {
        auto current = dynamic_cast<LibraryViewController *>(contentController.get());
        if (current == nullptr) {
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
	if (current == nullptr) {
		contentController = std::make_unique<BankViewController>(engine);
		contentController->init();
		view->setContentView(contentController->getView());
		view->toolbar.viewButton.setToggleState(true, NotificationType::dontSendNotification);
		view->hideActionButton();
	}
}


void MainViewController::loadView() {
    view = std::make_unique<MainView>();
}

void MainViewController::loadFile() {
    FileChooser myChooser("Please select the audio file you want to load...",
                          File::getSpecialLocation(File::userHomeDirectory),
                          engine.audioFormatManager.getWildcardForAllFormats());

    if (myChooser.browseForFileToOpen()) {
        File audioFile(myChooser.getResult());
        engine.loadAudioFile(audioFile);
    }
}

