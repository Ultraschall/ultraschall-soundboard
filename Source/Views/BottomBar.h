#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

class BottomBar : public Component {
public:
    constexpr const static int height = 56;

    BottomBar() : Component("BottomBar") {
#if LIVE_MOCK
        setLookAndFeel(new MaterialLookAndFeel());
#endif
        setOpaque(true);
        talkoverButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        muteButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Inactive);

        addAndMakeVisible(talkoverButton);
        addAndMakeVisible(volumeSlider);
        addAndMakeVisible(muteButton);

        //shadow.setOwner(this);
        setSize(320, height);
    }

    ~BottomBar() override = default;

    void paint(Graphics &g) override {
        g.fillAll(Material::Color::Surface::Dark);
        g.setColour(Material::Color::Icons::Selected::OnSurface::Active.withAlpha(0.12f));
        g.drawLine(0, 0, getWidth(), 0);
    }

    void resized() override {
        FlexBox flexBox;
        flexBox.alignContent = FlexBox::AlignContent::center;
        flexBox.alignItems = FlexBox::AlignItems::flexStart;

        flexBox.items.add(FlexItem(px(Material::IconButton::minButtonSize), px(Material::IconButton::minButtonSize), talkoverButton));
        flexBox.items.add(FlexItem(volumeSlider).withFlex(2));
        flexBox.items.add(FlexItem(px(Material::IconButton::minButtonSize), px(Material::IconButton::minButtonSize), muteButton));

        flexBox.performLayout(getLocalBounds().withTrimmedRight(static_cast<int>(getWidth() * 0.5) - px(Material::IconButton::minButtonSize)));
    }

    Material::IconButton talkoverButton{Material::Icons::mic_none};
    Slider volumeSlider{Slider::SliderStyle::LinearHorizontal, Slider::TextEntryBoxPosition::NoTextBox};
    Material::IconButton muteButton{Material::Icons::volume_up};
private:
    //Material::Shadows::DropShadower4dp shadow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBar)
};
