#include "LibraryView.h"

LibraryView::LibraryView()
{
    table.setColour(ListBox::backgroundColourId, findColour(Material::ColourIds::backgroundColorId));
    table.setRowHeight(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon + Material::Size::Toolbar));
    addAndMakeVisible(table);
}

void LibraryView::resized()
{
    table.setBounds(getLocalBounds());
}
