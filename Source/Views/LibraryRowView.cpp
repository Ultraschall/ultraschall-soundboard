/*
  ==============================================================================

	LibraryRowView.cpp
	Created: 8 May 2018 3:52:09pm
	Author:  danlin

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LibraryRowView.h"
#include <filesystem>

//==============================================================================
LibraryRowView::LibraryRowView()
{
	playIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	pauseIcon.setColour(findColour(Material::ColourIds::primaryColorId));
	stopIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	settingsIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));

	loopOffIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	loopOnIcon.setColour(findColour(Material::ColourIds::primaryColorId));

	fadeInIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
	fadeOutIcon.setColour(findColour(Material::ColourIds::textSecondaryColorId));

	playButton.setImages(playIcon.getDrawable(), nullptr, nullptr, nullptr, pauseIcon.getDrawable());
	stopButton.setImages(stopIcon.getDrawable());
	settingsButton.setImages(settingsIcon.getDrawable());
	loopButton.setImages(loopOffIcon.getDrawable(), nullptr, nullptr, nullptr, loopOnIcon.getDrawable());
	fadeButton.setImages(fadeInIcon.getDrawable(), nullptr, nullptr, nullptr, fadeOutIcon.getDrawable());

	addAndMakeVisible(playButton);
	addAndMakeVisible(stopButton);
	addAndMakeVisible(settingsButton);
	addAndMakeVisible(loopButton);
	addAndMakeVisible(fadeButton);
}

LibraryRowView::~LibraryRowView()
{
	if (audioThumbnail != nullptr)
	{
		audioThumbnail->removeChangeListener(this);
	}
}

void LibraryRowView::paint(Graphics& g)
{
	g.fillAll(findColour(Material::ColourIds::dialogColorId));
	g.setColour(findColour(Material::ColourIds::dividerColorId));
	g.drawLine(0, getHeight() - 1, getWidth(), getHeight() - 1);

	//if (audioThumbnail != nullptr)
	//{
	//	if (audioThumbnail->getTotalLength() > 0.0) {
	//		audioThumbnail->drawChannel(g, getLocalBounds().reduced(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge)), 0, audioThumbnail->getTotalLength(), 1, 1.0f);
	//	}
	//}

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
	const auto iconSize = MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon);
	FlexBox flexBox;

	flexBox.items.add(FlexItem(settingsButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(loopButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(spacer).withFlex(2));
	flexBox.items.add(FlexItem(fadeButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(stopButton).withMaxWidth(iconSize).withFlex(1));
	flexBox.items.add(FlexItem(playButton).withMaxWidth(iconSize).withFlex(1));

	flexBox.performLayout(
		getLocalBounds()
		.removeFromBottom(iconSize)
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge))
	);
}
