/*
  ==============================================================================

    TableComponent.h
    Created: 6 Jan 2015 2:11:44am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef TABLECOMPONENT_H_INCLUDED
#define TABLECOMPONENT_H_INCLUDED

#include "JuceHeader.h"
#include "LookAndFeel.h"
#include "PluginProcessor.h"

class SoundboardCellButton : public Button,
                             public Timer {
public:
    SoundboardCellButton(String buttonName, String icon)
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
    ~SoundboardCellButton()
    {
        if (isTimerRunning()) {
            stopTimer();
        }
    }

    void setHighlighted(bool value)
    {
        if (highlightState != value) {
            highlightState = value;
            repaint();
        }
    }

                                 void setHighlightColour(Colour color) {
                                     highlightColour = color;
                                     repaint();
                                 }

    // Timer
    void paintButton(Graphics& g, bool isMouseOverButton, bool /*isButtonDown*/) override
    {
        g.setColour(ThemeBackground1);
        g.drawLine((float) getWidth(), 0, (float) getWidth(), (float) getHeight(), 1.5f);

        g.setColour(ThemeForeground1);

        if (flashing) {
            if (flashingState) {
                g.setColour(ThemeForeground1.contrasting(0.5f));
            }
        } else if (highlightState) {
            g.setColour(highlightColour);
        } else if (!isEnabled()) {
            g.setColour(ThemeForeground2);
        } else if (isMouseOverButton) {
            g.setColour(ThemeForeground1.contrasting(0.1f));
        }

        g.setFont(getFontAwesome(getHeight() * 0.7f));
        if (iconRotation != 0) {
            g.addTransform(AffineTransform::rotation(-(float_Pi * iconRotation), getWidth() * 0.5f, getHeight() * 0.5f));
        }
        g.drawText(icon, 0, 0, getWidth(), getHeight(), Justification::centred, true);
    }

    // MultiTimer
    void timerCallback() override
    {
        flashingState = !flashingState;
        repaint();
    }

    void setFlashing(bool value)
    {
        flashing = value;
        if (value) {
            if (!isTimerRunning()) {
                startTimer(flashingSpeed);
            }
        }
        else {
            if (isTimerRunning()) {
                stopTimer();
            }
        }
    }

    // Icon
    void setIcon(String value)
    {
        icon = value;
        repaint();
    }

    void setRotation(float value) {
        iconRotation = value;
        repaint();
    }

    // Row Number
    void setRowNumber(int value) { rowNumber = value; }
    int getRowNumber() { return rowNumber; }

    // Tag
    void setTag(int value) { tag = value; }
    int getTag() { return tag; }

private:
    String icon;
    float iconRotation;

    bool highlightState;
    Colour highlightColour;

    bool flashing;
    bool flashingState;
    static const int flashingSpeed = (int)(1000 * 0.5);

    int rowNumber;
    int tag;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardCellButton)
};

class SoundboardTableComponent : public Component,
                                 public TableListBoxModel,
                                 public MultiTimer,
                                 public Button::Listener,
                                 public Slider::Listener {
public:
    SoundboardTableComponent(SoundboardAudioProcessor&);
    ~SoundboardTableComponent();

    // Component
    void resized() override;

    // TableListBoxModel
    int getNumRows() override;
    void paintRowBackground(Graphics& g,
                            int rowNumber,
                            int width,
                            int height,
                            bool rowIsSelected) override;
    void paintCell(Graphics& g,
                   int rowNumber,
                   int columnId,
                   int width,
                   int height,
                   bool rowIsSelected) override;
    void cellClicked(int rowNumber,
                     int columnId,
                     const MouseEvent& /*e*/) override;
    Component* refreshComponentForCell(int rowNumber,
                                       int columnId,
                                       bool isRowSelected,
                                       Component* existingComponentToUpdate) override;

    // MultiTimer
    void timerCallback(int timerID) override;

    // Button Listener
    void buttonClicked(Button* button) override;

    // Slider Listener
    void sliderValueChanged(Slider* slider) override;

    // Helper
    void updateContent();

private:
    SoundboardAudioProcessor& processor;

    enum TimerIds {
        TimerIdRepaint = 1
    };

    enum TableColumnIds {
        ColumnIdNumberLabel = 1,
        ColumnIdFileLabel = 2,
        ColumnIdLoopButton = 3,
        ColumnIdTimeLabel = 4,
        ColumnIdPlayPauseButton = 5,
        ColumnIdStopButton = 6,
        ColumnIdFadeOutButton = 7,
        ColumnIdGainSlider = 8
    };

    enum ButtonTags {
        ButtonTagLoop = 1,
        ButtonTagPlayPause = 2,
        ButtonTagStop = 3,
        ButtonTagFadeOut = 4
    };

    static const int NumberCellWidth = 24;
    static const int TimeCellWidth = 90;
    static const int ButtonCellWidth = 32;
    static const int SliderCellWidth = 32;

    ScopedPointer<TableListBox> tableListBox;

    bool mTimerState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardTableComponent)
};

#endif // TABLECOMPONENT_H_INCLUDED
