#include "PluginProcessor.h"
#include "PluginEditor.h"

// TODO: implement a own standalone wrapper!
UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor(
    UltraschallSoundboardAudioProcessor &p)
    : AudioProcessorEditor(&p), processor(p) {

// #if JUCE_LINUX || JUCE_WINDOWS || JUCE_ANDROID
//     openGLContext.attachTo(*this); // (*getTopLevelComponent());
// #endif

    LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);

    controller = std::make_unique<MainViewController>(p.engine);
    controller->init();
    addAndMakeVisible(controller->getView());

#if JUCE_LINUX || JUCE_WINDOWS || JUCE_MAC
    setResizeLimits(static_cast<int>(Material::IconButton::minButtonSize * 4), AppBar::height + BottomBar::height, 0x3fffffff, 0x3fffffff);
    setResizable(true, true);
#endif
    setSize(1024, 640);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor() {
    LookAndFeel::setDefaultLookAndFeel(nullptr);
    Material::Fonts::deleteInstance();
    Material::Typefaces::deleteInstance();
}

void UltraschallSoundboardAudioProcessorEditor::paint(Graphics &g) {
    g.fillAll(Material::Color::Surface::Main);
}

void UltraschallSoundboardAudioProcessorEditor::resized() {
    controller->getView()->setBounds(getLocalBounds());
}
