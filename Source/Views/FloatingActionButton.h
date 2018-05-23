#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class FloatingActionButton    : public Button
{
public:
    FloatingActionButton() : Button("FloatingActionButton")
    {
        setPaintingIsUnclipped(true);
        setSize(48, 48);
    }

    ~FloatingActionButton()
    {
    }

    void paintButton (Graphics &g, bool isMouseOverButton, bool isButtonDown) override
    {
        Path p;
        
        p.addEllipse(0, 0, getWidth(), getHeight());
        DropShadow s1(Colour(0.0f, 0.0f, 0.0f, 0.14f), 4, Point<int>(0, 0));
        DropShadow s2(Colour(0.0f, 0.0f, 0.0f, 0.12f), 4, Point<int>(0, 3));
        DropShadow s3(Colour(0.0f, 0.0f, 0.0f, 0.20f), 5, Point<int>(0, 1));
        s1.drawForPath(g, p);
        s2.drawForPath(g, p);
        s3.drawForPath(g, p);

        g.setColour(Material::Theme::Colour::Pallete::Primary);
        g.fillPath(p);
        
        icon.getDrawable()->drawWithin(g, getLocalBounds().withSizeKeepingCentre(24,24).toFloat(), RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
    }

private:
    Material::Icon icon{
        BinaryData::baselineadd24px_svg,
        BinaryData::baselineadd24px_svgSize,
        Material::Theme::Colour::Pallete::OnPrimary
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FloatingActionButton)
};
