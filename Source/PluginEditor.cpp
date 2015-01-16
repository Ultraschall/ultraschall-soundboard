/*
 ==============================================================================

 PluginEditor.cpp
 Author:  Daniel Lindenfelser

 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundboardAudioProcessorEditor::SoundboardAudioProcessorEditor(
    SoundboardAudioProcessor& p)
    : AudioProcessorEditor(&p)
    , processor(p)
    , mPauseState(true)
    , mTimerState(true)
{
    addAndMakeVisible(topBar = new Bar());

    addAndMakeVisible(fadeOutSlider = new Slider());
    fadeOutSlider->setRange(1, 30, 1);
    fadeOutSlider->setSkewFactor(0.5);
    fadeOutSlider->setValue(processor.getFadeOutSeconds());
    fadeOutSlider->setSliderStyle(Slider::SliderStyle::Rotary);
    fadeOutSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    fadeOutSlider->addListener(this);

    addAndMakeVisible(fadeOutLabel = new Label());
    fadeOutLabel->setColour(Label::ColourIds::textColourId, ThemeForeground1);
    fadeOutLabel->setText("Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s", NotificationType::dontSendNotification);

    addAndMakeVisible(loadDirectoryButton = new AwesomeButton(FA_FOLDER_OPEN_O));
    loadDirectoryButton->setButtonText("");
    loadDirectoryButton->addListener(this);

    addAndMakeVisible(gridButton = new TextButton());
    gridButton->setButtonText("G");
    gridButton->addListener(this);
    gridButton->setConnectedEdges(TextButton::ConnectedOnLeft);

    addAndMakeVisible(listButton = new TextButton());
    listButton->setButtonText("L");
    listButton->addListener(this);
    listButton->setConnectedEdges(TextButton::ConnectedOnRight);

    addAndMakeVisible(grid = new SoundboardGridComponent(p));
    grid->setVisible(false);
    addAndMakeVisible(table = new SoundboardTableComponent(p));

    addAndMakeVisible(settingsButton = new AwesomeButton(FA_COG));
    settingsButton->setButtonText("");
    settingsButton->addListener(this);

    addAndMakeVisible(oscActivityIndicator = new ActivityIndicator());
    oscActivityIndicator->setTitle(CharPointer_UTF8("OSC Aktivit\xc3\xa4t"));

    if (processor.wrapperType != AudioProcessor::wrapperType_Standalone)
    {
        addAndMakeVisible (resizer = new ResizableCornerComponent (this, &resizeLimits));
        resizeLimits.setSizeLimits (380, 320, 1024, 768);
    }

    addAndMakeVisible(settingsComponent = new OscSettings (processor.getPropertiesFile (), processor.getOscServer (), p));
    settingsComponent->setVisible (false);
    settingsComponent->toBack ();
    listButton->setEnabled(false);

    refresh();

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(processor.getWindowWidth(), processor.getWindowHeight());

    startTimer(TimerIdBlink, (int)(1000 * 0.5));
    startTimer(TimerIdUpdate, 50);
    startTimer(TimerIdRefresh, (int)(1000 * 0.5));
}

SoundboardAudioProcessorEditor::~SoundboardAudioProcessorEditor()
{
    stopTimer(TimerIdBlink);
    stopTimer(TimerIdUpdate);
    stopTimer(TimerIdRefresh);
    topBar = nullptr;
    fadeOutSlider = nullptr;
    fadeOutLabel = nullptr;
    loadDirectoryButton = nullptr;
    table = nullptr;
    grid = nullptr;
    resizer = nullptr;
    settingsButton = nullptr;
    oscActivityIndicator = nullptr;
    gridButton = nullptr;
}

//==============================================================================
void SoundboardAudioProcessorEditor::paint(Graphics& g)
{
    g.fillAll(ThemeBackground1);
}

void SoundboardAudioProcessorEditor::resized()
{
    topBar->setBounds(0, 0, getWidth(), 32);

    fadeOutSlider->setBounds(3, 5, 24, 24);
    fadeOutLabel->setBounds(27, 5, 150, 24);

    settingsButton->setBounds(getWidth() - 32, 5, 32, 24);
    loadDirectoryButton->setBounds(getWidth() - 67, 5, 32, 24);

    gridButton->setBounds(getWidth() - 160, 11, 60, 18);
    listButton->setBounds(getWidth() - 220, 11, 60, 18);

    table->setBounds(0, 32, getWidth(), getHeight() - 32);
    grid->setBounds(0, 32, getWidth(), getHeight() - 32);

    if (resizer)
    {
        resizer->setBounds (getWidth () - 16, getHeight () - 16, 16, 16);
    }

    oscActivityIndicator->setBounds(180, 5, 120, 24);

    processor.storeWindowWidth(getWidth());
    processor.storeWindowHeight(getHeight());

    settingsComponent->setBounds (0, 0, getWidth (), getHeight ());
}

void SoundboardAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
    if (loadDirectoryButton == buttonThatWasClicked) {
        FileChooser chooser("Open...");
        if (chooser.browseForDirectory()) {
            File directory = chooser.getResult();
            if (directory.isDirectory()) {
                processor.openDirectory(directory);
                table->updateContent();
                grid->updateContent();
            }
        }
    }
    else if (settingsButton == buttonThatWasClicked) {
        settingsComponent->setVisible (!settingsComponent->isVisible ());
        if (settingsComponent->isVisible ())
        {
            settingsComponent->toFront (true);
        }
        else
        {
            settingsComponent->toBack ();
        }
    }
    else if (gridButton == buttonThatWasClicked) {
        gridButton->setEnabled(false);
        listButton->setEnabled(true);

        table->setVisible(false);
        grid->setVisible(true);
        grid->toFront(true);
        if (resizer) {
            resizer->toFront(false);
        }
    }
    else if (listButton == buttonThatWasClicked) {
        listButton->setEnabled(false);
        gridButton->setEnabled(true);

        grid->setVisible(false);
        table->setVisible(true);
        table->toFront(true);
        if (resizer) {
            resizer->toFront(false);
        }
    }
}

void SoundboardAudioProcessorEditor::timerCallback(int timerID)
{
    if (timerID == TimerIdUpdate) {
        fadeOutSlider->setValue(processor.getFadeOutSeconds(), NotificationType::dontSendNotification);
        fadeOutLabel->setText("Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s",
                              NotificationType::dontSendNotification);

        if (oscActivityIndicator->getActive() != processor.receivedOscMessages()) {
            oscActivityIndicator->setActive(processor.receivedOscMessages());
            //repaint();
        }
    }
    else if (timerID == TimerIdRefresh) {
        refresh();
    }
}

void SoundboardAudioProcessorEditor::refresh()
{
    if (!processor.isLoocked()) {
        table->updateContent();
    }
}

void SoundboardAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == fadeOutSlider) {
        processor.setFadeOutSeconds((int)fadeOutSlider->getValue());
        fadeOutLabel->setText("Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s",
                              NotificationType::dontSendNotification);
    }
    else {
        int index = slider->getName().getIntValue();
        processor.setGain(index, (float)slider->getValue());
    }
}
