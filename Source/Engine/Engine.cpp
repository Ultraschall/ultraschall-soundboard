#include "Engine.h"
#include "../Models/ClipModel.h"

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
}

void Engine::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Engine::releaseResources()
{
    mixer.releaseResources();
}

void Engine::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
    mixer.getNextAudioBlock(bufferToFill);
}

void Engine::loadAudioFile(File file)
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

    state.getChildWithName(IDs::PLAYERS).addChild(playerState, -1, &undoManager);
    mixer.addInputSource(player, false);

    DebugState();
}

void Engine::DebugState() const
{
    Logger::getCurrentLogger()->outputDebugString(state.toXmlString());
}

Player *Engine::playerWithIdentifier(Identifier id)
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

void Engine::importDirectory(File directory)
{
    Array<File> files;
    directory.findChildFiles(files, File::findFiles, true);
    for (auto &f : files)
    {
        loadAudioFile(f);
    }
}

void Engine::newBank()
{
    Uuid uuid;
    const ValueTree bankState(IDs::BANK);
    BankModel model(bankState);
    model.uuid = uuid.toDashedString();
    model.title = "Bank " + state.getChildWithName(IDs::BANKS).getNumChildren() + 1;
    state.getChildWithName(IDs::BANKS).addChild(bankState, -1, &undoManager);

    DebugState();
}
