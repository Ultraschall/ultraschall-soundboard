/*
  ==============================================================================

    Library.h
    Created: 15 May 2015 9:33:15pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <juce_core/juce_core.h>
#include "Player.h"
#include "Slot.h"
#include "Bank.h"

const int maxNumThumbsToStore = 128;

class Library {
public:
    Library();
    ~Library();

    void openDirectory(File directory);

    void validateFiles();
    bool addFile(File file);
    Slot* getSlotWithFile(File file);

    Slot* getSlotAtIndex(int index);
    void moveSlot(int from, int to);
    int numSlots();

    Bank* getBankAtIndex(int index);
    void addSlotToBank(Slot* slot, int bankIndex, int slotIndex);
    int numBanks();

private:
    OwnedArray<Slot> slots;
    OwnedArray<Bank> banks;
    ScopedPointer<AudioFormatManager> formatManager;
    ScopedPointer<AudioThumbnailCache> thumbnailCache;
};


#endif  // LIBRARY_H_INCLUDED
