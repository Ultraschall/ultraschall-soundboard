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
    fadeOutSlider->setColour(Slider::ColourIds::rotarySliderFillColourId,
                             Colours::grey.brighter());
    fadeOutSlider->setSliderStyle(Slider::SliderStyle::Rotary);
    fadeOutSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true,
                                   0, 0);
    fadeOutSlider->addListener(this);

    addAndMakeVisible(fadeOutLabel = new Label());
    fadeOutLabel->setColour(Label::ColourIds::textColourId,
                            Colours::grey.brighter());
    fadeOutLabel->setText("Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s",
                          NotificationType::dontSendNotification);

    addAndMakeVisible(loadDirectoryButton = new AwesomeButton(FA_FOLDER_OPEN_O));
    loadDirectoryButton->setButtonText("Soundboard Laden");
    loadDirectoryButton->addListener(this);

    addAndMakeVisible(tableListBox = new TableListBox());

    tableListBox->setColour(TableListBox::ColourIds::backgroundColourId,
                            Colour::fromRGB(35, 35, 35));
    tableListBox->setColour(TableListBox::ColourIds::textColourId, Colours::grey);

    tableListBox->setModel(this);

    tableListBox->setHeaderHeight(21);

    tableListBox->getHeader().addColumn("", RowIdNum, 25, 25, 25,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Audio", RowIdFile, 250, 200, 4096,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdLoop, ButtonCellWidth,
                                        ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Time", RowIdTime, 90, 90, 90,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdPlayPause, ButtonCellWidth,
                                        ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdStop, ButtonCellWidth,
                                        ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdFadeOut, ButtonCellWidth,
                                        ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdGain, ButtonCellWidth,
                                        ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);

    addAndMakeVisible(buttomBar = new Bar());

    addAndMakeVisible(settingsButton = new AwesomeButton(FA_COG));
    settingsButton->setButtonText("Einstellungen");
    settingsButton->addListener(this);
    settingsButton->setColour(TextButton::ColourIds::textColourOnId, Colours::white);
    settingsButton->setColour(TextButton::ColourIds::textColourOffId, Colours::white);

    addAndMakeVisible(oscActivityIndicator = new ActivityIndicator());
    oscActivityIndicator->setTitle(CharPointer_UTF8("OSC Aktivit\xc3\xa4t"));

    addAndMakeVisible(resizer = new ResizableCornerComponent(this, &resizeLimits));
    resizeLimits.setSizeLimits(470, 320, 1024, 768);

    refresh();

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 300);

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
    tableListBox = nullptr;
    resizer = nullptr;
    settingsButton = nullptr;
    oscActivityIndicator = nullptr;
    buttomBar = nullptr;
}

//==============================================================================
void SoundboardAudioProcessorEditor::paint(Graphics& g)
{
    g.fillAll(Colour::fromRGB(33, 33, 33));
}

void SoundboardAudioProcessorEditor::resized()
{
    topBar->setBounds(0, 0, getWidth(), 32);

    fadeOutSlider->setBounds(3, 5, 24, 24);
    fadeOutLabel->setBounds(27, 5, 150, 24);

    loadDirectoryButton->setBounds(getWidth() - 153, 5, 150, 24);

    tableListBox->setBounds(0, 32, getWidth(), getHeight() - 64);
    tableListBox->getHeader().setColumnWidth(RowIdFile, getWidth() - 293);

    resizer->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);

    settingsButton->setBounds(getWidth() - 123, getHeight() - 27, 120, 24);
    oscActivityIndicator->setBounds(3, getHeight() - 27, 120, 24);
    buttomBar->setBounds(0, getHeight() - 32, getWidth(), 32);
}

// TableListBoxModel

int SoundboardAudioProcessorEditor::getNumRows()
{
    return processor.numAudioFiles();
}

void SoundboardAudioProcessorEditor::paintRowBackground(
    Graphics& g, int rowNumber, int /*width*/, int /*height*/,
    bool /*rowIsSelected*/)
{
    if (rowNumber % 2) {
        g.setColour(Colour::fromRGB(44, 44, 44));
    }
    else {
        g.setColour(Colour::fromRGB(46, 47, 49));
    }
    g.fillAll();
}

