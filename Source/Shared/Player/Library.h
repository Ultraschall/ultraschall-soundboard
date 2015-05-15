/*
  ==============================================================================

    Library.h
    Created: 15 May 2015 9:33:15pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "JuceHeader.h"
#include "Player.h"
#include "Slot.h"
#include "Bank.h"

class Library {
public:
    Library();
    ~Library();

    void validateFiles();
    bool addFile(File file);

    Slot* getSlotAtIndex(int index);
    int numSlots();

    Bank* getBankAtIndex(int index);
    int numBanks();

private:
    OwnedArray<Slot> slots;
    OwnedArray<Bank> banks;
    ScopedPointer<AudioFormatManager> formatManager;
    ScopedPointer<AudioThumbnailCache> thumbnailCache;
};


#endif  // LIBRARY_H_INCLUDED
