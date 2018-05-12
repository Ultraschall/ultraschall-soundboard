#include "SideNavbarView.h"

SideNavbarView::SideNavbarView()
{
    backButton.setImages(backIcon.getDrawable());

    addAndMakeVisible(backButton);
    addAndMakeVisible(settingsButton);
    addAndMakeVisible(importFolderButton);
}

SideNavbarView::~SideNavbarView()
{
}

void SideNavbarView::paint(Graphics &g)
{
    g.fillAll(findColour(Material::ColourIds::dialogColorId));   // clear the background
    g.setColour(findColour(Material::ColourIds::dividerColorId));
    g.drawLine(0.0f, MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar), getWidth(),
               MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::Toolbar));
}

void SideNavbarView::resized()
{
    backButton.setBounds(getLocalBounds().removeFromTop(
            MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)).removeFromRight(
            MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Icon)));

    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

    flexBox.items.add(FlexItem(importFolderButton).withMaxHeight(
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));
    flexBox.items.add(FlexItem(settingsButton).withMaxHeight(
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::MenuItem)).withFlex(1));

    flexBox.performLayout(
            getLocalBounds().withTrimmedTop(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::Toolbar)));
}

