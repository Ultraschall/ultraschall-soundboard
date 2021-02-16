/*
  ==============================================================================

    BankView.h
    Created: 9 Jan 2021 8:47:07pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "BankSelectorView.h"
#include "ClipView.h"

class BankView  : public juce::Component
{
public:
    BankView() : Component("BankView") {
        addAndMakeVisible(&bankSelectorView);
    }
    ~BankView() override = default;

    void paint (juce::Graphics& g) override {
        g.fillAll(Material::Color::Surface::Main);
    }
    void resized() override {
        FlexBox flexBox;
        flexBox.flexDirection = juce::FlexBox::Direction::column;
        flexBox.items.add(juce::FlexItem(bankSelectorView).withHeight(32));
        if (contentView != nullptr) {
            flexBox.items.add(FlexItem(*contentView).withFlex(1));
        }
        flexBox.performLayout(getLocalBounds());
    }

    void setClipView(Component* view) {
        if (view == contentView) return;
        
        if (contentView != nullptr) {
            removeChildComponent(contentView);
        }
        contentView = view;
        addAndMakeVisible(contentView);
        contentView->toBack();
        resized();
    }
    
    BankSelectorView bankSelectorView;

private:
    Component *contentView{nullptr};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankView)
};
