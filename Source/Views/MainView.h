/*
  ==============================================================================

    MainView.h
    Created: 4 May 2018 11:22:54am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MainView    : public Component
{
public:
    MainView();
    ~MainView();

    void paint (Graphics&) override;
    void resized() override;

    void setContentView(Component* view);

    Toolbar toolbar;
private:
    Component *contentView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainView)
};
