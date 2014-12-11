/*
  ==============================================================================

    LookAndFeel.h
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef LOOKANDFEEL_H_INCLUDED
#define LOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class LookAndFeel_Ultraschall : public LookAndFeel_V3 {
public:
    void drawTableHeaderBackground(Graphics& g,
                                   TableHeaderComponent& header) override;

    void drawTableHeaderColumn(Graphics& g, const String& columnName,
                               int /*columnId*/, int width, int height,
                               bool isMouseOver, bool isMouseDown,
                               int columnFlags) override;

    void fillTextEditorBackground(Graphics& g, int /*width*/, int /*height*/,
                                  TextEditor& textEditor) override;
    void drawTickBox(Graphics&, Component&, float x, float y, float w, float h,
                     bool ticked, bool isEnabled, bool isMouseOverButton,
                     bool isButtonDown) override;

    // Button
    void drawButtonBackground(Graphics&, Button&, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown);
    void drawToggleButton(Graphics& g, ToggleButton& button, bool isMouseOverButton, bool isButtonDown) override;
};

class Bar : public Component {
public:
    Bar()
    {
    }

    void paint(Graphics& g)
    {
        ColourGradient gradiant(Colour::fromRGB(45, 45, 45), 0.0f, 0.0f,
                                Colour::fromRGB(36, 36, 36), 0.0f, (float)getHeight(), false);
        gradiant.addColour(0.6f, Colour::fromRGB(31, 31, 31));

        g.setGradientFill(gradiant);
        g.fillRect(0, 0, getWidth(), getHeight());

        g.setColour(Colour::fromRGB(14, 14, 14));
        g.drawLine(0.0f, 1.0f, (float)getWidth(), 1.0f);
        g.setColour(Colour::fromRGB(19, 19, 19));
        g.drawLine(0.0f, 2.0f, (float)getWidth(), 2.0f);
        g.setColour(Colour::fromRGB(53, 53, 53));
        g.drawLine(0.0f, 3.0f, (float)getWidth(), 3.0f);

        g.setColour(Colour::fromRGB(21, 21, 21));
        g.drawLine(0.0f, (float)getHeight(), (float)getWidth(), (float)getHeight());
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Bar)
};

class AwesomeButton : public TextButton {
public:
    AwesomeButton(String icon)
        : icon(icon)
    {
    }

    void paint(Graphics& g)
    {
        int width = Font(getHeight() * 0.6f).getStringWidth(getButtonText().trim());
        width += getHeight();

        float x = (getWidth() - width) * 0.5f;

        getLookAndFeel().drawButtonBackground(g, *this, Colours::black, this->isMouseOver(), this->isDown());

        g.setColour(Colour::fromRGB(188, 188, 188));
        g.setFont(getHeight() * 0.6f);
        g.drawText(getButtonText(), (int)x + getHeight(), 0, getWidth() - getHeight(), getHeight(), Justification::left);

        g.setFont(getFontAwesome(getHeight() * 0.7f));
        g.setColour(Colours::black);
        g.drawText(icon, (int)x + 1, 1, getHeight(), getHeight(), Justification::centred, true);

        g.setColour(Colour::fromRGB(188, 188, 188));
        g.drawText(icon, (int)x, 0, getHeight(), getHeight(), Justification::centred, true);
    }

private:
    String icon;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AwesomeButton)
};

class ActivityIndicator : public Component {
public:
    ActivityIndicator()
    {
        isActive = false;
        title = "Activity";
    }

    void paint(Graphics& g)
    {
        int contentWidth = Font(getHeight() * 0.6f).getStringWidth(title);
        contentWidth += getHeight();
        float x = (getWidth() - contentWidth) * 0.5f;

        const float width = getWidth() - 1.0f;
        const float height = getHeight() - 1.0f;
        const float cornerSize = 4.0f;
        Path outline;
        outline.addRoundedRectangle(0.5f, 0.5f, width, height, cornerSize, cornerSize,
                                    true, true, true, true);
        ColourGradient gradiant(Colour::fromRGB(45, 45, 45), 0.0f, 0.0f,
                                Colour::fromRGB(36, 36, 36), 0.0f, height, false);
        gradiant.addColour(0.5f, Colour::fromRGB(31, 31, 31));

        g.setGradientFill(gradiant);
        g.fillPath(outline);

        g.setColour(Colours::black);
        g.strokePath(outline, PathStrokeType(1.0f), AffineTransform::translation(0.0f, 1.0f).scaled(1.0f, (height - 1.6f) / height));

        g.setColour(Colour::fromRGB(188, 188, 188));
        g.setFont(getHeight() * 0.6f);
        g.drawText(title, (int)x + getHeight(), 0, getWidth() - getHeight(), getHeight(), Justification::left);

        g.setFont(getFontAwesome(getHeight() * 0.4f));
        g.setColour(Colours::black);
        g.drawText(FA_CIRCLE, (int)x + 1, 1, getHeight(), getHeight(), Justification::centred, true);

        if (isActive) {
            g.setColour(Colour::fromRGB(255, 122, 102));
        }
        else {
            g.setColour(Colour::fromRGB(188, 188, 188));
        }
        g.drawText(FA_CIRCLE, (int)x, 0, getHeight(), getHeight(), Justification::centred, true);
    }

    void setActive(bool value) { isActive = value; }
    bool getActive() { return isActive; }
    void reset() { isActive = false; }

    void setTitle(String newTitle) { title = newTitle; }

private:
    String title;
    bool isActive;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ActivityIndicator)
};
#endif // LOOKANDFEEL_H_INCLUDED
