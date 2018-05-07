/*
  ==============================================================================

	MainView.cpp
	Created: 4 May 2018 11:22:54am
	Author:  danlin

  ==============================================================================
*/

#include "MainView.h"

//==============================================================================
MainView::MainView()
{
	addAndMakeVisible(toolbar);
	toolbarShadow.setOwner(&toolbar);

	addAndMakeVisible(spacer);
	addAndMakeVisible(bottomBar);

	addAndMakeVisible(sideNavbar);
    sideBarShadow.setOwner(&sideNavbar);
	sideNavbar.backButton.onClick = [this] {
		hideSideNavBar();
	};

	addButton.setImages(addIcon.getDrawable());
	addAndMakeVisible(addButton);
	addButton.toFront(true);
}

void MainView::paint(Graphics &g) {
	g.fillAll(findColour(Material::ColourIds::backgroundColorId));
	ultraschallIcon.getDrawable()->drawWithin(g, getLocalBounds().reduced(100).toFloat(), RectanglePlacement::centred, 0.2f);
}

void MainView::resized() {

	auto flexBox = FlexBox();

	flexBox.flexDirection = FlexBox::Direction::column;

	flexBox.items.add(FlexItem(toolbar).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar)).withWidth(getWidth()).withFlex(1));

	if (contentView != nullptr) {
		flexBox.items.add(FlexItem(*contentView).withWidth(getWidth()).withFlex(2));
	}
	else {
		flexBox.items.add(FlexItem(spacer).withWidth(getWidth()).withFlex(2));
	}

	flexBox.items.add(FlexItem(bottomBar).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar)).withWidth(getWidth()).withFlex(1));

	flexBox.performLayout(getLocalBounds());

	addButton.setBounds(
		getLocalBounds().getWidth() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
		getLocalBounds().getHeight() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
		int(MaterialLookAndFeel::convertDpToPixel<float>(80)),
		int(MaterialLookAndFeel::convertDpToPixel<float>(80))
	);

	if (sideBarVisible) {
		sideNavbar.setVisible(true);
        sideNavbarBackground.setBounds(getLocalBounds());
        sideNavbar.setBounds(getLocalBounds().removeFromLeft(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::NavigationDrawer)));
	}
	else {
		sideNavbar.setVisible(false);
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
    sideNavbar.toFront(false);

    auto endBounds = getLocalBounds().removeFromLeft(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::NavigationDrawer));
    auto startBounds = endBounds;
    startBounds.setPosition(-MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::NavigationDrawer), 0);
    sideNavbar.setBounds(startBounds);

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
    endBounds.setPosition(-MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::NavigationDrawer), 0);

    sideNavbarAnimator.animateComponent(
            &sideNavbar,
            endBounds,
            1.0f,
            200,
            false,
            0.8f,
            0.4f
    );

    sideBarVisible = false;
}
