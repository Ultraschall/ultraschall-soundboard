#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../LookAndFeel/Material.h"

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
        setColour(ColourIds::iconOnColourId, Material::Color::Secondary::Main);
		drawableOn = this->icon.getDrawable(findColour(ColourIds::iconOnColourId));
		drawableOff = this->icon.getDrawable(findColour(ColourIds::iconOffColourId));

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

    ~NavigationDrawerItem() noexcept override = default;

    void paintButton(Graphics &g, bool isMouseOverButton, bool /*isButtonDown*/) override {
        g.fillAll(Material::Color::Surface::Main);

        auto rect = getLocalBounds().withTrimmedTop(px(4)).withTrimmedBottom(px(4)).withTrimmedLeft(px(8)).withTrimmedRight(px(8)).toFloat();

        if (getToggleState()) {
			if (drawableOn != nullptr) {
				drawableOn->drawWithin(g, rect.withTrimmedLeft(px(8.0f)).withWidth(px<float>(iconSize)).withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)), RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
			}
            g.setColour(Material::Color::Surface::Light.withAlpha(0.12f));
            g.fillRoundedRectangle(rect, 4);
            g.setColour(Colours::white);
            g.setFont(Material::Fonts::getInstance()->Body2());
            g.drawText(title, getLocalBounds().withTrimmedBottom(px(16)).withTrimmedTop(px(16)).withTrimmedLeft(px(32 + iconSize)).withTrimmedRight(px(16)), Justification::centredLeft, false);
        } else {
			if (drawableOff != nullptr) {
				drawableOff->drawWithin(g, rect.withTrimmedLeft(px(8.0f)).withWidth(px<float>(iconSize)).withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)), RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
			}
            g.setColour(Material::Color::Icons::Selected::OnSurface::Inactive);
            g.setFont(Material::Fonts::getInstance()->Body2());
            g.drawText(title, getLocalBounds().withTrimmedBottom(px(16)).withTrimmedTop(px(16)).withTrimmedLeft(px(32 + iconSize)).withTrimmedRight(px(16)), Justification::centredLeft, false);
        }

        if (isMouseOverButton)
        {
            g.setColour(Material::Color::Surface::Dark.withAlpha(0.04f));
            g.fillRoundedRectangle(rect, 4);
        }
    }

private:
    Material::Icon &icon;
    String title;
    std::unique_ptr<Drawable> drawableOn;
	std::unique_ptr<Drawable> drawableOff;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavigationDrawerItem)
};
