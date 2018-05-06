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
}