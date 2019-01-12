#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
    Utility wrapper for ValueTree::Listener's that only want to override valueTreePropertyChanged.
*/
struct ValueTreePropertyChangeListener : public ValueTree::Listener
{
    void valueTreeChildAdded(ValueTree &, ValueTree &) override
    {
    }

    void valueTreeChildRemoved(ValueTree &, ValueTree &, int) override
    {
    }

    void valueTreeChildOrderChanged(ValueTree &, int, int) override
    {
    }

    void valueTreeParentChanged(ValueTree &) override
    {
    }

    void valueTreeRedirected(ValueTree &) override
    {
    }
};