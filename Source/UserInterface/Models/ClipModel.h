#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../Store/Identifier.h"

struct ClipModel
{
	explicit ClipModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::CLIP));

        id.referTo(state, IDs::clip_id, nullptr);
        bankId.referTo(state, IDs::clip_bank_id, nullptr);
        playerId.referTo(state, IDs::player_id, nullptr);
    }

    ValueTree state;
    CachedValue<String> id;
    CachedValue<int> bankId;
    CachedValue<String> playerId;
};
