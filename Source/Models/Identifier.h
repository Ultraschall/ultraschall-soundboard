#pragma once

#include "JuceHeader.h"

namespace IDs
{
#define DECLARE_ID(name) const juce::Identifier name (#name);

	// #Library
    DECLARE_ID(LIBRARY)
    DECLARE_ID(version)
    DECLARE_ID(uuid)
    DECLARE_ID(title)

	// #Players []
    DECLARE_ID(PLAYERS)

	// #Player
    DECLARE_ID(PLAYER)
    // uuid
    // title
    DECLARE_ID(path)
    DECLARE_ID(gain)
    DECLARE_ID(start_sample)
    DECLARE_ID(end_sample)
    DECLARE_ID(fadein_samples)
    DECLARE_ID(fadeout_sanples)
    DECLARE_ID(loop)

	// #Banks []
	DECLARE_ID(BANKS)

	// #Bank
    DECLARE_ID(BANK)
    // uuid
    // title

    // #Bank Clips []
    DECLARE_ID(CLIPS)
    
	// #Bank Clip
    DECLARE_ID(CLIP)
    // uuid
    DECLARE_ID(index)
    DECLARE_ID(player_uuid)

	// #Playlists []
	DECLARE_ID(PLAYLISTS)

	// #Playlist
	DECLARE_ID(PLAYLIST)
	// uuid
	// title
	
	// #Playlist Items
	DECLARE_ID(ITEMS)
	
	// #Playlist Item
	DECLARE_ID(ITEM)
	// player_uuid
	DECLARE_ID(action)

#undef DECLARE_ID
}
