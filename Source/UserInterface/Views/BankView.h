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
        addAndMakeVisible(&clipView);
    }
    ~BankView() override = default;

    void paint (juce::Graphics& g) override {
        g.fillAll(Material::Color::Surface::Main);
    }
    void resized() override {
        FlexBox flexBox;
        flexBox.flexDirection = juce::FlexBox::Direction::column;
        flexBox.items.add(juce::FlexItem(bankSelectorView).withHeight(32));
        flexBox.items.add(juce::FlexItem(clipView).withFlex(1));
        flexBox.performLayout(getLocalBounds());
    }

    ClipView clipView;
    BankSelectorView bankSelectorView;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankView)
};