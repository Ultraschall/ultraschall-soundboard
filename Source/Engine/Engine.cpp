/*
  ==============================================================================

	Library.cpp
	Created: 27 Apr 2018 4:22:31pm
	Author:  danlin

  ==============================================================================
*/

#include "Engine.h"

Engine::Engine()
	: audioThumbnailCache(21)
{
	audioFormatManager.registerBasicFormats();

	state = ValueTree(IDs::LIBRARY);
	state.setProperty(IDs::version, "4.0.0", nullptr);
	state.setProperty(IDs::title, "Unamed", nullptr);

    state.addChild(ValueTree(IDs::PLAYERS), -1, nullptr);
    state.addChild(ValueTree(IDs::BANKS), -1, nullptr);
}

void Engine::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Engine::releaseResources() {
	mixer.releaseResources();
}

void Engine::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
	mixer.getNextAudioBlock(bufferToFill);
}

void Engine::loadAudioFile(File file) {
    Uuid uuid;
	auto player = players.add(new Player(uuid.toDashedString()));
	if (!player->loadFileIntoTransport(file, &audioFormatManager, &audioThumbnailCache)) {
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

void Engine::DebugState() {
    Logger::getCurrentLogger()->outputDebugString(state.toXmlString());
}

Player *Engine::playerWithIdentifier(Identifier id) {
    for (auto& p : players) {
        if (p->getIdentifier() == id) {
            return p;
        }
    }
    return nullptr;
}
