/*
  ==============================================================================

    SideNavbarView.h
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "DrawingTools.h"
//==============================================================================
/*
*/
class SideNavbarView : public Component {
public:
    SideNavbarView();

    ~SideNavbarView();

    void paint(Graphics &) override;

    void resized() override;

private:
    class SideNavbarItemView : public Component {
    public:
        SideNavbarItemView(String t, Drawable *i) : title(t), icon(i) {

        }

        void paint(Graphics &g) override;

        String title;
        Drawable *icon;
    };

    SvgIcon settingsIcon = {BinaryData::ic_mic_black_48px_svg, BinaryData::ic_volume_up_white_48px_svgSize};
    SideNavbarItemView settings = {"Settings", settingsIcon.getDrawable()};

    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
