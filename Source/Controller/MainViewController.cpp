/*
  ==============================================================================

    MainViewController.cpp
    Created: 27 Apr 2018 4:35:25pm
    Author:  danlin

  ==============================================================================
*/

#include "MainViewController.h"
#include "../Views/MainView.h"

MainViewController::MainViewController(Library &core) : ViewController(core) {}

void MainViewController::viewDidLoad() {
    auto myView = dynamic_cast<MainView*>(view.get());
    if (myView == nullptr) return;

    myView->toolbar.addDefaultItems(mainToolbarItemFactory);
}

void MainViewController::loadView() {
    view = std::make_unique<MainView>();
}

void MainViewController::loadFile() {
    FileChooser myChooser ("Please select the audio file you want to load...",
                           File::getSpecialLocation (File::userHomeDirectory),
                           engine.audioFormatManager.getWildcardForAllFormats());

    if (myChooser.browseForFileToOpen())
    {
        File audioFile (myChooser.getResult());
        engine.loadAudioFile(audioFile);
    }
}

void MainViewController::MainToolbarItemFactory::getAllToolbarItemIds(Array<int> &ids) {
    ids.add(MainToolbarItemIds::showGrid);
    ids.add(MainToolbarItemIds::showLibrary);
	ids.add(flexibleSpacerId);
	ids.add(MainToolbarItemIds::gain);
	ids.add(MainToolbarItemIds::talkover);
	ids.add(flexibleSpacerId);
	ids.add(MainToolbarItemIds::settings);
	ids.add(MainToolbarItemIds::addFile);
}

void MainViewController::MainToolbarItemFactory::getDefaultItemSet(Array<int> &ids) {
    ids.add(MainToolbarItemIds::showGrid);
    ids.add(MainToolbarItemIds::showLibrary);
	ids.add(flexibleSpacerId);
	ids.add(MainToolbarItemIds::gain);
	ids.add(MainToolbarItemIds::talkover);
	ids.add(flexibleSpacerId);
	ids.add(MainToolbarItemIds::addFile);
	ids.add(MainToolbarItemIds::settings);
}

ToolbarItemComponent *MainViewController::MainToolbarItemFactory::createItem(int itemId) {
    switch(itemId) {
        case MainToolbarItemIds::showGrid: {
            auto button = new ToolbarButton(itemId, "Banks",
                                            Drawable::createFromImageData(
                                                    BinaryData::ic_view_module_white_48px_svg,
                                                    BinaryData::ic_view_module_white_48px_svgSize),
                                            nullptr);
            button->onClick = [&] {

            };
			return button;
        }
        case MainToolbarItemIds::showLibrary: {
            auto button = new ToolbarButton(itemId, "Library",
                                            Drawable::createFromImageData(
                                                    BinaryData::ic_view_headline_white_48px_svg,
                                                    BinaryData::ic_view_headline_white_48px_svgSize),
                                            nullptr);
            button->onClick = [&] {

            };
			return button;
        }
		case MainToolbarItemIds::talkover: {
			auto button = new ToolbarButton(itemId, "Talkover",
				Drawable::createFromImageData(
					BinaryData::ic_mic_none_white_48px_svg,
					BinaryData::ic_mic_none_white_48px_svgSize),
				Drawable::createFromImageData(
					BinaryData::ic_mic_white_48px_svg,
					BinaryData::ic_mic_white_48px_svgSize));
			button->onClick = [button] {
				button->setToggleState(!button->getToggleState(), NotificationType::dontSendNotification);
			};
			return button;
		}
		case MainToolbarItemIds::addFile: {
			auto button = new ToolbarButton(itemId, "Add Item",
				Drawable::createFromImageData(
					BinaryData::ic_folder_open_white_48px_svg,
					BinaryData::ic_folder_open_white_48px_svgSize),
				nullptr);
			button->onClick = [&] {
			};
			return button;
		}
		case MainToolbarItemIds::gain: {
			auto gain = new MainView::GainToolbarView(itemId);
			return gain;
		}
		case MainToolbarItemIds::settings: {
			auto button = new ToolbarButton(itemId, "Settings",
				Drawable::createFromImageData(
					BinaryData::ic_settings_white_48px_svg,
					BinaryData::ic_settings_white_48px_svgSize),
				nullptr);
			button->onClick = [&] {

			};
			return button;
		}

    }
    return nullptr;
}
