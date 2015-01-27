/*
  ==============================================================================

    SettingsComponent.cpp
    Created: 17 Jan 2015 11:14:17pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "SettingsComponent.h"

SoundboardSettingsComponent::SoundboardSettingsComponent(SoundboardAudioProcessor& p)
    : processor(p)
{
    addAndMakeVisible(themeLabel = new Label());
    themeLabel->setText(TRANS("Theme:"), dontSendNotification);
    addAndMakeVisible(themeComboBox = new ComboBox());
    themeComboBox->addItem("Tomorrow", static_cast<int>(ThemeTomorrow));
    themeComboBox->addItem("TomorrowNight", static_cast<int>(ThemeTomorrowNight));
    themeComboBox->addItem("TomorrowNightBlue", static_cast<int>(ThemeTomorrowNightBlue));
    themeComboBox->addItem("TomorrowNightBright", static_cast<int>(ThemeTomorrowNightBright));
    themeComboBox->addItem("TomorrowNightEighties", static_cast<int>(ThemeTomorrowNightEighties));
    themeComboBox->setSelectedId(p.getPropertiesFile()->getIntValue(ThemeIdentifier, static_cast<int>(ThemeTomorrowNightEighties)), dontSendNotification);
    themeComboBox->addListener(this);

    addAndMakeVisible(fadeOutLabel = new Label());
    fadeOutLabel->setText(TRANS("Fade-Out:"), dontSendNotification);
    addAndMakeVisible(fadeOutSlider = new Slider());
    fadeOutSlider->setRange(3, 30, 1);
    fadeOutSlider->setValue(processor.getFadeOutSeconds());
    fadeOutSlider->setSliderStyle(Slider::SliderStyle::Rotary);
    fadeOutSlider->setTextValueSuffix("s");
    fadeOutSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxRight, true, 48, 24);
    fadeOutSlider->addListener(this);

    addAndMakeVisible(oscBar = new Bar());
    addAndMakeVisible(oscLabel = new Label());
    oscLabel->setText(TRANS("OSC"), dontSendNotification);

    addAndMakeVisible(oscLocalEnabledToggleButton = new ToggleButton());
    oscLocalEnabledToggleButton->setButtonText(TRANS("Receive:"));
    oscLocalEnabledToggleButton->setToggleState(p.getPropertiesFile()->getBoolValue(OscReceivePortNumberIdentifier.toString()), dontSendNotification);
    oscLocalEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscLocalHostnameTextEditor = new TextEditor());
    oscLocalHostnameTextEditor->setMultiLine(false);
    oscLocalHostnameTextEditor->setReadOnly(true);
    oscLocalHostnameTextEditor->setText(SystemStats::getComputerName(), dontSendNotification);
    addAndMakeVisible(oscLocalPortNumberTextEditor = new TextEditor());
    oscLocalPortNumberTextEditor->setMultiLine(false);    oscLocalPortNumberTextEditor->setReadOnly(oscLocalEnabledToggleButton->getToggleState());
    oscLocalPortNumberTextEditor->setText(p.getPropertiesFile()->getValue(OscReceivePortNumberIdentifier.toString(), ""));

    addAndMakeVisible(oscRemoteEnabledToggleButton = new ToggleButton());
    oscRemoteEnabledToggleButton->setButtonText(TRANS("Send:"));
    oscRemoteEnabledToggleButton->setToggleState(p.getPropertiesFile()->getBoolValue(OscRemoteEnabledIdentifier.toString()), dontSendNotification);
    oscRemoteEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscRemoteHostnameTextEditor = new TextEditor());
    oscRemoteHostnameTextEditor->setMultiLine(false);
    oscRemoteHostnameTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemoteHostnameTextEditor->setText(p.getPropertiesFile()->getValue(OscRemoteHostnameIdentifier.toString(), ""), dontSendNotification);
    addAndMakeVisible(oscRemotePortNumberTextEditor = new TextEditor());
    oscRemotePortNumberTextEditor->setMultiLine(false);
    oscRemotePortNumberTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemotePortNumberTextEditor->setText(p.getPropertiesFile()->getValue(OscRemotePortNumberIdentifier.toString(), ""), dontSendNotification);

    addAndMakeVisible(oscRepeaterEnabledToggleButton = new ToggleButton());
    oscRepeaterEnabledToggleButton->setButtonText(TRANS("Repeater:"));
    oscRepeaterEnabledToggleButton->setToggleState(p.getPropertiesFile()->getBoolValue(OscRepeaterEnabledIdentifier.toString()), dontSendNotification);
    oscRepeaterEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscRepeaterHostnameTextEditor = new TextEditor());
    oscRepeaterHostnameTextEditor->setMultiLine(false);
    oscRepeaterHostnameTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterHostnameTextEditor->setText(p.getPropertiesFile()->getValue(OscRepeaterHostnameIdentifier.toString(), ""), dontSendNotification);
    addAndMakeVisible(oscRepeaterPortNumberTextEditor = new TextEditor());
    oscRepeaterPortNumberTextEditor->setMultiLine(false);
    oscRepeaterPortNumberTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterPortNumberTextEditor->setText(p.getPropertiesFile()->getValue(OscRepeaterPortNumberIdentifier.toString(), ""), dontSendNotification);

    addAndMakeVisible(loggerListBox = new ListBox);

    p.addOscParameterListener(this, "/ultraschall/soundboard/fadeout");
}

SoundboardSettingsComponent::~SoundboardSettingsComponent()
{
    themeLabel = nullptr;
    themeComboBox = nullptr;

    fadeOutLabel = nullptr;
    fadeOutSlider = nullptr;

    oscBar = nullptr;
    oscLabel = nullptr;

    oscLocalEnabledToggleButton = nullptr;
    oscLocalHostnameTextEditor = nullptr;
    oscLocalPortNumberTextEditor = nullptr;

    oscRemoteEnabledToggleButton = nullptr;
    oscRemoteHostnameTextEditor = nullptr;
    oscRemotePortNumberTextEditor = nullptr;

    oscRepeaterEnabledToggleButton = nullptr;
    oscRepeaterHostnameTextEditor = nullptr;
    oscRepeaterPortNumberTextEditor = nullptr;

    loggerListBox = nullptr;

    processor.removeOscParameterListener(this);
}

// Component
void SoundboardSettingsComponent::resized() {
    themeLabel->setBounds(3, 3, 80, 24);
    themeComboBox->setBounds(86, 3, getWidth() - 89, 24);

    fadeOutLabel->setBounds(3, 32, 80, 24);
    fadeOutSlider->setBounds(86, 32, 72, 24);

    oscBar->setBounds(0, 59, getWidth(), 32);
    oscLabel->setBounds(3, 64, 80, 24);

    oscLocalEnabledToggleButton->setBounds(3, 96, 80, 24);
    oscLocalHostnameTextEditor->setBounds(86, 96, getWidth() - 144, 24);
    oscLocalPortNumberTextEditor->setBounds(getWidth() - 51, 96, 48, 24);

    oscRemoteEnabledToggleButton->setBounds(3, 128, 80, 24);
    oscRemoteHostnameTextEditor->setBounds(86, 128, getWidth() - 144, 24);
    oscRemotePortNumberTextEditor->setBounds(getWidth() - 51, 128, 48, 24);

    oscRepeaterEnabledToggleButton->setBounds(3, 160, 80, 24);
    oscRepeaterHostnameTextEditor->setBounds(86, 160, getWidth() - 144, 24);
    oscRepeaterPortNumberTextEditor->setBounds(getWidth() - 51, 160, 48, 24);

    loggerListBox->setBounds(3, 192, getWidth() - 6, getHeight() - 195);
}

// ComboBox Listener
void SoundboardSettingsComponent::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    auto val = static_cast<Themes>(comboBoxThatHasChanged->getSelectedId());
    SwitchTheme(val);
    processor.getPropertiesFile()->setValue(ThemeIdentifier.toString(), val);
    processor.getActiveEditor()->sendLookAndFeelChange();
}

// Button Listener
void SoundboardSettingsComponent::buttonClicked(Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == oscLocalEnabledToggleButton)
    {
        oscLocalPortNumberTextEditor->setReadOnly(oscLocalEnabledToggleButton->getToggleState());
        processor.getPropertiesFile()->setValue(OscReceiveEnabledIdentifier.toString(), oscLocalEnabledToggleButton->getToggleState());
    }
    else if(buttonThatWasClicked == oscRemoteEnabledToggleButton)
    {
        oscRemoteHostnameTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
        oscRemotePortNumberTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
        processor.getPropertiesFile()->setValue(OscRemoteEnabledIdentifier.toString(), oscRemoteEnabledToggleButton->getToggleState());
    }
    else if(buttonThatWasClicked == oscRepeaterEnabledToggleButton)
    {
        oscRepeaterHostnameTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
        oscRepeaterPortNumberTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
        processor.getPropertiesFile()->setValue(OscRepeaterEnabledIdentifier.toString(), oscRepeaterEnabledToggleButton->getToggleState());
    }
}

// TextEditor Listener
void SoundboardSettingsComponent::textEditorTextChanged(TextEditor& editor)
{
    if (&editor == oscLocalPortNumberTextEditor)
    {
        processor.getPropertiesFile()->setValue(OscReceivePortNumberIdentifier.toString(), oscLocalPortNumberTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRemoteHostnameTextEditor)
    {
        processor.getPropertiesFile()->setValue(OscRemoteHostnameIdentifier.toString(), oscRemoteHostnameTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRemotePortNumberTextEditor)
    {
        processor.getPropertiesFile()->setValue(OscRemotePortNumberIdentifier.toString(), oscRemotePortNumberTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRepeaterHostnameTextEditor)
    {
        processor.getPropertiesFile()->setValue(OscRepeaterHostnameIdentifier.toString(), oscRepeaterHostnameTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRepeaterPortNumberTextEditor)
    {
        processor.getPropertiesFile()->setValue(OscRepeaterPortNumberIdentifier.toString(), oscRepeaterPortNumberTextEditor->getText().getIntValue());
    }
}

// Slider Listener
void SoundboardSettingsComponent::sliderValueChanged (Slider* slider)
{
    processor.setOscParameterValue("/ultraschall/soundboard/fadeout", static_cast<float>(slider->valueToProportionOfLength(slider->getValue())));
}

// ListBoxModel
int SoundboardSettingsComponent::getNumRows()
{
    return logger.size();
}

void SoundboardSettingsComponent::paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected)
{
    g.setColour(ThemeForeground1);
    g.drawText(logger[rowNumber], 0, 0, width, height, Justification::centredLeft);
}

// ChangeListener
void SoundboardSettingsComponent::changeListenerCallback (ChangeBroadcaster *source)
{
    OscParameter* parameter = dynamic_cast<OscParameter*>(source);
    if (parameter->addressMatch("/ultraschall/soundboard/fadeout"))
    {
        fadeOutSlider->setValue(fadeOutSlider->proportionOfLengthToValue(parameter->getValue()), dontSendNotification);
    }
}
