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
	DECLARE_ID(version)
	DECLARE_ID(uuid)
	DECLARE_ID(title)
    DECLARE_ID(PLAYERS)
    DECLARE_ID(BANKS)

	DECLARE_ID(PLAYER)
    // uuid
    // title
	DECLARE_ID(path)
    DECLARE_ID(gain)

	DECLARE_ID(BANK)
    // uuid
    // title
	DECLARE_ID(CLIPS)

	DECLARE_ID(CLIP)
    // uuid
	DECLARE_ID(index)
    DECLARE_ID(playerId)


#undef DECLARE_ID
}
