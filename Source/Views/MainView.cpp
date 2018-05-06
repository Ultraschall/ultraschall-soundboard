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

    sideBarShadower.setOwner(&sideNavbar);

    addButtonShadower.setOwner(&addButton);
}

void MainView::paint(Graphics &g) {
	g.fillAll(Colour(225, 225, 225));
	ultraschallIcon.getDrawable()->drawWithin(g, getLocalBounds().reduced(100).toFloat(), RectanglePlacement::centred, 0.2f);
}

void MainView::resized() {

	auto actionHeight = Material::convertDpToPixel<float>(this, 56);

	auto flexBox = FlexBox();

	flexBox.flexDirection = FlexBox::Direction::column;

	flexBox.items.add(FlexItem(toolbar).withMaxHeight(Material::convertDpToPixel<float>(this, 64)).withWidth(getWidth()).withFlex(1));

	if (contentView != nullptr) {
		flexBox.items.add(FlexItem(*contentView).withWidth(getWidth()).withFlex(2));
	}
	else {
		flexBox.items.add(FlexItem(spacer).withWidth(getWidth()).withFlex(2));
	}

	flexBox.items.add(FlexItem(bottomBar).withMaxHeight(actionHeight).withWidth(getWidth()).withFlex(1));

	flexBox.performLayout(getLocalBounds());

	addButton.setBounds(
		getLocalBounds().getWidth() - int(actionHeight * 1.5),
		getLocalBounds().getHeight() - int(actionHeight * 1.4),
		int(actionHeight),
		int(actionHeight)
	);

	if (sideBarVisible) {
        sideNavbarBackground.setBounds(getLocalBounds());
        sideNavbar.setBounds(getLocalBounds().removeFromLeft(Material::convertDpToPixel<int>(this, 300)));
    }
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

void MainView::showSideNavBar() {
    sideNavbarBackground.setBounds(getLocalBounds());
    addAndMakeVisible(sideNavbarBackground);
    sideNavbar.toFront(false);

    auto endBounds = getLocalBounds().removeFromLeft(Material::convertDpToPixel<int>(this, 300));
    auto startBounds = endBounds;
    startBounds.setPosition(-300, startBounds.getY());

    sideNavbar.setBounds(startBounds);
    addAndMakeVisible(sideNavbar);
    sideNavbar.toFront(false);

    sideNavbarBackgroundAnimator.fadeIn(&sideNavbarBackground, 200);
    sideNavbarAnimator.animateComponent(
            &sideNavbar,
            endBounds,
            1.0f,
            200,
            false,
            0.4f,
            0.8f
    );

    sideBarVisible = true;
}

void MainView::hideSideNavBar() {
    auto endBounds = sideNavbar.getLocalBounds();
    endBounds.setPosition(-300, endBounds.getY());

    sideNavbarBackgroundAnimator.fadeOut(&sideNavbarBackground, 200);
    sideNavbarAnimator.animateComponent(
            &sideNavbar,
            endBounds,
            1.0f,
            200,
            false,
            0.8f,
            0.4f
    );

    removeChildComponent(&sideNavbarBackground);
    sideBarVisible = false;
}
