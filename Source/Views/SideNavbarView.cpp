/*
  ==============================================================================

    SideNavbarView.cpp
    Created: 6 May 2018 6:49:28am
    Author:  danie

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideNavbarView.h"

//==============================================================================
SideNavbarView::SideNavbarView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SideNavbarView::~SideNavbarView()
{
}

void SideNavbarView::paint (Graphics& g)
{
    g.fillAll (Colours::white);   // clear the background
}

void SideNavbarView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
