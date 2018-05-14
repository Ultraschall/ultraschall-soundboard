#include "SideNavbarView.h"

SideNavbarView::SideNavbarView()
{
    backButton.setImages(backIcon.getDrawable());

    addAndMakeVisible(backButton);
    addAndMakeVisible(settingsButton);
    addAndMakeVisible(importFolderButton);
}

SideNavbarView::~SideNavbarView()
{
}

void SideNavbarView::paint(Graphics &g)
{
    g.fillAll(findColour(Material::ColourIds::dialogColorId));   // clear the background
}

void SideNavbarView::resized()
{
    backButton.setBounds(
		getLocalBounds()
			.removeFromTop(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::TitleHeight))
			.removeFromRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Padding::Left))
	);

    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(importFolderButton).withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight)).withFlex(1));
    flexBox.items.add(FlexItem(settingsButton).withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight)).withFlex(1));

    flexBox.performLayout(getLocalBounds().withTrimmedTop(Material::Specs::NavigationDrawer::Standard::Dimensions::TitleHeight));
}

