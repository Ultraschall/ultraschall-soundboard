#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryView : public Component
{
public:
    LibraryView() {
        table.setColour(ListBox::backgroundColourId, findColour(Material::ColourIds::backgroundColorId));
        table.setRowHeight(MaterialLookAndFeel::convertDpToPixel(64));
        addAndMakeVisible(table);
    }

    ~LibraryView() = default;

    void resized() override {
        table.setBounds(getLocalBounds());
    }

    ListBox table;
private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
