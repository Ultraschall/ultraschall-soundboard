#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "../Views/ClipView.h"

class ClipViewController : public ViewController<ClipView>
{
public:
    ClipViewController(String playerId, Engine &engine);

    void loadView() override;

    void viewDidLoad() override;

private:
    Player *player;
};