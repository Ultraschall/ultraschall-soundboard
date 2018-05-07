/*
  ==============================================================================

    BankView.h
    Created: 1 May 2018 11:20:13am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

//==============================================================================
/*
*/
class BankView    : public Component
{
public:
    BankView();
    ~BankView();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankView)
};
