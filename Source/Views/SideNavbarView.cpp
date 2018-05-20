#include "SideNavbarView.h"

SideNavbarView::SideNavbarView()
{
	viewPort.setViewedComponent(new Component());
	viewPort.getViewedComponent()->addAndMakeVisible(libraryTitle);
	viewPort.getViewedComponent()->addAndMakeVisible(importFolderButton);
	viewPort.getViewedComponent()->addAndMakeVisible(openFolderButton);
	viewPort.getViewedComponent()->addAndMakeVisible(saveFolderButton);

	viewPort.getViewedComponent()->addAndMakeVisible(seperator[0]);
	viewPort.getViewedComponent()->addAndMakeVisible(bankTitle);

	viewPort.getViewedComponent()->addAndMakeVisible(spacer);
	viewPort.getViewedComponent()->addAndMakeVisible(midiButton);
	viewPort.getViewedComponent()->addAndMakeVisible(oscButton);
	viewPort.getViewedComponent()->addAndMakeVisible(seperator[1]);
	viewPort.getViewedComponent()->addAndMakeVisible(settingsButton);

	viewPort.setScrollBarsShown(false, false, true, false);
	addAndMakeVisible(viewPort);
}

void SideNavbarView::paint(Graphics &g)
{
    g.fillAll(findColour(Material::ColourIds::dialogColorId));
}

void SideNavbarView::resized()
{
	viewPort.setBounds(getLocalBounds());
    FlexBox flexBox;

    flexBox.flexDirection = FlexBox::Direction::column;

	flexBox.items.add(FlexItem(libraryTitle)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);
    flexBox.items.add(FlexItem(importFolderButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);
	flexBox.items.add(FlexItem(openFolderButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);
	flexBox.items.add(FlexItem(saveFolderButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);

	flexBox.items.add(FlexItem(seperator[0])
							  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
							  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
							  .withFlex(1)
	);
	flexBox.items.add(FlexItem(bankTitle)
	    .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
	    .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);

	flexBox.items.add(FlexItem(spacer).withFlex(2));

	flexBox.items.add(FlexItem(midiButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);
	flexBox.items.add(FlexItem(oscButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);
	flexBox.items.add(FlexItem(seperator[1])
							  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
							  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
							  .withFlex(1)
	);
    flexBox.items.add(FlexItem(settingsButton)
		.withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
		.withFlex(1)
	);

    flexBox.performLayout(getLocalBounds());

	int height = 0;
	for (auto &i : flexBox.items) {
		height += i.associatedComponent->getHeight();
	}

	viewPort.getViewedComponent()->setBounds(getLocalBounds().withHeight(jmax(height, getLocalBounds().getHeight())));
}

