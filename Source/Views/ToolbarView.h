#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"

class ToolbarView : public Component
{
public:
    ToolbarView();

    ~ToolbarView();

    void paint(Graphics &) override;

    void resized() override;

    DrawableButton menuButton = {"Menu", DrawableButton::ImageFitted};
    DrawableButton viewButton = {"View", DrawableButton::ImageFitted};

private:
    Material::Icon menuIcon{BinaryData::baselinemenu24px_svg,
                            BinaryData::baselinemenu24px_svgSize,
                            findColour(Material::ColourIds::primaryTextColorId)};
    Material::Icon libraryIcon{BinaryData::baselineview_list24px_svg,
                               BinaryData::baselineview_list24px_svgSize,
                               findColour(Material::ColourIds::primaryTextColorId)};
    Material::Icon bankIcon{BinaryData::baselineview_module24px_svg,
                            BinaryData::baselineview_module24px_svgSize,
                            findColour(Material::ColourIds::primaryTextColorId)};

    Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToolbarView)
};
