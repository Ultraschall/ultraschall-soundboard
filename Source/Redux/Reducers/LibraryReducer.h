#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree library(ValueTree state, ActionObject action) {
    if (state.getNumProperties() == 0) {
		state.setProperty(IDs::library_title, "Soundboard", nullptr);
    }
    return state;
}
