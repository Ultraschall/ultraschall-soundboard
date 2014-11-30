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
        SoundboardAudioProcessor &p)
        : AudioProcessorEditor(&p), processor(p), mPauseState(true), mTimerState(false) {
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
    fadeOutLabel->setText(
            "Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s",
            NotificationType::dontSendNotification);

    addAndMakeVisible(loadDirectoryButton = new ImageButton());
    loadDirectoryButton->setButtonText("Soundboard Laden");
    loadDirectoryButton->addListener(this);

    addAndMakeVisible(tableListBox = new TableListBox());

    tableListBox->setColour(TableListBox::ColourIds::backgroundColourId,
            Colour::fromRGB(53, 53, 53));
    tableListBox->setColour(TableListBox::ColourIds::textColourId,
            Colours::grey);

    tableListBox->setModel(this);

    tableListBox->getHeader().addColumn("", RowIdNum, 25, 25, 25,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Audio", RowIdFile, 250, 200, INT32_MAX,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdLoop, ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Time", RowIdTime, 90, 90, 90,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdPlayPause, ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdStop, ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", RowIdFadeOut, ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
            TableHeaderComponent::notSortable);

    addAndMakeVisible(resizer = new ResizableCornerComponent(this, &resizeLimits));
    resizeLimits.setSizeLimits(470, 320, 1024, 768);

    refresh();
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 300);

    startTimer(0, (int) (1000 * 0.5));
    startTimer(1, 50);
}

SoundboardAudioProcessorEditor::~SoundboardAudioProcessorEditor() {
    tableListBox = nullptr;
    resizer = nullptr;
    loadDirectoryButton = nullptr;
    fadeOutLabel = nullptr;
    fadeOutSlider = nullptr;
}

//==============================================================================
void SoundboardAudioProcessorEditor::paint(Graphics &g) {
    g.fillAll(Colour::fromRGB(53, 53, 53));
    g.setColour(Colour::fromRGB(53, 53, 53).brighter());
    g.drawRect(getWidth() - 167, 3, 144, 24);
    g.setColour(Colours::whitesmoke.darker());
    g.drawText("Soundboard laden", getWidth() - 167, 3, 120, 24,
            Justification::centred);
    g.setFont(getFontAwesome(16));
    g.drawText(FA_FOLDER_OPEN_O, getWidth() - 47, 3, 24, 24,
            Justification::centred, true);
}

void SoundboardAudioProcessorEditor::resized() {
    fadeOutSlider->setBounds(3, 3, 24, 24);
    fadeOutLabel->setBounds(27, 3, 150, 24);
    loadDirectoryButton->setBounds(getWidth() - 147, 3, 144, 24);
    tableListBox->setBounds(3, 32, getWidth() - 6, getHeight() - 38);
    tableListBox->getHeader().setColumnWidth(RowIdFile, getWidth() - 268);
    resizer->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);
}

// TableListBoxModel

int SoundboardAudioProcessorEditor::getNumRows() {
    return processor.numAudioFiles();
}

void SoundboardAudioProcessorEditor::paintRowBackground(Graphics &g,
        int /*rowNumber*/,
        int /*width*/,
        int /*height*/,
        bool /*rowIsSelected*/) {
    g.setColour(Colour::fromRGB(53, 53, 53));
    g.fillAll();
}

