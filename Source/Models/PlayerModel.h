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
		startSample.referTo(state, IDs::start_sample, nullptr);
		endSample.referTo(state, IDs::end_sample, nullptr);
        fadeinSamples.referTo(state, IDs::fadein_samples, nullptr);
        fadeoutSamples.referTo(state, IDs::fadeout_sanples, nullptr);
        loop.referTo(state, IDs::loop, nullptr);
    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<String> path;
    CachedValue<String> title;
	CachedValue<float> gain;
    CachedValue<int64> startSample;
    CachedValue<int64> endSample;
    CachedValue<int64> fadeinSamples;
    CachedValue<int64> fadeoutSamples;
    CachedValue<bool> loop;

};
