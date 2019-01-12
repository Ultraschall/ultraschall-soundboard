#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree bank(ValueTree state, ActionObject action) {
	if (state.getNumChildren() == 0) {
		Uuid uuid;
		ValueTree bank(IDs::BANK);
		bank.setProperty(IDs::bank_uuid, uuid.toDashedString(), nullptr);
		bank.setProperty(IDs::bank_title, "Bank 1", nullptr);
		state.addChild(bank, -1, nullptr);
	}
    if (action.type == NewBank) {
		Uuid uuid;
		ValueTree bank(IDs::BANK);
		bank.setProperty(IDs::bank_uuid, uuid.toDashedString(), nullptr);
		bank.setProperty(IDs::bank_title, "Bank " + String(state.getNumChildren() + 1), nullptr);
		state.addChild(bank, -1, nullptr);
    }
    return state;
}
