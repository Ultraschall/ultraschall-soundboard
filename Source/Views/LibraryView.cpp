/*
  ==============================================================================

    LibraryView.cpp
    Created: 4 May 2018 11:23:44am
    Author:  danlin

  ==============================================================================
*/

#include "LibraryView.h"

void LibraryView::resized() {
    table.setBounds(getLocalBounds());
    addButton.setBounds(getLocalBounds().getWidth() - 70, getLocalBounds().getHeight() - 70, 60, 60);
}