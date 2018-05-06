/*
  ==============================================================================

    ToolbarView.h
    Created: 6 May 2018 4:12:25am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "DrawingTools.h"

//==============================================================================
/*
*/
class ToolbarView    : public Component
{
public:
    ToolbarView();
    ~ToolbarView();

    void paint (Graphics&) override;
    void resized() override;

private:
	float padding = { Material::convertDpToPixel(this, 24) };
	float iconSize = { Material::convertDpToPixel(this, 48) };
	SvgIcon menuIcon = { BinaryData::ic_menu_white_48px_svg, BinaryData::ic_menu_white_48px_svgSize };
	SvgIcon viewIcon = { BinaryData::ic_view_module_white_48px_svg, BinaryData::ic_view_module_white_48px_svgSize };
	DrawableButton menuButton = { "Menu", DrawableButton::ImageFitted };
	DrawableButton viewButton = { "View", DrawableButton::ImageFitted };
	Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToolbarView)
};
