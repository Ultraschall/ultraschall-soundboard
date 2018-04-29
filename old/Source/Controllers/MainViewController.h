/*
  ==============================================================================

    MainViewController.h
    Created: 19 Jan 2018 10:45:55pm
    Author:  danlin

  ==============================================================================
*/

#pragma once
#include "ViewController.h"

class MainViewController : public ViewController {

public:
    explicit MainViewController(Core& core) : ViewController(core) {}
};
