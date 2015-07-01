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
    return slots[index];
}

int Library::numSlots() {
    return slots.size();
}

Bank *Library::getBankAtIndex(int index) {
    return banks[index];
}

int Library::numBanks() {
    return banks.size();
}

Slot *Library::getSlotWithFile(File file) {
    return nullptr;
}

void Library::moveSlot(int from, int to) {
    slots.move(from, to);
}

void Library::addSlotToBank(Slot* slot, int bankIndex, int slotIndex) {
    if (banks[bankIndex]) {
        if (slots[slotIndex]) {
            banks[bankIndex]->setSlotAtIndex(slot, slotIndex);
        }
    }
}

void Library::openDirectory(File directory) {
    DirectoryIterator iterator(directory, true);
    while (iterator.next()) {
        if (formatManager->findFormatForFileExtension(iterator.getFile().getFileExtension()) != nullptr) {
            Slot* slot = new Slot();
            slot->loadFile(iterator.getFile());

            if (slot->getPlayer()->getState() == Player::Error) {
                delete slot;
                break;
            }
            slots.add(slot);
        }
    }
}
