#include "Engine.h"
#include "../Models/PlayerModel.h"
#include "../Models/PlaylistModel.h"
#include "../Models/BankModel.h"

Engine::Engine()
        : audioThumbnailCache(21)
{
    Logger::outputDebugString("Boot Engine");

    audioFormatManager.registerBasicFormats();
    Logger::outputDebugString("Support:");
    for (auto f : audioFormatManager)
    {
        Logger::outputDebugString(f->getFormatName());
    }

    state = ValueTree(IDs::LIBRARY);
    state.setProperty(IDs::version, "4.0.0", nullptr);
    state.setProperty(IDs::title, "Unamed", nullptr);

    state.addChild(ValueTree(IDs::PLAYERS), -1, nullptr);
    state.addChild(ValueTree(IDs::BANKS), -1, nullptr);
	state.addChild(ValueTree(IDs::PLAYLISTS), -1, nullptr);
	
	talkOver.gate(talkOverState);
    newBank();
	newPlaylist();

	undoManager.clearUndoHistory();
}

void Engine::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
	currentSampleRate = sampleRate;
	previousGain = currentGain;
}

void Engine::releaseResources()
{
    mixer.releaseResources();
}

void Engine::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
    mixer.getNextAudioBlock(bufferToFill);

	auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

	for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
	{
		const auto level = talkOverRange.convertFrom0to1(talkOver.process());

		if (talkOver.getState() == ADSR::env_sustain) continue;

		leftBuffer[sample] = leftBuffer[sample] * level;
		rightBuffer[sample] = rightBuffer[sample] * level;
	}

	if (currentGain == previousGain)
	{
		bufferToFill.buffer->applyGain(currentGain);
	}
	else
	{
		bufferToFill.buffer->applyGainRamp(0, bufferToFill.buffer->getNumSamples(), previousGain, currentGain);
		previousGain = currentGain;
	}
}

void Engine::loadAudioFile(const File& file)
{
    Uuid uuid;
    auto player = players.add(new Player(uuid.toDashedString()));
    if (!player->loadFileIntoTransport(file, &audioFormatManager, &audioThumbnailCache))
    {
        players.remove(players.indexOf(player), true);
        return;
    }

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


    state.getChildWithName(IDs::PLAYERS).addChild(playerState, -1, &undoManager);
    mixer.addInputSource(player, false);
}

void Engine::DebugState() const
{
    Logger::getCurrentLogger()->outputDebugString(state.toXmlString());
}

Player *Engine::playerWithIdentifier(const Identifier id)
{
    for (auto &p : players)
    {
        if (p->getIdentifier() == id)
        {
            return p;
        }
    }
    return nullptr;
}

void Engine::importDirectory(const File& directory)
{
    auto files = directory.findChildFiles(File::findFiles, true);
    for (auto &f : files)
    {
        loadAudioFile(f);
    }
}

void Engine::newBank()
{
    Uuid uuid;
	ValueTree bankState(IDs::BANK);
    BankModel model(bankState);
    model.uuid = uuid.toDashedString();
    model.title = "Bank " + String(state.getChildWithName(IDs::BANKS).getNumChildren() + 1);

	bankState.addChild(ValueTree(IDs::CLIPS), -1, &undoManager);

    state.getChildWithName(IDs::BANKS).addChild(bankState, -1, &undoManager);
}

void Engine::newPlaylist()
{
	Uuid uuid;
	ValueTree playlistState(IDs::PLAYLIST);
	PlaylistModel model(playlistState);
	model.uuid = uuid.toDashedString();
	model.title = "Playlist " + String(state.getChildWithName(IDs::PLAYLISTS).getNumChildren() + 1);

	playlistState.addChild(ValueTree(IDs::ITEMS), -1, &undoManager);

	state.getChildWithName(IDs::PLAYLISTS).addChild(playlistState, -1, &undoManager);
}
