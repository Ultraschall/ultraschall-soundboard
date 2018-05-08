/*
  ==============================================================================

    LibraryView.h
    Created: 4 May 2018 11:23:44am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryView : public Component
{
public:
    LibraryView() {
		table.setColour(ListBox::backgroundColourId, findColour(Material::ColourIds::backgroundColorId));
		table.setRowHeight(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon + Material::Size::Toolbar));
        addAndMakeVisible(table);
    };

    ~LibraryView() {}

    void resized() override;

	ListBox table;
private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
