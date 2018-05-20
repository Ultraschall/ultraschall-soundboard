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
    engine.playerWithIdentifier(Identifier(model->uuid))->addChangeListener(this);
    return model;
}

void LibraryViewController::deleteObject(PlayerModel *type) {
    engine.playerWithIdentifier(Identifier(type->uuid))->removeChangeListener(this);
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
        if (nullptr != existingComponentToUpdate) {
            delete existingComponentToUpdate;
        }

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

    const auto player = engine.playerWithIdentifier(Identifier(playerModel->uuid));
    if (player == nullptr) {
        return libraryRowView;
    }

    intLibraryRow(libraryRowView, player);
    refreshLibraryRow(libraryRowView, player);

    return libraryRowView;
}

LibraryView *LibraryViewController::getLibraryView() const {
    return dynamic_cast<LibraryView *>(getView());
}

void LibraryViewController::changeListenerCallback(ChangeBroadcaster *changeBroadcaster) {
    auto player = dynamic_cast<Player*>(changeBroadcaster);

    if (player == nullptr)
    {
        return;
    }

    for (auto &p: objects)
    {
        if (p->uuid == player->identifier.toString())
        {
            auto index = objects.indexOf(p);
            auto libraryRowView = dynamic_cast<LibraryRowView*>(getLibraryView()->table.getComponentForRowNumber(index));
            if (libraryRowView != nullptr)
            {
                refreshLibraryRow(libraryRowView, player);
            }
            return;
        }
    }
}

void LibraryViewController::intLibraryRow(LibraryRowView *libraryRowView, Player *player) {
    libraryRowView->SetAudioThumbnail(player->thumbnail);

    libraryRowView->settingsButton.onClick = [] {

    };

    libraryRowView->loopButton.onClick = [player, libraryRowView] {
        player->setLooping(!libraryRowView->loopButton.getToggleState());
    };

    libraryRowView->fadeButton.onClick = [player, libraryRowView] {
        const auto fadeState = libraryRowView->fadeButton.getToggleState();
        if (fadeState) {
            player->fadeOut();
        } else {
            player->fadeIn();
        }
    };

    libraryRowView->playButton.onClick = [player, libraryRowView] {
        const auto playState = libraryRowView->playButton.getToggleState();
        if (playState) {
            player->pause();
        } else {
            player->play();
        }
    };

    libraryRowView->stopButton.onClick = [player, libraryRowView] {
        player->stop();
    };
}

void LibraryViewController::refreshLibraryRow(LibraryRowView *libraryRowView, Player *player) {
    switch (player->fadeState) {
        case Player::fade_out:
            libraryRowView->fadeButton.setToggleState(false, dontSendNotification);
            break;

        case Player::fade_in:
        case Player::fade_idle:
            libraryRowView->fadeButton.setToggleState(true, dontSendNotification);
            break;
    }

    switch (player->playerState) {
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
        case Player::player_ready:
        case Player::player_idle:
            libraryRowView->setIsReady();
            break;
    }

    libraryRowView->loopButton.setToggleState(player->isLooping(), dontSendNotification);
}
