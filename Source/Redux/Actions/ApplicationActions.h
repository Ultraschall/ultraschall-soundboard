#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"
#include "../Identifier.h"

const Identifier ApplicationQuit("QUIT");
const Identifier EnableEngineSync("ENABLE_ENGINE_SYNC");
const Identifier DisableEngineSync("DISABLE_ENGINE_SYNC");

const Identifier SetGain("SET_GAIN");
const Identifier SetTalkOver("SET_TALK_OVER");
const Identifier SetMute("SET_MUTE");
const Identifier ToggleTalkOver("TOGGLE_TALK_OVER");
const Identifier ToggleMute("TOGGLE_MUTE");

const Identifier AddFile("ADD_FILE");
const Identifier AddDirectory("ADD_DIRECTORY");
const Identifier OpenProject("OPEN_PROJECT");
const Identifier ShowView("SHOW_VIEW");

class QuitAction : public ActionObject {
public:
    QuitAction() : ActionObject(ApplicationQuit) {};
};

class EnableEngineSyncAction : public ActionObject {
public:
	EnableEngineSyncAction() : ActionObject(EnableEngineSync) {};
};

class DisableEngineSyncAction : public ActionObject {
public:
	DisableEngineSyncAction() : ActionObject(DisableEngineSync) {};
};

class SetGainAction : public ActionObject {
public:
    SetGainAction(float gain) : ActionObject(SetGain, ValueTree { Args, {{ IDs::application_master_gain, gain }} })
    {};
};

class SetTalkOverAction : public  ActionObject {
public:
    SetTalkOverAction(bool value) : ActionObject(SetTalkOver, ValueTree { Args, {{ IDs::application_talkover, value }} }) {};
};

class SetMuteAction : public  ActionObject {
public:
    SetMuteAction(bool value) : ActionObject(SetMute, ValueTree { Args, {{ IDs::application_mute, value }} }) {};
};

class ToggleTalkOverAction : public  ActionObject {
public:
    ToggleTalkOverAction() : ActionObject(ToggleTalkOver) {};
};

class ToggleMuteAction : public  ActionObject {
public:
    ToggleMuteAction() : ActionObject(ToggleMute) {};
};

class AddFileAction : public  ActionObject {
public:
	AddFileAction() : ActionObject(AddFile) {};
};

class AddDirectoryAction : public  ActionObject {
public:
	AddDirectoryAction() : ActionObject(AddDirectory) {};
};

class OpenProjectAction : public  ActionObject {
public:
	OpenProjectAction() : ActionObject(OpenProject) {};
};

class ShowViewAction : public  ActionObject {
public:
	ShowViewAction(String view) : ActionObject(ShowView, ValueTree{ Args, {{ IDs::application_view, view }} }) {};
};
