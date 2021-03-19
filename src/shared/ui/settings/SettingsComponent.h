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
    ~SoundboardSettingsComponent() override;

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
    Bar globalBar;
    Label globalLabel;

    Label themeLabel;
    ComboBox themeComboBox;

    Slider duckingSlider;
    Label duckingLabel;

    Slider fadeOutSlider;
    Label fadeOutLabel;

    Bar oscBar;
    Label oscLabel;

    ToggleButton oscLocalEnabledToggleButton;
    TextEditor oscLocalHostnameTextEditor;
    TextEditor oscLocalPortNumberTextEditor;

    ToggleButton oscRemoteEnabledToggleButton;
    TextEditor oscRemoteHostnameTextEditor;
    TextEditor oscRemotePortNumberTextEditor;

    ToggleButton oscRepeaterEnabledToggleButton;
    TextEditor oscRepeaterHostnameTextEditor;
    TextEditor oscRepeaterPortNumberTextEditor;

    Bar audioBar;
    Label audioLabel;
    std::unique_ptr<AudioDeviceSelectorComponent> audioDeviceSelectorComponent;

    SoundboardAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardSettingsComponent)
};


#endif  // SETTINGSCOMPONENT_H_INCLUDED
