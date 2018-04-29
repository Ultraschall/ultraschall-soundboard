/*
  ==============================================================================

    TableComponent.cpp
    Created: 6 Jan 2015 2:11:44am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "TableComponent.h"
#include "LookAndFeel.h"

SoundboardTableComponent::SoundboardTableComponent(SoundboardAudioProcessor& p)
    : processor(p)
    , mTimerState(true)
{
    addAndMakeVisible(tableListBox = new TableListBox());
    tableListBox->setModel(this);
    tableListBox->setHeaderHeight(21);
    tableListBox->getHeader()
        .addColumn(String::empty,
            ColumnIdNumberLabel,
            NumberCellWidth,
            NumberCellWidth,
            NumberCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(TRANS("Audio"),
            ColumnIdFileLabel,
            max(getWidth() - 293, 293), // calculated at resize
            1,
            16000,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(String::empty,
            ColumnIdLoopButton,
            ButtonCellWidth,
            ButtonCellWidth,
            ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(TRANS("Time"),
            ColumnIdTimeLabel,
            TimeCellWidth,
            TimeCellWidth,
            TimeCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(String::empty,
            ColumnIdPlayPauseButton,
            ButtonCellWidth,
            ButtonCellWidth,
            ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(String::empty,
            ColumnIdStopButton,
            ButtonCellWidth,
            ButtonCellWidth,
            ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(String::empty,
                ColumnIdFadeButton,
            ButtonCellWidth,
            ButtonCellWidth,
            ButtonCellWidth,
            TableHeaderComponent::notSortable);
    tableListBox->getHeader()
        .addColumn(String::empty,
            ColumnIdGainSlider,
            ButtonCellWidth,
            ButtonCellWidth,
            ButtonCellWidth,
            TableHeaderComponent::notSortable);
    startTimer(TimerIdRepaint, static_cast<int>(1000 * 0.5));
}

SoundboardTableComponent::~SoundboardTableComponent()
{
    stopTimer(TimerIdRepaint);
    tableListBox = nullptr;
}

// Component
void SoundboardTableComponent::resized()
{
    tableListBox->setBounds(0, 0, getWidth(), getHeight());
    tableListBox->getHeader().setColumnWidth(ColumnIdFileLabel, getWidth() - 293);
}

// TableListBoxModel
int SoundboardTableComponent::getNumRows()
{
    return processor.numPlayers();
}

void SoundboardTableComponent::paintRowBackground(Graphics& g,
    int rowNumber,
    int /*width*/,
    int /*height*/,
    bool /*rowIsSelected*/)
{
    if (rowNumber % 2) {
        g.setColour(ThemeBackground2);
    }
    else {
        g.setColour(ThemeBackground3);
    }
    g.fillAll();
}

void SoundboardTableComponent::paintCell(Graphics& g,
    int rowNumber,
    int columnId,
    int width,
    int height,
    bool /*rowIsSelected*/)
{
    // FIXME: JUCE inserts at least 2 rows into the table (juce_ListBox.cpp, line 230).
    //        But that does not mean that we have at least two players since the number
    //        of players is the number of audio files within a folder. If there is only 
    //        one audio file in a folder -> crash!
    //        
    //        Until we have a proper solution, let's apply this quick sanity check.
    ;
    if(processor.playerAtIndex(rowNumber) == nullptr)
    {
        return;
    }
   
    g.setColour(ThemeBackground1);
    g.drawLine(static_cast<float>(width), 0, static_cast<float>(width), static_cast<float>(height), 1.5f);

    g.setColour(ThemeForeground1);
    auto text = String::empty;

    switch (columnId) {
    case ColumnIdNumberLabel:
        text = String(rowNumber + 1);
        break;
    case ColumnIdFileLabel:
        text = processor.playerAtIndex(rowNumber)->getTitle();
        break;
    case ColumnIdTimeLabel: {
        Colour colour;
        if (processor.playerAtIndex(rowNumber)->isPlayed()) {
            colour = ThemeGreen;
        }
        else if (processor.playerAtIndex(rowNumber)->isFading()) {
            colour = ThemeOrange;
        }
        else if (processor.playerAtIndex(rowNumber)->isLooping()) {
            colour = ThemeBlue;
        }
        else {
            colour = ThemeYellow;
        }

        g.setColour(colour.withAlpha(0.2f));
        auto processRect = g.getClipBounds().reduced(1).toFloat();
        g.fillRoundedRectangle(processRect, 2);

        g.setColour(colour);
        if (!processor.playerAtIndex(rowNumber)->isPlayed()) {
            g.fillRoundedRectangle(processRect.getX(),
                processRect.getY(),
                processRect.getWidth() * processor.playerAtIndex(rowNumber)->getProgress(),
                processRect.getHeight(),
                2);
        }

        g.setColour(ThemeForeground1);
        g.drawText(processor.playerAtIndex(rowNumber)->getProgressString(mTimerState),
            2,
            0,
            width - 4,
            height,
            Justification::centred,
            true);
        break;
    }
        default:break;
    }

    if (text.isNotEmpty()) {
        g.drawText(text, 4, 0, width - 8, height, Justification::centredLeft, true);
    }
}

void SoundboardTableComponent::cellClicked(int /*rowNumber*/, int columnId, const MouseEvent& /*e*/)
{
    if (columnId == ColumnIdTimeLabel) {
        mTimerState = !mTimerState;
        tableListBox->repaint();
    }
}

