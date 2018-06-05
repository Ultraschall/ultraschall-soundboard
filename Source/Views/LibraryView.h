#pragma once

#include "JuceHeader.h"
#include "../Material/Material.h"

#include "LibraryItem.h"

class LibraryView : public Component
{
public:
    LibraryView() {
        table.setColour(ListBox::backgroundColourId, Material::Color::Surface::Light);
        table.setRowHeight(px(LibraryItem::height));
        addAndMakeVisible(table);
    }
    
    ~LibraryView() = default;
    
    void resized() override {
        table.setBounds(getLocalBounds());
    }
    
    ListBox table;
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
