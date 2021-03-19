/*
  ==============================================================================

    TableButtonCell.h
    Created: 23 Jan 2015 7:04:37pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef TABLEBUTTONCELL_H_INCLUDED
#define TABLEBUTTONCELL_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>
#include "../LookAndFeel.h"

using namespace juce;

class SoundboardCellButton : public Button, public Timer
{
public:
    SoundboardCellButton(String buttonName, String iconGlyph);
    ~SoundboardCellButton() override;

    void setHighlighted(bool value);
    void setHighlightColour(Colour color);

    // Timer
    void paintButton(Graphics &g, bool isMouseOverButton, bool /*isButtonDown*/) override;

    // MultiTimer
    void timerCallback() override;
    void setFlashing(bool value);

    // Icon
    void setIcon(String value);
    void setRotation(float value);

    // Row Number
    void setRowNumber(int value);
    int  getRowNumber();

    // Tag
    void setTag(int value);
    int  getTag();

private:
    String icon;
    float  iconRotation;

    bool   highlightState;
    Colour highlightColour;

    bool             flashing;
    bool             flashingState;
    static const int flashingSpeed = static_cast<int>(1000 * 0.5);

    int rowNumber;
    int tag;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardCellButton)
};

#endif // TABLEBUTTONCELL_H_INCLUDED
