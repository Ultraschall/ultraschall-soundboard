#pragma once

#include "JuceHeader.h"
#include "Identifier.h"

struct LibraryModel
{
	LibraryModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::LIBRARY));

		version.referTo(state, IDs::version, nullptr);
		uuid.referTo(state, IDs::uuid, nullptr);
		title.referTo(state, IDs::title, nullptr);
	}

	ValueTree state;
	CachedValue<String> version;
	CachedValue<String> uuid;
	CachedValue<String> title;
};