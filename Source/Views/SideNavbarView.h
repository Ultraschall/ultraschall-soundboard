#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class SideNavbarView : public Component {
public:
    SideNavbarView() {
        viewPort.setViewedComponent(new Component());
        viewPort.getViewedComponent()->addAndMakeVisible(libraryTitle);
        viewPort.getViewedComponent()->addAndMakeVisible(importFolderButton);
        viewPort.getViewedComponent()->addAndMakeVisible(openFolderButton);
        viewPort.getViewedComponent()->addAndMakeVisible(saveFolderButton);
        
        viewPort.getViewedComponent()->addAndMakeVisible(seperator[0]);
        viewPort.getViewedComponent()->addAndMakeVisible(bankTitle);
        
        viewPort.getViewedComponent()->addAndMakeVisible(spacer);
        viewPort.getViewedComponent()->addAndMakeVisible(midiButton);
        viewPort.getViewedComponent()->addAndMakeVisible(oscButton);
        viewPort.getViewedComponent()->addAndMakeVisible(seperator[1]);
        viewPort.getViewedComponent()->addAndMakeVisible(settingsButton);
        
        viewPort.setScrollBarsShown(false, false, true, false);
        addAndMakeVisible(viewPort);
    }

    ~SideNavbarView() override = default;

    void paint(Graphics &g) override {
        g.fillAll(findColour(Material::ColourIds::dialogColorId));
    }

    void resized() override {
        
        viewPort.setBounds(getLocalBounds());
        FlexBox flexBox;
        
        flexBox.flexDirection = FlexBox::Direction::column;
        
        flexBox.items.add(FlexItem(libraryTitle)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(importFolderButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(openFolderButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(saveFolderButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        
        flexBox.items.add(FlexItem(seperator[0])
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(bankTitle)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        
        flexBox.items.add(FlexItem(spacer).withFlex(2));
        
        flexBox.items.add(FlexItem(midiButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(oscButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(seperator[1])
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
                          .withFlex(1)
                          );
        flexBox.items.add(FlexItem(settingsButton)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                          .withFlex(1)
                          );
        
        flexBox.performLayout(getLocalBounds());
        
        int height = 0;
        for (auto &i : flexBox.items) {
            height += i.associatedComponent->getHeight();
        }
        /*
        viewPort.getViewedComponent()->setBounds(getLocalBounds().withHeight(jmax(height, getLocalBounds().getHeight())));
        */
    }

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
    SideNavbarSeperator seperator[2]{SideNavbarSeperator(), SideNavbarSeperator()};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarView)
};
