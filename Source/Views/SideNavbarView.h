#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class SideNavbarView : public Component
{
public:
    SideNavbarView();

    ~SideNavbarView();

    void paint(Graphics &) override;

    void resized() override;

    SideNavbarItemView settingsButton{"Settings", settingsIcon};
    SideNavbarItemView importFolderButton{"Import Folder", importFolderIcon};

    DrawableButton backButton{"Back", DrawableButton::ButtonStyle::ImageFitted};

private:
    Material::Icon settingsIcon = {BinaryData::baselinesettings20px_svg,
                                   BinaryData::baselinesettings20px_svgSize,
                                   findColour(Material::ColourIds::textSecondaryColorId)};
    Material::Icon backIcon = {BinaryData::baselinenavigate_before24px_svg,
                               BinaryData::baselinenavigate_before24px_svgSize,
                               findColour(Material::ColourIds::textSecondaryColorId)};
    Material::Icon importFolderIcon{BinaryData::baselinefolder_open24px_svg,
                                    BinaryData::baselinefolder_open24px_svgSize,
                                    findColour(Material::ColourIds::textSecondaryColorId)};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
