#pragma once

#include "JuceHeader.h"
#include "../Material/Material.h"

class NavigationDrawerHeaderItem : public Component {
public:
    constexpr const static int height = 56;

    NavigationDrawerHeaderItem() : Component("NavigationDrawerHeaderItem") {
        setOpaque(true);
        title.setText("Soundboard", dontSendNotification);
        title.setFont(Material::Fonts::getInstance()->H6);
        addAndMakeVisible(title);
        setSize(304, height);
    }

    void paint (Graphics& g) override
    {
        g.fillAll(Material::Color::Surface::Main);
        g.setColour(Material::Color::Icons::Selected::OnSurface::Active.withAlpha(0.12f));
        g.drawLine(0, getHeight() - 1, getWidth(), getHeight() - 1);
    }

    void resized() override {
        FlexBox flexBox;
        flexBox.alignContent = FlexBox::AlignContent::center;
        flexBox.alignItems = FlexBox::AlignItems::flexStart;

        flexBox.items.add(FlexItem(title).withHeight(px(24)).withFlex(2));

        flexBox.performLayout(getLocalBounds().withTrimmedLeft(px(16)).withTrimmedRight(px(16)));
    }

    Label title;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavigationDrawerHeaderItem)

};