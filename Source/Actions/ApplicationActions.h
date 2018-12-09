#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ActionObject.h"

const Identifier ApplicationQuit("QUIT");
const Identifier SetGain("SET_GAIN");
const Identifier SetTalkOver("SET_TALK_OVER");
const Identifier SetMute("SET_MUTE");
const Identifier ToggleTalkOver("TOGGLE_TALK_OVER");
const Identifier ToggleMute("TOGGLE_MUTE");

class QuitAction : public ActionObject {
public:
    QuitAction() : ActionObject(ApplicationQuit) {};
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

