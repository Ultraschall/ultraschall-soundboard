

#pragma once

#include <JuceHeader.h>
#include "ClipItem.h"

//==============================================================================
/*
*/
class ClipView  : public juce::Component
{
public:
    ClipView() : Component("ClipView") {
        for (int index = 0; index <= 24; index++) {
            addAndMakeVisible (clips.add (new ClipItem()));
        }
    }
    ~ClipView() override = default;

    void paint (juce::Graphics&) override {

    }
    void resized() override {
        Grid grid;
        grid.setGap( Grid::Px(2));

        using Track = Grid::TrackInfo;
        using Fr = Grid::Fr;

        grid.templateRows  = {
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1))
        };
        grid.templateColumns = {
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1)),
                Track (Fr (1))
        };

        for (auto* clip : clips) {
            grid.items.add(GridItem(*clip));
        }
        grid.performLayout(getLocalBounds().withTrimmedLeft(2).withTrimmedRight(2).withTrimmedBottom(2));
    }

    OwnedArray<ClipItem> clips;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClipView)
};
