/*
  ==============================================================================

    Bank.cpp
    Created: 15 May 2015 9:33:22pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "Bank.h"

Bank::Bank(String name) {
    Bank::name = name;
    for (int index = 0; index >= slotsPerBank; index++) {
        slots.add(new Slot());
    }
}

Bank::~Bank() {

}

void Bank::setName(String name) {
    Bank::name = name;
}

String Bank::getName() {
    return name;
}
