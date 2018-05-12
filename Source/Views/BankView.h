#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "ClipView.h"

class BankView : public Component
{
public:
    BankView();

    ~BankView();

    void paint(Graphics &) override;

    void resized() override;

    DrawableButton nextButton{"Next", DrawableButton::ImageFitted};
    DrawableButton beforeButton{"Previous", DrawableButton::ImageFitted};
    Label titleLabel{"Bank"};
private:
    Material::Icon nextIcon{BinaryData::baselinenavigate_next24px_svg,
                            BinaryData::baselinenavigate_next24px_svgSize,
                            findColour(Material::primaryColorId)};
    Material::Icon beforeIcon{BinaryData::baselinenavigate_before24px_svg,
                              BinaryData::baselinenavigate_before24px_svgSize,
                              findColour(Material::primaryColorId)};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankView)
};
