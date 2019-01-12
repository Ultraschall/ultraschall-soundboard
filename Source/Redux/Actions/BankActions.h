#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"

const Identifier NewBank("NEW_BANK");

class NewBankAction : public ActionObject {
public:
    NewBankAction() : ActionObject(NewBank) {};
};
