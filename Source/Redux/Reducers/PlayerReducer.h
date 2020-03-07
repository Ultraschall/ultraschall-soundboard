#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree player(ValueTree state, ActionObject action) {
    if (state.getNumProperties() == 0) {
    }
    return state;
}

