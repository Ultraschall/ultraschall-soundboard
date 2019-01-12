#include "Engine.h"
//#include "../Models/BankModel.h"
//#include "../Models/PlayerModel.h"
//#include "../Models/PlaylistModel.h"

#include "../Redux/Identifier.h"

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

void Engine::loadAudioFile(const File &file) {
	Uuid uuid;
	auto player = std::make_unique<Player>(uuid.toDashedString());
	if (!player->loadFileIntoTransport(file, &audioFormatManager, &audioThumbnailCache)) {
		return;
	}
	player->addChangeListener(this);
//
//	const ValueTree playerState(IDs::PLAYER);
//	PlayerModel model(playerState);
//	model.uuid = uuid.toDashedString();
//	model.path = file.getFullPathName();
//	model.title = file.getFileName();
//	model.gain = 1.0f;
//	model.startSample = 0;
//	model.endSample = player->getTotalLength();
//	model.fadeinSamples = 1;
//	model.fadeoutSamples = 1;
//	model.loop = false;
//
//	model.playerState = player->playerState;
//	model.fadeState = player->fadeState;
//	model.missing = player->playerState == Player::player_error;
//
	mixer.addInputSource(player.get(), false);
	players[Identifier(uuid.toDashedString())] = (std::move(player));
//
////	state.getChildWithName(IDs::PLAYERS).addChild(playerState, -1, &undoManager);
}

Player *Engine::playerWithIdentifier(const Identifier &id) {
    auto search = players.find(id);
    return search == players.end() ? nullptr : search->second.get();
}

void Engine::importDirectory(const File &directory) {
	auto files = directory.findChildFiles(File::findFiles, true);
	for (auto &f : files) {
		loadAudioFile(f);
	}
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
	return false;
}

void Engine::sync(Store &store) {
	playersToUpdate.getLock().enter();
	for (const auto &p : playersToUpdate) {
		auto player = playerWithIdentifier(p);
		
	}
	playersToUpdate.clear();
	playersToUpdate.getLock().exit();
}

void Engine::toggleMuteState() {
	muteState = !muteState;
}
