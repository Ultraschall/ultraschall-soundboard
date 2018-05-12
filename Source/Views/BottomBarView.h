#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"

class BottomBarView : public Component
{
public:
    BottomBarView();

    void paint(Graphics &) override;

    void resized() override;

    Slider gainSlider;
    DrawableButton talkoverButton = {"Talkover", DrawableButton::ImageFitted};
private:
    Material::Icon talkoverOffIcon = {BinaryData::baselinemic_none24px_svg, BinaryData::baselinemic_none24px_svgSize};
    Material::Icon talkoverOnIcon = {BinaryData::baselinemic24px_svg, BinaryData::baselinemic24px_svgSize};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BottomBarView)
};
