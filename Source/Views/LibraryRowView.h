#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryRowView : public Component, public ChangeListener
{
public:
    LibraryRowView();

    ~LibraryRowView();

    void paint(Graphics &) override;

    void resized() override;

    String title{"file name / title"};
    bool isFading;
    bool isPaused;
    bool isPlayed;
    bool isPlaying;
    double progress{0.75};

    DrawableButton playButton{"Play", DrawableButton::ImageFitted};
    DrawableButton stopButton{"Stop", DrawableButton::ImageFitted};
    DrawableButton settingsButton{"Settings", DrawableButton::ImageFitted};
    DrawableButton fadeButton{"Fade In/Out", DrawableButton::ImageFitted};
    DrawableButton loopButton{"Loop", DrawableButton::ImageFitted};

    void SetAudioThumbnail(AudioThumbnail *thumbnail)
    {
        if (audioThumbnail != nullptr)
        {
            audioThumbnail->removeChangeListener(this);
        }

        audioThumbnail = thumbnail;

        if (audioThumbnail != nullptr)
        {
            audioThumbnail->addChangeListener(this);
        }
    }

    void changeListenerCallback(ChangeBroadcaster* /*source*/) override
    {
        repaint();
    }

private:
    Material::Icon playIcon{BinaryData::baselineplay_arrow24px_svg,
                            BinaryData::baselineplay_arrow24px_svgSize};
    Material::Icon pauseIcon{BinaryData::baselinepause24px_svg,
                             BinaryData::baselinepause24px_svgSize};
    Material::Icon stopIcon{BinaryData::baselinestop24px_svg,
                            BinaryData::baselinestop24px_svgSize};
    Material::Icon settingsIcon{BinaryData::baselinesettings20px_svg,
                                BinaryData::baselinesettings20px_svgSize};
    Material::Icon loopOnIcon{BinaryData::baselinesync24px_svg,
                              BinaryData::baselinesync24px_svgSize};
    Material::Icon loopOffIcon{BinaryData::baselinesync_disabled24px_svg,
                               BinaryData::baselinesync_disabled24px_svgSize};
    Material::Icon fadeInIcon{BinaryData::baselinetrending_up24px_svg,
                              BinaryData::baselinetrending_up24px_svgSize};
    Material::Icon fadeOutIcon{BinaryData::baselinetrending_down24px_svg,
                               BinaryData::baselinetrending_down24px_svgSize};

    AudioThumbnail *audioThumbnail{nullptr};

    Component spacer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryRowView)
};
