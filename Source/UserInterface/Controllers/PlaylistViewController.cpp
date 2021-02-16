#include "PlaylistViewController.h"
#include "../../Store/Actions/Actions.h"
#include "../../Engine/Player.h"

PlaylistViewController::PlaylistViewController(std::shared_ptr<Store> store)
	: ValueTreeObjectList<PlayerModel>(store->getState().getChildWithName(IDs::PLAYLISTS)), ViewController(store)
{
	rebuildObjects();
}

PlaylistViewController::~PlaylistViewController()
{
	freeObjects();
}

void PlaylistViewController::loadView()
{
	view = std::make_unique<LibraryView>();
}

void PlaylistViewController::viewDidLoad()
{
	getLibraryView()->table.setModel(this);
}

bool PlaylistViewController::isSuitableType(const juce::ValueTree &tree) const
{
	return tree.hasType(IDs::PLAYER);
	;
}

PlayerModel *PlaylistViewController::createNewObject(const juce::ValueTree &tree)
{
	return new PlayerModel(tree);
}

void PlaylistViewController::deleteObject(PlayerModel *type)
{
	delete type;
}

void PlaylistViewController::newObjectAdded(PlayerModel * /*type*/)
{
	updateContent();
}

void PlaylistViewController::objectRemoved(PlayerModel * /*type*/)
{
	updateContent();
}

void PlaylistViewController::objectOrderChanged()
{
	updateContent();
}

void PlaylistViewController::valueTreePropertyChanged(ValueTree &state, const Identifier & /*identifier*/)
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

LibraryView *PlaylistViewController::getLibraryView() const
{
	return dynamic_cast<LibraryView *>(getView());
}

int PlaylistViewController::getNumRows()
{
	return objects.size() + 1;
}

Component *PlaylistViewController::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate)
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

void PlaylistViewController::intLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel)
{
	auto uuid = Identifier(playerModel.id);
	libraryItem->fadeButton.onClick = [this, uuid, libraryItem] {
		const auto fadeState = libraryItem->fadeButton.getToggleState();
		if (fadeState)
		{
			const auto _ = store->dispatch(PlayerFadeInAction(uuid.toString()));
		}
		else
		{
			const auto _ = store->dispatch(PlayerFadeOutAction(uuid.toString()));
		}
	};

	libraryItem->playButton.onClick = [this, uuid, libraryItem] {
		const auto playState = libraryItem->playButton.getToggleState();
		if (playState)
		{
			const auto _ = store->dispatch(PlayerPauseAction(uuid.toString()));
		}
		else
		{
			const auto _ = store->dispatch(PlayerPlayAction(uuid.toString()));
		}
	};

	libraryItem->stopButton.onClick = [this, uuid, libraryItem] {
		const auto _ = store->dispatch(PlayerStopAction(uuid.toString()));
	};
}

void PlaylistViewController::refreshLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel)
{
	libraryItem->reset();
	libraryItem->title.setText(playerModel.title, dontSendNotification);
	libraryItem->time.setText("00:00:00", dontSendNotification);
	libraryItem->progress = playerModel.progress;

	switch (playerModel.fadeState)
	{
	case static_cast<int>(Player::FadeState::fade_out):
		libraryItem->fadeButton.setToggleState(false, dontSendNotification);
		break;

	default:
	case static_cast<int>(Player::FadeState::fade_in):
	case static_cast<int>(Player::FadeState::fade_idle):
		libraryItem->fadeButton.setToggleState(true, dontSendNotification);
		break;
	}

	switch (playerModel.playerState)
	{
	case static_cast<int>(Player::PlayerState::player_error):
		libraryItem->setError();
	case static_cast<int>(Player::PlayerState::player_stopped):
		libraryItem->setIsStopped();
		break;
	case static_cast<int>(Player::PlayerState::player_paused):
		libraryItem->setIsPaused();
		break;
	case static_cast<int>(Player::PlayerState::player_played):
		libraryItem->setIsPlayed();
		break;
	case static_cast<int>(Player::PlayerState::player_playing):
		libraryItem->setIsPlaying();
		break;
	default:
	case static_cast<int>(Player::PlayerState::player_ready):
	case static_cast<int>(Player::PlayerState::player_idle):
		libraryItem->setIsReady();
		break;
	}
}

void PlaylistViewController::updateContent() const
{
	auto libraryView = getLibraryView();
	if (libraryView != nullptr)
	{
		libraryView->table.updateContent();
	}
}
