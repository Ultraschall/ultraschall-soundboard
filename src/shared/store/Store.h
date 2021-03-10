//
// Created by Daniel Lindenfelser on 07.03.21.
//

#ifndef ULTRASCHALL_SOUNDBOARD_STORE_H
#define ULTRASCHALL_SOUNDBOARD_STORE_H

#include <juce_core/juce_core.h>

#include "State.h"


class Store {
public:
    juce::ValueTree getState();
private:
    juce::ValueTree state;
};

#endif //ULTRASCHALL_SOUNDBOARD_STORE_H
