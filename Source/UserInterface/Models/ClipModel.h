#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../Redux/Identifier.h"

struct ClipModel
{
	explicit ClipModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::CLIP));

        uuid.referTo(state, IDs::clip_uuid, nullptr);
        index.referTo(state, IDs::clip_index, nullptr);
        playerUuid.referTo(state, IDs::player_uuid, nullptr);
    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<int> index;
    CachedValue<String> playerUuid;
};
