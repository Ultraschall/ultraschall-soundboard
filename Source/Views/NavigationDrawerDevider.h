#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Material/Material.h"

class NavigationDrawerDevider : public Component {
public:
    constexpr const static int height = 8;

    NavigationDrawerDevider() : Component("NavigationDrawerDevider") {
        setOpaque(true);
        setSize(304, px(height));
    }
    ~NavigationDrawerDevider() override = default;

    void paint(Graphics &g) override {
        g.fillAll(Material::Color::Surface::Main);
        g.setColour(Material::Color::Icons::Selected::OnSurface::Active.withAlpha(0.12f));
        g.drawLine(0, px(4), getWidth(), px(4));
    }
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavigationDrawerDevider)
};