void SoundboardAudioProcessorEditor::paintCell(Graphics &g, int rowNumber,
        int columnId, int width,
        int height, bool /*rowIsSelected*/) {
    g.setColour(Colour::fromRGB(27, 27, 29));
    g.drawLine(0, (float) height, (float) width, (float) height);
    g.drawLine((float) width, 0, (float) width, (float) height);

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
                g.fillRect(0, 0, (int) (width * processor.SamplePlayerAtIndex(rowNumber)->getProgress()), height);
            } else {
                g.fillRect(0, 0, width, height);
            }
            g.setColour(Colours::grey);
            g.drawText(processor.SamplePlayerAtIndex(rowNumber)->getProgressString(mTimerState),
                    2, 0, width - 4, height, Justification::centred, true);
        }
            break;
        case RowIdPlayPause:
            if (processor.SamplePlayerAtIndex(rowNumber)->isPlaying()) {
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_PAUSE, 0, 0, width, height, Justification::centred, true);
            } else if (processor.SamplePlayerAtIndex(rowNumber)->isPaused()) {
                if (mPauseState) {
                    g.setColour(Colours::grey.darker().darker());
                }
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_PLAY, 0, 0, width, height, Justification::centred, true);
            } else {
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_PLAY, 0, 0, width, height, Justification::centred, true);
            }
            break;
        case RowIdStop:
            if (processor.SamplePlayerAtIndex(rowNumber)->isPlaying()
                    || processor.SamplePlayerAtIndex(rowNumber)->isPaused()) {
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_SQUARE, 0, 0, width, height, Justification::centred, true);
            } else if (processor.SamplePlayerAtIndex(rowNumber)->isPlayed()) {
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_SQUARE_O, 0, 0, width, height, Justification::centred, true);
            } else {
                g.setColour(Colours::grey.darker().darker());
                g.setFont(getFontAwesome(height * 0.7f));
                g.drawText(FA_SQUARE, 0, 0, width, height, Justification::centred, true);
            }
            break;
        case RowIdFadeOut:
            if (!processor.SamplePlayerAtIndex(rowNumber)->isPlaying()) {
                g.setColour(Colours::grey.darker().darker());
            } else {
                if (processor.SamplePlayerAtIndex(rowNumber)->isFadingOut()) {
                    g.setColour(Colours::whitesmoke);
                }
            }
            g.setFont(getFontAwesome(height * 0.7f));
            g.addTransform(AffineTransform::rotation(-(float_Pi * 0.5f), width * 0.5f, height * 0.5f));
            g.drawText(FA_SORT_AMOUNT_DESC, 0, 0, width, height, Justification::centred, true);
            break;
        default:
            text = String::empty;
            break;
    }

    if (text.isNotEmpty()) {
        g.drawText(text, 2, 0, width - 4, height, Justification::centredLeft, true);
    }

    g.setColour(Colours::black.withAlpha(0.2f));
    g.fillRect(width - 1, 0, 1, height);
}

void SoundboardAudioProcessorEditor::buttonClicked(
        Button *buttonThatWasClicked) {
    if (loadDirectoryButton == buttonThatWasClicked) {
        FileChooser chooser("Open...");
        if (chooser.browseForDirectory()) {
            File directory = chooser.getResult();
            if (directory.isDirectory()) {
                processor.openDirectory(directory);
                tableListBox->updateContent();
            }
        }
    }
}

void SoundboardAudioProcessorEditor::cellClicked(int rowNumber, int columnId,
        const MouseEvent & /*e*/) {
    if (columnId == RowIdLoop) {
        processor.SamplePlayerAtIndex(rowNumber)->setLooping(!processor.SamplePlayerAtIndex(rowNumber)->isLooping());
    }
    else if (columnId == RowIdPlayPause) {
        if (processor.SamplePlayerAtIndex(rowNumber)->getState() == SamplePlayer::Playing) {
            processor.SamplePlayerAtIndex(rowNumber)->pause();
        } else {
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
        if (processor.SamplePlayerAtIndex(rowNumber)->getState() == SamplePlayer::Playing) {
            processor.SamplePlayerAtIndex(rowNumber)->startFadeOut();
        }
    }
}

void SoundboardAudioProcessorEditor::timerCallback(int timerID) {
    if (timerID == 1) {
        fadeOutSlider->setValue(processor.getFadeOutSeconds(), NotificationType::dontSendNotification);
    } else if (timerID == 0) {
        mPauseState = !mPauseState;
        tableListBox->repaint();
    }
}

void SoundboardAudioProcessorEditor::refresh() {
    tableListBox->updateContent();
}

void SoundboardAudioProcessorEditor::sliderValueChanged(Slider * /*slider*/) {
    processor.setFadeOutSeconds((int) fadeOutSlider->getValue());
    fadeOutLabel->setText("Ausblendzeit: " + String(processor.getFadeOutSeconds()) + "s",
            NotificationType::dontSendNotification);
}