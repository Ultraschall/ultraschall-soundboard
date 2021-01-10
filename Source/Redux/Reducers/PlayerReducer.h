#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree player(ValueTree state, const ActionObject& action) {
    if (state.getNumProperties() == 0) {
    }
    return state;
}

