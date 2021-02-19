#pragma once

#include "JuceHeader.h"
#include "../../Store/Identifier.h"

struct ApplicationModel
{
public:
	ApplicationModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::APPLICATION));

		master_gain.referTo(state, IDs::application_master_gain, nullptr);
		mute.referTo(state, IDs::application_mute, nullptr);
		talkover.referTo(state, IDs::application_talkover, nullptr);
		view.referTo(state, IDs::application_view, nullptr);
	}

	ValueTree state;
	CachedValue<double> master_gain;
	CachedValue<bool> mute;
	CachedValue<bool> talkover;
	CachedValue<String> view;
};
