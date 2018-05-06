/*
  ==============================================================================

    BottomBarView.h
    Created: 6 May 2018 6:04:55am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "DrawingTools.h"

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

private:
	Slider gainSlider;
	float iconSize = { Material::convertDpToPixel<float>(48) };
	SvgIcon talkoverOffIcon = { BinaryData::ic_mic_none_black_48px_svg, BinaryData::ic_mic_none_black_48px_svgSize };
	SvgIcon talkoverOnIcon = { BinaryData::ic_mic_black_48px_svg, BinaryData::ic_mic_black_48px_svgSize };
	DrawableButton talkoverButton = { "Talkover", DrawableButton::ImageFitted };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBarView)
};
