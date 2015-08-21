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

class SoundboardAudioProcessorEditor : public AudioProcessorEditor, public Button::Listener, public Slider::Listener, public MultiTimer, public OscParameterListener
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

    // OscParameterListener
    void handleOscParameterMessage(OscParameter *parameter) override;
    
    void preload();
private:
    void showTable();
    void showGrid();
    
    static const int TimerIdRefresh = 1;

    ScopedPointer<SoundboardTableComponent>    table;
    ScopedPointer<SoundboardGridComponent>     grid;

    ScopedPointer<ResizableCornerComponent> resizableCornerComponent;
    ComponentBoundsConstrainer              resizeLimits;
    ScopedPointer<TextButton>               loadDirectoryButton;

    ScopedPointer<TextButton> duckButton;
    
    ScopedPointer<TextButton> gridButton;
    ScopedPointer<TextButton> listButton;
    
    ScopedPointer<Slider>     gainSlider;
    ScopedPointer<BubbleMessageComponent> gainBubble;


    ScopedPointer<Bar>        topBar;
    ScopedPointer<TextButton> settingsButton;
    ScopedPointer<TextButton> lockButton;
    
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
