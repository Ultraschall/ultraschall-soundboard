#pragma once

#include "JuceHeader.h"
#include "MaterialLookAndFeel.h"
#include "SideNavbarItemView.h"

class NavigationDrawer : public Component, public ChangeListener {
public:
    NavigationDrawer() : Component("NavigationDrawer") {
        Desktop::getInstance().getAnimator().addChangeListener(this);
    }

    ~NavigationDrawer() override {
        Desktop::getInstance().getAnimator().removeChangeListener(this);
    }

    void changeListenerCallback(ChangeBroadcaster *source) override {

    }

    void show() {

    }

    void hide() {

    }

    void toggle() {

    }

    void resized() override {
        Component::resized();
    }

private:
    class NavigationDrawerBackground : public Button {
    public:
        NavigationDrawerBackground() : Button("NavigationDrawerBackground") {
        }

        void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override {
            g.fillAll(Colours::black.withAlpha(0.25f));
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NavigationDrawerBackground)
    };

    class NavigationDrawerModal : public Component {

    };

    Viewport viewport;
    bool isDrawerVisible{false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NavigationDrawer)
};

class SideNavbarView : public Component, public ChangeListener {
public:
    SideNavbarView() {
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

        sideBarShadow.setOwner(this);

        background.onClick = [this] {
            hideSideBar();
        };

        Desktop::getInstance().getAnimator().addChangeListener(this);
    }

    ~SideNavbarView() override {
        Desktop::getInstance().getAnimator().removeChangeListener(this);
    };

    void paint(Graphics &g) override {
        g.fillAll(findColour(Material::ColourIds::dialogColorId));
    }

    void resized() override {

        viewPort.setBounds(getLocalBounds());
        FlexBox flexBox;

        flexBox.flexDirection = FlexBox::Direction::column;

        flexBox.items.add(FlexItem(libraryTitle)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(importFolderButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(openFolderButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(saveFolderButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );

        flexBox.items.add(FlexItem(seperator[0])
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(bankTitle)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );

        flexBox.items.add(FlexItem(spacer).withFlex(2));

        flexBox.items.add(FlexItem(midiButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(oscButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(seperator[1])
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(8))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(8))
                                  .withFlex(1)
        );
        flexBox.items.add(FlexItem(settingsButton)
                                  .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withMinHeight(MaterialLookAndFeel::convertDpToPixel(
                                          Material::Specs::NavigationDrawer::Modal::Dimensions::ItemHeight))
                                  .withFlex(1)
        );

        flexBox.performLayout(getLocalBounds());

        int height = 0;
        for (auto &i : flexBox.items) {
            height += i.associatedComponent->getHeight();
        }

        viewPort.getViewedComponent()->setBounds(
                getLocalBounds().withHeight(jmax(height, getLocalBounds().getHeight())));
    }

    void showSideBar() {
        if (sideBarVisible) return;

        auto endBounds = getParentComponent()->getLocalBounds().removeFromLeft(
                MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width));
        auto startBounds = endBounds;
        startBounds.setPosition(
                -MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width),
                0);
        setBounds(startBounds);
        background.setBounds(getParentComponent()->getLocalBounds());

        getParentComponent()->addAndMakeVisible(background);
        getParentComponent()->addAndMakeVisible(this);

        background.toFront(false);
        toFront(true);

        Desktop::getInstance().getAnimator().fadeIn(&background, 200);
        Desktop::getInstance().getAnimator().animateComponent(
                this,
                endBounds,
                1.0f,
                200,
                false,
                0.4f,
                0.8f
        );

        sideBarVisible = true;
    }

    void hideSideBar() {
        if (!sideBarVisible) return;

        auto endBounds = getLocalBounds();
        endBounds.setPosition(
                -MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width),
                0);

        Desktop::getInstance().getAnimator().fadeOut(&background, 200);
        Desktop::getInstance().getAnimator().animateComponent(
                this,
                endBounds,
                1.0f,
                200,
                false,
                0.8f,
                0.4f
        );

        sideBarVisible = false;
    }

    void changeListenerCallback(ChangeBroadcaster *source) override {
        if (!sideBarVisible && !Desktop::getInstance().getAnimator().isAnimating(this)) {
            this->setVisible(false);
            background.setVisible(false);
        }
    }

    bool isSideBarVisible() {
        return sideBarVisible;
    }

    SideNavbarTitle libraryTitle{"Library"};
    SideNavbarItem importFolderButton{"Import Folder",
                                      BinaryData::baselinefolder_open24px_svg,
                                      BinaryData::baselinefolder_open24px_svgSize,
                                      findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem saveFolderButton{"Save",
                                    BinaryData::baselinearchive24px_svg,
                                    BinaryData::baselinearchive24px_svgSize,
                                    findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem openFolderButton{"Open",
                                    BinaryData::baselineunarchive24px_svg,
                                    BinaryData::baselineunarchive24px_svgSize,
                                    findColour(Material::ColourIds::textPrimaryColorId)};

    SideNavbarTitle bankTitle{"Bank"};

    SideNavbarItem midiButton{"MIDI Learn",
                              BinaryData::baselinesettings_input_svideo24px_svg,
                              BinaryData::baselinesettings_input_svideo24px_svgSize,
                              findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem oscButton{"OSC",
                             BinaryData::baselinesettings_input_antenna24px_svg,
                             BinaryData::baselinesettings_input_antenna24px_svgSize,
                             findColour(Material::ColourIds::textPrimaryColorId)};
    SideNavbarItem settingsButton{"Settings",
                                  BinaryData::baselinesettings20px_svg,
                                  BinaryData::baselinesettings20px_svgSize,
                                  findColour(Material::ColourIds::textPrimaryColorId)};


private:
    Viewport viewPort;
    Component spacer;
    SideNavbarSeperator seperator[2];

    Material::Shadows::_16dp sideBarShadow;

    bool sideBarVisible = false;
    class BackgroundButton : public Button {
    public:
        BackgroundButton() : Button("BackgroundButton") {
        }

        void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override {
            g.fillAll(Colours::black.withAlpha(0.25f));
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BackgroundButton)
    };
    BackgroundButton background;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SideNavbarView)
};
