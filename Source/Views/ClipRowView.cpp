#include "../../JuceLibraryCode/JuceHeader.h"
#include "ClipRowView.h"

ClipRowView::ClipRowView()
{
}

ClipRowView::~ClipRowView()
{
}

void ClipRowView::paint(Graphics &g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background
}

void ClipRowView::resized()
{
}
