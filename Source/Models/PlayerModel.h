#pragma once

#include "JuceHeader.h"
#include "Identifier.h"
#include "ValueTreeObjectList.h"

struct PlayerModel
{
public:
    explicit PlayerModel(const ValueTree &v)
            : state(v)
    {
        jassert(v.hasType(IDs::PLAYER));

        uuid.referTo(state, IDs::uuid, nullptr);
        path.referTo(state, IDs::path, nullptr);
        title.referTo(state, IDs::title, nullptr);
		gain.referTo(state, IDs::gain, nullptr);
    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<String> path;
    CachedValue<String> title;
	CachedValue<int> gain;
};
