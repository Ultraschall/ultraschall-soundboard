#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LookAndFeel/LookAndFeel.h"

#include "PluginProcessor.h"
#include "UserInterface/Controllers/MainViewController.h"

class UltraschallSoundboardAudioProcessorEditor : public AudioProcessorEditor {
public:
    explicit UltraschallSoundboardAudioProcessorEditor(UltraschallSoundboardAudioProcessor &);

    ~UltraschallSoundboardAudioProcessorEditor();

    void paint(Graphics &) override;

    void resized() override;

private:
    UltraschallSoundboardAudioProcessor &processor;

    std::unique_ptr<MainViewController> controller;
    MaterialLookAndFeel lookAndFeel;
//    OpenGLContext openGLContext;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraschallSoundboardAudioProcessorEditor)
};
