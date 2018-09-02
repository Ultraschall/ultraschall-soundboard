#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

namespace IDs {
#define DECLARE_ID(name, id) const juce::Identifier name (#id);

    // #Library
    DECLARE_ID(LIBRARY, LIBRARY)
    DECLARE_ID(library_version, version)
    DECLARE_ID(library_uuid, uuid)
    DECLARE_ID(library_title, title)
    DECLARE_ID(library_master_gain, master_gain)

    // #Players []
    DECLARE_ID(PLAYERS, PLAYERS)

    // #Player
    DECLARE_ID(PLAYER, PLAYER)
    DECLARE_ID(player_uuid, uuid)
    DECLARE_ID(player_title, title)
    DECLARE_ID(player_path, path)
    DECLARE_ID(player_gain, gain)
    DECLARE_ID(player_start_sample, start_sample)
    DECLARE_ID(player_end_sample, end_sample)
    DECLARE_ID(player_fadein_samples, fadein_samples)
    DECLARE_ID(player_fadeout_samples, fadeout_samples)
    DECLARE_ID(player_loop, loop)

    DECLARE_ID(player_state, state)
    DECLARE_ID(player_state_fade, fade)
    DECLARE_ID(player_state_missing, missing)
	DECLARE_ID(player_state_progress, progress)


    // #Banks []
    DECLARE_ID(BANKS, BANKS)

    // #Bank
    DECLARE_ID(BANK, BANK)
    DECLARE_ID(bank_uuid, uuid)
    DECLARE_ID(bank_title, title)

    // #Bank Clips []
    DECLARE_ID(CLIPS, CLIPS)

    // #Bank Clip
    DECLARE_ID(CLIP, CLIP)
    DECLARE_ID(clip_uuid, uuid)
    DECLARE_ID(clip_index, index)
    //DECLARE_ID(player_uuid, uuid)

    // #Playlists []
    DECLARE_ID(PLAYLISTS, PLAYLISTS)

    // #Playlist
    DECLARE_ID(PLAYLIST, PLAYLIST)
    DECLARE_ID(playlist_uuid, uuid)
    DECLARE_ID(playlist_title, title)
	DECLARE_ID(playlist_action, action)

    // #Playlist Items
    DECLARE_ID(ITEMS, ITEMS)

    // #Playlist Item
    DECLARE_ID(ITEM, ITEM)
    //DECLARE_ID(player_uuid, uuid);
    

#undef DECLARE_ID
}