void SoundboardAudioProcessorEditor::paintCell(Graphics& g, int rowNumber,
                                               int columnId, int width,
                                               int height,
                                               bool /*rowIsSelected*/)
{
    g.setColour(Colour::fromRGB(39, 39, 41));
    g.drawLine((float)width, 0, (float)width, (float)height, 1.5f);

    g.setColour(Colours::grey);

    String text = String::empty;

    switch (columnId) {
    case RowIdNum:
        text = String(rowNumber + 1);
        break;
    case RowIdFile:
        text = processor.SamplePlayerAtIndex(rowNumber)->getTitle();
        break;
    case RowIdLoop:
        if (processor.SamplePlayerAtIndex(rowNumber)->isLooping()) {
            g.setColour(Colours::whitesmoke);
        }

        g.setFont(getFontAwesome(height * 0.7f));
        g.drawText(FA_REFRESH, 0, 0, width, height, Justification::centred, true);
        return;
    case RowIdTime: {
        g.setColour(Colours::black);
        if (!processor.SamplePlayerAtIndex(rowNumber)->isPlayed()) {
            g.fillRect(0, 0,
                       (int)(width * processor.SamplePlayerAtIndex(rowNumber)->getProgress()),
                       height);
        }
        else {
            g.fillRect(0, 0, width, height);
        }
        g.setColour(Colours::grey);
        g.drawText(processor.SamplePlayerAtIndex(rowNumber)
                       ->getProgressString(mTimerState),
                   2, 0, width - 4, height, Justification::centred, true);
    } break;
    case RowIdPlayPause:
        if (processor.SamplePlayerAtIndex(rowNumber)->isPlaying()) {
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_PAUSE, 0, 0, width, height, Justification::centred, true);
        }
        else if (processor.SamplePlayerAtIndex(rowNumber)->isPaused()) {
            if (mPauseState) {
                g.setColour(Colours::grey.darker().darker());
            }
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_PLAY, 0, 0, width, height, Justification::centred, true);
        }
        else {
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_PLAY, 0, 0, width, height, Justification::centred, true);
        }
        break;
    case RowIdStop:
        if (processor.SamplePlayerAtIndex(rowNumber)->isPlaying() || processor.SamplePlayerAtIndex(rowNumber)->isPaused()) {
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_SQUARE, 0, 0, width, height, Justification::centred, true);
        }
        else if (processor.SamplePlayerAtIndex(rowNumber)->isPlayed()) {
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_SQUARE_O, 0, 0, width, height, Justification::centred,
                       true);
        }
        else {
            g.setColour(Colours::grey.darker().darker());
            g.setFont(getFontAwesome(height * 0.7f));
            g.drawText(FA_SQUARE, 0, 0, width, height, Justification::centred, true);
        }
        break;
    case RowIdFadeOut:
        if (!processor.SamplePlayerAtIndex(rowNumber)->isPlaying()) {
            g.setColour(Colours::grey.darker().darker());
        }
        else {
            if (processor.SamplePlayerAtIndex(rowNumber)->isFadingOut()) {
                g.setColour(Colours::whitesmoke);
            }
        }
        g.setFont(getFontAwesome(height * 0.7f));
        g.addTransform(AffineTransform::rotation(-(float_Pi * 0.5f), width * 0.5f,
                                                 height * 0.5f));
        g.drawText(FA_SORT_AMOUNT_DESC, 0, 0, width, height, Justification::centred,
                   true);
        break;
    default:
        text = String::empty;
        break;
    }

    if (text.isNotEmpty()) {
        g.drawText(text, 4, 0, width - 8, height, Justification::centredLeft, true);
    }
}

Component* SoundboardAudioProcessorEditor::refreshComponentForCell(int rowNumber, int columnId,
                                                                   bool /*isRowSelected*/, Component* existingComponentToUpdate)
{
    if (columnId == RowIdGain) // If it's the ratings column, we'll return our custom component..
    {
        Slider* slider = (Slider*)existingComponentToUpdate;

        // If an existing component is being passed-in for updating, we'll re-use it, but
        // if not, we'll have to create one.
        if (slider == 0) {
            slider = new Slider();
            slider->setRange(0.0, 1.0, 0.01);
            slider->setValue(1.0);
            slider->setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::grey.brighter());
            slider->setSliderStyle(Slider::SliderStyle::Rotary);
            slider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
            slider->addListener(this);
        }
        slider->setValue(processor.SamplePlayerAtIndex(rowNumber)->getGain(), NotificationType::dontSendNotification);
        slider->setName(String(rowNumber));

        return slider;
    }
    else {
        // for any other column, just return 0, as we'll be painting these columns directly.

        jassert(existingComponentToUpdate == 0);
        return 0;
    }
}

void
SoundboardAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
    if (loadDirectoryButton == buttonThatWasClicked) {
        FileChooser chooser("Open...");
        if (chooser.browseForDirectory()) {
            File directory = chooser.getResult();
            if (directory.isDirectory()) {
                gainSliders.clear();
                processor.openDirectory(directory);
                for (int i = 0; i < processor.numAudioFiles(); i++) {
                    Slider* slider = new Slider();
                    slider->setBounds(0, 0, ButtonCellWidth, ButtonCellWidth);
                    gainSliders.add(slider);
                }
                tableListBox->updateContent();
            }
        }
    }
    if (settingsButton == buttonThatWasClicked) {
        processor.openSettings();
    }
}

void SoundboardAudioProcessorEditor::cellClicked(int rowNumber, int columnId,
                                                 const MouseEvent& /*e*/)
{
    if (columnId == RowIdLoop) {
        processor.SamplePlayerAtIndex(rowNumber)
            ->setLooping(!processor.SamplePlayerAtIndex(rowNumber)->isLooping());
    }
    else if (columnId == RowIdPlayPause) {
        if (processor.SamplePlayerAtIndex(rowNumber)->getState() == Player::Playing) {
            processor.SamplePlayerAtIndex(rowNumber)->pause();
        }
        else {
            processor.SamplePlayerAtIndex(rowNumber)->play();
        }
    }
    else if (columnId == RowIdStop) {
        processor.SamplePlayerAtIndex(rowNumber)->stop();
    }
    else if (columnId == RowIdTime) {
        mTimerState = !mTimerState;
        tableListBox->repaint();
    }
    else if (columnId == RowIdFadeOut) {
        if (processor.SamplePlayerAtIndex(rowNumber)->getState() == Player::Playing) {
            processor.SamplePlayerAtIndex(rowNumber)->startFadeOut();
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
            repaint();
        }
    }
    else if (timerID == TimerIdBlink) {
        mPauseState = !mPauseState;
        tableListBox->repaint();
    }
    else if (timerID == TimerIdRefresh) {
        refresh();
    }
}

void SoundboardAudioProcessorEditor::refresh()
{
    if (!processor.isLoocked()) {
        tableListBox->updateContent();
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

void SoundboardAudioProcessorEditor::refreshTable() { tableListBox->repaint(); }