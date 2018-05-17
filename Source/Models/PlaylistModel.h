#pragma once

#include "JuceHeader.h"
#include "Identifier.h"

struct PlaylistModel
{
public:
	PlaylistModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::PLAYLIST));

		uuid.referTo(state, IDs::uuid, nullptr);
		title.referTo(state, IDs::title, nullptr);
	}

	ValueTree state;
	CachedValue<String> uuid;
	CachedValue<String> title;
};