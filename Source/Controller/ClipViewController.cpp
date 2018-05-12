#include "ClipViewController.h"

ClipViewController::ClipViewController(String playerId, Engine &engine) : ViewController(engine)
{
    player = engine.playerWithIdentifier(playerId);
}

void ClipViewController::loadView()
{
    view.reset(new ClipView());
}

void ClipViewController::viewDidLoad()
{
    view->playButton.onClick = [this]
    {
        auto toggleState = view->playButton.getToggleState();
        if (toggleState == true)
        {

        } else
        {
            this->player->play();
        }
        view->playButton.setToggleState(!toggleState, NotificationType::dontSendNotification);
    };
}
