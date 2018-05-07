/*
  ==============================================================================

    ClipView.cpp
    Created: 29 Apr 2018 12:22:06pm

  ==============================================================================
*/

#include "ClipView.h"

ClipView::ClipView() {
	playButton.setImages(pauseIcon.getDrawable(), nullptr, nullptr, nullptr, playIcon.getDrawable());
    addAndMakeVisible(playButton);
}

ClipView::~ClipView() {

}

void ClipView::paint(Graphics &g) {
    auto border = g.getClipBounds().reduced(1).toFloat();
    auto cell   = border.reduced(2).toFloat();

    g.setColour(Colours::black);
    g.fillAll();

    g.setColour(Colours::whitesmoke);
    g.fillRect(border);
}

void ClipView::resized() {
    auto height = float(getHeight());


    auto flexBox = FlexBox();
    flexBox.items.add(FlexItem(getWidth() / 4.0f, height));
    flexBox.items.add(FlexItem(playButton).withFlex(1).withHeight(height));
    flexBox.items.add(FlexItem(getWidth() / 4.0f, height));

    flexBox.performLayout(getLocalBounds());
}

