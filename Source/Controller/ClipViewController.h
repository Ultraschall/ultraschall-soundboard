/*
  ==============================================================================

    ClipViewController.h
    Created: 2 May 2018 5:22:57pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "../Views/ClipView.h"

class ClipViewController : public ViewController {
public:
    ClipViewController(Identifier playerId, Engine &core);

    void loadView() override;

    void viewDidLoad() override;

private:
    Player* player;
};