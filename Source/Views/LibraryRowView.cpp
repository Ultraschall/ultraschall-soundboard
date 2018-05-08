/*
  ==============================================================================

    LibraryRowView.cpp
    Created: 8 May 2018 3:52:09pm
    Author:  danlin

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LibraryRowView.h"

//==============================================================================
LibraryRowView::LibraryRowView()
{
	setInterceptsMouseClicks(true, true);

	playIcon.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	stopIcon.setColour(findColour(Material::ColourIds::textPrimaryColorId));

	playButton.setImages(playIcon.getDrawable(), nullptr, nullptr, nullptr, pauseIcon.getDrawable());
	stopButton.setImages(stopIcon.getDrawable());

	selectionButton.setColour(ToggleButton::ColourIds::tickColourId, findColour(Material::ColourIds::primaryColorId));
	selectionButton.setColour(ToggleButton::ColourIds::tickDisabledColourId, findColour(Material::ColourIds::primaryColorId));
	selectionButton.setButtonText("");
	selectionButton.setEnabled(true);
	addAndMakeVisible(selectionButton);
	selectionButton.onClick = [this] {
		selectionButton.setToggleState(!selectionButton.getToggleState(), NotificationType::dontSendNotification);
	};

	addAndMakeVisible(playButton);
	addAndMakeVisible(stopButton);

}

LibraryRowView::~LibraryRowView()
{
}

void LibraryRowView::paint (Graphics& g)
{
	g.fillAll(findColour(Material::ColourIds::dialogColorId));
	g.setColour(findColour(Material::ColourIds::dividerColorId));
	g.drawLine(0, getHeight(), getWidth(), getHeight());

	g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	g.drawText(title, getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(16)), Justification::centredLeft);

	//g.setColour(findColour(Material::ColourIds::dividerColorId));
	//g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166)));
	//g.setColour(findColour(Material::ColourIds::primaryColorId));
	//g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166 * progress)));
}

void LibraryRowView::resized()
{
	FlexBox flexBox;

	flexBox.items.add(FlexItem(selectionButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::IconTouch)).withFlex(1));
	flexBox.items.add(FlexItem(spacer).withFlex(2));
	flexBox.items.add(FlexItem(stopButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::IconTouch)).withFlex(1));
	flexBox.items.add(FlexItem(playButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::IconTouch)).withFlex(1));

	flexBox.performLayout(getLocalBounds().reduced(Material::Size::SpaceBetweenContentAreas));
}
