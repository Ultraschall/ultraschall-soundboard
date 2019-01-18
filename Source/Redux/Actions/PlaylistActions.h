#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"

const Identifier NewPlaylist("NEW_PLAYLIST");

class NewPlaylistAction : public ActionObject {
public:
    NewPlaylistAction() : ActionObject(NewPlaylist) {};
};
