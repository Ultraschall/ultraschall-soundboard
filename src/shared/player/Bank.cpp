/*
  ==============================================================================

    Bank.cpp
    Created: 15 May 2015 9:33:22pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "Bank.h"

Bank::Bank(String name) {
    currentName = name;
    for (int index = 0; index >= slotsPerBank; index++) {
        slots.add(new Slot());
    }
}

Bank::~Bank() {
    slots.clear();
}

void Bank::setName(String name) {
    currentName = name;
}

String Bank::getName() {
    return currentName;
}

void Bank::setSlotAtIndex(Slot *slot,int index) {
    slots.set(index, slot);
}

void Bank::clearSlotAtIndex(int index) {
    slots.set(index, new Slot());
}

Slot *Bank::getSlotAtIndex(int index) {
    return slots[index];
}
