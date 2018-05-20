#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryRowView : public Component, public ChangeListener {
public:
    LibraryRowView();

    ~LibraryRowView() override;

    void paint(Graphics &) override;

    void resized() override;

    void reset()
    {
        playButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
        loopButton.setToggleState(false, dontSendNotification);
    }

    void setIsPlaying()
    {
        playButton.setToggleState(true, dontSendNotification);
        fadeButton.setToggleState(true, dontSendNotification);
    }

    void setIsPaused()
    {
        playButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
    }

    void setIsStopped()
    {
        playButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
    }

    void setIsPlayed()
    {
        playButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
    }

    void setIsReady()
    {
        playButton.setToggleState(false, dontSendNotification);
        fadeButton.setToggleState(false, dontSendNotification);
    }

    void setHasError()
    {
        errorState = true;
    }

    String title{"file name / title"};

    Material::IconToggleButton playButton{"Play",
                                          BinaryData::baselineplay_arrow24px_svg,
                                          BinaryData::baselineplay_arrow24px_svgSize,
                                          BinaryData::baselinepause24px_svg,
                                          BinaryData::baselinepause24px_svgSize,
                                          findColour(Material::ColourIds::textSecondaryColorId),
                                          findColour(Material::ColourIds::primaryColorId)};
    Material::IconButton stopButton{"Stop",
                                    BinaryData::baselinestop24px_svg,
                                    BinaryData::baselinestop24px_svgSize,
                                    findColour(Material::ColourIds::textSecondaryColorId)};
    Material::IconButton settingsButton{"Settings", BinaryData::baselinesettings20px_svg,
                                        BinaryData::baselinesettings20px_svgSize,
                                        findColour(Material::ColourIds::textSecondaryColorId)};
    Material::IconToggleButton fadeButton{"Fade In/Out",
                                          BinaryData::baselinetrending_up24px_svg,
                                          BinaryData::baselinetrending_up24px_svgSize,
                                          BinaryData::baselinetrending_down24px_svg,
                                          BinaryData::baselinetrending_down24px_svgSize,
                                          findColour(Material::ColourIds::textSecondaryColorId),
                                          findColour(Material::ColourIds::primaryColorId)};
    Material::IconToggleButton loopButton{"Loop",
                                          BinaryData::baselinesync24px_svg,
                                          BinaryData::baselinesync24px_svgSize,
                                          BinaryData::baselinesync_disabled24px_svg,
                                          BinaryData::baselinesync_disabled24px_svgSize,
                                          findColour(Material::ColourIds::textSecondaryColorId),
                                          findColour(Material::ColourIds::textSecondaryColorId)};

    void SetAudioThumbnail(std::shared_ptr<AudioThumbnail> &thumbnail) {
        if (!audioThumbnail.expired()) {
            audioThumbnail.lock()->removeChangeListener(this);
        }

        audioThumbnail = thumbnail;

        if (!audioThumbnail.expired()) {
            audioThumbnail.lock()->addChangeListener(this);
        }
    }

    void changeListenerCallback(ChangeBroadcaster * /*source*/) override {
        repaint();
    }

private:
    std::weak_ptr<AudioThumbnail> audioThumbnail;

    Component spacer;
    bool errorState{false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryRowView)
};
