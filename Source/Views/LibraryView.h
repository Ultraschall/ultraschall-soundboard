/*
  ==============================================================================

    LibraryView.h
    Created: 4 May 2018 11:23:44am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "DrawingTools.h"

class LibraryView : public Component, public TableListBoxModel
{
public:
    LibraryView() {

        table.setHeaderHeight(0);
        table.setModel(this);
		table.setColour(ListBox::backgroundColourId, Colour(225, 225, 225));

        addAndMakeVisible(table);
    };

    ~LibraryView() {}

    int getNumRows() override
    {
        return numberOfRows;
    }

    void paintRowBackground(Graphics &graphics, int rowNumber, int width, int height, bool rowIsSelected) override {
        graphics.fillAll(Colours::white);
    }

    void paintCell(Graphics &graphics, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override {

    }

    void resized() override;

    enum ComumnIds {
        ComumnIdNumber = 1,
        ComumnIdPlaying = 2,
        ComumnIdName = 3,
    };
private:
    TableListBox table  { {}, this };
    int numberOfRows = 12;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
