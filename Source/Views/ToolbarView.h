#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"

class ToolbarView : public Component
{
public:
    ToolbarView();

    ~ToolbarView() override = default;

    void paint(Graphics &) override;

    void resized() override;

    Material::IconButton menuButton{
		"Menu",
		BinaryData::baselinemenu24px_svg,
		BinaryData::baselinemenu24px_svgSize,
		findColour(Material::ColourIds::primaryTextColorId)
	};

	Material::IconToggleButton viewButton{
		"View",
		BinaryData::baselinegrid_on24px_svg,
		BinaryData::baselinegrid_on24px_svgSize,
		BinaryData::baselinelibrary_music24px_svg,
		BinaryData::baselinelibrary_music24px_svgSize,
		findColour(Material::ColourIds::primaryTextColorId),
		findColour(Material::ColourIds::primaryTextColorId)
	};

private:
    Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToolbarView)
};
