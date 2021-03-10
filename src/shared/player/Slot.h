/*
  ==============================================================================

    Slot.h
    Created: 15 May 2015 9:33:36pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include <juce_core/juce_core.h>
#include "Player.h"

using namespace juce;

class Slot {
public:
    Slot();
    ~Slot();

    Player* getPlayer();
    bool isEmpty();
    void loadFile(File file);
    void clear();

private:
    ScopedPointer<Player> player;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slot)
};

#endif  // SLOT_H_INCLUDED
