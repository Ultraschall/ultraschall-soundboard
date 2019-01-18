#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree playlist(ValueTree state, ActionObject action) {
    if (state.getNumChildren() == 0) {
        Uuid uuid;
        ValueTree playlist(IDs::PLAYLIST);
        playlist.setProperty(IDs::playlist_id, uuid.toDashedString(), nullptr);
        playlist.setProperty(IDs::playlist_title, "Playlist 1", nullptr);
        state.addChild(playlist, -1, nullptr);
    }
    if (action.type == NewPlaylist) {
        Uuid uuid;
        ValueTree playlist(IDs::PLAYLIST);
        playlist.setProperty(IDs::playlist_id, uuid.toDashedString(), nullptr);
        playlist.setProperty(IDs::playlist_title, "Playlist " + String(state.getNumChildren() + 1), nullptr);
        state.addChild(playlist, -1, nullptr);
    }
    return state;
}
