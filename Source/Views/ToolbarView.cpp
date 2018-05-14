/*
  ==============================================================================

	ToolbarView.cpp
	Created: 6 May 2018 4:12:25am
	Author:  danie

  ==============================================================================
*/

#include "ToolbarView.h"

//==============================================================================
ToolbarView::ToolbarView()
{
	menuButton.setEdgeIndent(0);
	menuButton.setImages(menuIcon.getDrawable());

	viewButton.setEdgeIndent(0);
	viewButton.setImages(libraryIcon.getDrawable(), nullptr, nullptr, nullptr, bankIcon.getDrawable());
	viewButton.setColour(DrawableButton::ColourIds::backgroundOnColourId, Colours::transparentWhite);

	addAndMakeVisible(menuButton);
	addAndMakeVisible(viewButton);
	addAndMakeVisible(spacer);
}

ToolbarView::~ToolbarView()
{
}

void ToolbarView::paint(Graphics &g)
{
	g.fillAll(findColour(Material::primaryColorId));
}

void ToolbarView::resized()
{
	FlexBox flexBox;

	flexBox.flexDirection = FlexBox::Direction::row;
	flexBox.alignContent = FlexBox::AlignContent::center;

	flexBox.items.add(FlexItem(menuButton)
		.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withFlex(2));
	flexBox.items.add(FlexItem(spacer).withFlex(1));
	flexBox.items.add(FlexItem(viewButton)
		.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withFlex(2));

	flexBox.performLayout(
		getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Padding::Left))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Padding::Right))
	);
}
