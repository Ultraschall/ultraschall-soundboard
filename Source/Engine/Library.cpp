/*
  ==============================================================================

	Library.cpp
	Created: 27 Apr 2018 4:22:31pm
	Author:  danlin

  ==============================================================================
*/

#include "Library.h"

Library::Library()
	: audioThumbnailCache(21)
{
	audioFormatManager.registerBasicFormats();

	state = ValueTree(IDs::LIBRARY);
	state.setProperty(IDs::version, "4.0.0", nullptr);
	state.setProperty(IDs::title, "Unamed", nullptr);

	auto players = ValueTree(IDs::PLAYERS);
    state.addChild(players, -1, nullptr);
    playersState = std::make_unique<PlayerList>(players);
    state.addChild(ValueTree(IDs::BANKS), -1, nullptr);
}

void Library::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Library::releaseResources() {
	mixer.releaseResources();
}

void Library::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
	mixer.getNextAudioBlock(bufferToFill);
}

void Library::loadAudioFile(File file) {
    Uuid uuid;
	auto player = players.add(new Player(uuid.toDashedString()));
	if (!player->loadFileIntoTransport(file, &audioFormatManager)) {
		players.remove(players.indexOf(player), true);
        return;
	}



	ValueTree playerState(IDs::PLAYER);
    PlayerModel model(playerState);
    model.uuid = uuid.toDashedString();
    model.path = file.getFullPathName();
    model.title = file.getFileName();

    state.getChildWithName(IDs::PLAYERS).addChild(playerState, 0, &undoManager);
	mixer.addInputSource(player, false);

    DebugState();
}

void Library::DebugState() {
    Logger::getCurrentLogger()->outputDebugString(state.toXmlString());
}

Player *Library::playerWithIdentifier(Identifier id) {
    for (auto& p : players) {
        if (p->getIdentifier() == id) {
            return p;
        }
    }
    return nullptr;
}
