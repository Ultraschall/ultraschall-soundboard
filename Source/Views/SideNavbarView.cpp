/*
  ==============================================================================

    SideNavbarView.cpp
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#include "SideNavbarView.h"

//==============================================================================
SideNavbarView::SideNavbarView() {
	backIcon.setColour(Colour(224, 224, 224));
	backButton.setImages(backIcon.getDrawable());

	addAndMakeVisible(backButton);
	addAndMakeVisible(settings);
}

SideNavbarView::~SideNavbarView() {
}

void SideNavbarView::paint(Graphics &g) {
    g.fillAll(Colours::white);   // clear the background
	g.setColour(Colour(224, 224, 224));
	g.drawLine(0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar), getWidth(), MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar));
}

void SideNavbarView::resized() {
	backButton.setBounds(getLocalBounds().removeFromTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)).removeFromRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Icon)));

    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(settings).withMaxHeight(MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));

    flexBox.performLayout(getLocalBounds().withTrimmedTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)));
}

void SideNavbarView::SideNavbarItemView::paintButton(Graphics & g, bool isMouseOverButton, bool isButtonDown)
{
	auto lookAndFeel = dynamic_cast<MaterialLookAndFeel*>(&getLookAndFeel());

	if (isMouseOverButton) {
		g.fillAll(Colour(250, 250, 250));
	}
	icon->drawWithin(g, { MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::ScreenEdge), 0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Icon),
		float(getHeight()) }, RectanglePlacement::centred, 0.60);

	lookAndFeel->setFontRobotoMedium(g);
	g.setColour(Colours::black.withAlpha(0.60f));
	g.drawFittedText(title,
		getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ContentLeftMargin))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ScreenEdge)),
		Justification::centredLeft, 1);
}
