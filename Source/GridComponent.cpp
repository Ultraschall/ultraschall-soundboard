/*
  ==============================================================================

    GridComponent.cpp
    Created: 6 Jan 2015 2:13:24am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "GridComponent.h"

SoundboardGridComponent::SoundboardGridComponent(SoundboardAudioProcessor& p)
    : processor(p)
{
    updateContent();
    startTimer(TimerIdRepaint, (int)(1000 * 0.5));
}

SoundboardGridComponent::~SoundboardGridComponent()
{
    stopTimer(TimerIdRepaint);
    cells.clear(true);
}

void SoundboardGridComponent::resized()
{
    int cellWidth = getWidth() / 4;
    int cellHeight = getHeight() / 6;
    if (cellHeight != 0 && cellWidth != 0) {
        for (int index = 0; index < cells.size(); index++) {
            int column = index % 4;
            int row = index / 4;

            int x = column * cellWidth;
            int y = row * cellHeight;

            cells[index]->setBounds(x, y, cellWidth, cellHeight);
        }
    }
}

// MultiTimer
void SoundboardGridComponent::timerCallback(int timerID) {
    if (timerID == TimerIdRepaint) {
        if (isVisible()) {
            repaint();
        }
    }
}

// Helper
void SoundboardGridComponent::updateContent()
{
    cells.clear(true);

    for (int index = 0; index < 24; index++) {
        if (index < processor.numAudioFiles()) {
            SoundboardGridCell *cell = new SoundboardGridCell(processor.SamplePlayerAtIndex(index));
            cells.add(cell);
            addAndMakeVisible(cell);
            cell->setIndex(index + 1);
        } else {
            SoundboardGridCell *cell = new SoundboardGridCell(nullptr);
            cells.add(cell);
            addAndMakeVisible(cell);
            cell->setIndex(index + 1);
        }
    }

    resized();
}

