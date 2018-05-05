/*
  ==============================================================================

    LibraryViewController.cpp
    Created: 4 May 2018 11:04:34am
    Author:  danlin

  ==============================================================================
*/

#include "JuceHeader.h"
#include "LibraryViewController.h"

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