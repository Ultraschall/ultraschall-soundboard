#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../Redux/Identifier.h"

struct LibraryModel
{
    explicit LibraryModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::LIBRARY));

		uuid.referTo(state, IDs::library_uuid, nullptr);
		title.referTo(state, IDs::library_title, nullptr);
    }

	ValueTree state;
	CachedValue<String> uuid;
	CachedValue<String> title;
};
