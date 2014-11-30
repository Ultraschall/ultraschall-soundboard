/*
  ==============================================================================

    LookAndFeel.cpp
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "LookAndFeel.h"

void LookAndFeel_Ultraschall::drawTableHeaderBackground(Graphics &g, TableHeaderComponent &header) {
    Rectangle<int> r(header.getLocalBounds());

    g.setColour(Colour::fromRGB(53, 53, 53));
    g.fillRect(r);

    g.setColour(Colour::fromRGB(53, 53, 53).darker());
    for (int i = header.getNumColumns(true); --i >= 0;) {
        g.fillRect(header.getColumnPosition(i));
    }


    g.setColour(Colours::black.withAlpha(0.5f));

    for (int i = header.getNumColumns(true); --i >= 0;) {
        g.fillRect(header.getColumnPosition(i).removeFromRight(1));
    }
}

void LookAndFeel_Ultraschall::drawTableHeaderColumn(Graphics &g, const String &columnName, int /*columnId*/,
        int width, int height, bool /*isMouseOver*/, bool /*isMouseDown*/,
        int /*columnFlags*/) {
    Rectangle<int> area(width, height);
    area.reduce(4, 0);
    g.setColour(Colours::whitesmoke.darker());
    g.setFont(Font(height * 0.5f, Font::bold));
    if (columnName == "Time") {
        g.drawFittedText(columnName, area, Justification::centred, 1);
    } else {
        g.drawFittedText(columnName, area, Justification::centredLeft, 1);
    }
}

void LookAndFeel_Ultraschall::fillTextEditorBackground(Graphics &g, int /*width*/, int /*height*/, TextEditor &textEditor) {
    if (textEditor.hasKeyboardFocus(true)) {
        g.fillAll(textEditor.findColour(TextEditor::backgroundColourId).brighter());
    } else {
        g.fillAll(textEditor.findColour(TextEditor::backgroundColourId));
    }
}