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
    themeComboBox->setSelectedId(processor.getPropertiesFile()->getIntValue(ThemeIdentifier), dontSendNotification);
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

    // receiver
    addAndMakeVisible(oscLocalEnabledToggleButton = new ToggleButton());
    oscLocalEnabledToggleButton->setButtonText(TRANS("Receive:"));
    oscLocalEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscLocalHostnameTextEditor = new TextEditor());
    oscLocalHostnameTextEditor->setMultiLine(false);
    oscLocalHostnameTextEditor->setText(SystemStats::getComputerName(), dontSendNotification);
    oscLocalHostnameTextEditor->setReadOnly(true);
    addAndMakeVisible(oscLocalPortNumberTextEditor = new TextEditor());
    oscLocalPortNumberTextEditor->setMultiLine(false);
    oscLocalPortNumberTextEditor->setReadOnly(oscLocalEnabledToggleButton->getToggleState());
    oscLocalPortNumberTextEditor->addListener(this);

    addAndMakeVisible(oscRemoteEnabledToggleButton = new ToggleButton());
    oscRemoteEnabledToggleButton->setButtonText(TRANS("Send:"));
    oscRemoteEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscRemoteHostnameTextEditor = new TextEditor());
    oscRemoteHostnameTextEditor->setMultiLine(false);
    oscRemoteHostnameTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemoteHostnameTextEditor->addListener(this);
    addAndMakeVisible(oscRemotePortNumberTextEditor = new TextEditor());
    oscRemotePortNumberTextEditor->setMultiLine(false);
    oscRemotePortNumberTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemotePortNumberTextEditor->addListener(this);

    addAndMakeVisible(oscRepeaterEnabledToggleButton = new ToggleButton());
    oscRepeaterEnabledToggleButton->setButtonText(TRANS("Repeater:"));
    oscRepeaterEnabledToggleButton->addListener(this);
    addAndMakeVisible(oscRepeaterHostnameTextEditor = new TextEditor());
    oscRepeaterHostnameTextEditor->setMultiLine(false);
    oscRepeaterHostnameTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterHostnameTextEditor->addListener(this);
    addAndMakeVisible(oscRepeaterPortNumberTextEditor = new TextEditor());
    oscRepeaterPortNumberTextEditor->setMultiLine(false);
    oscRepeaterPortNumberTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterPortNumberTextEditor->addListener(this);

    // listen to fadeout changes
    processor.getOscManager()->addOscParameterListener(this, "/ultraschall/soundboard/fadeout$");
    // listen to all setup changes
    processor.getOscManager()->addOscParameterListener(this, "/ultraschall/soundboard/setup/.+");
}

SoundboardSettingsComponent::~SoundboardSettingsComponent()
{
    processor.getOscManager()->removeOscParameterListener(this);
    
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
}

// Component
void SoundboardSettingsComponent::resized()
{
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
}

void SoundboardSettingsComponent::paint(Graphics &g) {
    g.fillAll(ThemeBackground2);
}

// ComboBox Listener
void SoundboardSettingsComponent::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == themeComboBox) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/ui/theme",
            themeComboBox->getSelectedId());
    }
}

// Button Listener
void SoundboardSettingsComponent::buttonClicked(Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == oscLocalEnabledToggleButton) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/enabled",
            oscLocalEnabledToggleButton->getToggleState());
    }
    else if (buttonThatWasClicked == oscRemoteEnabledToggleButton) {
        oscRemoteHostnameTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
        oscRemotePortNumberTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/enabled",
            oscRemoteEnabledToggleButton->getToggleState());
    }
    else if (buttonThatWasClicked == oscRepeaterEnabledToggleButton) {
        oscRepeaterHostnameTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
        oscRepeaterPortNumberTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/enabled",
            oscRepeaterEnabledToggleButton->getToggleState());
    }
}

// TextEditor Listener
void SoundboardSettingsComponent::textEditorTextChanged(TextEditor& editor)
{
    if (&editor == oscLocalPortNumberTextEditor) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/receive/port",
            oscLocalPortNumberTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRemoteHostnameTextEditor) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/host",
            oscRemoteHostnameTextEditor->getText());
    }
    else if (&editor == oscRemotePortNumberTextEditor) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/remote/port",
            oscRemotePortNumberTextEditor->getText().getIntValue());
    }
    else if (&editor == oscRepeaterHostnameTextEditor) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/host",
            oscRepeaterHostnameTextEditor->getText());
    }
    else if (&editor == oscRepeaterPortNumberTextEditor) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/port",
            oscRepeaterPortNumberTextEditor->getText().getIntValue());
    }
}

// Slider Listener
void SoundboardSettingsComponent::sliderValueChanged(Slider* slider)
{
    if (slider == fadeOutSlider) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/fadeout", static_cast<float>(slider->valueToProportionOfLength(slider->getValue())));
    }
}

// Osc Parameter Listener
void SoundboardSettingsComponent::handleOscParameterMessage(OscParameter* parameter)
{
    if (parameter->addressMatch("/ultraschall/soundboard/fadeout")) {
        fadeOutSlider->setValue(fadeOutSlider->proportionOfLengthToValue(parameter->getValue()), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/receive/port")) {
        oscLocalPortNumberTextEditor->setText(parameter->getValue(), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/receive/enabled")) {
        oscLocalEnabledToggleButton->setToggleState(parameter->getValue(), dontSendNotification);
        oscLocalPortNumberTextEditor->setReadOnly(parameter->getValue());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/host")) {
        oscRemoteHostnameTextEditor->setText(parameter->getValue(), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/port")) {
        oscRemotePortNumberTextEditor->setText(parameter->getValue(), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/remote/enabled")) {
        oscRemoteEnabledToggleButton->setToggleState(parameter->getValue(), dontSendNotification);
        oscRemoteHostnameTextEditor->setReadOnly(parameter->getValue());
        oscRemotePortNumberTextEditor->setReadOnly(parameter->getValue());
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/host")) {
        oscRepeaterHostnameTextEditor->setText(parameter->getValue(), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/port")) {
        oscRepeaterPortNumberTextEditor->setText(parameter->getValue(), dontSendNotification);
    }
    else if (parameter->addressMatch("/ultraschall/soundboard/setup/osc/repeater/enabled")) {
        oscRepeaterEnabledToggleButton->setToggleState(parameter->getValue(), dontSendNotification);
        oscRepeaterHostnameTextEditor->setReadOnly(parameter->getValue());
        oscRepeaterPortNumberTextEditor->setReadOnly(parameter->getValue());
    }
}
