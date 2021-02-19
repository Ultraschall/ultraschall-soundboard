#pragma once

#include "JuceHeader.h"
#include "LookAndFeel/Material.h"

#include "PluginProcessor.h"
#include "UserInterface/Controllers/MainViewController.h"

class UltraschallSoundboardAudioProcessorEditor : public AudioProcessorEditor {
public:
    explicit UltraschallSoundboardAudioProcessorEditor(UltraschallSoundboardAudioProcessor &);

    ~UltraschallSoundboardAudioProcessorEditor();

    void paint(Graphics &) override;
    void parentHierarchyChanged() override;
    void resized() override;

private:
    UltraschallSoundboardAudioProcessor &processor;

    std::unique_ptr<MainViewController> controller;
    MaterialLookAndFeel lookAndFeel;
#if JUCE_LINUX || JUCE_WINDOWS
    OpenGLContext openGLContext;
#endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraschallSoundboardAudioProcessorEditor)
};
