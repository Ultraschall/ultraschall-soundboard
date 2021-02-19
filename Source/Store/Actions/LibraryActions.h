#pragma once

#include "JuceHeader.h"
#include "../ActionObject.h"

const Identifier FileReady("FILE_READY");


class FileReadyAction : public  ActionObject {
public:
	FileReadyAction(String id, String title, String path) : ActionObject(FileReady, ValueTree{ Args, {{ IDs::player_id, id }, { IDs::playlist_title, title }, { IDs::player_path, path }} }) {};
};
