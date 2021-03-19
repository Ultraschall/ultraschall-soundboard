/*
  ==============================================================================

    GridComponent.h
    Created: 6 Jan 2015 2:13:24am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef GRIDCOMPONENT_H_INCLUDED
#define GRIDCOMPONENT_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>

#include "../LookAndFeel.h"
#include "../../../plugin/PluginProcessor.h"
#include "GridCell.h"

using namespace juce;

class SoundboardGridComponent : public Component
{
public:
    explicit SoundboardGridComponent(SoundboardAudioProcessor &);
    ~SoundboardGridComponent() override;

    // Component
    void resized() override;

    // Helper
    void updateContent();

private:
    enum TimerIds
    {
        TimerIdRepaint = 1
    };

    SoundboardAudioProcessor &processor;
    OwnedArray<SoundboardGridCell> cells; JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardGridComponent)
};

#endif // GRIDCOMPONENT_H_INCLUDED
