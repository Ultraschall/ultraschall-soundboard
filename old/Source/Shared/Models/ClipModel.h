/*
  ==============================================================================

    ClipModel.h
    Created: 19 Jan 2018 10:41:25pm
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "IDs.h"

struct Clip {
	Clip (const ValueTree& v) : state(v) {
		jassert(v.hasType(IDs::Clip));
		name.referTo(state, IDs::Name, nullptr);
	}

	ValueTree state;
	CachedValue<String> name;
};

template<>
struct VariantConverter<Colour> {
	static Colour fromVar (const var& v) {
		return Colour::fromString(v.toString());
	}

	static var toVar (const Colour& c) {
		return c.toString();
	}
};