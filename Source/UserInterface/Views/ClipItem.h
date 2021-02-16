/*
  ==============================================================================

    ClipView.h
    Created: 9 Jan 2021 8:18:19pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../LookAndFeel/Material.h"

//==============================================================================
/*
*/
class ClipItem  : public Component
{
public:
    ClipItem() : Component("ClipItem") {
        add = Material::Icons::add.getDrawable(Material::Color::Icons::White::Inactive);
        play = Material::Icons::play_arrow.getDrawable(Material::Color::Icons::White::Active);
        pause = Material::Icons::pause.getDrawable(Material::Color::Icons::White::Active);
        stop = Material::Icons::stop.getDrawable(Material::Color::Icons::White::Active);
        playing = Material::Icons::volume_up.getDrawable(Material::Color::Icons::White::Active);
    }
    ~ClipItem() override = default;

    void paint (juce::Graphics& g) override {
        if (playerId.isEmpty()) {
            add->drawWithin(g,
                                 getLocalBounds().toFloat().withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)),
                                 RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
        } else {
            g.fillAll(Colours::black);
            auto bounds = getLocalBounds();
            g.drawRect(bounds.removeFromRight(bounds.getWidth() * progress));
        }
    }
    void resized() override {}

    void setIsPlaying() {

    }

    float progress{0};
    String playerId{""};
private:
    std::unique_ptr<Drawable> add, play, pause, stop, playing;
    int iconSize{16};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClipItem)
};
