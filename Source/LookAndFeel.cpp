/*
  ==============================================================================

    LookAndFeel.cpp
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "LookAndFeel.h"

Colour ThemeBackground1 = TomorrowBackground1;
Colour ThemeBackground2 = TomorrowBackground2;
Colour ThemeBackground3 = TomorrowBackground3;
Colour ThemeForeground1 = TomorrowForeground1;
Colour ThemeForeground2 = TomorrowForeground2;
Colour ThemeRed = TomorrowRed;
Colour ThemeOrange = TomorrowOrange;
Colour ThemeYellow = TomorrowYellow;
Colour ThemeGreen = TomorrowGreen;
Colour ThemeAqua = TomorrowAqua;
Colour ThemeBlue = TomorrowBlue;
Colour ThemePurple = TomorrowPurple;

void LookAndFeel_Ultraschall::drawTableHeaderBackground(
    Graphics& g, TableHeaderComponent& header)
{
    Rectangle<int> r(header.getLocalBounds());

    g.setColour(ThemeBackground1);
    g.fillRect(r);

    g.setColour(ThemeBackground2);

    for (int i = header.getNumColumns(true); --i >= 0;) {
        g.fillRect(header.getColumnPosition(i).removeFromRight(1));
    }
}

void LookAndFeel_Ultraschall::drawTableHeaderColumn(
    Graphics& g, const String& columnName, int /*columnId*/, int width,
    int height, bool /*isMouseOver*/, bool /*isMouseDown*/,
    int /*columnFlags*/)
{
    Rectangle<int> area(width, height);
    area.reduce(4, 0);
    g.setColour(ThemeForeground2);
    g.setFont(Font(height * 0.5f, Font::bold));
    if (columnName == "Time") {
        g.drawFittedText(columnName, area, Justification::centred, 1);
    }
    else {
        g.drawFittedText(columnName, area, Justification::centredLeft, 1);
    }
}

