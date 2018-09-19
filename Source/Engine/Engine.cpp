#include "Engine.h"
#include "../Models/BankModel.h"
#include "../Models/PlayerModel.h"
#include "../Models/PlaylistModel.h"

Engine::Engine()
        : audioThumbnailCache(21) {
    Logger::outputDebugString("Boot Engine");

    audioFormatManager.registerBasicFormats();
    Logger::outputDebugString("Support:");
    for (auto f : audioFormatManager) {
        Logger::outputDebugString(f->getFormatName());
    }

    state = ValueTree(IDs::LIBRARY);
    state.setProperty(IDs::library_version, "4.0.0", nullptr);
    state.setProperty(IDs::library_title, "Soundboard", nullptr);
    state.setProperty(IDs::library_master_gain, 1.0f, nullptr);
    state.setProperty(IDs::library_state_talkover, isTalkOver(), nullptr);
    state.setProperty(IDs::library_state_mute, isMuted(), nullptr);

    state.addChild(ValueTree(IDs::PLAYERS), -1, nullptr);
    state.addChild(ValueTree(IDs::BANKS), -1, nullptr);
    state.addChild(ValueTree(IDs::PLAYLISTS), -1, nullptr);

    talkOver.gate(talkOverState);
    newBank();
    newPlaylist();

    undoManager.clearUndoHistory();

    setGain(1.0f);

    startTimer(100);

    debugState();
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
    } else {
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

    const ValueTree playerState(IDs::PLAYER);
    PlayerModel model(playerState);
    model.uuid = uuid.toDashedString();
    model.path = file.getFullPathName();
    model.title = file.getFileName();
    model.gain = 1.0f;
    model.startSample = 0;
    model.endSample = player->getTotalLength();
    model.fadeinSamples = 1;
    model.fadeoutSamples = 1;
    model.loop = false;

    model.playerState = player->playerState;
    model.fadeState = player->fadeState;
    model.missing = player->playerState == Player::player_error;

    mixer.addInputSource(player.get(), false);
    players.push_back(std::move(player));

    state.getChildWithName(IDs::PLAYERS).addChild(playerState, -1, &undoManager);
}

void Engine::debugState() const {
    Logger::outputDebugString(state.toXmlString());
}

Player *Engine::playerWithIdentifier(const Identifier &id) {
    for (auto &p : players) {
        if (p->identifier == id) {
            return p.get();
        }
    }
    return nullptr;
}

void Engine::importDirectory(const File &directory) {
    auto files = directory.findChildFiles(File::findFiles, true);
    for (auto &f : files) {
        loadAudioFile(f);
    }
}

void Engine::newBank() {
    Uuid uuid;
    ValueTree bankState(IDs::BANK);
    BankModel model(bankState);
    model.uuid = uuid.toDashedString();
    model.title = "Bank " + String(state.getChildWithName(IDs::BANKS).getNumChildren() + 1);

    bankState.addChild(ValueTree(IDs::CLIPS), -1, &undoManager);

    state.getChildWithName(IDs::BANKS).addChild(bankState, -1, &undoManager);
}

void Engine::newPlaylist() {
    Uuid uuid;
    ValueTree playlistState(IDs::PLAYLIST);
    PlaylistModel model(playlistState);
    model.uuid = uuid.toDashedString();
    model.title = "Playlist " + String(state.getChildWithName(IDs::PLAYLISTS).getNumChildren() + 1);

    playlistState.addChild(ValueTree(IDs::ITEMS), -1, &undoManager);

    state.getChildWithName(IDs::PLAYLISTS).addChild(playlistState, -1, &undoManager);
}

Engine::~Engine() {
    stopTimer();
    mixer.removeAllInputs();
    players.clear();
    audioFormatManager.clearFormats();
    audioThumbnailCache.clear();
}

void Engine::setGain(float value) {
    currentGain = gainRange.convertFrom0to1(value);
    state.setProperty(IDs::library_master_gain, getGain(), nullptr);
}

void Engine::toggleTalkOver() {
    talkOver.setAttackRate(static_cast<float>((currentSampleRate / 1000) * talkOverFadeMs));
    talkOver.setReleaseRate(static_cast<float>((currentSampleRate / 1000) * talkOverFadeMs));
    talkOverState = !talkOverState;
    talkOver.gate(talkOverState);
    state.setProperty(IDs::library_state_talkover, isTalkOver(), nullptr);
}

void Engine::openFile(const File &file) {
    XmlDocument xmlDocument(file);
    const std::unique_ptr<XmlElement> xml(xmlDocument.getDocumentElement());
    undoManager.clearUndoHistory();
    mixer.removeAllInputs();
    players.clear();
    audioThumbnailCache.clear();
    state = ValueTree::fromXml(*xml);
    auto playersState = state.getChildWithName(IDs::PLAYERS);
    if (playersState.isValid()) {
        for (const auto &playerState : playersState) {
            PlayerModel playerModel(playerState);
            auto player = std::make_unique<Player>(playerModel.uuid.get());
            if (!player->loadFileIntoTransport(File(playerModel.path), &audioFormatManager, &audioThumbnailCache)) {
                playerModel.missing = true;
                continue;
            }
            players.push_back(std::move(player));
            playerModel.missing = false;
        }
    }
}

void Engine::saveFile(const File &file) const {
    const std::unique_ptr<XmlElement> xml(state.createXml());
    xml->writeToFile(file, String{});
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

void Engine::timerCallback() {
    playersToUpdate.getLock().enter();
    for (const auto &p : playersToUpdate) {
        auto player = playerWithIdentifier(p);
        auto playerState = playerStateWithIdentifier(p);

        syncState(playerState, player);
    }
    playersToUpdate.clear();
    playersToUpdate.getLock().exit();
}

ValueTree Engine::playerStateWithIdentifier(const Identifier &id) {
    auto players = state.getChildWithName(IDs::PLAYERS);
    return players.getChildWithProperty(IDs::player_uuid, id.toString());
}

void Engine::syncState(ValueTree state, Player *player) {
    PlayerModel model(state);

    if (player->playerState != model.playerState) {
        model.playerState = player->playerState;
    }

    if (player->fadeState != model.fadeState) {
        model.fadeState = player->fadeState;
    }

    if (player->isLooping() != model.loop) {
        model.loop = player->isLooping();
    }

    if (player->progress != model.progress) {
        model.progress = player->progress;
    }

    //Logger::outputDebugString(state.toXmlString());
}

bool Engine::isTalkOver() const {
    return talkOverState;
}

float Engine::getGain() const {
    return gainRange.convertTo0to1(currentGain);
}

void Engine::toggleMuteState() {
    muteState = !muteState;
    state.setProperty(IDs::library_state_mute, isMuted(), nullptr);
}

bool Engine::isMuted() {
    return muteState;
}
