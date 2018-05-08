/*
  ==============================================================================

    LibraryRowView.h
    Created: 8 May 2018 3:52:09pm
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MaterialLookAndFeel.h"

//==============================================================================
/*
*/
class LibraryRowView    : public Component
{
public:
    LibraryRowView();
    ~LibraryRowView();

    void paint (Graphics&) override;
    void resized() override;

	String title{ "file name / title" };
	bool isFading;
	bool isPaused;
	bool isPlayed;
	bool isPlaying;
	double progress{0.75};

	DrawableButton playButton{ "Play", DrawableButton::ImageFitted };
	DrawableButton stopButton{ "Stop", DrawableButton::ImageFitted };

	ToggleButton selectionButton{ "Toggle" };
private:
	Material::Icon playIcon{ BinaryData::ic_play_arrow_black_48px_svg, BinaryData::ic_play_arrow_black_48px_svgSize };
	Material::Icon pauseIcon{ BinaryData::ic_pause_black_48px_svg, BinaryData::ic_pause_black_48px_svgSize };
	Material::Icon stopIcon{ BinaryData::ic_stop_black_48px_svg, BinaryData::ic_stop_black_48px_svgSize };

	Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryRowView)
};
