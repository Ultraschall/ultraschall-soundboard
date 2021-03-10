/*
  ==============================================================================

    SettingsComponent.h
    Created: 17 Jan 2015 11:14:17pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef SETTINGSCOMPONENT_H_INCLUDED
#define SETTINGSCOMPONENT_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>

#include "../LookAndFeel.h"
#include "../../../plugin/PluginProcessor.h"

using namespace juce;

#if SHOW_AUDIO_SETTINGS
extern ScopedPointer<AudioDeviceManager> deviceManager;
#endif

class SoundboardSettingsComponent: public Component,
                                   public ComboBox::Listener,
                                   public Button::Listener,
                                   public TextEditor::Listener,
                                   public Slider::Listener,
                                   public OscParameterListener
{
public:
    explicit SoundboardSettingsComponent(SoundboardAudioProcessor&);
    ~SoundboardSettingsComponent();

    // Component
    void resized() override;
    void paint(Graphics &g) override;

    // ComboBox Listener
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

    // Button Listener
    void buttonClicked(Button* buttonThatWasClicked) override;

    // TextEditor Listener
    void textEditorTextChanged(TextEditor& editor) override;

    // Slider Listener
    void sliderValueChanged (Slider* slider) override;

    // OscParameterListener
    void handleOscParameterMessage(OscParameter *parameter) override;

private:
    ScopedPointer<Bar> globalBar;
    ScopedPointer<Label> globalLabel;

    ScopedPointer<Label> themeLabel;
    ScopedPointer<ComboBox> themeComboBox;

    ScopedPointer<Slider> duckingSlider;
    ScopedPointer<Label> duckingLabel;

    ScopedPointer<Slider> fadeOutSlider;
    ScopedPointer<Label> fadeOutLabel;

    ScopedPointer<Bar> oscBar;
    ScopedPointer<Label> oscLabel;

    ScopedPointer<ToggleButton> oscLocalEnabledToggleButton;
    ScopedPointer<TextEditor> oscLocalHostnameTextEditor;
    ScopedPointer<TextEditor> oscLocalPortNumberTextEditor;

    ScopedPointer<ToggleButton> oscRemoteEnabledToggleButton;
    ScopedPointer<TextEditor> oscRemoteHostnameTextEditor;
    ScopedPointer<TextEditor> oscRemotePortNumberTextEditor;

    ScopedPointer<ToggleButton> oscRepeaterEnabledToggleButton;
    ScopedPointer<TextEditor> oscRepeaterHostnameTextEditor;
    ScopedPointer<TextEditor> oscRepeaterPortNumberTextEditor;

    ScopedPointer<Bar> audioBar;
    ScopedPointer<Label> audioLabel;
    ScopedPointer<AudioDeviceSelectorComponent> audioDeviceSelectorComponent;

    SoundboardAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardSettingsComponent)
};


#endif  // SETTINGSCOMPONENT_H_INCLUDED
