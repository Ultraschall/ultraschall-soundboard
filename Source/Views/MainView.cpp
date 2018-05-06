/*
  ==============================================================================

	MainView.cpp
	Created: 4 May 2018 11:22:54am
	Author:  danlin

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MainView.h"

//==============================================================================
MainView::MainView()
{
	addAndMakeVisible(toolbar);
	dropShadower.setOwner(&toolbar);
	
	addAndMakeVisible(spacer);
	addAndMakeVisible(bottomBar);

	addButton.setImages(addIcon.getDrawable());
	addAndMakeVisible(addButton);
	addButton.toFront(true);

	addAndMakeVisible(sideNavbar);
	sideNavbar.toFront(false);
}

MainView::~MainView() {

}

void MainView::paint(Graphics &g) {
	g.fillAll(Colour(225, 225, 225));
	ultraschallIcon.getDrawable()->drawWithin(g, getLocalBounds().reduced(100).toFloat(), RectanglePlacement::centred, 0.2f);
}

void MainView::resized() {

	auto actionHeight = Material::convertDpToPixel(this, 56);

	auto flexBox = FlexBox();

	flexBox.flexDirection = FlexBox::Direction::column;

	flexBox.items.add(FlexItem(toolbar).withMaxHeight(Material::convertDpToPixel(this, 64)).withWidth(getWidth()).withFlex(1));

	if (contentView != nullptr) {
		flexBox.items.add(FlexItem(*contentView).withWidth(getWidth()).withFlex(2));
	}
	else {
		flexBox.items.add(FlexItem(spacer).withWidth(getWidth()).withFlex(2));
	}

	flexBox.items.add(FlexItem(bottomBar).withMaxHeight(actionHeight).withWidth(getWidth()).withFlex(1));

	flexBox.performLayout(getLocalBounds());

	addButton.setBounds(
		getLocalBounds().getWidth() - (actionHeight * 1.5),
		getLocalBounds().getHeight() - (actionHeight * 1.4),
		actionHeight,
		actionHeight
	);

	sideNavbar.setBounds(getLocalBounds().removeFromLeft(Material::convertDpToPixel(this, 300)));
}

void MainView::setContentView(Component *view) {
	if (view == contentView) return;

	contentView = view;
	addAndMakeVisible(contentView);
	contentView->toBack();
	addButton.toFront(true);
	resized();
	repaint();
}

bool MainView::GainToolbarView::getToolbarItemSizes(int toolbarThickness, bool isToolbarVertical, int &preferredSize,
	int &minSize, int &maxSize) {
	if (isToolbarVertical)
		return false;

	preferredSize = 250;
	minSize = 80;
	maxSize = 300;
	return true;
}

void
MainView::GainToolbarView::paintButtonArea(Graphics &g, int width, int height, bool isMouseOver, bool isMouseDown) {
}

void MainView::GainToolbarView::contentAreaChanged(const Rectangle<int> &newBounds) {
	slider.setSize(newBounds.getWidth() - 2,
		jmin(newBounds.getHeight() - 2, 22));

	slider.setCentrePosition(newBounds.getCentreX(), newBounds.getCentreY());
}
