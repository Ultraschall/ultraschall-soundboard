/*
  ==============================================================================

    ClipView.cpp
    Created: 29 Apr 2018 12:22:06pm

  ==============================================================================
*/

#include "ClipView.h"

ClipView::ClipView() {
    playButton.reset(new DrawableButton("Play / Pause Button", DrawableButton::ButtonStyle::ImageFitted));
    playIcon.reset(new SvgIcon(BinaryData::ic_play_circle_outline_white_48px_svg, BinaryData::ic_play_circle_outline_white_48px_svgSize));
    pauseIcon.reset(new SvgIcon(BinaryData::ic_pause_circle_outline_white_48px_svg, BinaryData::ic_pause_circle_outline_white_48px_svgSize));

    setPaused();

    addAndMakeVisible(playButton.get());
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
    flexBox.items.add(FlexItem(*playButton).withFlex(1).withHeight(height));
    flexBox.items.add(FlexItem(getWidth() / 4.0f, height));

    flexBox.performLayout(getLocalBounds());
}

void ClipView::setPaused() {
    playButton->setImages(playIcon->getDrawable());
}

void ClipView::setPlaying() {
    playButton->setImages(pauseIcon->getDrawable());
}
