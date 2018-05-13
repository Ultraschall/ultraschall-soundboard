#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <memory>

UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor(
        UltraschallSoundboardAudioProcessor &p)
        : AudioProcessorEditor(&p), processor(p)
{
#if JUCE_LINUX || JUCE_WINDOWS
    openGLContext.attachTo(*getTopLevelComponent());
#endif

    LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);

    // TODO: implement a own standalone wrapper!

    controller = std::make_unique<MainViewController>(p.library);
    controller->init();
    addAndMakeVisible(controller->getView());

    setResizable(true, true);
    setSize(320, 320);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor()
{
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void UltraschallSoundboardAudioProcessorEditor::paint(Graphics &g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(findColour(Material::ColourIds::backgroundColorId));
}

void UltraschallSoundboardAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    controller->getView()->setBounds(getLocalBounds());
}
