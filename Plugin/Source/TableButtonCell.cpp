/*
  ==============================================================================

    TableButtonCell.cpp
    Created: 23 Jan 2015 7:04:37pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "TableButtonCell.h"

SoundboardCellButton::SoundboardCellButton(String buttonName, String icon)
        : Button(buttonName),
          icon(icon),
          iconRotation(0.0f),
          highlightState(false),
          highlightColour(ThemeForeground2),
          flashing(false),
          flashingState(false),
          rowNumber(-1),
          tag(-1)
{
}

SoundboardCellButton::~SoundboardCellButton()
{
    if (isTimerRunning())
    {
        stopTimer();
    }
}

void SoundboardCellButton::setHighlighted(bool value)
{
    if (highlightState != value)
    {
        highlightState = value;
        repaint();
    }
}

void SoundboardCellButton::setHighlightColour(Colour color)
{
    highlightColour = color;
    repaint();
}

// Timer
void SoundboardCellButton::paintButton(Graphics &g, bool isMouseOverButton, bool /*isButtonDown*/)
{
    g.setColour(ThemeBackground1);
    g.drawLine(static_cast<float>(getWidth()),
               0,
               static_cast<float>(getWidth()),
               static_cast<float>(getHeight()),
               1.5f);

    g.setColour(ThemeForeground1);

    if (flashing)
    {
        if (flashingState)
        {
            g.setColour(ThemeForeground1.contrasting(0.5f));
        }
    }
    else if (highlightState)
    {
        g.setColour(highlightColour);
    }
    else if (!isEnabled())
    {
        g.setColour(ThemeForeground2);
    }
    else if (isMouseOverButton)
    {
        g.setColour(ThemeForeground1.contrasting(0.1f));
    }

    g.setFont(getFontAwesome(getHeight() * 0.7f));
    if (iconRotation != 0)
    {
        g.addTransform(AffineTransform::rotation(-(float_Pi * iconRotation), getWidth() * 0.5f, getHeight() * 0.5f));
    }
    g.drawText(icon, 0, 0, getWidth(), getHeight(), Justification::centred, true);
}

// MultiTimer
void SoundboardCellButton::timerCallback()
{
    flashingState = !flashingState;
    repaint();
}

void SoundboardCellButton::setFlashing(bool value)
{
    flashing = value;
    if (value)
    {
        if (!isTimerRunning())
        {
            startTimer(flashingSpeed);
        }
    }
    else
    {
        if (isTimerRunning())
        {
            stopTimer();
        }
    }
}

// Icon
void SoundboardCellButton::setIcon(String value)
{
    icon = value;
    repaint();
}

void SoundboardCellButton::setRotation(float value)
{
    iconRotation = value;
    repaint();
}

// Row Number
void SoundboardCellButton::setRowNumber(int value)
{
    rowNumber = value;
}

int SoundboardCellButton::getRowNumber()
{
    return rowNumber;
}

// Tag
void SoundboardCellButton::setTag(int value)
{
    tag = value;
}

int SoundboardCellButton::getTag()
{
    return tag;
}
