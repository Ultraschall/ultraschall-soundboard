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
        : ultraschallIcon(BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize),
          contentView(nullptr) {
    toolbar.setStyle(Toolbar::ToolbarItemStyle::iconsOnly);
    addAndMakeVisible(toolbar);
}

MainView::~MainView() {

}

void MainView::paint(Graphics &g) {
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    if (contentView == nullptr) {
        g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background

        ultraschallIcon.getDrawable()->drawWithin(g, getLocalBounds().reduced(100).toFloat(),
                                                  RectanglePlacement::centred, 1.0f);
    }
}

void MainView::resized() {
    auto flexBox = FlexBox();

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(toolbar).withMaxHeight(32).withWidth(getWidth()).withFlex(1));

    if (contentView != nullptr) {
        flexBox.items.add(FlexItem(*contentView).withWidth(getWidth()).withFlex(2));
    }

    flexBox.performLayout(getLocalBounds());
}

void MainView::setContentView(Component *view) {
    if (view == contentView) return;

    contentView = view;
    addAndMakeVisible(contentView);
    resized();
    repaint();
}

bool MainView::GainToolbarView::getToolbarItemSizes(int toolbarThickness, bool isToolbarVertical, int &preferredSize,
                                                    int &minSize, int &maxSize) {
    if (isToolbarVertical)
        return false;

    preferredSize = 250;
    minSize = 80;
    maxSize = 300;
    return true;
}

void
MainView::GainToolbarView::paintButtonArea(Graphics &g, int width, int height, bool isMouseOver, bool isMouseDown) {
}

void MainView::GainToolbarView::contentAreaChanged(const Rectangle<int> &newBounds) {
    slider.setSize(newBounds.getWidth() - 2,
                   jmin(newBounds.getHeight() - 2, 22));

    slider.setCentrePosition(newBounds.getCentreX(), newBounds.getCentreY());
}
