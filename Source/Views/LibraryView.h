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

        table.setHeaderHeight(21);
        table.setModel(this);
        table.getHeader().addColumn(String::empty,
                                    ComumnIdNumber,
                                    32,
                                    32,
                                    32,
                                    TableHeaderComponent::notSortable);

        addButton.setImages(addIcon.getDrawable());
        addAndMakeVisible(table);
        addAndMakeVisible(addButton);
        addButton.toFront(false);
    };

    ~LibraryView() {}

    int getNumRows() override
    {
        return numberOfRows;
    }

    void paintRowBackground(Graphics &graphics, int rowNumber, int width, int height, bool rowIsSelected) override {
        graphics.fillAll(Colours::darkgrey);
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
    SvgIcon addIcon {BinaryData::add_svg, BinaryData::add_svgSize};
    DrawableButton addButton { "Add", DrawableButton::ImageFitted };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
