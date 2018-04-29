/*
  ==============================================================================

	Library.h
	Created: 27 Apr 2018 4:22:31pm
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include <vector>
#include "JuceHeader.h"
#include "Identifier.h"
#include "Player.h"


class Library {
public:
	Library();
private:
	std::vector<Player> players;
	juce::ValueTree state;
};
