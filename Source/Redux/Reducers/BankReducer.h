#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree bank(ValueTree state, const ActionObject& action) {
	if (state.getNumChildren() == 0) {
		Uuid uuid;
		ValueTree bank(IDs::BANK);
		bank.setProperty(IDs::bank_id, uuid.toDashedString(), nullptr);
		bank.setProperty(IDs::bank_title, "Bank 1", nullptr);
		state.addChild(bank, -1, nullptr);
	}
    if (action.type == NewBank) {
		Uuid uuid;
		ValueTree bank(IDs::BANK);
		bank.setProperty(IDs::bank_id, uuid.toDashedString(), nullptr);
		bank.setProperty(IDs::bank_title, "Bank " + String(state.getNumChildren() + 1), nullptr);
		state.addChild(bank, -1, nullptr);
    }
    if (action.type == NewClip) {
        Uuid uuid;
        auto players = state.getChildWithName(IDs::PLAYERS);
        auto player = players.getChildWithProperty(IDs::player_id, action.args.getProperty(IDs::clip_player_id));
        jassert(player.isValid());
        auto banks = state.getChildWithName(IDs::BANKS);
        auto bank = banks.getChildWithProperty(IDs::bank_id, action.args.getProperty(IDs::clip_bank_id));
        jassert(bank.isValid());

        ValueTree clip(IDs::CLIP);
        clip.setProperty(IDs::clip_id, uuid.toDashedString(), nullptr);
        clip.setProperty(IDs::clip_index, action.args.getProperty(IDs::clip_index), nullptr);
        clip.setProperty(IDs::clip_player_id, action.args.getProperty(IDs::clip_player_id), nullptr);
        clip.setProperty(IDs::clip_bank_id, action.args.getProperty(IDs::clip_bank_id), nullptr);
    }
    return state;
}
