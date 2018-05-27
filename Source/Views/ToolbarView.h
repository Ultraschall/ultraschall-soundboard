#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"

class ToolbarView : public Component
{
public:
    ToolbarView() {
        #if LIVE_MOCK
        setLookAndFeel(new MaterialLookAndFeel());
        #endif
        addAndMakeVisible(menuButton);
	    addAndMakeVisible(viewButton);
	    addAndMakeVisible(spacer);
	    toolbarShadow.setOwner(this);
    };

    ~ToolbarView() override = default;

    void paint(Graphics &g) override {
        g.fillAll(Material::Theme::Pallete::Primary);
    };

    void resized() override {
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
                              .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Padding::Right)));
    };

    Material::IconButton menuButton{
		"Menu",
		BinaryData::baselinemenu24px_svg,
		BinaryData::baselinemenu24px_svgSize,
		Material::Theme::Pallete::OnPrimary
	};

	Material::IconToggleButton viewButton{
		"View",
		BinaryData::baselinegrid_on24px_svg,
		BinaryData::baselinegrid_on24px_svgSize,
		BinaryData::baselinelibrary_music24px_svg,
		BinaryData::baselinelibrary_music24px_svgSize,
        Material::Theme::Pallete::OnPrimary,
		Material::Theme::Pallete::OnPrimary
	};

private:
    Component spacer;
    Material::Shadows::_4dp toolbarShadow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToolbarView)
};
