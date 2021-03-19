/*
  ==============================================================================

    TableComponent.h
    Created: 6 Jan 2015 2:11:44am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef TABLECOMPONENT_H_INCLUDED
#define TABLECOMPONENT_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>
#include "../../../plugin/PluginProcessor.h"
#include "TableButtonCell.h"

using namespace juce;

class SoundboardTableComponent
        : public Component,
          public TableListBoxModel,
          public MultiTimer,
          public Button::Listener,
          public Slider::Listener
{
public:
    explicit SoundboardTableComponent(SoundboardAudioProcessor &);
    ~SoundboardTableComponent() override;

    // Component
    void resized() override;

    // TableListBoxModel
    int  getNumRows() override;
    void paintRowBackground(Graphics &g, int rowNumber, int width, int height, bool rowIsSelected) override;
    void paintCell(Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    void cellClicked(int rowNumber, int columnId, const MouseEvent & /*e*/) override;
    Component
            *refreshComponentForCell(int rowNumber,
                                     int columnId,
                                     bool isRowSelected,
                                     Component *existingComponentToUpdate) override;

    // MultiTimer
    void timerCallback(int timerID) override;

    // Button Listener
    void buttonClicked(Button *button) override;

    // Slider Listener
    void sliderValueChanged(Slider *slider) override;

    // Helper
    void updateContent();

private:
    SoundboardAudioProcessor &processor;

    enum TimerIds
    {
        TimerIdRepaint = 1
    };

    enum TableColumnIds
    {
        ColumnIdNumberLabel     = 1,
        ColumnIdFileLabel       = 2,
        ColumnIdLoopButton      = 3,
        ColumnIdTimeLabel       = 4,
        ColumnIdPlayPauseButton = 5,
        ColumnIdStopButton      = 6,
        ColumnIdFadeButton = 7,
        ColumnIdGainSlider      = 8
    };

    enum ButtonTags
    {
        ButtonTagLoop = 1, ButtonTagPlayPause = 2, ButtonTagStop = 3, ButtonTagFade = 4
    };

    static const int NumberCellWidth = 24;
    static const int TimeCellWidth   = 90;
    static const int ButtonCellWidth = 32;
    static const int SliderCellWidth = 32;

    TableListBox tableListBox;

    bool mTimerState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardTableComponent)
};

#endif // TABLECOMPONENT_H_INCLUDED
