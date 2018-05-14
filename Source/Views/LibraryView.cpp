#include "LibraryView.h"

LibraryView::LibraryView()
{
    table.setColour(ListBox::backgroundColourId, findColour(Material::ColourIds::backgroundColorId));
    table.setRowHeight(MaterialLookAndFeel::convertDpToPixel(64));
    addAndMakeVisible(table);
}

void LibraryView::resized()
{
    table.setBounds(getLocalBounds());
}
