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
    backIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    backButton.setImages(backIcon.getDrawable());
    
    addAndMakeVisible(backButton);
    addAndMakeVisible(importButton);
	addAndMakeVisible(settingsButton);
}

SideNavbarView::~SideNavbarView() {
}

void SideNavbarView::paint(Graphics &g) {
	g.fillAll(findColour(Material::ColourIds::dialogColorId));   // clear the background
	g.setColour(findColour(Material::ColourIds::dividerColorId));
	g.drawLine(0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar), getWidth(), MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar));
}

void SideNavbarView::resized() {
    backButton.setBounds(getLocalBounds().removeFromTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)).removeFromRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Icon)));

    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(importButton).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));
    flexBox.items.add(FlexItem(settingsButton).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));

    flexBox.performLayout(getLocalBounds().withTrimmedTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)));
}

void SideNavbarView::SideNavbarItemView::paintButton(Graphics & g, bool isMouseOverButton, bool isButtonDown)
{
    auto material = dynamic_cast<MaterialLookAndFeel*>(&getLookAndFeel());
	if (isMouseOverButton) {
		g.fillAll(findColour(Material::ColourIds::dividerColorId));
	}
	icon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	icon.getDrawable()->drawWithin(g, { MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::ScreenEdge), 0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Icon),
		float(getHeight()) }, RectanglePlacement::centred, 1);
    g.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    material->setFontRobotoMedium(g);
	g.drawFittedText(title,
		getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ContentLeftMargin))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ScreenEdge)),
		Justification::centredLeft, 1);
}
