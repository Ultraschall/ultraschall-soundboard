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

    void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override {
        const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
        if (isMouseOverButton)
        {
            g.setColour(findColour(Material::ColourIds::dividerColorId));
            g.fillRoundedRectangle(getLocalBounds().reduced(MaterialLookAndFeel::convertDpToPixel(8)).toFloat(), MaterialLookAndFeel::convertDpToPixel(4.0f));
        }
        
        icon.getDrawable()->drawWithin(g, {
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::NavigationDrawer::Modal::Padding::Left),
            0.0f,
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::NavigationDrawer::Modal::Dimensions::Icon),
            float(getHeight())
        }, RectanglePlacement::onlyReduceInSize, 1);
        
        g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
        g.setFont(Font(material->robotoCondensed_Bold));
        g.setFont(MaterialLookAndFeel::convertDpToPixel(14));
        g.drawText(text,
                   getLocalBounds()
                   .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Padding::TextLeft)),
                   Justification::centredLeft);
    }

private:
    String text;
    Material::Icon icon;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarItem)
};

class SideNavbarTitle : public Component {
public:
    explicit SideNavbarTitle(const String &title) : Component(title), text(title) {
	}

    void paint(Graphics &g) override {
        const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
        auto font = Font(material->robotoCondensed_Regular);
        
        g.setColour(findColour(Material::textSecondaryColorId));
        g.setFont(font);
        g.setFont(MaterialLookAndFeel::convertDpToPixel(14));
        g.drawText(text, getLocalBounds()
                   .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Padding::Left))
                   .withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Bottom)), Justification::bottomLeft);
    }

private:
    String text;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarTitle)
};

class SideNavbarSeperator : public Component {
public:
	SideNavbarSeperator() = default;

    void paint(Graphics &g) override {
        g.setColour(findColour(Material::ColourIds::dividerColorId));
        auto y = getHeight() * 0.5f;
        g.drawLine(0, y, getWidth(), y);
    }

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarSeperator)
};
