/*
  ==============================================================================

    LibraryViewController.h
    Created: 4 May 2018 11:04:34am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ViewController.h"

//==============================================================================
/*
*/
class LibraryViewController : public ViewController
{
public:
	LibraryViewController(Library &engine) : ViewController(engine) {};

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryViewController)
};
