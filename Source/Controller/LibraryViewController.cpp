#include "JuceHeader.h"

#include "LibraryViewController.h"

#include "../Views/LibraryRowView.h"

LibraryViewController::LibraryViewController(Engine & engine)
	: ValueTreeObjectList<PlayerModel>(engine.state.getChildWithName(IDs::PLAYERS)),
	ViewController(engine)
{
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
    return new PlayerModel(tree);
}

void LibraryViewController::deleteObject(PlayerModel *type) {
    delete type;
}

void LibraryViewController::newObjectAdded(PlayerModel *type) {
	getLibraryView()->table.updateContent();
}

void LibraryViewController::objectRemoved(PlayerModel *type) {
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

int LibraryViewController::getNumRows()
{
	return objects.size();
}

void LibraryViewController::paintListBoxItem(int rowNumber, Graphics & g, int width, int height, bool rowIsSelected)
{
}

Component * LibraryViewController::refreshComponentForRow(int rowNumber, bool isRowSelected, Component * existingComponentToUpdate)
{
	const auto existingLibraryRowViewToUpdate = dynamic_cast<LibraryRowView*>(existingComponentToUpdate);
    if (existingComponentToUpdate != nullptr && existingLibraryRowViewToUpdate == nullptr)
    {
        delete existingComponentToUpdate;
    }
	LibraryRowView* rowView = existingLibraryRowViewToUpdate != nullptr ? existingLibraryRowViewToUpdate : new LibraryRowView();

	const auto playerModel = objects[rowNumber];
	if (playerModel == nullptr)
	{
		return rowView;
	}

	rowView->title = playerModel->title;

	const auto player = engine.playerWithIdentifier(Identifier(playerModel->uuid));
	if (playerModel == nullptr)
	{
		return rowView;
	}

	rowView->SetAudioThumbnail(player->thumbnail.get());
	rowView->playButton.onClick = [player, rowView] {
		const auto playState = rowView->playButton.getToggleState();
		if (playState)
		{
			player->pause();
		} 
		else
		{
			player->play();
		}
		rowView->playButton.setToggleState(!playState, NotificationType::dontSendNotification);
	};
	rowView->stopButton.onClick = [player, rowView] {
		player->stop();
		rowView->playButton.setToggleState(false, NotificationType::dontSendNotification);
	};
	rowView->loopButton.onClick = [rowView] {
		const auto loopState = rowView->loopButton.getToggleState();
		rowView->loopButton.setToggleState(!loopState, NotificationType::dontSendNotification);
	};

	return rowView;
}

LibraryView * LibraryViewController::getLibraryView() const
{
	return dynamic_cast<LibraryView*>(getView());
}
