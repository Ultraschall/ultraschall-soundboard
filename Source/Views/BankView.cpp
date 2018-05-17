#include "BankView.h"

BankView::BankView()
{
    nextButton.setImages(nextIcon.getDrawable());
    beforeButton.setImages(beforeIcon.getDrawable());
    titleLabel.setText("Test", NotificationType::dontSendNotification);

    addAndMakeVisible(nextButton);
    addAndMakeVisible(beforeButton);
    addAndMakeVisible(titleLabel);
}

BankView::~BankView()
{
}

void BankView::paint(Graphics &g)
{
    g.fillAll(getLookAndFeel().findColour(Material::ColourIds::backgroundColorId));
}

void BankView::resized()
{
    //FlexBox flexBox;

    //flexBox.items.add(FlexItem(beforeButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon)).withFlex(1));
    //flexBox.items.add(FlexItem(titleLabel).withFlex(2));
    //flexBox.items.add(FlexItem(nextButton).withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Size::Icon)).withFlex(1));

    //flexBox.performLayout(getLocalBounds().withBottom(Material::Size::NavigationDrawer));
}
