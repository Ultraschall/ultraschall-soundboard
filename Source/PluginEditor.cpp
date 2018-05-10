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
#ifndef JUCE_MAC
    openGLContext.attachTo(*getTopLevelComponent());
#endif
    
	LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);
	// TODO: implement a own standalone wrapper!
	//TopLevelWindow* w = TopLevelWindow::getTopLevelWindow(0);
	//w->setUsingNativeTitleBar(true);
    controller = std::make_unique<MainViewController>(p.library);
    controller->init();
	addAndMakeVisible(controller->getView());

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	
	
	setResizeLimits(128, 128, 1024, 1024);
	setResizable(true, true);
	setSize(320, 320);
}

UltraschallSoundboardAudioProcessorEditor::~UltraschallSoundboardAudioProcessorEditor()
{
	LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void UltraschallSoundboardAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (findColour (Material::ColourIds::backgroundColorId));
}

void UltraschallSoundboardAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	controller->getView()->setBounds(getLocalBounds());
}
