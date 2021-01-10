#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"

const Identifier NewBank("NEW_BANK");
const Identifier RemoveBank("REMOVE_BANK");

const Identifier NewClip("NEW_CLIP");
const Identifier RemoveClip("REMOVE_CLIP");

class NewBankAction : public ActionObject {
public:
    NewBankAction() : ActionObject(NewBank) {};
};

class NewClipAction : public ActionObject {
public:
    NewClipAction(String bankId, String playerId, int index) : ActionObject(NewClip, ValueTree{ Args, { {IDs::clip_bank_id, bankId}, {IDs::clip_player_id, playerId}, {IDs::clip_index, index}  } }) {

    };
};
