/*
  ==============================================================================

    MainView.h
    Created: 4 May 2018 11:22:54am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "DrawingTools.h"

//==============================================================================
/*
*/
class MainView    : public Component
{
public:
    MainView();
    ~MainView();

    void paint (Graphics&) override;
    void resized() override;

    void setContentView(Component* view);

    Toolbar toolbar;

	class GainToolbarView : public ToolbarItemComponent {
	public:
		GainToolbarView(const int toolbarItemId) 
			: ToolbarItemComponent(toolbarItemId, "Gain", false) {
			addAndMakeVisible(slider);
			slider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
		}
		// Geerbt �ber ToolbarItemComponent
		virtual bool getToolbarItemSizes(int toolbarThickness, bool isToolbarVertical, int & preferredSize, int & minSize, int & maxSize) override;
		virtual void paintButtonArea(Graphics & g, int width, int height, bool isMouseOver, bool isMouseDown) override;
		virtual void contentAreaChanged(const Rectangle<int>& newBounds) override;
	private:
		Slider slider;
	};
private:
    Component *contentView = nullptr;

	std::unique_ptr<Component> temp;

	SvgIcon ultraschallIcon;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainView)
};
