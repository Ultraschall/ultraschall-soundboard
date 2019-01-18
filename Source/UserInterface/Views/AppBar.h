#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../../LookAndFeel/Material.h"
#include "../../LookAndFeel/IconButton.h"

class AppBar : public Component
{
public:
    constexpr const static int height = 56;

    AppBar() noexcept : Component("AppBar")
    {
        setOpaque(true);
        
        title.setText("Soundboard", dontSendNotification);
        title.setFont(Material::Fonts::getInstance()->H6());
        
        menuButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        addAndMakeVisible(menuButton);
        addAndMakeVisible(title);

        //shadow.setOwner(this);
        setSize(px(320), px(height));
    }

    ~AppBar() noexcept override = default;

    void paint (Graphics& g) override
    {
        g.fillAll(Material::Color::Surface::Dark);
    }

    void resized() override
    {
        FlexBox flexBox;
        flexBox.alignContent = FlexBox::AlignContent::center;
        flexBox.alignItems = FlexBox::AlignItems::flexStart;
        
        flexBox.items.add(FlexItem(px<float>(Material::IconButton::minButtonSize), px<float>(Material::IconButton::minButtonSize), menuButton));
        flexBox.items.add(FlexItem(title).withFlex(2));
        
        flexBox.performLayout(getLocalBounds());
    }

    Material::IconButton menuButton{ Material::Icons::menu };
    Label title;
private:
    //Material::Shadows::DropShadower4dp shadow;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AppBar)
};
