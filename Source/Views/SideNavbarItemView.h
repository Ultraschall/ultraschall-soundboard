#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"


class SideNavbarItemView : public Button {
public:
	SideNavbarItemView(String t, Material::Icon &i) : Button(t), title(t), icon(i) {};

	String title;
	Material::Icon &icon;

	virtual void paintButton(Graphics & g, bool isMouseOverButton, bool isButtonDown) override;

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarItemView)
};