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
    toolbar.setStyle(Toolbar::ToolbarItemStyle::iconsOnly);
    addAndMakeVisible(toolbar);
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
    // This method is where you should set the bounds of any child
    // components that your component contains..
    auto flexBox = FlexBox();
    flexBox.items.add(FlexItem(toolbar).withMaxHeight(32).withFlex(1));

    if (contentView != nullptr) {
        flexBox.items.add(FlexItem(*contentView).withFlex(2));
    }

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
