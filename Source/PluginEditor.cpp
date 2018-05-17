#include "PluginProcessor.h"
#include "PluginEditor.h"

// TODO: implement a own standalone wrapper!
UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor(
        UltraschallSoundboardAudioProcessor &p)
        : AudioProcessorEditor(&p), processor(p)
{
#if JUCE_LINUX || JUCE_WINDOWS || JUCE_ANDROID
    openGLContext.attachTo(*getTopLevelComponent());
#endif

    LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);

    controller = std::make_unique<MainViewController>(p.library);
    controller->init();
    addAndMakeVisible(controller->getView());

#if JUCE_LINUX || JUCE_WINDOWS
    setResizable(true, true);
    setSize(320, 320);
#endif
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor()
{
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}

void UltraschallSoundboardAudioProcessorEditor::paint(Graphics &g)
{
    g.fillAll(findColour(Material::ColourIds::backgroundColorId));
}

void UltraschallSoundboardAudioProcessorEditor::resized()
{
    controller->getView()->setBounds(getLocalBounds());
}