Component* SoundboardTableComponent::refreshComponentForCell(int rowNumber,
    int columnId,
    bool /*isRowSelected*/,
    Component* existingComponentToUpdate)
{
    // FIXME: JUCE inserts at least 2 rows into the table (juce_ListBox.cpp, line 230).
    //        But that does not mean that we have at least two players since the number
    //        of players is the number of audio files within a folder. If there is only 
    //        one audio file in a folder -> crash!
    //        
    //        Until we have a proper solution, let's apply this quick sanity check.
    if (processor.playerAtIndex(rowNumber) == nullptr)
    {
        return nullptr;
    }

    if (columnId == ColumnIdLoopButton) {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr) {
            button = new SoundboardCellButton("Loop", FontAwesome_Refresh);
            button->setTag(ButtonTagLoop);
            button->addListener(this);
            button->setHighlightColour(ThemeBlue);
        }

        button->setHighlighted(processor.playerAtIndex(rowNumber)->isLooping());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdPlayPauseButton) {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr) {
            button = new SoundboardCellButton("Play / Pause", FontAwesome_Play);
            button->setTag(ButtonTagPlayPause);
            button->addListener(this);
        }

        if (processor.playerAtIndex(rowNumber)->isPlaying()) {
            button->setIcon(FontAwesome_Pause);
        }
        else {
            button->setIcon(FontAwesome_Play);
        }
        button->setFlashing(processor.playerAtIndex(rowNumber)->isPaused());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdStopButton) {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr) {
            button = new SoundboardCellButton("Stop", FontAwesome_Square);
            button->setTag(ButtonTagStop);
            button->addListener(this);
            button->setEnabled(false);
            button->setHighlightColour(ThemeGreen);
        }

        button->setRowNumber(rowNumber);
        button->setEnabled(false);
        button->setIcon(FontAwesome_Square);
        button->setHighlighted(false);

        if (processor.playerAtIndex(rowNumber)->isPlaying()
            || processor.playerAtIndex(rowNumber)->isPaused()) {
            button->setEnabled(true);
        }
        else if (processor.playerAtIndex(rowNumber)->isPlayed()) {
            button->setIcon(FontAwesome_SquareO);
            button->setEnabled(true);
            button->setHighlighted(true);
        }

        return button;
    }
    if (columnId == ColumnIdFadeButton) {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr) {
            button = new SoundboardCellButton("Fade-In", FontAwesome_SortAmountAsc);
            button->setRotation(0.5);
            button->setTag(ButtonTagFade);
            button->addListener(this);
            button->setHighlightColour(ThemeOrange);
        }
        if (processor.playerAtIndex(rowNumber)->isPlaying()) {
            button->setIcon(FontAwesome_SortAmountDesc);
        } else {
            button->setIcon(FontAwesome_SortAmountAsc);
        }
        button->setEnabled(!processor.playerAtIndex(rowNumber)->isFading());
        button->setHighlighted(processor.playerAtIndex(rowNumber)->isFading());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdGainSlider) {
        auto slider = static_cast<Slider*>(existingComponentToUpdate);

        if (slider == nullptr) {
            slider = new Slider();
            slider->setRange(0.0, 1.0, 0.01);
            slider->setValue(1.0);
            slider->setSliderStyle(Slider::SliderStyle::Rotary);
            slider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
            slider->addListener(this);
        }

        slider->setValue(processor.playerAtIndex(rowNumber)->getGain(), dontSendNotification);
        slider->setName(String(rowNumber));

        return slider;
    }

    jassert(existingComponentToUpdate == nullptr);
    return nullptr;
}

// MultiTimer
void SoundboardTableComponent::timerCallback(int timerID)
{
    if (isVisible()) {
        if (timerID == TimerIdRepaint) {
            tableListBox->repaint();
        }
    }
}

// Button Listener
void SoundboardTableComponent::buttonClicked(Button* button)
{
    auto cellButton = static_cast<SoundboardCellButton*>(button);
    if (!cellButton) {
        return;
    }

    // FIXME: JUCE inserts at least 2 rows into the table (juce_ListBox.cpp, line 230).
    //        But that does not mean that we have at least two players since the number
    //        of players is the number of audio files within a folder. If there is only 
    //        one audio file in a folder -> crash!
    //        
    //        Until we have a proper solution, let's apply this quick sanity check.
    if (processor.playerAtIndex(cellButton->getRowNumber()) == nullptr)
    {
        return;
    }

    auto player = processor.playerAtIndex(cellButton->getRowNumber());
    if (!player) {
        return;
    }

    if (cellButton->getTag() == ButtonTagLoop) {
        player->setLooping(!player->isLooping());
        cellButton->setHighlighted(player->isLooping());
    }
    else if (cellButton->getTag() == ButtonTagPlayPause) {
        if (player->isPlaying()) {
            player->pause();
        }
        else {
            player->play();
        }
    }
    else if (cellButton->getTag() == ButtonTagStop) {
        player->stop();
    }
    else if (cellButton->getTag() == ButtonTagFade) {
        if (player->isPlaying()) {
            player->startFadeOut();
        } else  {
            player->startFadeIn();
        }
    }

    tableListBox->repaintRow(cellButton->getRowNumber());
}

// Button Listener
void SoundboardTableComponent::sliderValueChanged(Slider* slider)
{
    int index = slider->getName().getIntValue();
    processor.setGain(index, (float)slider->getValue());
}

// Helper
void SoundboardTableComponent::updateContent()
{
    tableListBox->updateContent();
}
