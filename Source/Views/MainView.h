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
#include "ToolbarView.h"
#include "BottomBarView.h"
#include "SideNavbarView.h"

//==============================================================================
/*
*/
class MainView : public Component
{
public:
	MainView();
	~MainView();

	void paint(Graphics&) override;
	void resized() override;

	void setContentView(Component* view);

	class GainToolbarView : public ToolbarItemComponent {
	public:
		GainToolbarView(const int toolbarItemId)
			: ToolbarItemComponent(toolbarItemId, "Gain", false) {
			addAndMakeVisible(slider);
			slider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
		}
		virtual bool getToolbarItemSizes(int toolbarThickness, bool isToolbarVertical, int & preferredSize, int & minSize, int & maxSize) override;
		virtual void paintButtonArea(Graphics & g, int width, int height, bool isMouseOver, bool isMouseDown) override;
		virtual void contentAreaChanged(const Rectangle<int>& newBounds) override;
	private:
		Slider slider;
	};
private:
	ToolbarView toolbar;
	Component *contentView = nullptr;
	SvgIcon ultraschallIcon = { BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize };
	DropShadower dropShadower = { DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.19f), 6, Point<int>(0, 6)) };

	Component spacer;
	BottomBarView bottomBar;
	SideNavbarView sideNavbar;

	SvgIcon addIcon{ BinaryData::add_svg, BinaryData::add_svgSize };
	DrawableButton addButton{ "Add", DrawableButton::ImageFitted };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
