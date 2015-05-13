/*
 ==============================================================================

 PluginEditor.cpp
 Author:  Daniel Lindenfelser

 ==============================================================================
 */

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "JuceHeader.h"
#include "LookAndFeel.h"
#include "PluginProcessor.h"
#include "TableComponent.h"
#include "GridComponent.h"
#include "SettingsComponent.h"

class SoundboardAudioProcessorEditor
        : public AudioProcessorEditor, public Button::Listener, public Slider::Listener, public MultiTimer
{
public:
    explicit SoundboardAudioProcessorEditor(SoundboardAudioProcessor &);
    ~SoundboardAudioProcessorEditor();

    // Button::Listener
    void buttonClicked(Button *buttonThatWasClicked) override;

    // Slider::Listener
    void sliderValueChanged(Slider *slider) override;

    void paint(Graphics &) override;
    void resized() override;
    void refresh();
    void timerCallback(int timerID) override;

private:
    static const int TimerIdUpdate  = 1;
    static const int TimerIdBlink   = 2;
    static const int TimerIdRefresh = 3;

    ScopedPointer<SoundboardTableComponent>    table;
    ScopedPointer<SoundboardGridComponent>     grid;

    ScopedPointer<ResizableCornerComponent> resizableCornerComponent;
    ComponentBoundsConstrainer              resizeLimits;
    ScopedPointer<TextButton>               loadDirectoryButton;

    ScopedPointer<TextButton> duckButton;
    
    ScopedPointer<TextButton> gridButton;
    ScopedPointer<TextButton> listButton;

    ScopedPointer<Bar>        topBar;
    ScopedPointer<TextButton> settingsButton;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoundboardAudioProcessor &processor;
    bool                     mPauseState;
    bool                     mTimerState;

#if JUCE_WINDOWS
#if JUCE_OPENGL
    OpenGLContext openGLContext;
#endif
#endif
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardAudioProcessorEditor)
};

#endif // PLUGINEDITOR_H_INCLUDED
