/*
  ==============================================================================

    GridComponent.cpp
    Created: 6 Jan 2015 2:13:24am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "GridComponent.h"

SoundboardGridComponent::SoundboardGridComponent(SoundboardAudioProcessor &p) : processor(p)
{
    updateContent();
    startTimer(TimerIdRepaint, static_cast<int>(1000 * 0.5));
}

SoundboardGridComponent::~SoundboardGridComponent()
{
    stopTimer(TimerIdRepaint);
    cells.clear(true);
}

void SoundboardGridComponent::resized()
{
    auto cellWidth  = getWidth() / 4;
    auto cellHeight = getHeight() / 6;
    if (cellHeight != 0 && cellWidth != 0)
    {
        for (int index = 0; index < cells.size(); index++)
        {
            auto column = index % 4;
            auto row    = index / 4;

            auto x = column * cellWidth;
            auto y = row * cellHeight;

            cells[index]->setBounds(x, y, cellWidth, cellHeight);
        }
    }
}

// MultiTimer
void SoundboardGridComponent::timerCallback(int timerID)
{
    if (timerID == TimerIdRepaint)
    {
        if (isVisible())
        {
            repaint();
        }
    }
}

// Helper
void SoundboardGridComponent::updateContent()
{
    cells.clear(true);

    for (int index = 0; index < 24; index++)
    {
        if (index < processor.numPlayers())
        {
            auto cell = new SoundboardGridCell(processor.playerAtIndex(index));
            cells.add(cell);
            addAndMakeVisible(cell);
            cell->setIndex(index + 1);
        }
        else
        {
            auto cell = new SoundboardGridCell(nullptr);
            cells.add(cell);
            addAndMakeVisible(cell);
            cell->setIndex(index + 1);
        }
    }

    resized();
}
