#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class ClipView : public Component
{
public:
    explicit ClipView() {
        playButton.setImages(pauseIcon.getDrawable(), nullptr, nullptr, nullptr, playIcon.getDrawable());
        addAndMakeVisible(playButton);
    }

    ~ClipView() = default;

    void paint(Graphics &g) override {
        auto border = g.getClipBounds().reduced(1).toFloat();
        auto cell = border.reduced(2).toFloat();
        
        g.setColour(Colours::black);
        g.fillAll();
        
        g.setColour(Colours::whitesmoke);
        g.fillRect(border);
    }

    void resized() override {
        auto height = float(getHeight());
        
        
        auto flexBox = FlexBox();
        flexBox.items.add(FlexItem(getWidth() / 4.0f, height));
        flexBox.items.add(FlexItem(playButton).withFlex(1).withHeight(height));
        flexBox.items.add(FlexItem(getWidth() / 4.0f, height));
        
        flexBox.performLayout(getLocalBounds());
    }

    DrawableButton playButton{"Play / Pause Button", DrawableButton::ButtonStyle::ImageFitted};
private:
    Material::Icon playIcon{BinaryData::baselineplay_arrow24px_svg, BinaryData::baselineplay_arrow24px_svgSize};
    Material::Icon pauseIcon{BinaryData::baselinepause24px_svg, BinaryData::baselinepause24px_svgSize};

    enum ClipState
    {
        isIdle,
        isPlaying,
        isLooping,
        isFading
    };

    ClipState state;
    float progress;
public:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClipView)
};
