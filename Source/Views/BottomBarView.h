#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"

class BottomBarView : public Component, public ChangeListener
{
public:
	BottomBarView();

	void paint(Graphics &) override;

	void resized() override;

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

	void showNavigation();
	void hideNavigation();

	virtual void changeListenerCallback(ChangeBroadcaster * source) override;
private:

	Component spacer;

	bool navigationVisible{ false };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BottomBarView)
};
