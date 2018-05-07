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

//==============================================================================
/*
*/
class SideNavbarView : public Component {
public:
    SideNavbarView();

    ~SideNavbarView();

    void paint(Graphics &) override;

    void resized() override;

private:
    class SideNavbarItemView : public Button {
    public:
		SideNavbarItemView(String t, Material::Icon &i) : title(t), icon(i), Button(t) {};

        String title;
		Material::Icon &icon;

		// Geerbt über Button
		virtual void paintButton(Graphics & g, bool isMouseOverButton, bool isButtonDown) override;
	};

    Material::Icon settingsIcon = {BinaryData::ic_mic_black_48px_svg, BinaryData::ic_mic_black_48px_svgSize};
	Material::Icon backIcon = { BinaryData::ic_keyboard_arrow_left_black_48px_svg, BinaryData::ic_keyboard_arrow_left_black_48px_svgSize };
public:
	SideNavbarItemView settings{ "Settings", settingsIcon };
	DrawableButton backButton{ "Back", DrawableButton::ButtonStyle::ImageFitted };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
