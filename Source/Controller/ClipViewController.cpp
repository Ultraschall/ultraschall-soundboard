/*
  ==============================================================================

    ClipViewController.cpp
    Created: 2 May 2018 5:22:57pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "ClipViewController.h"

ClipViewController::ClipViewController(Identifier playerId, Engine &engine) : ViewController(engine) {
    player = engine.playerWithIdentifier(playerId);
}

void ClipViewController::loadView() {
    view.reset(new ClipView());
}

void ClipViewController::viewDidLoad() {
    auto v = static_cast<ClipView*>(view.get());
    v->playButton->onClick = [v, this] {
        v->setPlaying();
        this->player->play();
    };
}
