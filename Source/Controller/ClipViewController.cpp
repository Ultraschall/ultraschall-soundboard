#include "ClipViewController.h"
#include <memory>

ClipViewController::ClipViewController(String playerId, Engine &engine) : ViewController(engine)
{
    player = engine.playerWithIdentifier(playerId);
}

void ClipViewController::loadView()
{
    view = std::make_unique<ClipView>();
}

void ClipViewController::viewDidLoad()
{
    view->playButton.onClick = [this]
    {
        auto toggleState = view->playButton.getToggleState();
        if (toggleState)
        {

        } else
        {
            this->player->play();
        }
        view->playButton.setToggleState(!toggleState, NotificationType::dontSendNotification);
    };
}
