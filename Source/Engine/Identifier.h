/*
  ==============================================================================

	Identifier.h
	Created: 29 Apr 2018 12:30:09pm
	Author:  danie

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

namespace IDs {
#define DECLARE_ID(name) const juce::Identifier name (#name);

	DECLARE_ID(LIBRARY)
	DECLARE_ID(uuid)
	DECLARE_ID(title)

	DECLARE_ID(PLAYER)
	DECLARE_ID(path)

	DECLARE_ID(BANK)
	DECLARE_ID(Clips)

	DECLARE_ID(CLIP)
	DECLARE_ID(number)

#undef DECLARE_ID
}
