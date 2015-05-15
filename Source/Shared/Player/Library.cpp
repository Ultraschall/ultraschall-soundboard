/*
  ==============================================================================

    Library.cpp
    Created: 15 May 2015 9:33:15pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "Library.h"

const int maxNumThumbsToStore = 128;

Library::Library() {
    formatManager = new AudioFormatManager();
    formatManager->registerBasicFormats();
    thumbnailCache = new AudioThumbnailCache(maxNumThumbsToStore);
}

Library::~Library() {
    formatManager = nullptr;
}

void Library::validateFiles() {

}

bool Library::addFile(File file) {
    return false;
}

Slot *Library::getSlotAtIndex(int index) {
    return nullptr;
}

int Library::numSlots() {
    return 0;
}

Bank *Library::getBankAtIndex(int index) {
    return nullptr;
}

int Library::numBanks() {
    return 0;
}
