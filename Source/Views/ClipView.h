/*
  ==============================================================================

    ClipView.h
    Created: 29 Apr 2018 12:22:06pm

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class ClipView : public Component {
public:
    explicit ClipView();

    ~ClipView();

    void paint(Graphics &g) override;

    void resized() override;

	DrawableButton playButton{ "Play / Pause Button", DrawableButton::ButtonStyle::ImageFitted };
private:
	Material::Icon playIcon{ BinaryData::baselineplay_arrow24px_svg, BinaryData::baselineplay_arrow24px_svgSize };
	Material::Icon pauseIcon{ BinaryData::baselinepause24px_svg, BinaryData::baselinepause24px_svgSize };

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
