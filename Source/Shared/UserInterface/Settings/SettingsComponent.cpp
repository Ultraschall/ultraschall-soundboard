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
    addAndMakeVisible(globalBar = new Bar());
    addAndMakeVisible(globalLabel = new Label());
    globalLabel->setText(TRANS("General"), dontSendNotification);

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
    fadeOutSlider->setValue(processor.getFadeOutSeconds(), dontSendNotification);
    fadeOutSlider->setSliderStyle(Slider::SliderStyle::Rotary);
    fadeOutSlider->setTextValueSuffix("s");
    fadeOutSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxRight, true, 48, 24);
    fadeOutSlider->addListener(this);

    addAndMakeVisible(duckingLabel = new Label());
    duckingLabel->setText(TRANS("Ducking:"), dontSendNotification);
    addAndMakeVisible(duckingSlider = new Slider());
    duckingSlider->setRange(0, 100, 1);
    duckingSlider->setValue(duckingSlider->proportionOfLengthToValue(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/duck/percentage")), dontSendNotification);
    duckingSlider->setSliderStyle(Slider::SliderStyle::Rotary);
    duckingSlider->setTextValueSuffix("%");
    duckingSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxRight, true, 48, 24);
    duckingSlider->addListener(this);

    addAndMakeVisible(oscBar = new Bar());
    addAndMakeVisible(oscLabel = new Label());
    oscLabel->setText(TRANS("OSC"), dontSendNotification);

    // receiver
    addAndMakeVisible(oscLocalEnabledToggleButton = new ToggleButton());
    oscLocalEnabledToggleButton->setButtonText(TRANS("Receive:"));
    oscLocalEnabledToggleButton->addListener(this);
    oscLocalEnabledToggleButton->setToggleState(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/receive/enabled"), dontSendNotification);
    addAndMakeVisible(oscLocalHostnameTextEditor = new TextEditor());
    oscLocalHostnameTextEditor->setMultiLine(false);
    oscLocalHostnameTextEditor->setReadOnly(true);
    oscLocalHostnameTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/receive/host"), dontSendNotification);
    addAndMakeVisible(oscLocalPortNumberTextEditor = new TextEditor());
    oscLocalPortNumberTextEditor->setMultiLine(false);
    oscLocalPortNumberTextEditor->setReadOnly(oscLocalEnabledToggleButton->getToggleState());
    oscLocalPortNumberTextEditor->addListener(this);
    oscLocalPortNumberTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/receive/port"), dontSendNotification);

    addAndMakeVisible(oscRemoteEnabledToggleButton = new ToggleButton());
    oscRemoteEnabledToggleButton->setButtonText(TRANS("Send:"));
    oscRemoteEnabledToggleButton->addListener(this);
    oscRemoteEnabledToggleButton->setToggleState(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/remote/enabled"), dontSendNotification);
    addAndMakeVisible(oscRemoteHostnameTextEditor = new TextEditor());
    oscRemoteHostnameTextEditor->setMultiLine(false);
    oscRemoteHostnameTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemoteHostnameTextEditor->addListener(this);
    oscRemoteHostnameTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/remote/host"), dontSendNotification);
    addAndMakeVisible(oscRemotePortNumberTextEditor = new TextEditor());
    oscRemotePortNumberTextEditor->setMultiLine(false);
    oscRemotePortNumberTextEditor->setReadOnly(oscRemoteEnabledToggleButton->getToggleState());
    oscRemotePortNumberTextEditor->addListener(this);
    oscRemotePortNumberTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/remote/port"), dontSendNotification);

    addAndMakeVisible(oscRepeaterEnabledToggleButton = new ToggleButton());
    oscRepeaterEnabledToggleButton->setButtonText(TRANS("Repeater:"));
    oscRepeaterEnabledToggleButton->addListener(this);
    oscRepeaterEnabledToggleButton->setToggleState(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/enabled"), dontSendNotification);
    addAndMakeVisible(oscRepeaterHostnameTextEditor = new TextEditor());
    oscRepeaterHostnameTextEditor->setMultiLine(false);
    oscRepeaterHostnameTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterHostnameTextEditor->addListener(this);
    oscRepeaterHostnameTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/host"), dontSendNotification);
    addAndMakeVisible(oscRepeaterPortNumberTextEditor = new TextEditor());
    oscRepeaterPortNumberTextEditor->setMultiLine(false);
    oscRepeaterPortNumberTextEditor->setReadOnly(oscRepeaterEnabledToggleButton->getToggleState());
    oscRepeaterPortNumberTextEditor->addListener(this);
    oscRepeaterPortNumberTextEditor->setText(processor.getOscManager()->getOscParameterValue("/ultraschall/soundboard/setup/osc/repeater/port"), dontSendNotification);

    #if SHOW_AUDIO_SETTINGS
    addAndMakeVisible(audioBar = new Bar());
    addAndMakeVisible(audioLabel = new Label());
    audioLabel->setText(TRANS("Audio Settings"), dontSendNotification);
    addAndMakeVisible(audioDeviceSelectorComponent = new AudioDeviceSelectorComponent(*deviceManager,
            processor.getNumInputChannels(),
            processor.getNumInputChannels(),
            processor.getNumOutputChannels(),
            processor.getNumOutputChannels(),
            true,
            false,
            true,
            false));
    #endif

    // listen to fadeout changes
    processor.getOscManager()->addOscParameterListener(this, "/ultraschall/soundboard/fadeout$");
    // listen to all setup changes
    processor.getOscManager()->addOscParameterListener(this, "/ultraschall/soundboard/setup/.+");
    resized();
}

SoundboardSettingsComponent::~SoundboardSettingsComponent()
{
    processor.getOscManager()->removeOscParameterListener(this);

    globalBar = nullptr;
    globalLabel = nullptr;

    themeLabel = nullptr;
    themeComboBox = nullptr;

    fadeOutLabel = nullptr;
    fadeOutSlider = nullptr;

    duckingLabel = nullptr;
    duckingSlider = nullptr;

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

    audioBar = nullptr;
    audioLabel = nullptr;

    audioDeviceSelectorComponent = nullptr;
}

// Component
void SoundboardSettingsComponent::resized()
{
    int elementHeight = 32;
    int elementY = 0;
    globalBar->setBounds(0, elementY, getWidth(), elementHeight);
    globalLabel->setBounds(3, elementY + 6, getWidth() - 6, 24);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    themeLabel->setBounds(3, elementY, 80, elementHeight);
    themeComboBox->setBounds(86, elementY, getWidth() - 89, elementHeight);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    fadeOutLabel->setBounds(3, elementY, 80, elementHeight);
    fadeOutSlider->setBounds(86, elementY, 72, elementHeight);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    duckingLabel->setBounds(3, elementY, 80, elementHeight);
    duckingSlider->setBounds(86, elementY, 72, elementHeight);

    elementY = elementY + elementHeight + 3;
    elementHeight = 32;

    oscBar->setBounds(0, elementY, getWidth(), elementHeight);
    oscLabel->setBounds(3, elementY + 6, getWidth() - 6, 24);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    oscLocalEnabledToggleButton->setBounds(3, elementY, 80, elementHeight);
    oscLocalHostnameTextEditor->setBounds(86, elementY, getWidth() - 144, elementHeight);
    oscLocalPortNumberTextEditor->setBounds(getWidth() - 51, elementY, 48, elementHeight);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    oscRemoteEnabledToggleButton->setBounds(3, elementY, 80, elementHeight);
    oscRemoteHostnameTextEditor->setBounds(86, elementY, getWidth() - 144, elementHeight);
    oscRemotePortNumberTextEditor->setBounds(getWidth() - 51, elementY, 48, elementHeight);

    elementY = elementY + elementHeight + 3;
    elementHeight = 24;

    oscRepeaterEnabledToggleButton->setBounds(3, elementY, 80, elementHeight);
    oscRepeaterHostnameTextEditor->setBounds(86, elementY, getWidth() - 144, elementHeight);
    oscRepeaterPortNumberTextEditor->setBounds(getWidth() - 51, elementY, 48, elementHeight);

    #if SHOW_AUDIO_SETTINGS
    elementY = elementY + elementHeight + 3;
    elementHeight = 32;

    audioBar->setBounds(0, elementY, getWidth(), elementHeight);
    audioLabel->setBounds(3, elementY + 6, getWidth() - 6, 24);

    elementY = elementY + elementHeight + 3;
    //elementHeight = 200;

    audioDeviceSelectorComponent->setBounds(3, elementY, getWidth() - 6, getHeight() - elementY);
    #endif
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
    } else if (slider == duckingSlider) {
        processor.getOscManager()->setOscParameterValue("/ultraschall/soundboard/duck/percentage", static_cast<float>(duckingSlider->valueToProportionOfLength(duckingSlider->getValue())));
    }
}

// Osc Parameter Listener
void SoundboardSettingsComponent::handleOscParameterMessage(OscParameter* parameter)
{
    if (parameter->addressMatch("/ultraschall/soundboard/fadeout")) {
        fadeOutSlider->setValue(fadeOutSlider->proportionOfLengthToValue(parameter->getValue()), dontSendNotification);
    } else if (parameter->addressMatch("/ultraschall/soundboard/duck/percentage")) {
        duckingSlider->setValue(duckingSlider->proportionOfLengthToValue(parameter->getValue()), dontSendNotification);
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
