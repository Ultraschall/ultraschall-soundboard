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
}

void MainViewController::MainToolbarItemFactory::getDefaultItemSet(Array<int> &ids) {
    ids.add(MainToolbarItemIds::showGrid);
    ids.add(MainToolbarItemIds::showLibrary);
}

ToolbarItemComponent *MainViewController::MainToolbarItemFactory::createItem(int itemId) {
    switch(itemId) {
        case MainToolbarItemIds::showGrid: {
            auto button = new ToolbarButton(itemId, "Show Banks",
                                            Drawable::createFromImageData(
                                                    BinaryData::ic_pause_circle_outline_black_48px_svg,
                                                    BinaryData::ic_pause_circle_outline_black_48px_svgSize),
                                            nullptr);
            button->onClick = [&] {

            };
            break;
        }
        case MainToolbarItemIds::showLibrary: {
            auto button = new ToolbarButton(itemId, "Show Library",
                                            Drawable::createFromImageData(
                                                    BinaryData::ic_pause_circle_outline_black_48px_svg,
                                                    BinaryData::ic_pause_circle_outline_black_48px_svgSize),
                                            nullptr);
            button->onClick = [&] {

            };
            break;
        }

    }
    return nullptr;
}
