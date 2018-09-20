#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Material/Material.h"

class BottomBar : public Component {
public:
    constexpr const static int height = 56;

    BottomBar() noexcept : Component("BottomBar") {
#if LIVE_MOCK
        setLookAndFeel(new MaterialLookAndFeel());
#endif
        setOpaque(true);

        talkoverButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        talkoverButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);

        muteButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        muteButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);

        volumeSlider.setRange (0, 1);

        addAndMakeVisible(talkoverButton);
        addAndMakeVisible(volumeSlider);
        addAndMakeVisible(muteButton);

        //shadow.setOwner(this);
        setSize(320, height);
    }

    ~BottomBar() noexcept override = default;

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

    Material::IconToggleButton talkoverButton{
        Material::Icons::mic_none,
        Material::Icons::mic
    };
    Slider volumeSlider{Slider::SliderStyle::LinearHorizontal, Slider::TextEntryBoxPosition::NoTextBox};
    Material::IconToggleButton muteButton{
            Material::Icons::volume_up,
            Material::Icons::volume_off
    };
private:
    //Material::Shadows::DropShadower4dp shadow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BottomBar)
};
