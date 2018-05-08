/*
  ==============================================================================

    BottomBarView.cpp
    Created: 6 May 2018 6:04:55am
    Author:  danie

  ==============================================================================
*/

#include "BottomBarView.h"

//==============================================================================
BottomBarView::BottomBarView()
{
	gainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	gainSlider.setColour(Slider::trackColourId, findColour(Material::ColourIds::primaryColorId));
	gainSlider.setColour(Slider::thumbColourId, findColour(Material::ColourIds::primaryColorId));
    gainSlider.setColour(Slider::backgroundColourId, findColour(Material::ColourIds::dividerColorId));
    
    talkoverOnIcon.setColour(findColour(Material::ColourIds::primaryColorId));
    talkoverOffIcon.setColour(findColour(Material::ColourIds::primaryColorId));

	talkoverButton.setImages(
		talkoverOffIcon.getDrawable(),
		nullptr, nullptr, nullptr,
		talkoverOnIcon.getDrawable()
	);
	talkoverButton.setColour(DrawableButton::backgroundOnColourId, Colours::transparentWhite);
    
	addAndMakeVisible(gainSlider);
	addAndMakeVisible(talkoverButton);

	talkoverButton.onClick = [this] {
		talkoverButton.setToggleState(!talkoverButton.getToggleState(), NotificationType::dontSendNotification);
	};
}

BottomBarView::~BottomBarView()
{
}

void BottomBarView::paint (Graphics& g)
{
    g.fillAll (findColour(Material::ColourIds::appBarColorId));
    g.setColour(findColour(Material::ColourIds::dividerColorId));
    g.drawLine(0, 0, getWidth(), 0);
}

void BottomBarView::resized()
{
	FlexBox flexBox;

	flexBox.items.add(FlexItem(gainSlider).withFlex(1));
	flexBox.items.add(FlexItem(talkoverButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel<float>(48)).withFlex(2));

	flexBox.performLayout(getLocalBounds().withTrimmedRight(getWidth() * 0.5f));
}
