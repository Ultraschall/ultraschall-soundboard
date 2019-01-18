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
