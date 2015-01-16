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
    : processor(p), mTimerState(true)
{
    addAndMakeVisible(tableListBox = new TableListBox());
    tableListBox->setModel(this);
    tableListBox->setHeaderHeight(21);
    tableListBox->getHeader().addColumn("", ColumnIdNumberLabel,
                                        NumberCellWidth, NumberCellWidth, NumberCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Audio", ColumnIdFileLabel,
                                        max(getWidth() - 293, 293), 1, 16000, // calculated at resize
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", ColumnIdLoopButton,
                                        ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("Time", ColumnIdTimeLabel,
                                        TimeCellWidth, TimeCellWidth, TimeCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", ColumnIdPlayPauseButton,
                                        ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", ColumnIdStopButton,
                                        ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", ColumnIdFadeOutButton,
                                        ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
                                        TableHeaderComponent::notSortable);
    tableListBox->getHeader().addColumn("", ColumnIdGainSlider,
                                        ButtonCellWidth, ButtonCellWidth, ButtonCellWidth,
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
    if (rowNumber % 2)
    {
        g.setColour(ThemeBackground2);
    }
    else
    {
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
    g.setColour(ThemeBackground1);
    g.drawLine(static_cast<float>(width), 0, static_cast<float>(width), static_cast<float>(height), 1.5f);

    g.setColour(ThemeForeground1);
    auto text = String::empty;

    switch (columnId)
    {
    case ColumnIdNumberLabel:
        text = String(rowNumber + 1);
        break;
    case ColumnIdFileLabel:
        text = processor.playerAtIndex(rowNumber)->getTitle();
        break;
    case ColumnIdTimeLabel:
        {
            Colour colour;
            if (processor.playerAtIndex(rowNumber)->isPlayed())
            {
                colour = ThemeGreen;
            }
            else if (processor.playerAtIndex(rowNumber)->isFadingOut())
            {
                colour = ThemeOrange;
            }
            else if (processor.playerAtIndex(rowNumber)->isLooping())
            {
                colour = ThemeBlue;
            }
            else
            {
                colour = ThemeYellow;
            }

            g.setColour(colour.withAlpha(0.2f));
            auto processRect = g.getClipBounds().reduced(1).toFloat();
            g.fillRoundedRectangle(processRect, 2);

            g.setColour(colour);
            if (!processor.playerAtIndex(rowNumber)->isPlayed())
            {
                g.fillRoundedRectangle(processRect.getX(), processRect.getY(), processRect.getWidth() * processor.playerAtIndex(rowNumber)->getProgress(), processRect.getHeight(), 2);
            }

            g.setColour(ThemeForeground1);
            g.drawText(processor.playerAtIndex(rowNumber)->getProgressString(mTimerState), 2, 0, width - 4, height, Justification::centred, true);
            break;
        }
    }

    if (text.isNotEmpty())
    {
        g.drawText(text, 4, 0, width - 8, height, Justification::centredLeft, true);
    }
}

void SoundboardTableComponent::cellClicked(int /*rowNumber*/,
                                           int columnId,
                                           const MouseEvent& /*e*/)
{
    if (columnId == ColumnIdTimeLabel)
    {
        mTimerState = !mTimerState;
        tableListBox->repaint();
    }
}

Component* SoundboardTableComponent::refreshComponentForCell(int rowNumber,
                                                             int columnId,
                                                             bool /*isRowSelected*/,
                                                             Component* existingComponentToUpdate)
{
    if (columnId == ColumnIdLoopButton)
    {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr)
        {
            button = new SoundboardCellButton("Loop", FA_REFRESH);
            button->setTag(ButtonTagLoop);
            button->addListener(this);
            button->setHighlightColour(ThemeBlue);
        }

        button->setHighlighted(processor.playerAtIndex(rowNumber)->isLooping());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdPlayPauseButton)
    {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr)
        {
            button = new SoundboardCellButton("Play / Pause", FA_PLAY);
            button->setTag(ButtonTagPlayPause);
            button->addListener(this);
        }

        if (processor.playerAtIndex(rowNumber)->isPlaying())
        {
            button->setIcon(FA_PAUSE);
        }
        else
        {
            button->setIcon(FA_PLAY);
        }
        button->setFlashing(processor.playerAtIndex(rowNumber)->isPaused());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdStopButton)
    {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr)
        {
            button = new SoundboardCellButton("Stop", FA_SQUARE);
            button->setTag(ButtonTagStop);
            button->addListener(this);
            button->setEnabled(false);
            button->setHighlightColour(ThemeGreen);
        }

        button->setRowNumber(rowNumber);
        button->setEnabled(false);
        button->setIcon(FA_SQUARE);
        button->setHighlighted(false);

        if (processor.playerAtIndex(rowNumber)->isPlaying() || processor.playerAtIndex(rowNumber)->isPaused())
        {
            button->setEnabled(true);
        }
        else if (processor.playerAtIndex(rowNumber)->isPlayed())
        {
            button->setIcon(FA_SQUARE_O);
            button->setEnabled(true);
            button->setHighlighted(true);
        }

        return button;
    }
    if (columnId == ColumnIdFadeOutButton)
    {
        auto button = static_cast<SoundboardCellButton*>(existingComponentToUpdate);

        if (button == nullptr)
        {
            button = new SoundboardCellButton("Fade-Out", FA_VOLUME_DOWN);
            button->setTag(ButtonTagFadeOut);
            button->addListener(this);
            button->setHighlightColour(ThemeOrange);
        }

        button->setEnabled(processor.playerAtIndex(rowNumber)->isPlaying());
        button->setHighlighted(processor.playerAtIndex(rowNumber)->isFadingOut());
        button->setRowNumber(rowNumber);

        return button;
    }
    if (columnId == ColumnIdGainSlider)
    {
        auto slider = static_cast<Slider*>(existingComponentToUpdate);

        if (slider == nullptr)
        {
            slider = new Slider();
            slider->setRange(0.0, 1.0, 0.01);
            slider->setValue(1.0);
            slider->setSliderStyle(Slider::SliderStyle::Rotary);
            slider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
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
    if (timerID == TimerIdRepaint)
    {
        tableListBox->repaint();
    }
}

// Button Listener
void SoundboardTableComponent::buttonClicked(Button* button)
{
    auto cellButton = static_cast<SoundboardCellButton*>(button);
    if (!cellButton)
    {
        return;
    }

    auto player = processor.playerAtIndex(cellButton->getRowNumber());
    if (!player)
    {
        return;
    }

    if (cellButton->getTag() == ButtonTagLoop)
    {
        player->setLooping(!player->isLooping());
        cellButton->setHighlighted(player->isLooping());
    }
    else if (cellButton->getTag() == ButtonTagPlayPause)
    {
        if (player->isPlaying())
        {
            player->pause();
        }
        else
        {
            player->play();
        }
    }
    else if (cellButton->getTag() == ButtonTagStop)
    {
        player->stop();
    }
    else if (cellButton->getTag() == ButtonTagFadeOut)
    {
        player->startFadeOut();
    }

    tableListBox->repaintRow(cellButton->getRowNumber());
}

// Button Listener
void SoundboardTableComponent::sliderValueChanged(Slider* /*slider*/)
{
}

// Helper
void SoundboardTableComponent::updateContent()
{
    tableListBox->updateContent();
}
