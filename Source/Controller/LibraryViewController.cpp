/*
  ==============================================================================

    LibraryViewController.cpp
    Created: 4 May 2018 11:04:34am
    Author:  danlin

  ==============================================================================
*/

#include "JuceHeader.h"
#include "LibraryViewController.h"
#include "../Views/LibraryView.h"

bool LibraryViewController::isSuitableType(const juce::ValueTree &tree) const {
    return tree.hasType(IDs::PLAYER);;
}

PlayerModel *LibraryViewController::createNewObject(const juce::ValueTree &tree) {
    return new PlayerModel(tree);
}

void LibraryViewController::deleteObject(PlayerModel *type) {
    delete type;
}

void LibraryViewController::newObjectAdded(PlayerModel *type) {

}

void LibraryViewController::objectRemoved(PlayerModel *type) {

}

void LibraryViewController::objectOrderChanged() {

}

void LibraryViewController::loadView() {
    view = std::make_unique<LibraryView>();
}

void LibraryViewController::viewDidLoad() {
    auto tableListBox = getTableListBox();
    if (tableListBox == nullptr) return;
}
