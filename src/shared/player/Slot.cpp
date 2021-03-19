/*
  ==============================================================================

    Slot.cpp
    Created: 15 May 2015 9:33:36pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "Slot.h"

Slot::Slot() {

}

Slot::~Slot() {
    player = nullptr;
}

Player *Slot::getPlayer() {
    return player;
}

bool Slot::isEmpty() {
    return player != nullptr;
}

void Slot::clear() {

}
