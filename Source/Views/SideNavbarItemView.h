#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class SideNavbarItem : public Button
{
public:
    SideNavbarItem(const String &title, const char *data, const size_t size, const Colour &colour = Colours::black)
        : Button(title), text(title), icon(data, size, colour)
    {
    }

    void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override;

private:
    String text;
    Material::Icon icon;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarItem)
};

class SideNavbarTitle : public Component {
public:
    explicit SideNavbarTitle(const String &title) : Component(title), text(title) {
	}

	void paint(Graphics &g) override;

private:
    String text;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarTitle)
};

class SideNavbarSeperator : public Component {
public:
	SideNavbarSeperator() = default;

    void paint(Graphics &g) override;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarSeperator)
};