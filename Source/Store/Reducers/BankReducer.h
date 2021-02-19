#pragma once

#include "JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree banks(ValueTree state, const ActionObject& action) {
	if (action.type == Init) {
        Uuid uuid;
        ValueTree bank(IDs::BANK);
        bank.setProperty(IDs::bank_id, uuid.toDashedString(), nullptr);
        bank.setProperty(IDs::bank_title, "Bank 1", nullptr);
        state.addChild(bank, -1, nullptr);
        state.setProperty(IDs::banks_slected_id, uuid.toDashedString(), nullptr);
    } else if (action.type == CreateBank) {
        Uuid uuid;
        ValueTree bank(IDs::BANK);
        bank.setProperty(IDs::bank_id, uuid.toDashedString(), nullptr);
        bank.setProperty(IDs::bank_title, "Bank " + String(state.getNumChildren() + 1), nullptr);
        state.addChild(bank, -1, nullptr);
    } else if (action.type == UpdateBank) {
        auto bank = state.getChildWithProperty(IDs::bank_id, action.args.getProperty(IDs::bank_id));
        jassert(bank.isValid());
        bank.setProperty(IDs::bank_title, action.args.getProperty(IDs::bank_title), nullptr);
    } else if (action.type == DeleteBank) {
        auto bank = state.getChildWithProperty(IDs::bank_id, action.args.getProperty(IDs::bank_id));
        jassert(bank.isValid());
        state.removeChild(bank, nullptr);
    } else if (action.type == SelectBank) {
        state.setProperty(IDs::banks_slected_id, action.args.getProperty(IDs::bank_id), nullptr);
    }
    return state;
}
