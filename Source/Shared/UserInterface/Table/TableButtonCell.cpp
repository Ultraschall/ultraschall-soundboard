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

	Colour colour;

	colour = ThemeForeground1;

    if (flashing)
    {
        if (flashingState)
        {
			colour = ThemeForeground1.contrasting(0.5f);
        }
    }
    else if (highlightState)
    {
		colour = highlightColour;
    }
    else if (!isEnabled())
    {
		colour = ThemeForeground2;
    }
    else if (isMouseOverButton)
    {
		colour = ThemeForeground1.contrasting(0.1f);
    }

	auto iconSize = min(getHeight(), getWidth()) * 0.7f;

	FontAwesome::drawCenterdRotated(g, icon, iconSize, colour, Rectangle<int>(getWidth(), getHeight()), iconRotation);
}

// Timer
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
