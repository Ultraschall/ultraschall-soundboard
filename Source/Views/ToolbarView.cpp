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
    menuButton.setImages(menuIcon.getDrawable());
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

    flexBox.items.add(FlexItem(menuButton)
                              .withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon))
                              .withFlex(2));
    flexBox.items.add(FlexItem(spacer).withFlex(1));
    flexBox.items.add(FlexItem(viewButton)
                              .withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon))
                              .withFlex(2));

    flexBox.performLayout(getLocalBounds().withTrimmedLeft(
            MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge)).withTrimmedRight(
            MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge)));
}
