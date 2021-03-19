/*
  ==============================================================================

    Bank.h
    Created: 15 May 2015 9:33:22pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <juce_core/juce_core.h>
#include "Slot.h"

using namespace juce;

const int slotsPerBank = 24;

class Bank {
public:
    Bank(String name);
    ~Bank();

    String getName();
    void setName(String name);

    void setSlotAtIndex(Slot* slot, int index);
    void clearSlotAtIndex(int index);
    Slot* getSlotAtIndex(int index);
private:
    String currentName;
    Array<Slot*> slots;
};

#endif  // BANK_H_INCLUDED
