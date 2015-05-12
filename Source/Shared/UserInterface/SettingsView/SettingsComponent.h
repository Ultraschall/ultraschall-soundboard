/*
  ==============================================================================

    SettingsComponent.h
    Created: 17 Jan 2015 11:14:17pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef SETTINGSCOMPONENT_H_INCLUDED
#define SETTINGSCOMPONENT_H_INCLUDED

#include "JuceHeader.h"
#include "LookAndFeel.h"
#include "PluginProcessor.h"

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

    // ComboBox Listener
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

    // Button Listener
    void buttonClicked(Button* buttonThatWasClicked) override;

    // TextEditor Listener
    void textEditorTextChanged(TextEditor& editor) override;

    // Slider Listener
    void sliderValueChanged (Slider* slider);

    // OscParameterListener
    void handleOscParameterMessage(OscParameter *parameter) override;

private:
    ScopedPointer<Label> themeLabel;
    ScopedPointer<ComboBox> themeComboBox;

    ScopedPointer<Slider> fadeOutSlider;
    ScopedPointer<Label> fadeOutLabel;

    ScopedPointer<Slider> gainSlider;
    ScopedPointer<Label> gainLabel;

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

    SoundboardAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardSettingsComponent)
};


#endif  // SETTINGSCOMPONENT_H_INCLUDED
