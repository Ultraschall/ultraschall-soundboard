#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MaterialLookAndFeel.h"

class LibraryRowView : public Component, public ChangeListener {
public:
    LibraryRowView() {
        addAndMakeVisible(playButton);
        addAndMakeVisible(stopButton);
        addAndMakeVisible(settingsButton);
        addAndMakeVisible(loopButton);
        addAndMakeVisible(fadeButton);
    }

    ~LibraryRowView() override {
        if (!audioThumbnail.expired())
        {
            audioThumbnail.lock()->removeChangeListener(this);
        }
    }

    void paint(Graphics &g) override {
        //const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
        
        g.fillAll(findColour(Material::ColourIds::dialogColorId));
        g.setColour(findColour(Material::ColourIds::dividerColorId));
        g.drawLine(0, getHeight() - 1, getWidth(), getHeight() - 1);
        
        g.setColour(findColour(Material::ColourIds::dialogColorId).contrasting(0.05));
        if (!audioThumbnail.expired())
        {
            auto thumbnail = audioThumbnail.lock();
            if (thumbnail->getTotalLength() > 0.0)
            {
                thumbnail->drawChannel(g, getLocalBounds()
                                       .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base))
                                       .withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base)),
                                       0, thumbnail->getTotalLength(), 1, 1.0f);
            }
        }
        
        //    g.setColour(findColour(Material::ColourIds::primaryColorId));
        //    g.fillRect(getLocalBounds().withTrimmedBottom(iconBarSize));
        
        //    g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
        //    material->setFontRoboto(g);
        //    g.setFont(14);
        //    g.drawText(title,
        //               getLocalBounds()
        //                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base))
        //                       .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base)),
        //               Justification::topLeft
        //    );
        
        //g.setColour(findColour(Material::ColourIds::textSecondaryColorId));
        //g.setFont(8);
        //g.drawText("00:00:00", getLocalBounds()
        //                   .removeFromRight(MaterialLookAndFeel::convertDpToPixel(96))
        //                   .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 26)),
        //           Justification::topLeft);
        
        //auto p = 0.75;
        //g.fillRect(
        //        getLocalBounds()
        //                .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(108))
        //                .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 30))
        //                .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 8))
        //                .withHeight(MaterialLookAndFeel::convertDpToPixel(8))
        //);
        //    g.fillRect(
        //            getLocalBounds()
        //                    .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(108))
        //                    .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 30))
        //                    .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 8))
        //                    .withHeight(MaterialLookAndFeel::convertDpToPixel(8))
        //    );
        //g.setColour(findColour(Material::ColourIds::dividerColorId));
        //g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166)));
        //g.setColour(findColour(Material::ColourIds::primaryColorId));
        //g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166 * progress)));
    }

    void resized() override {
        const auto iconSize = MaterialLookAndFeel::convertDpToPixel(40);
        FlexBox flexBox;
        
        flexBox.items.add(FlexItem(settingsButton).withMaxWidth(iconSize).withFlex(1));
        flexBox.items.add(FlexItem(loopButton).withMaxWidth(iconSize).withFlex(1));
        flexBox.items.add(FlexItem(spacer).withFlex(2));
        flexBox.items.add(FlexItem(fadeButton).withMaxWidth(iconSize).withFlex(1));
        flexBox.items.add(FlexItem(stopButton).withMaxWidth(iconSize).withFlex(1));
        flexBox.items.add(FlexItem(playButton).withMaxWidth(iconSize).withFlex(1));
        
        flexBox.performLayout(
                              getLocalBounds()
                              .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Left))
                              .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Right))
                              );
    }

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
