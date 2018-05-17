#include "ClipViewController.h"

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
	    const auto toggleState = view->playButton.getToggleState();
        if (toggleState)
        {

        } else
        {
            this->player->play();
        }
        view->playButton.setToggleState(!toggleState, NotificationType::dontSendNotification);
    };
}
