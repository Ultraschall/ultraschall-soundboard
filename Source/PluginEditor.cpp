/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <memory>

//==============================================================================
UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor (UltraschallSoundboardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    controller = std::make_unique<MainViewController>(p.library);
    controller->init();
	addAndMakeVisible(controller->getView());

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	setResizable(true, true);
	setSize (400, 320);
	setResizeLimits(320, 320, 1024, 1024);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor()
{
}

//==============================================================================
void UltraschallSoundboardAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void UltraschallSoundboardAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	controller->getView()->setBounds(getLocalBounds());
}
