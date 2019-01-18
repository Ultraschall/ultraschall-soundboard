#pragma once


#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../LookAndFeel/Material.h"

class StartupView : public Component
{
public:
    StartupView() {
		setOpaque(true);
    }
    
    ~StartupView() noexcept override = default;
    
    void paint(Graphics& g) override {
        g.fillAll(Material::Color::Surface::Light);
    }
    
    void resized() override {
    }
    
private:
    ImageComponent image;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StartupView)
};
