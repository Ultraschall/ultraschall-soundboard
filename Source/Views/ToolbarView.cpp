#include "ToolbarView.h"

ToolbarView::ToolbarView()
{
	addAndMakeVisible(menuButton);
	addAndMakeVisible(viewButton);
	addAndMakeVisible(spacer);
}

void ToolbarView::paint(Graphics &g)
{
	g.fillAll(findColour(Material::primaryColorId));
}

void ToolbarView::resized()
{
	FlexBox flexBox;

	flexBox.flexDirection = FlexBox::Direction::row;
	flexBox.alignContent = FlexBox::AlignContent::center;

	flexBox.items.add(FlexItem(menuButton)
		.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withFlex(2));
	flexBox.items.add(FlexItem(spacer).withFlex(1));
	flexBox.items.add(FlexItem(viewButton)
		.withHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withMaxWidth(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::IconSize))
		.withFlex(2));

	flexBox.performLayout(
		getLocalBounds()
		.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Padding::Left))
		.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Padding::Right))
	);
}
