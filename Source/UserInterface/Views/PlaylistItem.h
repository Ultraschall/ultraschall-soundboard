#pragma once

#include "JuceHeader.h"

class PlaylistItem : public Component
{
public:
    PlaylistItem() {
		setOpaque(true);
    }
    
    ~PlaylistItem() noexcept override = default;
    
    void paint(Graphics& g) override {
    }
    
    void resized() override {
    }
    
private:    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaylistItem)
};
