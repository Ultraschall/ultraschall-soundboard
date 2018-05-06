/*
  ==============================================================================

    SideNavbarView.cpp
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideNavbarView.h"

//==============================================================================
SideNavbarView::SideNavbarView() {
    addAndMakeVisible(settings);
}

SideNavbarView::~SideNavbarView() {
}

void SideNavbarView::paint(Graphics &g) {
    g.fillAll(Colours::white);   // clear the background
}

void SideNavbarView::resized() {
    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(settings).withMaxHeight(Material::convertDpToPixel<float>(this, 48)).withFlex(1));

    flexBox.performLayout(getLocalBounds().withTrimmedTop(Material::convertDpToPixel<int>(this, 64)));
}

void SideNavbarView::SideNavbarItemView::paint(Graphics &g) {
    icon->drawWithin(g, {Material::convertDpToPixel<float>(this, 16), 0, Material::convertDpToPixel<float>(this, 24),
                         float(getHeight())}, RectanglePlacement::centred, 0.87);
    g.setColour(Colours::black.withAlpha(0.87f));
    g.drawFittedText(title,
                     getLocalBounds()
                             .withTrimmedLeft(Material::convertDpToPixel<int>(this, 72))
                             .withTrimmedRight(Material::convertDpToPixel<int>(this, 16)),
                     Justification::centredLeft, 1);
}
