/*
  ==============================================================================

    GridComponent.h
    Created: 6 Jan 2015 2:13:24am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef GRIDCOMPONENT_H_INCLUDED
#define GRIDCOMPONENT_H_INCLUDED

#include "JuceHeader.h"
#include "LookAndFeel.h"
#include "PluginProcessor.h"

class SoundboardGridCell : public Component, public ChangeListener {
public:
    explicit SoundboardGridCell(Player* p)
        : player(p)
        , index(-1)
        , progressState(true)
    {
        setRepaintsOnMouseActivity(true);
        if (player) {
            player->getThumbnail()->addChangeListener(this);
        }
    }
    ~SoundboardGridCell()
    {
    }

    void mouseUp (const MouseEvent& event) override {
        if (player) {
            Rectangle<float> loopArea(0.0f, 0.0f, getHeight() * 0.5f, getHeight() * 0.5f);
            Rectangle<float> timerArea(0.0f, getHeight() - getHeight() * 0.5f, getHeight() * 0.5f, getHeight() * 0.5f);
            Rectangle<float> fadeoutArea(getWidth() - getHeight() * 0.5f, 0.0f, getHeight() * 0.5f, getHeight() * 0.5f);
            Rectangle<float> stopArea(getWidth() - getHeight() * 0.5f, getHeight() - getHeight() * 0.5f, getHeight() * 0.5f, getHeight() * 0.5f);
            if (loopArea.contains(event.position)) {
                player->setLooping(!player->isLooping());
            } else if (fadeoutArea.contains(event.position)) {
                if (player->isPlaying()) {
                    player->startFadeOut();
                }
            } else if (stopArea.contains(event.position)) {
                player->stop();
            } else if (timerArea.contains(event.position)) {
                progressState = !progressState;
            } else {
                if (player->isPlaying()) {
                    player->pause();
                } else {
                    player->play();
                }
            }
            repaint();
        }
    }


    void paint(Graphics& g) override
    {
        auto border = g.getClipBounds().reduced(1).toFloat();
        auto cell = border.reduced(2).toFloat();

        g.setColour(ThemeBackground1);
        g.fillAll();

        g.setColour(ThemeBackground3);
        g.fillRect(border);

        if (player) {
            Colour colour;
            if (player->isPlayed()) {
                colour = ThemeGreen;
            } else if (player->isFadingOut()) {
                colour = ThemeOrange;
            } else if (player->isLooping()) {
                colour = ThemeBlue;
            } else {
                colour = ThemeYellow;
            }

            g.setColour(colour.withAlpha(0.2f));
            g.fillRoundedRectangle(cell, 2);

            g.setColour(colour.withAlpha(0.2f));
            auto thumbArea = cell.reduced(0, 5).toType<int>();
            if (player->getThumbnail()->getTotalLength() > 0.0) {
                player->getThumbnail()->drawChannel(g, thumbArea, 0, player->getThumbnail()->getTotalLength(), 1, 1.0f);
            }

            g.setColour(colour.brighter(0.4f));
            g.drawHorizontalLine(static_cast<int>(g.getClipBounds().getHeight() * 0.5f - 1), g.getClipBounds().getX() + 3.0f, g.getClipBounds().getWidth() - 3.0f);

            if (player->isPlayed()) {
                g.setColour(colour.withAlpha(0.9f));
                g.setFont(getFontAwesome(getHeight() * 0.5f));
                g.drawText(FA_PAUSE, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
            } else if (player->isFadingOut()) {
                g.setColour(colour.withAlpha(0.5f));
                g.fillRoundedRectangle(cell.getX(), cell.getY(), cell.getWidth() * player->getGain(), cell.getHeight(), 2);

                g.setColour(colour.withAlpha(0.9f));
                g.setFont(getFontAwesome(getHeight() * 0.5f));
                g.drawText(FA_PAUSE, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
            } else if (player->isLooping()) {
                g.setColour(colour.withAlpha(0.5f));
                g.fillRoundedRectangle(cell.getX(), cell.getY(), cell.getWidth() * player->getProgress(), cell.getHeight(), 2);

                g.setColour(colour.withAlpha(0.9f));
                g.setFont(getFontAwesome(getHeight() * 0.5f));
                if (player->isPlaying()) {
                    g.drawText(FA_PAUSE, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
                } else {
                    g.drawText(FA_PLAY, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
                }
            } else {
                g.setColour(colour.withAlpha(0.5f));
                g.fillRoundedRectangle(cell.getX(), cell.getY(), cell.getWidth() * player->getProgress(), cell.getHeight(), 2);

                g.setColour(colour.withAlpha(0.9f));
                g.setFont(getFontAwesome(getHeight() * 0.5f));
                if (player->isPlaying()) {
                    g.drawText(FA_PAUSE, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
                } else {
                    g.drawText(FA_PLAY, thumbArea.getX(), thumbArea.getY(), thumbArea.getWidth(), thumbArea.getHeight(), Justification::centred, false);
                }
            }

            auto info = cell.reduced(1).toType<int>();
            g.resetToDefaultState();
            g.setFont(getHeight() * 0.15f);
            g.setColour(ThemeForeground1);
            g.drawText(player->getProgressString(progressState), info.getX(), info.getY(), info.getWidth(), info.getHeight(), Justification::bottomLeft, false);
            g.drawText(player->getTitle(), info.getX(), info.getY(), info.getWidth(), info.getHeight(), Justification::centredTop, false);

            if (isMouseOver(true)) {
                auto helperRect = cell.reduced(3).toType<int>();
                if (player->isLooping()) {
                    g.setColour(colour);
                } else {
                    g.setColour(ThemeForeground1.withAlpha(0.5f));
                }
                g.setFont(getFontAwesome(getHeight() * 0.25f));
                g.drawText(FA_REFRESH, helperRect.getX(), helperRect.getY(), helperRect.getWidth(), helperRect.getHeight(), Justification::topLeft, false);

                if (player->isPlayed()) {
                    g.setColour(colour);
                    g.drawText(FA_SQUARE_O, helperRect.getX(), helperRect.getY(), helperRect.getWidth(), helperRect.getHeight(), Justification::bottomRight, false);
                } else {
                    if (!player->isPaused() && !player->isPlaying()) {
                        g.setColour(ThemeForeground1.withAlpha(0.25f));
                    } else {
                        g.setColour(ThemeForeground1.withAlpha(0.5f));
                    }
                    g.drawText(FA_SQUARE, helperRect.getX(), helperRect.getY(), helperRect.getWidth(), helperRect.getHeight(), Justification::bottomRight, false);
                }

                if (!player->isPlaying()) {
                    g.setColour(ThemeForeground1.withAlpha(0.25f));
                } else if(player->isFadingOut()) {
                    g.setColour(colour);
                } else {
                    g.setColour(ThemeForeground1.withAlpha(0.5f));
                }
                g.drawText(FA_VOLUME_DOWN, helperRect.getX(), helperRect.getY(), helperRect.getWidth(), helperRect.getHeight(), Justification::topRight, false);
            }
        } else {
            g.setColour(ThemeForeground2);
            g.drawHorizontalLine(static_cast<int>(g.getClipBounds().getHeight() * 0.5f - 1), g.getClipBounds().getX() + 3.0f, g.getClipBounds().getWidth() - 3.0f);
        }
    }

    void changeListenerCallback(ChangeBroadcaster* /*source*/) override
    {
        repaint();
    }
    void setIndex(int value) { index = value; }
    int getIndex() { return index; }

private:
    Player* player;
    int index;
    bool progressState;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardGridCell)
};

class SoundboardGridComponent : public Component, public MultiTimer {
public:
    explicit SoundboardGridComponent(SoundboardAudioProcessor&);
    ~SoundboardGridComponent();

    // Component
    void resized() override;

    // MultiTimer
    void timerCallback(int timerID) override;

    // Helper
    void updateContent();

private:
    enum TimerIds {
        TimerIdRepaint = 1
    };

    SoundboardAudioProcessor& processor;
    OwnedArray<SoundboardGridCell> cells;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardGridComponent)
};

#endif // GRIDCOMPONENT_H_INCLUDED
