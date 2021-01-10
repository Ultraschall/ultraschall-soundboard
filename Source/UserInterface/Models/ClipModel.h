#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../Redux/Identifier.h"

struct ClipModel
{
	explicit ClipModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::CLIP));

        id.referTo(state, IDs::clip_id, nullptr);
        index.referTo(state, IDs::clip_index, nullptr);
        playerId.referTo(state, IDs::player_id, nullptr);
    }

    ValueTree state;
    CachedValue<String> id;
    CachedValue<int> index;
    CachedValue<String> playerId;
};
