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

		uuid.referTo(state, IDs::playlist_uuid, nullptr);
		title.referTo(state, IDs::playlist_title, nullptr);
		action.referTo(state, IDs::playlist_action, nullptr);
	}

	ValueTree state;
	CachedValue<String> uuid;
	CachedValue<String> title;
	CachedValue<int> action;
};