#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class BottomBarView : public Component, public ChangeListener
{
public:
	BottomBarView() {
		addAndMakeVisible(spacer);

		gainSlider.setNormalisableRange(NormalisableRange<double>(0.0, 1.0));
		gainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);

		addAndMakeVisible(gainSlider);
		addAndMakeVisible(talkoverButton);
	}

	void paint(Graphics &g) override {
		g.fillAll(findColour(Material::appBarColorId));
		g.setColour(findColour(Material::dividerColorId));
		g.drawLine(0, 0, getWidth(), 0);
	}

	void resized() override {
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

	Slider gainSlider;
	Material::IconToggleButton talkoverButton{ 
		"Talkover", 
		BinaryData::baselinemic_none24px_svg, 
		BinaryData::baselinemic_none24px_svgSize, 
		BinaryData::baselinemic24px_svg, 
		BinaryData::baselinemic24px_svgSize, 
		findColour(Material::ColourIds::primaryColorId), 
		findColour(Material::ColourIds::primaryColorId) 
	};

	Material::IconButton nextButton{ 
		"Next", 
		BinaryData::baselinenavigate_next24px_svg, 
		BinaryData::baselinenavigate_next24px_svgSize,
		findColour(Material::ColourIds::textSecondaryColorId)
	};
	Material::IconButton beforeButton{ 
		"Before", 
		BinaryData::baselinenavigate_before24px_svg, 
		BinaryData::baselinenavigate_before24px_svgSize,
		findColour(Material::ColourIds::textSecondaryColorId)
	};

	void showNavigation() {
		if (navigationVisible == true) return;

		addAndMakeVisible(nextButton);
		addAndMakeVisible(beforeButton);

		Desktop::getInstance().getAnimator().fadeIn(&nextButton, 200);
		Desktop::getInstance().getAnimator().fadeIn(&beforeButton, 200);

		navigationVisible = true;

		resized();
	}
	void hideNavigation() {
		if (navigationVisible == false) return;

		Desktop::getInstance().getAnimator().fadeOut(&nextButton, 200);
		Desktop::getInstance().getAnimator().fadeOut(&beforeButton, 200);

		navigationVisible = false;
	}

	virtual void changeListenerCallback(ChangeBroadcaster * source) override {
		if (navigationVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&nextButton))
		{
			removeChildComponent(&nextButton);
		}
		if (navigationVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&beforeButton))
		{
			removeChildComponent(&beforeButton);
		}
	}
private:

	Component spacer;

	bool navigationVisible{ false };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BottomBarView)
};
