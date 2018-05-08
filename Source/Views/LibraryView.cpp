/*
  ==============================================================================

    LibraryView.cpp
    Created: 4 May 2018 11:23:44am
    Author:  danlin

  ==============================================================================
*/

#include "LibraryView.h"

LibraryView::LibraryView() {
	  table.setColour(ListBox::backgroundColourId, findColour(Material::ColourIds::backgroundColorId));
	  table.setRowHeight(MaterialLookAndFeel::convertDpToPixel(Material::Size::IconSmall + Material::Size::Toolbar));
	  addAndMakeVisible(table);
  }

  void LibraryView::resized() {
    table.setBounds(getLocalBounds());
}
