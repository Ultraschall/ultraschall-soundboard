#pragma once

#include "JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree application(ValueTree state, const ActionObject& action) {
	if (action.type == Init) {
        state.setProperty(IDs::application_version, "4.0.0", nullptr);
		state.setProperty(IDs::application_master_gain, 1.0f, nullptr);
        state.setProperty(IDs::application_talkover, false, nullptr);
        state.setProperty(IDs::application_talkover_gain, 0.25f, nullptr);
        state.setProperty(IDs::application_talkover_restore_gain, 1.0f, nullptr);

        state.setProperty(IDs::application_mute, false, nullptr);
		state.setProperty(IDs::application_view, "main", nullptr);
	}
    if (action.type == SetGain) {
        float value = action.args.getProperty(IDs::application_master_gain);

        if (!bool(state.getProperty(IDs::application_talkover))) {
            state.setProperty(IDs::application_master_gain, value, nullptr);
        } else {
            state.setProperty(IDs::application_talkover_restore_gain, value, nullptr);
        }
        
    }
    if (action.type == SetTalkOver) {
        bool value = action.args.getProperty(IDs::application_talkover);
        state.setProperty(IDs::application_talkover, value, nullptr);
        if (bool(value)) {
            auto master_gain = state.getProperty(IDs::application_master_gain);
            auto talkover_gain = state.getProperty(IDs::application_talkover_gain);
            state.setProperty(IDs::application_master_gain, talkover_gain, nullptr);
            state.setProperty(IDs::application_talkover_restore_gain, master_gain, nullptr);
        } else {
            auto restore_gain = state.getProperty(IDs::application_talkover_restore_gain);
            state.setProperty(IDs::application_master_gain, restore_gain, nullptr);
        }
    }
    if (action.type == SetMute) {
        float value = action.args.getProperty(IDs::application_mute);
        state.setProperty(IDs::application_mute, value, nullptr);
    }
    if (action.type == ToggleTalkOver) {
        bool value = !state.getProperty(IDs::application_talkover);
        state.setProperty(IDs::application_talkover, value, nullptr);
        if (bool(value)) {
            auto master_gain = state.getProperty(IDs::application_master_gain);
            auto talkover_gain = state.getProperty(IDs::application_talkover_gain);
            state.setProperty(IDs::application_master_gain, talkover_gain, nullptr);
            state.setProperty(IDs::application_talkover_restore_gain, master_gain, nullptr);
        } else {
            auto restore_gain = state.getProperty(IDs::application_talkover_restore_gain);
            state.setProperty(IDs::application_master_gain, restore_gain, nullptr);
        }
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
