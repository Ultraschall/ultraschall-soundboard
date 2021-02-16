#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree players(ValueTree state, const ActionObject& action) {
    if (state.getNumProperties() == 0) {
    }
	if (action.type == FileReady) {
		String id = action.args.getProperty(IDs::player_id);
		String title = action.args.getProperty(IDs::player_title);
		String path = action.args.getProperty(IDs::player_path);
		ValueTree player(IDs::PLAYER);
		player.setProperty(IDs::player_id, id, nullptr);
		player.setProperty(IDs::player_title, title, nullptr);
		player.setProperty(IDs::player_path, path, nullptr);
		state.addChild(player, -1, nullptr);
	}
    return state;
}
