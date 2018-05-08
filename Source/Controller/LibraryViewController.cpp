/*
  ==============================================================================

    LibraryViewController.cpp
    Created: 4 May 2018 11:04:34am
    Author:  danlin

  ==============================================================================
*/

#include "JuceHeader.h"
#include "LibraryViewController.h"
#include "../Views/LibraryRowView.h"

LibraryViewController::LibraryViewController(Engine & engine)
	: drow::ValueTreeObjectList<PlayerModel>(engine.state.getChildWithName(IDs::PLAYERS)),
	ViewController(engine)
{

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
	//getLibraryView()->table.updateContent();
}

void LibraryViewController::objectRemoved(PlayerModel *type) {
	//getLibraryView()->table.updateContent();
}

void LibraryViewController::objectOrderChanged() {
	//getLibraryView()->table.updateContent();
}

void LibraryViewController::loadView() {
    view = std::make_unique<LibraryView>();
}

void LibraryViewController::viewDidLoad() {
	getLibraryView()->table.setModel(this);
}

int LibraryViewController::getNumRows()
{
	return 13;// objects.size();
}

void LibraryViewController::paintListBoxItem(int rowNumber, Graphics & g, int width, int height, bool rowIsSelected)
{
}

Component * LibraryViewController::refreshComponentForRow(int rowNumber, bool isRowSelected, Component * existingComponentToUpdate)
{
	if (existingComponentToUpdate != nullptr) return existingComponentToUpdate;
	return new LibraryRowView();
}

LibraryView * LibraryViewController::getLibraryView() {
	return dynamic_cast<LibraryView*>(getView());
}
