#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class SideNavbarView : public Component {
public:
    SideNavbarView();

    ~SideNavbarView();

    void paint(Graphics &) override;

    void resized() override;

	SideNavbarItemView settingsButton{ "Settings", settingsIcon };
	DrawableButton backButton{ "Back", DrawableButton::ButtonStyle::ImageFitted };
private:

    Material::Icon settingsIcon = {BinaryData::baselinesettings20px_svg, BinaryData::baselinesettings20px_svgSize};
	Material::Icon backIcon = { BinaryData::baselinenavigate_before24px_svg, BinaryData::baselinenavigate_before24px_svgSize };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
