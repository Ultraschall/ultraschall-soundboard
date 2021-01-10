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
        progressBar.setPercentageDisplay(false);
        addAndMakeVisible(&progressBar);
        addAndMakeVisible(&addButton);
        addAndMakeVisible(&playButton);
        addAndMakeVisible(&pauseButton);
        addAndMakeVisible(&stopButton);

        addButton.setColour(Material::IconButton::iconColourId, Colours::whitesmoke.withAlpha(0.5f));

        playButton.setVisible(false);
        pauseButton.setVisible(false);
        stopButton.setVisible(false);
    }
    ~ClipItem() override = default;

    void paint (juce::Graphics& g) override {
        // g.fillAll(Colours::black);
    }
    void resized() override {
        auto bounds = getLocalBounds();
        progressBar.setBounds(bounds);
        addButton.setBounds(bounds.withSizeKeepingCentre(16, 16));
        playButton.setBounds(bounds.withSizeKeepingCentre(16, 16));

        pauseButton.setBounds(2, bounds.getHeight() - 18, 16, 16);
        stopButton.setBounds(bounds.getWidth() - 18, bounds.getHeight() - 18, 16, 16);
    }

    void setIsPlaying() {
        addButton.setVisible(false);
        playButton.setVisible(true);

    }

    void mouseEnter(const MouseEvent &event) override {
        Component::mouseEnter(event);
        pauseButton.setVisible(true);
        stopButton.setVisible(true);
    }

    void mouseExit(const MouseEvent &event) override {
        pauseButton.setVisible(false);
        stopButton.setVisible(false);
    }

    Material::IconButton addButton{ Material::Icons::add };
    Material::IconToggleButton playButton{ Material::Icons::play_arrow, Material::Icons::volume_up };
    Material::IconButton pauseButton{ Material::Icons::pause };
    Material::IconButton stopButton{ Material::Icons::stop };
    double progress{0.0};
private:
    ProgressBar progressBar{progress};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClipItem)
};
