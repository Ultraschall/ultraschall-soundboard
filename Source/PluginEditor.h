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
#include "OscSettings.h"
#include "LookAndFeel.h"

static const int RowIdNum = 1;
static const int RowIdFile = 2;
static const int RowIdLoop = 3;
static const int RowIdTime = 4;
static const int RowIdPlayPause = 5;
static const int RowIdStop = 6;
static const int RowIdFadeOut = 7;
static const int RowIdGain = 8;

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
    SoundboardAudioProcessorEditor(SoundboardAudioProcessor&);
    ~SoundboardAudioProcessorEditor();

    // TableListBoxModel
    int getNumRows() override;

    void paintRowBackground(Graphics& g, int rowNumber, int width, int height,
                            bool rowIsSelected) override;

    void paintCell(Graphics& g, int rowNumber, int columnId, int width,
                   int height, bool rowIsSelected) override;

    void cellClicked(int rowNumber, int columnId,
                     const MouseEvent& /*e*/) override;
    Component* refreshComponentForCell(int rowNumber, int columnId,
                                       bool isRowSelected, Component* existingComponentToUpdate);
    // Button::Listener
    void buttonClicked(Button* buttonThatWasClicked) override;

    // Slider::Listener
    void sliderValueChanged(Slider* slider) override;

    //==============================================================================
    void paint(Graphics&) override;

    void resized() override;

    void refresh();

    void refreshTable();

    void timerCallback(int timerID);

private:
    ScopedPointer<TableListBox> tableListBox;
    ScopedPointer<ResizableCornerComponent> resizer;
    ComponentBoundsConstrainer resizeLimits;
    ScopedPointer<AwesomeButton> loadDirectoryButton;
    ScopedPointer<Slider> fadeOutSlider;
    ScopedPointer<Label> fadeOutLabel;

    ScopedPointer<Bar> buttomBar;
    ScopedPointer<Bar> topBar;
    ScopedPointer<AwesomeButton> settingsButton;
    ScopedPointer<ActivityIndicator> oscActivityIndicator;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoundboardAudioProcessor& processor;
    bool mPauseState;
    bool mTimerState;

    OwnedArray<Slider> gainSliders;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessorEditor)
};

#endif // PLUGINEDITOR_H_INCLUDED
