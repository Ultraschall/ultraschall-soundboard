#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class SideNavbarView : public Component
{
public:
	SideNavbarView();

	~SideNavbarView();

	void paint(Graphics &) override;

	void resized() override;

	SideNavbarTitleItemView libraryTitle{ "Library", "Library" };
	SideNavbarItemView importFolderButton{ "Import Folder", importFolderIcon };
	SideNavbarItemView saveFolderButton{ "Save", saveIcon };
	SideNavbarItemView openFolderButton{ "Open", openIcon };

	SideNavbarTitleItemView bankTitle{ "Bank", "Bank" };

	SideNavbarItemView midiButton{ "MIDI Learn", midiIcon };
	SideNavbarItemView oscButton{ "OSC", oscIcon };
	SideNavbarItemView settingsButton{ "Settings", settingsIcon };

private:
	Viewport viewPort;

	Material::Icon settingsIcon = { BinaryData::baselinesettings20px_svg,
								   BinaryData::baselinesettings20px_svgSize,
								   findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon backIcon = { BinaryData::baselinenavigate_before24px_svg,
							   BinaryData::baselinenavigate_before24px_svgSize,
							   findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon importFolderIcon{ BinaryData::baselinefolder_open24px_svg,
									BinaryData::baselinefolder_open24px_svgSize,
									findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon saveIcon{ BinaryData::baselinearchive24px_svg,
							BinaryData::baselinearchive24px_svgSize,
							findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon openIcon{ BinaryData::baselineunarchive24px_svg,
							BinaryData::baselineunarchive24px_svgSize,
							findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon oscIcon{ BinaryData::baselinesettings_input_antenna24px_svg,
							BinaryData::baselinesettings_input_antenna24px_svgSize,
							findColour(Material::ColourIds::textSecondaryColorId) };

	Material::Icon midiIcon{ BinaryData::baselinesettings_input_svideo24px_svg,
							 BinaryData::baselinesettings_input_svideo24px_svgSize,
							 findColour(Material::ColourIds::textSecondaryColorId) };


	Component spacer;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarView)
};
