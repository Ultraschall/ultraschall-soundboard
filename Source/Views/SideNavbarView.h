/*
  ==============================================================================

    SideNavbarView.h
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SideNavbarView    : public Component
{
public:
    SideNavbarView();
    ~SideNavbarView();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideNavbarView)
};
