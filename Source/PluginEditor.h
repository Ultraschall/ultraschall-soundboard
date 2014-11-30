/*
 ==============================================================================
 
 PluginEditor.cpp
 Author:  Daniel Lindenfelser
 
 ==============================================================================
 */

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

static const int RowIdNum = 1;
static const int RowIdFile = 2;
static const int RowIdLoop = 3;
static const int RowIdTime = 4;
static const int RowIdPlayPause = 5;
static const int RowIdStop = 6;
static const int RowIdFadeOut = 7;

static const int ButtonCellWidth = 32;

//==============================================================================
/**
*/
class SoundboardAudioProcessorEditor : public AudioProcessorEditor,
                                       public TableListBoxModel,
                                       public Button::Listener,
                                       public Slider::Listener,
                                       public MultiTimer {
public:
    SoundboardAudioProcessorEditor(SoundboardAudioProcessor &);

    ~SoundboardAudioProcessorEditor();

    // TableListBoxModel
    int getNumRows();

    void paintRowBackground(Graphics &g,
            int rowNumber,
            int width, int height,
            bool rowIsSelected);

    void paintCell(Graphics &g,
            int rowNumber,
            int columnId,
            int width, int height,
            bool rowIsSelected);

    void cellClicked(int rowNumber, int columnId, const MouseEvent & /*e*/);

    // Button::Listener
    void buttonClicked(Button *buttonThatWasClicked);

    // Slider::Listener
    void sliderValueChanged(Slider *slider);

    //==============================================================================
    void paint(Graphics &) override;

    void resized() override;

    void refresh();

    void timerCallback(int timerID);

private:
    ScopedPointer<TableListBox> tableListBox;
    ScopedPointer<ResizableCornerComponent> resizer;
    ComponentBoundsConstrainer resizeLimits;
    ScopedPointer<ImageButton> loadDirectoryButton;
    ScopedPointer<Slider> fadeOutSlider;
    ScopedPointer<Label> fadeOutLabel;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoundboardAudioProcessor &processor;
    bool mPauseState;
    bool mTimerState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessorEditor)
};

#endif // PLUGINEDITOR_H_INCLUDED
