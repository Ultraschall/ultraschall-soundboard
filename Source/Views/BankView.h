#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "ClipView.h"

class BankView : public Component
{
public:
    BankView() {
        nextButton.setImages(nextIcon.getDrawable());
        beforeButton.setImages(beforeIcon.getDrawable());
        titleLabel.setText("Test", NotificationType::dontSendNotification);

        addAndMakeVisible(nextButton);
        addAndMakeVisible(beforeButton);
        addAndMakeVisible(titleLabel);
    }

    ~BankView() = default;

    void paint(Graphics &g) override {
        g.fillAll(getLookAndFeel().findColour(Material::ColourIds::backgroundColorId));
    }

    void resized() override {
        //FlexBox flexBox;

        //flexBox.items.add(FlexItem(beforeButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon)).withFlex(1));
        //flexBox.items.add(FlexItem(titleLabel).withFlex(2));
        //flexBox.items.add(FlexItem(nextButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon)).withFlex(1));

        //flexBox.performLayout(getLocalBounds().withBottom(Material::Size::NavigationDrawer));
    }

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
