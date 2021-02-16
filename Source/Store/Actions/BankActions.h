#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"

const Identifier CreateBank("CREATE_BANK");
const Identifier UpdateBank("UPDATE_BANK");
const Identifier DeleteBank("DELETE_BANK");

const Identifier SelectBank("SELECT_BANK");

const Identifier CreateClip("CREATE_CLIP");
const Identifier UpdateClip("UPDATE_CLIP");
const Identifier DeleteClip("DELETE_CLIP");

class CreateBankAction : public ActionObject {
public:
    CreateBankAction() : ActionObject(CreateBank) {};
};
class UpdateBankAction : public ActionObject {
public:
    UpdateBankAction(String id, String title) : ActionObject(UpdateBank,
                                                                 ValueTree{ Args, { {IDs::bank_id, id}, {IDs::bank_title, title} }}) {};
};
class DeleteBankAction : public ActionObject {
public:
    DeleteBankAction(String id) : ActionObject(DeleteBank, ValueTree{ Args, { {IDs::bank_id, id}}}) {};
};
class SelectBankAction : public ActionObject {
public:
    SelectBankAction(String id) : ActionObject(SelectBank, ValueTree{ Args, { {IDs::bank_id, id}}}) {};
};

class CreateClipAction : public ActionObject {
public:
    CreateClipAction(String bankId, String playerId) : ActionObject(CreateClip, ValueTree{ Args, { {IDs::clip_bank_id, bankId}, {IDs::clip_player_id, playerId}  } }) {
        
    };
};

class UpdateClipAction : public ActionObject {
public:
    UpdateClipAction(String clipId, String bankId, String playerId) : ActionObject(UpdateClip, ValueTree{ Args, { {IDs::clip_id, clipId}, {IDs::clip_bank_id, bankId}, {IDs::clip_player_id, playerId}  } }) {
        
    };
};

class DeleteClipAction : public ActionObject {
public:
    DeleteClipAction(String clipId) : ActionObject(DeleteClip, ValueTree{ Args, {  {IDs::clip_id, clipId}  } }) {
        
    };
};

