#include "Engine.h"
#include "../UserInterface/Models/PlayerModel.h"
#include "../Redux/Identifier.h"
#include "../Redux/Actions/Actions.h"

Engine::Engine() : audioThumbnailCache(21) {
	Logger::outputDebugString("[ENGINE] Boot...");
    Logger::outputDebugString("[ENGINE] Register Formats:");
	audioFormatManager.registerBasicFormats();
	for (auto f : audioFormatManager) {
		Logger::outputDebugString("[ENGINE] Format " + f->getFormatName() + " enabled.");
	}
}

void Engine::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
	currentSampleRate = sampleRate;
	previousGain = currentGain;
}

void Engine::releaseResources() {
	mixer.releaseResources();
}

void Engine::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {
	mixer.getNextAudioBlock(bufferToFill);

	auto *leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	auto *rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

	for (auto sample = 0; sample < bufferToFill.numSamples; ++sample) {
		const auto level = talkOverRange.convertFrom0to1(talkOver.process());

		if (talkOver.getState() == ADSR::env_sustain)
			continue;

		leftBuffer[sample] = leftBuffer[sample] * level;
		rightBuffer[sample] = rightBuffer[sample] * level;
	}

	if (currentGain == previousGain) {
		bufferToFill.buffer->applyGain(currentGain);
	}
	else {
		bufferToFill.buffer->applyGainRamp(0, bufferToFill.buffer->getNumSamples(), previousGain, currentGain);
		previousGain = currentGain;
	}
}

bool Engine::loadAudioFile(Identifier id, const File &file) {
	auto player = std::make_unique<Player>(id);
	if (!player->loadFileIntoTransport(file, &audioFormatManager, &audioThumbnailCache)) {
		return false;
	}
	player->addChangeListener(this);
	mixer.addInputSource(player.get(), false);
	players[id] = std::move(player);
	playersToUpdate.addIfNotAlreadyThere(id);
	return true;
}

Player *Engine::playerWithIdentifier(const Identifier &id) {
    auto search = players.find(id);
    return search == players.end() ? nullptr : search->second.get();
}

Engine::~Engine() {
	mixer.removeAllInputs();
	players.clear();
	audioFormatManager.clearFormats();
	audioThumbnailCache.clear();
}

void Engine::setGain(float value) {
	currentGain = gainRange.convertFrom0to1(value);
}

void Engine::toggleTalkOver() {
	talkOver.setAttackRate(static_cast<float>((currentSampleRate / 1000) * talkOverFadeMs));
	talkOver.setReleaseRate(static_cast<float>((currentSampleRate / 1000) * talkOverFadeMs));
	talkOverState = !talkOverState;
	talkOver.gate(talkOverState);
}

void Engine::openFile(const File &file) {
//	XmlDocument xmlDocument(file);
//	const std::unique_ptr<XmlElement> xml(xmlDocument.getDocumentElement());
////	undoManager.clearUndoHistory();
//	mixer.removeAllInputs();
//	players.clear();
//	audioThumbnailCache.clear();
//	state = ValueTree::fromXml(*xml);
//	auto playersState = state.getChildWithName(IDs::PLAYERS);
//	if (playersState.isValid()) {
//		for (const auto &playerState : playersState) {
//			PlayerModel playerModel(playerState);
//			auto player = std::make_unique<Player>(playerModel.uuid.get());
//			if (!player->loadFileIntoTransport(File(playerModel.path), &audioFormatManager, &audioThumbnailCache)) {
//				playerModel.missing = true;
//				continue;
//			}
//			players.push_back(std::move(player));
//			playerModel.missing = false;
//		}
//	}
}

void Engine::saveFile(const File &file) const {
//	const std::unique_ptr<XmlElement> xml(state.createXml());
//	xml->writeToFile(file, String{});
}

void Engine::playerLooping(const Identifier &uuid, bool looping) {
	playerWithIdentifier(uuid)->setLooping(looping);
}

void Engine::playerFadeOut(const Identifier &uuid) {
	playerWithIdentifier(uuid)->fadeOut();
}

void Engine::playerFadeIn(const Identifier &uuid) {
	playerWithIdentifier(uuid)->fadeIn();
}

void Engine::playerPlay(const Identifier &uuid) {
	playerWithIdentifier(uuid)->play();
}

void Engine::playerPause(const Identifier &uuid) {
	playerWithIdentifier(uuid)->pause();
}

void Engine::playerStop(const Identifier &uuid) {
	playerWithIdentifier(uuid)->stop();
}

void Engine::changeListenerCallback(ChangeBroadcaster *source) {
	auto player = dynamic_cast<Player *>(source);
	if (player == nullptr) {
		return;
	}

	playersToUpdate.addIfNotAlreadyThere(player->identifier);
}

bool Engine::dispatch(const ActionObject &action, Store &store)
{
	auto uuid = action.args.getProperty(IDs::player_id);
	if (action.type == PlayerPlay) {
		playerPlay(Identifier(uuid));
	}
	if (action.type == PlayerStop) {
		playerStop(Identifier(uuid));
	}
	if (action.type == PlayerPause) {
		playerPause(Identifier(uuid));
	}
	if (action.type == PlayerFadeIn) {
		playerFadeIn(Identifier(uuid));
	}
	if (action.type == PlayerFadeOut) {
		playerFadeOut(Identifier(uuid));
	}

	return false;
}

void Engine::sync(Store &store) {
	playersToUpdate.getLock().enter();
	for (const auto &p : playersToUpdate) {
		auto player = playerWithIdentifier(p);
		auto library = store.getState().getChildWithName(IDs::LIBRARY);
		jassert(library.isValid());
		auto playerState = library.getChildWithProperty(IDs::player_id, p.toString());
		jassert(playerState.isValid());
		
		PlayerModel model(playerState);
		model.gain = player->getGain();
		model.startSample = 0;
		model.endSample = player->getTotalLength();
		model.fadeinSamples = 1;
		model.fadeoutSamples = 1;
		model.loop = player->isLooping();

		model.playerState = player->playerState;
		model.fadeState = player->fadeState;
		model.missing = player->playerState == Player::player_error;
		model.progress = player->progress;
	}
	playersToUpdate.clear();
	playersToUpdate.getLock().exit();
}

void Engine::toggleMuteState() {
	muteState = !muteState;
}
