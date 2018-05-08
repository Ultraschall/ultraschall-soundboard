/*
  ==============================================================================

    SideNavbarView.h
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

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

	SideNavbarItemView importButton{ "Import Folder", importIcon };
	SideNavbarItemView settingsButton{ "Settings", settingsIcon };
	DrawableButton backButton{ "Back", DrawableButton::ButtonStyle::ImageFitted };
private:

    Material::Icon settingsIcon = {BinaryData::ic_settings_white_48px_svg, BinaryData::ic_settings_white_48px_svgSize};
    Material::Icon importIcon = {BinaryData::ic_folder_open_white_48px_svg, BinaryData::ic_folder_open_white_48px_svgSize};
	Material::Icon backIcon = { BinaryData::ic_keyboard_arrow_left_black_48px_svg, BinaryData::ic_keyboard_arrow_left_black_48px_svgSize };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
