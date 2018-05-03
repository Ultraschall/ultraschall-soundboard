/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
UltraschallSoundboardAudioProcessorEditor::UltraschallSoundboardAudioProcessorEditor (UltraschallSoundboardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    auto player = p.library.playerAtIndex(1);
    controller.reset(new ClipViewController(player->getIdentifier(), p.library));
    controller->init();
	addAndMakeVisible(controller->getView());

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor()
{
}

//==============================================================================
void UltraschallSoundboardAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void UltraschallSoundboardAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	controller->getView()->setBounds(getLocalBounds());
}
