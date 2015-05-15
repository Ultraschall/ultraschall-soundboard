/*
  ==============================================================================

    Slot.h
    Created: 15 May 2015 9:33:36pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include "JuceHeader.h"
#include "Player.h"

class Slot {
public:
    Slot();
    ~Slot();

    Player* getPlayer();
    bool isEmpty();
    void loadFile(File file);
private:
    ScopedPointer<Player> player;
};

#endif  // SLOT_H_INCLUDED
