/*
  ==============================================================================

    lookAndFeel.cpp
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "LookAndFeel.h"

Colour ThemeBackground1 = TomorrowBackground1;
Colour ThemeBackground2 = TomorrowBackground2;
Colour ThemeBackground3 = TomorrowBackground3;
Colour ThemeForeground1 = TomorrowForeground1;
Colour ThemeForeground2 = TomorrowForeground2;
Colour ThemeRed         = TomorrowRed;
Colour ThemeOrange      = TomorrowOrange;
Colour ThemeYellow      = TomorrowYellow;
Colour ThemeGreen       = TomorrowGreen;
Colour ThemeAqua        = TomorrowAqua;
Colour ThemeBlue        = TomorrowBlue;
Colour ThemePurple      = TomorrowPurple;

void SetThemeColors(LookAndFeel *lookAndFeel)
{
    lookAndFeel->setColour(TextButton::buttonColourId, ThemeBackground2);
    lookAndFeel->setColour(TextButton::buttonOnColourId, ThemeBackground3);
    lookAndFeel->setColour(TextButton::textColourOffId, ThemeForeground1);
    lookAndFeel->setColour(TextButton::textColourOnId, ThemeForeground2);

    lookAndFeel->setColour(TableListBox::backgroundColourId, ThemeBackground1);
    lookAndFeel->setColour(TableListBox::textColourId, ThemeForeground1);

    lookAndFeel->setColour(Label::textColourId, ThemeForeground1);

    lookAndFeel->setColour(ToggleButton::textColourId, ThemeForeground1);

    lookAndFeel->setColour(ListBox::textColourId, ThemeForeground1);


    lookAndFeel->setColour(TextEditor::backgroundColourId, ThemeBackground1);
    lookAndFeel->setColour(TextEditor::textColourId, ThemeForeground1);
    lookAndFeel->setColour(TextEditor::highlightColourId, ThemeBackground2);
    lookAndFeel->setColour(TextEditor::highlightedTextColourId, ThemeForeground1);
    lookAndFeel->setColour(TextEditor::outlineColourId, ThemeBackground3);
    lookAndFeel->setColour(TextEditor::focusedOutlineColourId, ThemeBackground2);

    lookAndFeel->setColour(ComboBox::backgroundColourId, ThemeBackground1);
    lookAndFeel->setColour(ComboBox::textColourId, ThemeForeground1);
    lookAndFeel->setColour(ComboBox::outlineColourId, ThemeBackground2);
    lookAndFeel->setColour(ComboBox::buttonColourId, ThemeBackground3);
    lookAndFeel->setColour(ComboBox::arrowColourId, ThemeForeground2);

    lookAndFeel->setColour(PopupMenu::backgroundColourId, ThemeBackground1);
    lookAndFeel->setColour(PopupMenu::textColourId, ThemeForeground1);
    lookAndFeel->setColour(PopupMenu::headerTextColourId, ThemeForeground1);
    lookAndFeel->setColour(PopupMenu::highlightedBackgroundColourId, ThemeBackground2);
    lookAndFeel->setColour(PopupMenu::highlightedTextColourId, ThemeForeground1);

    lookAndFeel->setColour(Slider::rotarySliderFillColourId, ThemeForeground1);
    lookAndFeel->setColour(Slider::textBoxBackgroundColourId, ThemeBackground2);
    lookAndFeel->setColour(Slider::textBoxOutlineColourId, ThemeBackground2);
    lookAndFeel->setColour(Slider::textBoxTextColourId, ThemeForeground1);
    lookAndFeel->setColour(Slider::thumbColourId, ThemeForeground1);
    lookAndFeel->setColour(Slider::trackColourId, ThemeBackground1);


    lookAndFeel->setColour(TextButton::textColourOnId, ThemeForeground1);
    lookAndFeel->setColour(TextButton::textColourOffId, ThemeForeground1);

    lookAndFeel->setColour(ListBox::backgroundColourId, ThemeBackground2);
    lookAndFeel->setColour(ListBox::outlineColourId, ThemeBackground1);
    lookAndFeel->setColour(ListBox::textColourId, ThemeForeground1);

    lookAndFeel->setColour(BubbleMessageComponent::backgroundColourId, ThemeBackground3);
    lookAndFeel->setColour(BubbleMessageComponent::outlineColourId, ThemeBackground1);
}

void SwitchTheme(Themes theme)
{
    switch (theme)
    {
        case ThemeTomorrow:
        {
            ThemeBackground1 = TomorrowBackground1;
            ThemeBackground2 = TomorrowBackground2;
            ThemeBackground3 = TomorrowBackground3;
            ThemeForeground1 = TomorrowForeground1;
            ThemeForeground2 = TomorrowForeground2;
            ThemeRed         = TomorrowRed;
            ThemeOrange      = TomorrowOrange;
            ThemeYellow      = TomorrowYellow;
            ThemeGreen       = TomorrowGreen;
            ThemeAqua        = TomorrowAqua;
            ThemeBlue        = TomorrowBlue;
            ThemePurple      = TomorrowPurple;
            break;
        };
        case ThemeTomorrowNightBright:
        {
            ThemeBackground1 = TomorrowNightBrightBackground1;
            ThemeBackground2 = TomorrowNightBrightBackground2;
            ThemeBackground3 = TomorrowNightBrightBackground3;
            ThemeForeground1 = TomorrowNightBrightForeground1;
            ThemeForeground2 = TomorrowNightBrightForeground2;
            ThemeRed         = TomorrowNightBrightRed;
            ThemeOrange      = TomorrowNightBrightOrange;
            ThemeYellow      = TomorrowNightBrightYellow;
            ThemeGreen       = TomorrowNightBrightGreen;
            ThemeAqua        = TomorrowNightBrightAqua;
            ThemeBlue        = TomorrowNightBrightBlue;
            ThemePurple      = TomorrowNightBrightPurple;
            break;
        };
        case ThemeTomorrowNight:
        {
            ThemeBackground1 = TomorrowNightBackground1;
            ThemeBackground2 = TomorrowNightBackground2;
            ThemeBackground3 = TomorrowNightBackground3;
            ThemeForeground1 = TomorrowNightForeground1;
            ThemeForeground2 = TomorrowNightForeground2;
            ThemeRed         = TomorrowNightRed;
            ThemeOrange      = TomorrowNightOrange;
            ThemeYellow      = TomorrowNightYellow;
            ThemeGreen       = TomorrowNightGreen;
            ThemeAqua        = TomorrowNightAqua;
            ThemeBlue        = TomorrowNightBlue;
            ThemePurple      = TomorrowNightPurple;
            break;
        };
        case ThemeTomorrowNightEighties:
        {
            ThemeBackground1 = TomorrowNightEightiesBackground1;
            ThemeBackground2 = TomorrowNightEightiesBackground2;
            ThemeBackground3 = TomorrowNightEightiesBackground3;
            ThemeForeground1 = TomorrowNightEightiesForeground1;
            ThemeForeground2 = TomorrowNightEightiesForeground2;
            ThemeRed         = TomorrowNightEightiesRed;
            ThemeOrange      = TomorrowNightEightiesOrange;
            ThemeYellow      = TomorrowNightEightiesYellow;
            ThemeGreen       = TomorrowNightEightiesGreen;
            ThemeAqua        = TomorrowNightEightiesAqua;
            ThemeBlue        = TomorrowNightEightiesBlue;
            ThemePurple      = TomorrowNightEightiesPurple;
            break;
        };
        case ThemeTomorrowNightBlue:
        {
            ThemeBackground1 = TomorrowNightBlueBackground1;
            ThemeBackground2 = TomorrowNightBlueBackground2;
            ThemeBackground3 = TomorrowNightBlueBackground3;
            ThemeForeground1 = TomorrowNightBlueForeground1;
            ThemeForeground2 = TomorrowNightBlueForeground2;
            ThemeRed         = TomorrowNightBlueRed;
            ThemeOrange      = TomorrowNightBlueOrange;
            ThemeYellow      = TomorrowNightBlueYellow;
            ThemeGreen       = TomorrowNightBlueGreen;
            ThemeAqua        = TomorrowNightBlueAqua;
            ThemeBlue        = TomorrowNightBlueBlue;
            ThemePurple      = TomorrowNightBluePurple;
            break;
        };
    }
    SetThemeColors(defaultLookAndFeel);
    SetThemeColors(awesomeLookAndFeel);
    LookAndFeel::setDefaultLookAndFeel(defaultLookAndFeel);
}

ScopedPointer<LookAndFeel_Ultraschall>         defaultLookAndFeel;
ScopedPointer<LookAndFeel_Ultraschall_Awesome> awesomeLookAndFeel;

void LookAndFeel_Ultraschall::drawTableHeaderBackground(Graphics &g, TableHeaderComponent &header)
{
    auto r(header.getLocalBounds());

    g.setColour(ThemeBackground1);
    g.fillRect(r);

    g.setColour(ThemeBackground2);

    for (int i = header.getNumColumns(true); --i >= 0;)
    {
        g.fillRect(header.getColumnPosition(i).removeFromRight(1));
    }
}

void LookAndFeel_Ultraschall::drawTableHeaderColumn (Graphics& g, TableHeaderComponent&, const String& columnName,
                                                     int columnId, int width, int height, bool isMouseOver,
                                                     bool isMouseDown, int columnFlags)
{
    Rectangle<int> area(width, height);
    area.reduce(4, 0);
    g.setColour(ThemeForeground2);
    g.setFont(Font(height * 0.5f, Font::bold));
    if (columnName == "Time")
    {
        g.drawFittedText(columnName, area, Justification::centred, 1);
    }
    else
    {
        g.drawFittedText(columnName, area, Justification::centredLeft, 1);
    }
}
