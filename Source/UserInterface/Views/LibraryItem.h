#pragma once

#include "JuceHeader.h"
#include "../../LookAndFeel/Material.h"

class LibraryItem : public Component {
public:
    constexpr const static int height = 62;
    
    LibraryItem() : Component("LibraryItem") {
		setOpaque(true);
        progressBar.setPercentageDisplay(false);
        
        progressBar.setColour(ProgressBar::ColourIds::backgroundColourId, Material::Color::Primary::_700.withAlpha(0.24f));
        progressBar.setColour(ProgressBar::ColourIds::foregroundColourId, Material::Color::Primary::_700);
        
        reset();
        
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
		auto colour = error ? Material::Color::Surface::Dark : Material::Color::Surface::Base;
		g.fillAll(colour);
        if (thumbnail != nullptr) {
            thumbnail->drawChannel(g, getBounds().withTrimmedTop(10), 0, thumbnail->getTotalLength(), 1, 1.0f);
        }
        g.setColour(Material::Color::Icons::Selected::OnSurface::Active.withAlpha(0.12f));
        g.drawLine(0.0f, getHeight() - 1.0f, static_cast<float>(getWidth()), getHeight() - 1.0f);
    }
    
    void resized() override {
        FlexBox flexBox;
        
        flexBox.items.add(FlexItem(muteButton).withWidth(Material::IconButton::minButtonSize));

        flexBox.items.add(FlexItem(title).withFlex(2));
        flexBox.items.add(FlexItem(time).withMaxWidth(px(48.0f)));

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
        muteButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        muteButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        fadeButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        fadeButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        stopButton.setColour(Material::IconButton::iconColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        
        playButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);
        playButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Inactive);

        muteButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
        playButton.setToggleState(false, dontSendNotification);
        
        progress = 0.0;
    }
    
    void setError() {
		muteButton.setEnabled(false);
		fadeButton.setEnabled(false);
		stopButton.setEnabled(false);
		playButton.setEnabled(false);
		error = true;
		repaint();
    }
    
    void setIsStopped() {
        playButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
        fadeButton.setColour(Material::IconToggleButton::iconInactiveColourId, Material::Color::Icons::Selected::OnSurface::Active);
    }
    
    void setIsPaused() {
        fadeButton.setToggleState(false, dontSendNotification);
        playButton.setToggleState(false, dontSendNotification);
    }
    
    void setIsPlayed() {
        stopButton.setColour(Material::IconButton::iconColourId, Material::Color::Primary::Main);
    }
    
    void setIsPlaying() {
        muteButton.setColour(Material::IconToggleButton::iconActiveColourId, Material::Color::Secondary::Main);
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
    
    Material::IconToggleButton muteButton{ Material::Icons::volume_mute, Material::Icons::volume_up };
    Material::IconToggleButton fadeButton{ Material::Icons::call_made, Material::Icons::call_made };
    Material::IconButton stopButton{ Material::Icons::stop };
    Material::IconToggleButton playButton{ Material::Icons::play_arrow, Material::Icons::pause };
    Label title;
    Label time;
    double progress{0.0};
    std::shared_ptr<AudioThumbnail> thumbnail;
private:
    ProgressBar progressBar{progress};
	bool error{false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LibraryItem)
};
