#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Identifier.h"

struct LibraryModel
{
	LibraryModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::LIBRARY));

		version.referTo(state, IDs::library_version, nullptr);
		uuid.referTo(state, IDs::library_uuid, nullptr);
		title.referTo(state, IDs::library_title, nullptr);
	}

	ValueTree state;
	CachedValue<String> version;
	CachedValue<String> uuid;
	CachedValue<String> title;
};