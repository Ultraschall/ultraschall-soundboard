/*
  ==============================================================================

    BankSelectorView.h
    Created: 9 Jan 2021 8:48:19pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "../../LookAndFeel/Material.h"

class BankSelectorView  : public juce::Component
{
public:
    BankSelectorView() : Component("BankSelectorView") {
        addAndMakeVisible(&backButton);
        addAndMakeVisible(&title);
        addAndMakeVisible(&forwardButton);

        title.setJustificationType(Justification::centred);
        title.setText("Empty", dontSendNotification);
    }
    ~BankSelectorView() override = default;

    void paint (juce::Graphics& g) override {
        // g.fillAll(Colours::blue);
    }
    void resized() override {
        FlexBox flexBox;
        flexBox.flexDirection = juce::FlexBox::Direction::row;
        flexBox.items.add(juce::FlexItem(backButton).withWidth(48));
        flexBox.items.add(juce::FlexItem(title).withFlex(1));
        flexBox.items.add(juce::FlexItem(forwardButton).withWidth(48));
        flexBox.performLayout(getLocalBounds());
    }

    Label title;
    Material::IconButton backButton{ Material::Icons::back };
    Material::IconButton forwardButton{ Material::Icons::forward };

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankSelectorView)
};