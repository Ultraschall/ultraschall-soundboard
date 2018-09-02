#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Identifier.h"

struct LibraryModel
{
    explicit LibraryModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::LIBRARY));

		version.referTo(state, IDs::library_version, nullptr);
		uuid.referTo(state, IDs::library_uuid, nullptr);
		title.referTo(state, IDs::library_title, nullptr);
        master_gain.referTo(state, IDs::library_master_gain, nullptr);
	}

	ValueTree state;
	CachedValue<String> version;
	CachedValue<String> uuid;
	CachedValue<String> title;

	CachedValue<float> master_gain;
};