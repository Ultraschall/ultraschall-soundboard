#include "JuceHeader.h"

#include "LibraryViewController.h"

#include "../Views/LibraryRowView.h"

LibraryViewController::LibraryViewController(Engine &engine)
        : ValueTreeObjectList<PlayerModel>(engine.state.getChildWithName(IDs::PLAYERS)),
          ViewController(engine) {
    rebuildObjects();
}

LibraryViewController::~LibraryViewController() {
    getLibraryView()->table.setModel(nullptr);
    freeObjects();
}

bool LibraryViewController::isSuitableType(const juce::ValueTree &tree) const {
    return tree.hasType(IDs::PLAYER);;
}

PlayerModel *LibraryViewController::createNewObject(const juce::ValueTree &tree) {
    auto model = new PlayerModel(tree);
    return model;
}

void LibraryViewController::deleteObject(PlayerModel *type) {
    delete type;
}

void LibraryViewController::newObjectAdded(PlayerModel *type) {
    ignoreUnused(type);
    getLibraryView()->table.updateContent();
}

void LibraryViewController::objectRemoved(PlayerModel *type) {
    ignoreUnused(type);
    getLibraryView()->table.updateContent();
}

void LibraryViewController::objectOrderChanged() {
    getLibraryView()->table.updateContent();
}

void LibraryViewController::loadView() {
    view = std::make_unique<LibraryView>();
}

void LibraryViewController::viewDidLoad() {
    getLibraryView()->table.setModel(this);
}

int LibraryViewController::getNumRows() {
    return objects.size() + 1;
}

void LibraryViewController::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) {
    ignoreUnused(rowNumber);
    ignoreUnused(g);
    ignoreUnused(width);
    ignoreUnused(height);
    ignoreUnused(rowIsSelected);
}

Component *LibraryViewController::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate) {
    ignoreUnused(isRowSelected);

    if (rowNumber >= objects.size())
    {
        delete existingComponentToUpdate;
        return nullptr;
    }

    LibraryRowView *libraryRowView = nullptr;

    auto existingLibraryRowView = dynamic_cast<LibraryRowView*>(existingComponentToUpdate);
    if (nullptr != existingComponentToUpdate)
    {
        if (nullptr == existingLibraryRowView) {
            delete existingComponentToUpdate;
            libraryRowView = new LibraryRowView();
        } else {
            libraryRowView = existingLibraryRowView;
        }
    } else {
        libraryRowView = new LibraryRowView();
    }
    const auto playerModel = objects[rowNumber];
    if (playerModel == nullptr) {
        return libraryRowView;
    }

    libraryRowView->reset();
    libraryRowView->title = playerModel->title;

    intLibraryRow(libraryRowView, *playerModel);
    refreshLibraryRow(libraryRowView, *playerModel);

    return libraryRowView;
}

LibraryView *LibraryViewController::getLibraryView() const {
    return dynamic_cast<LibraryView *>(getView());
}

void LibraryViewController::intLibraryRow(LibraryRowView *libraryRowView, PlayerModel &playerModel) {
    auto uuid = Identifier(playerModel.uuid);
    libraryRowView->settingsButton.onClick = [] {

    };

    libraryRowView->loopButton.onClick = [this, uuid, libraryRowView] {
        engine.playerLooping(uuid, !libraryRowView->loopButton.getToggleState());
    };

    libraryRowView->fadeButton.onClick = [this, uuid, libraryRowView] {
        const auto fadeState = libraryRowView->fadeButton.getToggleState();
        if (fadeState) {
            engine.playerFadeOut(uuid);
        } else {
            engine.playerFadeIn(uuid);
        }
    };

    libraryRowView->playButton.onClick = [this, uuid, libraryRowView] {
        const auto playState = libraryRowView->playButton.getToggleState();
        if (playState) {
            engine.playerPause(uuid);
        } else {
            engine.playerPlay(uuid);
        }
    };

    libraryRowView->stopButton.onClick = [this, uuid, libraryRowView] {
        engine.playerStop(uuid);
    };
}

void LibraryViewController::refreshLibraryRow(LibraryRowView *libraryRowView, PlayerModel &playerModel) {
    switch (playerModel.fadeState) {
        case Player::fade_out:
            libraryRowView->fadeButton.setToggleState(false, dontSendNotification);
            break;

        default:
        case Player::fade_in:
        case Player::fade_idle:
            libraryRowView->fadeButton.setToggleState(true, dontSendNotification);
            break;
    }

    switch (playerModel.playerState) {
        case Player::player_error:
            libraryRowView->setHasError();
        case Player::player_stopped:
            libraryRowView->setIsStopped();
            break;
        case Player::player_paused:
            libraryRowView->setIsPaused();
            break;
        case Player::player_played:
            libraryRowView->setIsPlayed();
            break;
        case Player::player_playing:
            libraryRowView->setIsPlaying();
            break;
        default:
        case Player::player_ready:
        case Player::player_idle:
            libraryRowView->setIsReady();
            break;
    }

    libraryRowView->loopButton.setToggleState(playerModel.loop, dontSendNotification);
}

void LibraryViewController::valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) {

    if (state.hasType(IDs::PLAYER))
    {
        auto index = indexOf(state);
        auto playerModel = objects[index];
        auto libraryRowView = dynamic_cast<LibraryRowView*>(getLibraryView()->table.getComponentForRowNumber(indexOf(state)));
        refreshLibraryRow(libraryRowView, *playerModel);
    }
}
