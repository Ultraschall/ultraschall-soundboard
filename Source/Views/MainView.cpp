/*
  ==============================================================================

    MainView.cpp
    Created: 4 May 2018 11:22:54am
    Author:  danlin

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MainView.h"

//==============================================================================
MainView::MainView()
{
    toolbar.setStyle(Toolbar::ToolbarItemStyle::iconsWithText);
    addAndMakeVisible(toolbar);
	temp = std::make_unique<Component>();
	setContentView(temp.get());
}

MainView::~MainView()
{

}

void MainView::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("MainView", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void MainView::resized()
{
    auto flexBox = FlexBox();

	flexBox.flexDirection = FlexBox::Direction::row;


	if (contentView != nullptr) {
		flexBox.items.add(FlexItem(*contentView).withFlex(2));
	}


	flexBox.items.add(FlexItem(toolbar).withMaxHeight(48).withWidth(getWidth()).withFlex(1));

    flexBox.performLayout(getLocalBounds());
}

void MainView::setContentView(Component *view) {
    contentView = nullptr;
    if (view != nullptr) {
        contentView = view;
        addAndMakeVisible(view);
        resized();
    }
}

bool MainView::GainToolbarView::getToolbarItemSizes(int toolbarThickness, bool isToolbarVertical, int & preferredSize, int & minSize, int & maxSize)
{
	if (isToolbarVertical)
		return false;

	preferredSize = 250;
	minSize = 80;
	maxSize = 300;
	return true;
}

void MainView::GainToolbarView::paintButtonArea(Graphics & g, int width, int height, bool isMouseOver, bool isMouseDown)
{
}

void MainView::GainToolbarView::contentAreaChanged(const Rectangle<int>& newBounds)
{
	slider.setSize(newBounds.getWidth() - 2,
		jmin(newBounds.getHeight() - 2, 22));

	slider.setCentrePosition(newBounds.getCentreX(), newBounds.getCentreY());
}
