/*
  ==============================================================================

    MaterialLookAndFeel.h
    Created: 6 May 2018 10:29:06am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MaterialLookAndFeel : public LookAndFeel_V4
{
public:
    MaterialLookAndFeel() {
        LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypeface(robotoRegular);
    }



private:
    juce::Typeface::Ptr robotoRegular = juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoMedium_ttfSize);
};