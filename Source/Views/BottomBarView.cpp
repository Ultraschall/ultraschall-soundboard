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
	gainSlider.setColour(Slider::trackColourId, Colour(211, 47, 47));
	gainSlider.setColour(Slider::thumbColourId, Colour(211, 47, 47));
	gainSlider.setColour(Slider::backgroundColourId, Colour(225, 225, 225));
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
    g.fillAll (Colour(245, 245, 245));
}

void BottomBarView::resized()
{
	FlexBox flexBox;

	flexBox.items.add(FlexItem(gainSlider).withFlex(1));
	flexBox.items.add(FlexItem(talkoverButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel<float>(48)).withFlex(2));

	flexBox.performLayout(getLocalBounds().withTrimmedRight(getWidth() * 0.5f));
}
