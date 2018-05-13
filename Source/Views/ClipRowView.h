#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

class ClipRowView : public Component
{
public:
    ClipRowView();

    ~ClipRowView();

    void paint(Graphics &) override;

    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClipRowView)
};
