/*
  ==============================================================================

    Bank.h
    Created: 15 May 2015 9:33:22pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include "JuceHeader.h"
#include "Slot.h"

const int slotsPerBank = 24;

class Bank {
public:
    Bank(String name);
    ~Bank();

    String getName();
    void setName(String name);
private:
    String name;
    OwnedArray<Slot> slots;
};

#endif  // BANK_H_INCLUDED
