#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

namespace IDs {
#define DECLARE_ID(name, id) const juce::Identifier name (#id);
	// #State
	DECLARE_ID(STATE, STATE)


	// #Application
	DECLARE_ID(APPLICATION, APPLICATION)
	DECLARE_ID(application_version, version)
	DECLARE_ID(application_master_gain, master_gain)
	DECLARE_ID(application_talkover, state_talkover)
	DECLARE_ID(application_mute, state_mute)
	DECLARE_ID(application_view, view)

	// #Players []
    DECLARE_ID(PLAYERS, PLAYERS)

    // #Player
    DECLARE_ID(PLAYER, PLAYER)
    DECLARE_ID(player_id, id)
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

	// -----------------------------

    // #Banks []
    DECLARE_ID(BANKS, BANKS)

    // #Bank
    DECLARE_ID(BANK, BANK)
    DECLARE_ID(bank_id, id)
    DECLARE_ID(bank_title, title)

    // #Bank Clips []
    DECLARE_ID(CLIPS, CLIPS)

    // #Bank Clip
    DECLARE_ID(CLIP, CLIP)
    DECLARE_ID(clip_id, id)
    DECLARE_ID(clip_index, index)
    DECLARE_ID(clip_player_id, player_id)
	DECLARE_ID(clip_bank_id, bank_id)


	// -----------------------------

    // #Playlists []
    DECLARE_ID(PLAYLISTS, PLAYLISTS)

    // #Playlist
    DECLARE_ID(PLAYLIST, PLAYLIST)
    DECLARE_ID(playlist_id, id)
    DECLARE_ID(playlist_title, title)
	DECLARE_ID(playlist_action, action)

    // #Playlist Items
    DECLARE_ID(PLAYLISTITEMS, ITEMS)

    // #Playlist Item
    DECLARE_ID(ITEM, ITEM)
    //DECLARE_ID(player_uuid, uuid);
    

#undef DECLARE_ID
}
