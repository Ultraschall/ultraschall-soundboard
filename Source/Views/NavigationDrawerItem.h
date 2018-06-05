#pragma once

#include "JuceHeader.h"
#include "../Material/Material.h"

class NavigationDrawerItem : public Button {
public:
    constexpr const static int height = 48;
    constexpr const static int iconSize = 24;

    enum ColourIds {
        iconOffColourId = 0x900001,
        iconOnColourId  = 0x900002
    };

    NavigationDrawerItem(Material::Icon &icon, String title) : Button("NavigationDrawerItem"), icon(icon), title(title) {
        setOpaque(true);
        setColour(ColourIds::iconOffColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        setColour(ColourIds::iconOnColourId, Material::Color::Primary::_700);
        onStateChange = [this] {
            if (getToggleState()) {
                drawable.reset(this->icon.getDrawable(findColour(ColourIds::iconOnColourId)));
            } else {
                drawable.reset(this->icon.getDrawable(findColour(ColourIds::iconOffColourId)));
            }
            repaint();
        };
        setSize(304, height);
    }

#if LIVE_MOCK
    NavigationDrawerItem() : NavigationDrawerItem(Material::Icons::mic_none, "Live Mock Title")
    {
        onClick = [this] {
            setToggleState(!getToggleState(), sendNotification);
        };
    }
#endif

    ~NavigationDrawerItem() override {
    }

    void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override {
        g.fillAll(Material::Color::Surface::Main);

        auto rect = getLocalBounds().withTrimmedTop(px(4)).withTrimmedBottom(px(4)).withTrimmedLeft(px(8)).withTrimmedRight(px(8)).toFloat();

        if (drawable != nullptr) {
            drawable->drawWithin(g, rect.withTrimmedLeft(px(8)).withWidth(iconSize).withSizeKeepingCentre(iconSize, iconSize), RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
        }

        if (getToggleState()) {
            g.setColour(Material::Color::Primary::_700.withAlpha(0.12f));
            g.fillRoundedRectangle(rect, 4);
            g.setColour(Material::Color::Primary::Main);
            g.setFont(Material::Fonts::getInstance()->Body2);
            g.drawText(title, getLocalBounds().withTrimmedBottom(px(16)).withTrimmedTop(px(16)).withTrimmedLeft(px(32 + iconSize)).withTrimmedRight(px(16)), Justification::centredLeft, false);
        } else {
            g.setColour(Material::Color::Icons::Selected::OnSurface::Inactive);
            g.setFont(Material::Fonts::getInstance()->Body2);
            g.drawText(title, getLocalBounds().withTrimmedBottom(px(16)).withTrimmedTop(px(16)).withTrimmedLeft(px(32 + iconSize)).withTrimmedRight(px(16)), Justification::centredLeft, false);
        }

        if (isMouseOverButton)
        {
            g.setColour(Material::Color::Surface::Dark.withAlpha(0.04f));
            g.fillRoundedRectangle(rect, 4);
        }
    }

    void colourChanged() override {
        if (getToggleState()) {
            drawable.reset(icon.getDrawable(findColour(ColourIds::iconOnColourId)));
        } else {
            drawable.reset(icon.getDrawable(findColour(ColourIds::iconOffColourId)));
        }
    }

private:
    Material::Icon &icon;
    String title;
    std::unique_ptr<Drawable> drawable;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavigationDrawerItem)
};
