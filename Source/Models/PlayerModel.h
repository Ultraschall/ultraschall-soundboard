#pragma once

#include "JuceHeader.h"
#include "Identifier.h"

struct PlayerModel
{
    PlayerModel(const ValueTree &v)
            : state(v)
    {
        jassert(v.hasType(IDs::PLAYER));

        uuid.referTo(state, IDs::player_uuid, nullptr);
        path.referTo(state, IDs::player_path, nullptr);
        title.referTo(state, IDs::player_title, nullptr);
		gain.referTo(state, IDs::player_gain, nullptr);
		startSample.referTo(state, IDs::player_start_sample, nullptr);
		endSample.referTo(state, IDs::player_end_sample, nullptr);
        fadeinSamples.referTo(state, IDs::player_fadein_samples, nullptr);
        fadeoutSamples.referTo(state, IDs::player_fadeout_samples, nullptr);
        loop.referTo(state, IDs::player_loop, nullptr);

        playerState.referTo(state, IDs::player_state, nullptr);
        fadeState.referTo(state, IDs::player_state_fade, nullptr);
        missing.referTo(state, IDs::player_state_missing, nullptr);
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

    CachedValue<int> playerState;
    CachedValue<int> fadeState;
    CachedValue<bool> missing;
};
