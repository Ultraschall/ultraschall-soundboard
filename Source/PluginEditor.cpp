#include "PluginEditor.h"
#include "PluginProcessor.h"

// TODO(danlin): implement a own standalone wrapper!
UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor(
    UltraschallSoundboardAudioProcessor &p)
    : AudioProcessorEditor(&p), processor(p) {

#if JUCE_LINUX || JUCE_WINDOWS
	openGLContext.attachTo(*this);
#endif
	setLookAndFeel(&lookAndFeel);
	LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);

    controller = std::make_unique<MainViewController>(processor.getStore());
    controller->init();
    addAndMakeVisible(controller->getView());

#if JUCE_LINUX || JUCE_WINDOWS || JUCE_MAC
    setResizeLimits(px(Material::IconButton::minButtonSize * 10), px(Material::IconButton::minButtonSize * 7), 0x3fffffff, 0x3fffffff);
    setResizable(true, true);
#endif
    setSize(1024, 640);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor() {
	removeAllChildren();
	controller = nullptr;
	setLookAndFeel(nullptr);
    LookAndFeel::setDefaultLookAndFeel(nullptr);
    Material::Fonts::deleteInstance();
    Material::Typefaces::deleteInstance();
}

void UltraschallSoundboardAudioProcessorEditor::paint(Graphics &g) {
    g.fillAll(Material::Color::Surface::Main);
}

void UltraschallSoundboardAudioProcessorEditor::parentHierarchyChanged()
{
    if (PluginHostType::getPluginLoadedAs() == AudioProcessor::wrapperType_Standalone) {
        if (TopLevelWindow::getNumTopLevelWindows() == 1) {
            auto topLevelWindow = TopLevelWindow::getTopLevelWindow(0);
            topLevelWindow->setUsingNativeTitleBar(true);
            //topLevelWindow->setLookAndFeel(&lookAndFeel);
        }
    }
}

void UltraschallSoundboardAudioProcessorEditor::resized() {
    controller->getView()->setBounds(getLocalBounds());
}
