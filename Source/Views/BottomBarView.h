/*
  ==============================================================================

    BottomBarView.h
    Created: 6 May 2018 6:04:55am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

//==============================================================================
/*
*/
class BottomBarView    : public Component
{
public:
    BottomBarView();
    ~BottomBarView();

    void paint (Graphics&) override;
    void resized() override;

	Slider gainSlider;
	DrawableButton talkoverButton = { "Talkover", DrawableButton::ImageFitted };
private:
	Material::Icon talkoverOffIcon = { BinaryData::ic_mic_none_black_48px_svg, BinaryData::ic_mic_none_black_48px_svgSize };
	Material::Icon talkoverOnIcon = { BinaryData::ic_mic_black_48px_svg, BinaryData::ic_mic_black_48px_svgSize };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBarView)
};
