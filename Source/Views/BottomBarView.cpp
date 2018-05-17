#include "BottomBarView.h"

BottomBarView::BottomBarView()
{
	addAndMakeVisible(spacer);

	gainSlider.setNormalisableRange(NormalisableRange<double>(0.0, 1.0));
    gainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);

	addAndMakeVisible(gainSlider);
    addAndMakeVisible(talkoverButton);
}

void BottomBarView::paint(Graphics &g)
{
    g.fillAll(findColour(Material::ColourIds::appBarColorId));
    g.setColour(findColour(Material::ColourIds::dividerColorId));
    g.drawLine(0, 0, getWidth(), 0);
}

void BottomBarView::resized()
{
    FlexBox flexBox;

	flexBox.flexDirection = FlexBox::Direction::row;
	flexBox.alignContent = FlexBox::AlignContent::center;

    flexBox.items.add(FlexItem(gainSlider)
							.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width))
							.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
							.withFlex(1));
    flexBox.items.add(FlexItem(talkoverButton)
							.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
							.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
                            .withFlex(2));
	flexBox.items.add(FlexItem(spacer).withFlex(1));
	if (navigationVisible)
	{
		flexBox.items.add(FlexItem(beforeButton)
			.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
			.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
			.withFlex(2));
		flexBox.items.add(FlexItem(nextButton)
			.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
			.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
			.withFlex(2));
	}

    flexBox.performLayout(getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Left))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Right))
	);
}

void BottomBarView::showNavigation()
{
	if (navigationVisible == true) return;
	
	addAndMakeVisible(nextButton);
	addAndMakeVisible(beforeButton);

	Desktop::getInstance().getAnimator().fadeIn(&nextButton, 200);
	Desktop::getInstance().getAnimator().fadeIn(&beforeButton, 200);

	navigationVisible = true;

	resized();
}

void BottomBarView::hideNavigation()
{
	if (navigationVisible == false) return;

	Desktop::getInstance().getAnimator().fadeOut(&nextButton, 200);
	Desktop::getInstance().getAnimator().fadeOut(&beforeButton, 200);

	navigationVisible = false;
}

void BottomBarView::changeListenerCallback(ChangeBroadcaster * source)
{
	if (navigationVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&nextButton))
	{
		removeChildComponent(&nextButton);
	}
	if (navigationVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&beforeButton))
	{
		removeChildComponent(&beforeButton);
	}
}
