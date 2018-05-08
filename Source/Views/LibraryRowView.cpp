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
//	playButton.setColour(DrawableButton::backgroundColourId, Colours::magenta);
//	settingsButton.setColour(DrawableButton::backgroundColourId, Colours::magenta);
//	stopButton.setColour(DrawableButton::backgroundColourId, Colours::magenta);

	playIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	stopIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	settingsIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));


	playButton.setImages(playIcon.getDrawable(), nullptr, nullptr, nullptr, pauseIcon.getDrawable());
	stopButton.setImages(stopIcon.getDrawable());
	settingsButton.setImages(settingsIcon.getDrawable());

	addAndMakeVisible(playButton);
	addAndMakeVisible(stopButton);
	addAndMakeVisible(settingsButton);

}

LibraryRowView::~LibraryRowView()
{
}

void LibraryRowView::paint (Graphics& g)
{
	g.fillAll(findColour(Material::ColourIds::dialogColorId));
	g.setColour(findColour(Material::ColourIds::dividerColorId));
	g.drawLine(0, getHeight(), getWidth(), getHeight());

//    g.setColour(findColour(Material::ColourIds::primaryColorId));
//	g.fillRect(getLocalBounds().withTrimmedBottom(iconBarSize));

	g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	g.setFont(14);
	g.drawText(title, getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge)).withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge)), Justification::topLeft);

	//g.setColour(findColour(Material::ColourIds::dividerColorId));
	//g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166)));
	//g.setColour(findColour(Material::ColourIds::primaryColorId));
	//g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166 * progress)));
}

void LibraryRowView::resized()
{
	auto iconSize = MaterialLookAndFeel::convertDpToPixel(30);
	FlexBox flexBox;

	flexBox.items.add(FlexItem(settingsButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(spacer).withFlex(2));
	flexBox.items.add(FlexItem(stopButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(playButton).withMaxWidth(iconSize).withFlex(1));

	flexBox.performLayout(
			getLocalBounds()
					.removeFromBottom(iconSize)
					.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge))
					.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge))
	);
}
