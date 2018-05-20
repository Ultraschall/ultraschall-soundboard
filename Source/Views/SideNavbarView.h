#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class SideNavbarView : public Component {
public:
    SideNavbarView();

    ~SideNavbarView() override = default;

    void paint(Graphics &) override;

    void resized() override;

    SideNavbarTitle libraryTitle{"Library"};
    SideNavbarItem importFolderButton{"Import Folder",
                                      BinaryData::baselinefolder_open24px_svg,
                                      BinaryData::baselinefolder_open24px_svgSize,
                                      findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem saveFolderButton{"Save",
                                    BinaryData::baselinearchive24px_svg,
                                    BinaryData::baselinearchive24px_svgSize,
                                    findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem openFolderButton{"Open",
                                    BinaryData::baselineunarchive24px_svg,
                                    BinaryData::baselineunarchive24px_svgSize,
                                    findColour(Material::ColourIds::textPrimaryColorId)};

    SideNavbarTitle bankTitle{"Bank"};

    SideNavbarItem midiButton{"MIDI Learn",
                              BinaryData::baselinesettings_input_svideo24px_svg,
                              BinaryData::baselinesettings_input_svideo24px_svgSize,
                              findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem oscButton{"OSC",
                             BinaryData::baselinesettings_input_antenna24px_svg,
                             BinaryData::baselinesettings_input_antenna24px_svgSize,
                             findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem settingsButton{"Settings",
                                  BinaryData::baselinesettings20px_svg,
                                  BinaryData::baselinesettings20px_svgSize,
                                  findColour(Material::ColourIds::textPrimaryColorId)};

private:
    Viewport viewPort;
    Component spacer;
    SideNavbarSeperator seperator[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarView)
};
