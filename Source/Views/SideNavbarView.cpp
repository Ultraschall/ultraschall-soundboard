/*
  ==============================================================================

    SideNavbarView.cpp
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#include "SideNavbarView.h"

//==============================================================================
SideNavbarView::SideNavbarView() {
	addAndMakeVisible(backButton);
	addAndMakeVisible(settings);
}

SideNavbarView::~SideNavbarView() {
}

void SideNavbarView::paint(Graphics &g) {
	g.fillAll(findColour(Material::ColourIds::dialogColorId));   // clear the background
	g.setColour(findColour(Material::ColourIds::dividerColorId));
	g.drawLine(0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar), getWidth(), MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar));
}

void SideNavbarView::resized() {
	backIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	backButton.setImages(backIcon.getDrawable());

	backButton.setBounds(getLocalBounds().removeFromTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)).removeFromRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Icon)));

    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(settings).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));

    flexBox.performLayout(getLocalBounds().withTrimmedTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)));
}

void SideNavbarView::SideNavbarItemView::paintButton(Graphics & g, bool isMouseOverButton, bool isButtonDown)
{
	if (isMouseOverButton) {
		g.fillAll(findColour(Material::ColourIds::dividerColorId));
	}
	icon.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	icon.getDrawable()->drawWithin(g, { MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::ScreenEdge), 0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Icon),
		float(getHeight()) }, RectanglePlacement::centred, 0.60);

	g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	g.drawFittedText(title,
		getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ContentLeftMargin))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ScreenEdge)),
		Justification::centredLeft, 1);
}
