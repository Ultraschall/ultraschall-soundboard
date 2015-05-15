/*
  ==============================================================================

    GridCell.cpp
    Created: 23 Jan 2015 7:02:25pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "GridCell.h"


SoundboardGridCell::SoundboardGridCell(Player *p) : player(p), index(-1), progressState(true)
{
    setRepaintsOnMouseActivity(true);
    if (player)
    {
        player->getThumbnail()->addChangeListener(this);
        player->addChangeListener(this);
    }
}

SoundboardGridCell::~SoundboardGridCell()
{
    if (player)
    {
        player->getThumbnail()->removeChangeListener(this);
        player->removeChangeListener(this);
    }
}

void SoundboardGridCell::mouseUp(const MouseEvent &event)
{
    if (player)
    {
        Rectangle<float> loopArea(0.0f, 0.0f, getHeight() * 0.5f, getHeight() * 0.5f);
        Rectangle<float> timerArea(0.0f, getHeight() - getHeight() * 0.5f, getHeight() * 0.5f, getHeight() * 0.5f);
        Rectangle<float> fadeoutArea(getWidth() - getHeight() * 0.5f, 0.0f, getHeight() * 0.5f, getHeight() * 0.5f);
        Rectangle<float> stopArea(getWidth() - getHeight() * 0.5f,  getHeight() - getHeight() * 0.5f,  getHeight() * 0.5f, getHeight() * 0.5f);

        if (loopArea.contains(event.position))
        {
            player->setLooping(!player->isLooping());
        }
        else if (fadeoutArea.contains(event.position))
        {
            if (!player->isFading()) {
                if (player->isPlaying()) {
                    player->startFadeOut();
                } else if (player->isStopped() || player->isPaused()) {
                    player->startFadeIn();
                }
            }
        }
        else if (stopArea.contains(event.position))
        {
            player->stop();
        }
        else if (timerArea.contains(event.position))
        {
            progressState = !progressState;
        }
        else
        {
            if (player->isPlaying())
            {
                player->pause();
            }
            else
            {
                player->play();
            }
        }
        repaint();
    }
}


void SoundboardGridCell::paint(Graphics &g)
{
    auto border = g.getClipBounds().reduced(1).toFloat();
    auto cell   = border.reduced(2).toFloat();

    g.setColour(ThemeBackground1);
    g.fillAll();

    g.setColour(ThemeBackground3);
    g.fillRect(border);

    if (player)
    {
        Colour colour;
        if (player->isPlayed())
        {
            colour = ThemeGreen;
        }
        else if (player->isFading())
        {
            colour = ThemeOrange;
        }
        else if (player->isLooping())
        {
            colour = ThemeBlue;
        }
        else
        {
            colour = ThemeYellow;
        }

        g.setColour(colour.withAlpha(0.2f));
        g.fillRoundedRectangle(cell, 2);

        g.setColour(colour.withAlpha(0.2f));
        auto thumbArea = cell.reduced(0, 5).toType<int>();
        if (player->getThumbnail()->getTotalLength() > 0.0)
        {
            player->getThumbnail()->drawChannel(g, thumbArea, 0, player->getThumbnail()->getTotalLength(), 1, 1.0f);
        }

        float gainWidth = cell.getWidth() * 0.025f;
        {
            g.setColour(colour.withAlpha(0.5f));
            float y = cell.getHeight() - (player->getGain() * cell.getHeight()) + cell.getY();
            float height = cell.getHeight() - y + cell.getY();
            float x = cell.getWidth() - gainWidth + cell.getX();

            g.fillRoundedRectangle(x, y, gainWidth, height, 2);
        }

        g.setColour(colour.brighter(0.4f));
        g.drawHorizontalLine(static_cast<int>(g.getClipBounds().getHeight() * 0.5f - 1),
                             g.getClipBounds().getX() + 3.0f,
                             g.getClipBounds().getWidth() - 3.0f);

        int iconSize = int(getHeight() * 0.5f);
        int iconX = int((getWidth() * 0.5f ) - (iconSize * 0.5f));
        int iconY = int((getHeight() * 0.5f) - (iconSize * 0.5f));
        if (player->isPlayed())
        {
            FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Play, iconSize, colour.withAlpha(0.9f)), iconX, iconY);
        }
        else if (player->isLooping())
        {
            g.setColour(colour.withAlpha(0.5f));
            g.fillRoundedRectangle(cell.getX(),
                                   cell.getY(),
                                   cell.getWidth() * player->getProgress(),
                                   cell.getHeight(),
                                   2);

            g.setColour(colour.withAlpha(0.9f));
            g.setFont(getFontAwesome(getHeight() * 0.5f));
            if (player->isPlaying())
            {
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Pause, iconSize, colour.withAlpha(0.9f)), iconX, iconY);
            }
            else
            {
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Play, iconSize, colour.withAlpha(0.9f)), iconX, iconY);
            }
        }
        else
        {
            g.setColour(colour.withAlpha(0.5f));
            g.fillRoundedRectangle(cell.getX(),
                                   cell.getY(),
                                   cell.getWidth() * player->getProgress(),
                                   cell.getHeight(),
                                   2);

            if (player->isPlaying())
            {
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Pause, iconSize, colour.withAlpha(0.9f)), iconX, iconY);
            }
            else
            {
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Play, iconSize, colour.withAlpha(0.9f)), iconX, iconY);
            }
        }

        auto info = cell.reduced(1).toType<int>();
        g.resetToDefaultState();
        g.setFont(getHeight() * 0.15f);
        g.setColour(ThemeForeground1);
        g.drawText(player->getProgressString(progressState),
                   info.getX(),
                   info.getY(),
                   info.getWidth(),
                   info.getHeight(),
                   Justification::bottomLeft,
                   false);
        g.drawText(player->getTitle(),
                   info.getX(),
                   info.getY(),
                   info.getWidth(),
                   info.getHeight(),
                   Justification::centredTop,
                   false);

        if (isMouseOver(true))
        {
            iconSize = int(getHeight() * 0.25f);
            Colour iconColour = colour.withAlpha(0.9f);
            g.setColour(ThemeForeground1);
            
            auto helperRect = cell.reduced(3).toType<int>();
            if (player->isLooping())
            {
                iconColour = colour.withAlpha(0.9f);
            }
            else
            {
                iconColour = ThemeForeground1.withAlpha(0.5f);
            }
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Refresh, iconSize, iconColour),
                                   helperRect.getX(),
                                   helperRect.getY());

            if (player->isPlayed())
            {
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Square_O, iconSize, colour),
                                   helperRect.getWidth() - iconSize - (gainWidth * 0.5f),
                                   helperRect.getHeight() - iconSize + + helperRect.getY());
            }
            else
            {
                if (!player->isPaused() && !player->isPlaying())
                {
                    iconColour = ThemeForeground1.withAlpha(0.25f);
                }
                else
                {
                    iconColour = ThemeForeground1.withAlpha(0.5f);
                }
                FontAwesome.drawAt(g, FontAwesome.getIcon(FontAwesome_Square, iconSize, iconColour),
                                   helperRect.getWidth() - iconSize - (gainWidth * 0.5f),
                                   helperRect.getHeight() - iconSize + + helperRect.getY());
            }

            Icon icon;
            if (player->isFading())
            {
                iconColour = colour.withAlpha(0.9f);
            }
            else
            {
                iconColour = ThemeForeground1.withAlpha(0.5f);
            }

            if (player->isPlaying()) {
                icon = FontAwesome_Sort_Amount_Desc;
            } else {
                icon = FontAwesome_Sort_Amount_Asc;
            }

            FontAwesome.drawAt(g, FontAwesome.getRotatedIcon(icon, iconSize, iconColour, 0.5f),
                               helperRect.getWidth() - iconSize - (gainWidth * 0.5f),
                               helperRect.getX());
        }
    }
    else
    {
        g.setColour(ThemeForeground2);
        g.drawHorizontalLine(static_cast<int>(g.getClipBounds().getHeight() * 0.5f - 1),
                             g.getClipBounds().getX() + 3.0f,
                             g.getClipBounds().getWidth() - 3.0f);
    }
}

void SoundboardGridCell::changeListenerCallback(ChangeBroadcaster * /*source*/)
{
    repaint();
}

void SoundboardGridCell::setIndex(int value)
{
    index = value;
}

int SoundboardGridCell::getIndex()
{
    return index;
}
