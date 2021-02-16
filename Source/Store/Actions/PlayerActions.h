#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../ActionObject.h"

const Identifier PlayerPlay("PLAYER_PLAY");
const Identifier PlayerStop("PLAYER_STOP");
const Identifier PlayerPause("PLAYER_PAUSE");
const Identifier PlayerFadeIn("PLAYER_FADE_IN");
const Identifier PlayerFadeOut("PLAYER_FADE_OUT");

const Identifier PlayerToggleLooping("PLAYER_TOGGLE_LOOPING");

class PlayerPlayAction : public  ActionObject {
public:
	PlayerPlayAction(String id) : ActionObject(PlayerPlay, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};
class PlayerStopAction : public  ActionObject {
public:
	PlayerStopAction(String id) : ActionObject(PlayerStop, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};
class PlayerPauseAction : public  ActionObject {
public:
	PlayerPauseAction(String id) : ActionObject(PlayerPause, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};
class PlayerFadeInAction : public  ActionObject {
public:
	PlayerFadeInAction(String id) : ActionObject(PlayerFadeIn, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};
class PlayerFadeOutAction : public  ActionObject {
public:
	PlayerFadeOutAction(String id) : ActionObject(PlayerFadeOut, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};

class PlayerToggleLoopingAction : public  ActionObject {
public:
	PlayerToggleLoopingAction(String id) : ActionObject(PlayerToggleLooping, ValueTree{ Args, {{ IDs::player_id, id }} }) {};
};
