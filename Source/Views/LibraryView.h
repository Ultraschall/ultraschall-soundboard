#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryView : public Component
{
public:
    LibraryView();;

    ~LibraryView()
    {
    }

    void resized() override;

    ListBox table;
private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
