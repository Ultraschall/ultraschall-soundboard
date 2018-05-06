/*
  ==============================================================================

    ToolbarView.cpp
    Created: 6 May 2018 4:12:25am
    Author:  danie

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ToolbarView.h"

//==============================================================================
ToolbarView::ToolbarView()
{
	menuButton.setImages(menuIcon.getDrawable());
	viewButton.setImages(libraryIcon.getDrawable(), nullptr, nullptr, nullptr, bankIcon.getDrawable());
	addAndMakeVisible(menuButton);
	addAndMakeVisible(viewButton);
	addAndMakeVisible(spacer);
}

ToolbarView::~ToolbarView()
{
}

void ToolbarView::paint (Graphics& g)
{
    g.fillAll (Colour(211, 47, 47));
}

void ToolbarView::resized()
{
	FlexBox flexBox;

	flexBox.flexDirection = FlexBox::Direction::row;

	flexBox.items.add(FlexItem(menuButton).withMaxWidth(iconSize).withFlex(2));
	flexBox.items.add(FlexItem(spacer).withFlex(1));
	flexBox.items.add(FlexItem(viewButton).withMaxWidth(iconSize).withFlex(2));

	flexBox.performLayout(getLocalBounds().withTrimmedLeft(padding).withTrimmedRight(padding));
}
