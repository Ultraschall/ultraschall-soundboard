/*
  ==============================================================================

    ToolbarView.h
    Created: 6 May 2018 4:12:25am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

//==============================================================================
/*
*/
class ToolbarView : public Component {
public:
    ToolbarView();

    ~ToolbarView();

    void paint(Graphics &) override;

    void resized() override;

    DrawableButton menuButton = {"Menu", DrawableButton::ImageFitted};
    DrawableButton viewButton = {"View", DrawableButton::ImageFitted};

private:
	Material::Icon menuIcon{BinaryData::ic_menu_white_48px_svg, BinaryData::ic_menu_white_48px_svgSize};
	Material::Icon libraryIcon{BinaryData::ic_view_module_white_48px_svg, BinaryData::ic_view_module_white_48px_svgSize};
	Material::Icon bankIcon{BinaryData::ic_view_headline_white_48px_svg, BinaryData::ic_view_headline_white_48px_svgSize};

    Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToolbarView)
};
