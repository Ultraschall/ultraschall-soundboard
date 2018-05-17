#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class SideNavbarItemView : public Button
{
public:
    SideNavbarItemView(const String title, Material::Icon &icon) : Button(title), title(title), icon(icon)
    {
    };

    String title;
    Material::Icon &icon;

    virtual void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarItemView)
};

class SideNavbarTitleItemView : public Component {
public:
	SideNavbarTitleItemView(const String name, const String text) : Component(name), text(text) {
		const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
		font = Font(material->roboto_Medium);
	}

	void paint(Graphics &g) override
	{
		g.setFont(font);
		g.setFont(MaterialLookAndFeel::convertDpToPixel(20));
		g.drawText(text, getLocalBounds()
			.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Padding::Left))
			.withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Bottom)), Justification::bottomLeft);
	}
private:
	String text;
	Font font;
};