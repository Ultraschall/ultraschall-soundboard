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
#include "../LookAndFeel.h"
#include "../../../Plugin/PluginProcessor.h"
#include "GridCell.h"

class SoundboardGridComponent : public Component
{
public:
    explicit SoundboardGridComponent(SoundboardAudioProcessor &);
    ~SoundboardGridComponent();

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
