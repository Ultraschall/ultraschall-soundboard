#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Material/Material.h"
#include "../Material/IconButton.h"

class LibraryItem : public Component {
public:
    constexpr const static int height = 62;
    
    LibraryItem() : Component("LibraryItem") {
		setOpaque(true);
        settingsButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Active);
        progressBar.setPercentageDisplay(false);
        
        progressBar.setColour(ProgressBar::ColourIds::backgroundColourId, Material::Color::Secondary::_700.withAlpha(0.24f));
        progressBar.setColour(ProgressBar::ColourIds::foregroundColourId, Material::Color::Secondary::_700);
        
        reset();
        
        addAndMakeVisible(settingsButton);
        addAndMakeVisible(loopButton);
        addAndMakeVisible(muteButton);
        addAndMakeVisible(title);
        addAndMakeVisible(time);
        addAndMakeVisible(fadeButton);
        addAndMakeVisible(stopButton);
        addAndMakeVisible(playButton);
        addAndMakeVisible(progressBar);
        setOpaque(true);
    }
    
    ~LibraryItem() noexcept override = default;

    void paint(Graphics &g) override {
        g.fillAll(Material::Color::Surface::Base);
        g.setColour(Material::Color::Icons::Selected::OnSurface::Active.withAlpha(0.12f));
        g.drawLine(0, getHeight() - 1, getWidth(), getHeight() - 1);
    }
    
    void resized() override {
        FlexBox flexBox;
        
        flexBox.items.add(FlexItem(settingsButton).withWidth(Material::IconButton::minButtonSize));
        flexBox.items.add(FlexItem(loopButton).withWidth(Material::IconButton::minButtonSize).withMargin(FlexItem::Margin(0, 8, 0, 0)));
        flexBox.items.add(FlexItem(muteButton).withWidth(Material::IconButton::minButtonSize));

        flexBox.items.add(FlexItem(title).withFlex(2));
        flexBox.items.add(FlexItem(time).withMaxWidth(px(48)));

        flexBox.items.add(FlexItem(fadeButton).withWidth(Material::IconButton::minButtonSize));
        flexBox.items.add(FlexItem(stopButton).withWidth(Material::IconButton::minButtonSize));
        flexBox.items.add(FlexItem(playButton).withWidth(Material::IconButton::minButtonSize));
        
        flexBox.performLayout(getLocalBounds().withTrimmedLeft(16).withTrimmedBottom(12).withTrimmedRight(16).withTrimmedTop(2));
        
        progressBar.setBounds(getLocalBounds().withTrimmedLeft(16).withHeight(4).withTrimmedRight(16).withY(getHeight() - 12));
    }
    
    void refresh() {
        resized();
    }
    
    void reset() {
        loopButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        loopButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        muteButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        muteButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        fadeButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        fadeButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        stopButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        playButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        playButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);

        loopButton.setToggleState(false, dontSendNotification);
        muteButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
        playButton.setToggleState(false, dontSendNotification);
        
        progress = 0.0;
    }
    
    void setError() {
        
    }
    
    void setIsStopped() {
        playButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        fadeButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
    }
    
    void setIsPaused() {
        fadeButton.setToggleState(true, dontSendNotification);
        playButton.setToggleState(true, dontSendNotification);
    }
    
    void setIsPlayed() {
        stopButton.setColour(Material::IconButton::iconColourId, Material::Color::Primary::Main);
    }
    
    void setIsPlaying() {
        muteButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        fadeButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        stopButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Active);
        playButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Active);

        muteButton.setToggleState(true, dontSendNotification);
        fadeButton.setToggleState(true, dontSendNotification);
        playButton.setToggleState(true, dontSendNotification);
    }
    
    void setIsReady() {
        playButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        fadeButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
    }
    
    Material::IconButton settingsButton{ Material::Icons::settings };
    Material::IconToggleButton loopButton{ Material::Icons::loop, Material::Icons::loop };
    Material::IconToggleButton muteButton{ Material::Icons::volume_mute, Material::Icons::volume_up };
    Material::IconToggleButton fadeButton{ Material::Icons::call_made, Material::Icons::call_made };
    Material::IconButton stopButton{ Material::Icons::stop };
    Material::IconToggleButton playButton{ Material::Icons::play_arrow, Material::Icons::pause };
    Label title;
    Label time;
    double progress{0.5};
private:
    ProgressBar progressBar{progress};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LibraryItem)
};
