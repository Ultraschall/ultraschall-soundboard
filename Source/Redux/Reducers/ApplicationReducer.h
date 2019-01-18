#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree application(ValueTree state, ActionObject action) {
	if (state.getNumProperties() == 0) {
        state.setProperty(IDs::application_version, "4.0.0", nullptr);
		state.setProperty(IDs::application_master_gain, 1.0f, nullptr);
        state.setProperty(IDs::application_talkover, false, nullptr);
        state.setProperty(IDs::application_mute, false, nullptr);
		state.setProperty(IDs::application_view, "main", nullptr);
	}
    if (action.type == SetGain) {
        float value = action.args.getProperty(IDs::application_master_gain);
        state.setProperty(IDs::application_master_gain, value, nullptr);
    }
    if (action.type == SetTalkOver) {
        bool value = action.args.getProperty(IDs::application_talkover);
        state.setProperty(IDs::application_talkover, value, nullptr);
    }
    if (action.type == SetMute) {
        float value = action.args.getProperty(IDs::application_mute);
        state.setProperty(IDs::application_mute, value, nullptr);
    }
    if (action.type == ToggleTalkOver) {
        bool value = state.getProperty(IDs::application_talkover);
        state.setProperty(IDs::application_talkover, !value, nullptr);
    }
    if (action.type == ToggleMute) {
        bool value = state.getProperty(IDs::application_mute);
        state.setProperty(IDs::application_mute, !value, nullptr);
    }
	if (action.type == ShowView) {
		String value = action.args.getProperty(IDs::application_view);
		if (state.getProperty(IDs::application_view) != value) {
			state.setProperty(IDs::application_view, value, nullptr);
		}
	}
    return state;
}
