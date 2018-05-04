/*
  ==============================================================================

    ClipView.h
    Created: 29 Apr 2018 12:22:06pm

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "DrawingTools.h"

class ClipView : public Component {
public:
    explicit ClipView();

    ~ClipView();

    void paint(Graphics &g) override;

    void resized() override;

    void setPlaying();

    void setPaused();

    std::unique_ptr<DrawableButton> playButton;
private:
    std::unique_ptr<SvgIcon> playIcon;
    std::unique_ptr<SvgIcon> pauseIcon;

    enum ClipState {
        isIdle,
        isPlaying,
        isLooping,
        isFading
    };

    ClipState state;
    float progress;
public:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClipView)
};
