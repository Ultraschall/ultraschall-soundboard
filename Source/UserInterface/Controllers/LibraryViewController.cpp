#include "LibraryViewController.h"
#include "../../Redux/Actions/Actions.h"
#include "../../Engine/Player.h"

LibraryViewController::LibraryViewController(std::shared_ptr<Store> store)
    : ValueTreeObjectList<PlayerModel>(store->getState().getChildWithName(IDs::PLAYERS)), ViewController(store)
{
    rebuildObjects();
}

LibraryViewController::~LibraryViewController()
{
    freeObjects();
}

void LibraryViewController::loadView()
{
    view = std::make_unique<LibraryView>();
}

void LibraryViewController::viewDidLoad()
{
    getLibraryView()->table.setModel(this);
}

bool LibraryViewController::isSuitableType(const juce::ValueTree &tree) const
{
    return tree.hasType(IDs::PLAYER);
    ;
}

PlayerModel *LibraryViewController::createNewObject(const juce::ValueTree &tree)
{
    return new PlayerModel(tree);
}

void LibraryViewController::deleteObject(PlayerModel *type)
{
    delete type;
}

void LibraryViewController::newObjectAdded(PlayerModel * /*type*/)
{
    updateContent();
}

void LibraryViewController::objectRemoved(PlayerModel * /*type*/)
{
    updateContent();
}

void LibraryViewController::objectOrderChanged()
{
    updateContent();
}

void LibraryViewController::valueTreePropertyChanged(ValueTree &state, const Identifier & /*identifier*/)
{

    if (state.hasType(IDs::PLAYER))
    {
        auto libraryItem = dynamic_cast<class LibraryItem *>(getLibraryView()->table.getComponentForRowNumber(indexOf(state)));
        if (libraryItem == nullptr)
        {
            return;
        }

        auto index = indexOf(state);
        auto playerModel = objects[index];
        refreshLibraryRow(libraryItem, *playerModel);
    }
}

LibraryView *LibraryViewController::getLibraryView() const
{
    return dynamic_cast<LibraryView *>(getView());
}

int LibraryViewController::getNumRows()
{
    return objects.size() + 1;
}

Component *LibraryViewController::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate)
{
    ignoreUnused(isRowSelected);

    if (rowNumber >= objects.size())
    {
        delete existingComponentToUpdate;
        return nullptr;
    }

    LibraryItem *libraryItem = nullptr;

    auto existinglibraryItem = dynamic_cast<LibraryItem *>(existingComponentToUpdate);
    if (nullptr != existingComponentToUpdate)
    {
        if (nullptr == existinglibraryItem)
        {
            delete existingComponentToUpdate;
            libraryItem = new LibraryItem();
        }
        else
        {
            libraryItem = existinglibraryItem;
        }
    }
    else
    {
        libraryItem = new LibraryItem();
    }
    const auto playerModel = objects[rowNumber];
    if (playerModel == nullptr)
    {
        return libraryItem;
    }

    intLibraryRow(libraryItem, *playerModel);
    refreshLibraryRow(libraryItem, *playerModel);

    return libraryItem;
}

void LibraryViewController::intLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel)
{
    auto uuid = Identifier(playerModel.id);
    libraryItem->fadeButton.onClick = [this, uuid, libraryItem] {
        const auto fadeState = libraryItem->fadeButton.getToggleState();
        if (fadeState)
        {
			store->dispatch(PlayerFadeInAction(uuid.toString()));
        }
        else
        {
			store->dispatch(PlayerFadeOutAction(uuid.toString()));
        }
    };

    libraryItem->playButton.onClick = [this, uuid, libraryItem] {
        const auto playState = libraryItem->playButton.getToggleState();
        if (playState)
        {
			store->dispatch(PlayerPauseAction(uuid.toString()));
        }
        else
        {
			store->dispatch(PlayerPlayAction(uuid.toString()));
        }
    };

    libraryItem->stopButton.onClick = [this, uuid, libraryItem] {
		store->dispatch(PlayerStopAction(uuid.toString()));
    };
}

void LibraryViewController::refreshLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel)
{
    libraryItem->reset();
    libraryItem->title.setText(playerModel.title, dontSendNotification);
    libraryItem->time.setText("00:00:00", dontSendNotification);
    libraryItem->progress = playerModel.progress;

    switch (playerModel.fadeState)
    {
    case Player::fade_out:
        libraryItem->fadeButton.setToggleState(false, dontSendNotification);
        break;

    default:
    case Player::fade_in:
    case Player::fade_idle:
        libraryItem->fadeButton.setToggleState(true, dontSendNotification);
        break;
    }

    switch (playerModel.playerState)
    {
    case Player::player_error:
        libraryItem->setError();
    case Player::player_stopped:
        libraryItem->setIsStopped();
        break;
    case Player::player_paused:
        libraryItem->setIsPaused();
        break;
    case Player::player_played:
        libraryItem->setIsPlayed();
        break;
    case Player::player_playing:
        libraryItem->setIsPlaying();
        break;
    default:
    case Player::player_ready:
    case Player::player_idle:
        libraryItem->setIsReady();
        break;
    }
}

void LibraryViewController::updateContent() const
{
    auto libraryView = getLibraryView();
    if (libraryView != nullptr)
    {
		libraryView->table.updateContent();
    }
}
