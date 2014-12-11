/*
  ==============================================================================

    LookAndFeel.cpp
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "LookAndFeel.h"

void LookAndFeel_Ultraschall::drawTableHeaderBackground(
    Graphics& g, TableHeaderComponent& header)
{
    Rectangle<int> r(header.getLocalBounds());

    ColourGradient gradiant(Colour::fromRGB(45, 45, 45), 0.0f, 0.0f,
                            Colour::fromRGB(36, 36, 36), 0.0f, (float)r.getHeight(), false);
    gradiant.addColour(0.5f, Colour::fromRGB(31, 31, 31));
    
    g.setGradientFill(gradiant);
    g.fillRect(r);

    g.setColour(Colours::black.withAlpha(0.5f));

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
    g.setColour(Colours::whitesmoke.darker());
    g.setFont(Font(height * 0.5f, Font::bold));
    if (columnName == "Time") {
        g.drawFittedText(columnName, area, Justification::centred, 1);
    }
    else {
        g.drawFittedText(columnName, area, Justification::centredLeft, 1);
    }
}

void LookAndFeel_Ultraschall::fillTextEditorBackground(Graphics& g,
                                                       int /*width*/,
                                                       int /*height*/,
                                                       TextEditor& textEditor)
{
    if (textEditor.isReadOnly()) {
        g.fillAll(textEditor.findColour(TextEditor::backgroundColourId).darker());
    }
    else {
        if (textEditor.hasKeyboardFocus(true)) {
            g.fillAll(
                textEditor.findColour(TextEditor::backgroundColourId).brighter());
        }
        else {
            g.fillAll(textEditor.findColour(TextEditor::backgroundColourId));
        }
    }
}

void LookAndFeel_Ultraschall::drawTickBox(Graphics& g, Component& /*c*/, float x,
                                          float y, float w, float h,
                                          bool ticked, bool isEnabled,
                                          bool /*isMouseOverButton*/,
                                          bool isButtonDown)
{
    Path box;
    box.addRoundedRectangle(0.0f, 2.0f, 6.0f, 6.0f, 1.0f);

    g.setColour(isEnabled ? Colours::blue.withAlpha(isButtonDown ? 0.3f : 0.1f)
                          : Colours::lightgrey.withAlpha(0.1f));

    AffineTransform trans(
        AffineTransform::scale(w / 9.0f, h / 9.0f).translated(x, y));

    g.fillPath(box, trans);

    g.setColour(Colours::whitesmoke.withAlpha(0.6f));
    g.strokePath(box, PathStrokeType(0.9f), trans);

    if (ticked) {
        Path tick;
        tick.startNewSubPath(1.5f, 3.0f);
        tick.lineTo(3.0f, 6.0f);
        tick.lineTo(6.0f, 0.0f);

        g.setColour(isEnabled ? Colours::whitesmoke : Colours::grey);
        g.strokePath(tick, PathStrokeType(2.5f), trans);
    }
}

void LookAndFeel_Ultraschall::drawToggleButton(Graphics& g,
                                               ToggleButton& button,
                                               bool isMouseOverButton,
                                               bool isButtonDown)
{
    const int tickWidth = jmin(20, button.getHeight() - 4);

    drawTickBox(g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
                (float)tickWidth, (float)tickWidth, button.getToggleState(),
                button.isEnabled(), isMouseOverButton, isButtonDown);

    g.setColour(button.findColour(ToggleButton::textColourId));
    g.setFont(jmin(15.0f, button.getHeight() * 0.6f));

    if (!button.isEnabled())
        g.setOpacity(0.5f);

    const int textX = tickWidth + 5;

    g.drawFittedText(button.getButtonText(), textX, 4,
                     button.getWidth() - textX - 2, button.getHeight() - 8,
                     Justification::centredLeft, 10);
}

static void drawButtonShape(Graphics& g, const Path& outline, Colour baseColour, float height)
{
    ColourGradient gradiant(Colour::fromRGB(45, 45, 45), 0.0f, 0.0f,
                            Colour::fromRGB(36, 36, 36), 0.0f, height, false);
    gradiant.addColour(0.5f, Colour::fromRGB(31, 31, 31));

    g.setGradientFill(gradiant);
    g.fillPath(outline);

    g.setColour(Colours::black);
    g.strokePath(outline, PathStrokeType(1.0f), AffineTransform::translation(0.0f, 1.0f).scaled(1.0f, (height - 1.6f) / height));
}

void LookAndFeel_Ultraschall::drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown)
{
    Colour baseColour(backgroundColour.withMultipliedSaturation(button.hasKeyboardFocus(true) ? 1.3f : 0.9f)
                          .withMultipliedAlpha(button.isEnabled() ? 0.9f : 0.5f));

    if (isButtonDown || isMouseOverButton)
        baseColour = baseColour.contrasting(isButtonDown ? 0.2f : 0.1f);

    const bool flatOnLeft = button.isConnectedOnLeft();
    const bool flatOnRight = button.isConnectedOnRight();
    const bool flatOnTop = button.isConnectedOnTop();
    const bool flatOnBottom = button.isConnectedOnBottom();

    const float width = button.getWidth() - 1.0f;
    const float height = button.getHeight() - 1.0f;

    if (width > 0 && height > 0) {
        const float cornerSize = 4.0f;

        Path outline;
        outline.addRoundedRectangle(0.5f, 0.5f, width, height, cornerSize, cornerSize,
                                    !(flatOnLeft || flatOnTop),
                                    !(flatOnRight || flatOnTop),
                                    !(flatOnLeft || flatOnBottom),
                                    !(flatOnRight || flatOnBottom));

        drawButtonShape(g, outline, baseColour, height);
    }
}
