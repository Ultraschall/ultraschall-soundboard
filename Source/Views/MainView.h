#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"
#include "ToolbarView.h"
#include "BottomBarView.h"
#include "SideNavbarView.h"
#include "FloatingActionButton.h"

class BackgroundButton : public Button
{
public:
    BackgroundButton() : Button("Background")
    {
    }

protected:
    void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override
    {
        g.fillAll(Colours::black.withAlpha(0.25f));
    }
};

class MainView : public Component, public ChangeListener
{
public:
    MainView() {
        Desktop::getInstance().getAnimator().addChangeListener(this);
        
        addAndMakeVisible(toolbar);
        toolbarShadow.setOwner(&toolbar);
        
        addAndMakeVisible(spacer);
        addAndMakeVisible(bottomBar);
        
        addAndMakeVisible(sideNavbar);
        sideBarShadow.setOwner(&sideNavbar);
        
        addAndMakeVisible(addButton);
        addButton.toFront(true);
    };

    ~MainView() {
        Desktop::getInstance().getAnimator().removeChangeListener(this);
    }

    void paint(Graphics &g) override {
        if (getLocalBounds().getWidth() < 250 || getLocalBounds().getHeight() < 250)
        {
            return;
        }
        g.fillAll(Material::Theme::Colour::Pallete::Background);
        ultraschallIcon.getDrawable()->drawWithin(g, getLocalBounds().reduced(100).toFloat(), RectanglePlacement::centred,
                                                  0.2f);
    }

    void resized() override {
        auto flexBox = FlexBox();
        
        flexBox.flexDirection = FlexBox::Direction::column;
        
        flexBox.items.add(FlexItem(toolbar)
                          .withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::Height))
                          .withMinHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::Height))
                          .withWidth(getWidth()).withFlex(1));
        
        if (contentView != nullptr)
        {
            flexBox.items.add(FlexItem(*contentView).withWidth(getWidth()).withFlex(2));
        } else
        {
            flexBox.items.add(FlexItem(spacer).withWidth(getWidth()).withFlex(2));
        }
        
        flexBox.items.add(FlexItem(bottomBar).withMaxHeight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::TopAppBar::Regular::Dimensions::Height)).withWidth(getWidth()).withFlex(1));
        
        flexBox.performLayout(getLocalBounds());
        
        if (actionButtonVisible)
        {
            addButton.setBounds(
                                getLocalBounds().getWidth() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                getLocalBounds().getHeight() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                int(MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::FloatingActionButton::Regular::Dimensions::Size)),
                                int(MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::FloatingActionButton::Regular::Dimensions::Size))
                                );
        }
        
        if (sideBarVisible)
        {
            sideNavbarBackground.setBounds(getLocalBounds());
            sideNavbar.setBounds(getLocalBounds().removeFromLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width)));
        }
    };

    void setContentView(Component *view) {
        if (view == contentView) return;
        
        removeChildComponent(&spacer);
        contentView = view;
        addAndMakeVisible(contentView);
        contentView->toBack();
        addButton.toFront(true);
        if (sideBarVisible)
        {
            sideNavbarBackground.toFront(false);
            sideNavbar.toFront(false);
        }
        resized();
        repaint();
    };

    void showSideNavBar() {
        if (sideBarVisible == true) return;
        
        auto endBounds = getLocalBounds().removeFromLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width));
        auto startBounds = endBounds;
        startBounds.setPosition(-MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width), 0);
        sideNavbar.setBounds(startBounds);
        sideNavbarBackground.setBounds(getLocalBounds());
        
        addAndMakeVisible(sideNavbarBackground);
        addAndMakeVisible(sideNavbar);
        
        sideNavbarBackground.toFront(false);
        sideNavbar.toFront(false);
        
        Desktop::getInstance().getAnimator().fadeIn(&sideNavbarBackground, 200);
        Desktop::getInstance().getAnimator().animateComponent(
                                                              &sideNavbar,
                                                              endBounds,
                                                              1.0f,
                                                              200,
                                                              false,
                                                              0.4f,
                                                              0.8f
                                                              );
        
        sideBarVisible = true;
    }

    void hideSideNavBar() {
        if (sideBarVisible == false) return;
        
        auto endBounds = sideNavbar.getLocalBounds();
        endBounds.setPosition(-MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Dimensions::Width), 0);
        
        Desktop::getInstance().getAnimator().fadeOut(&sideNavbarBackground, 200);
        Desktop::getInstance().getAnimator().animateComponent(
                                                              &sideNavbar,
                                                              endBounds,
                                                              1.0f,
                                                              200,
                                                              false,
                                                              0.8f,
                                                              0.4f
                                                              );
        
        sideBarVisible = false;
    }

    bool isSideBarVisible()
    {
        return sideBarVisible;
    }

    void changeListenerCallback(juce::ChangeBroadcaster * /*source*/) override {
        if (sideBarVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&sideNavbar))
        {
            removeChildComponent(&sideNavbar);
            removeChildComponent(&sideNavbarBackground);
        }
        if (actionButtonVisible == false && !Desktop::getInstance().getAnimator().isAnimating(&addButton))
        {
            removeChildComponent(&addButton);
        }
    }

    BottomBarView bottomBar;
    SideNavbarView sideNavbar;
    BackgroundButton sideNavbarBackground;
	
    ToolbarView toolbar;
    FloatingActionButton addButton;

    void showActionButton() {
        if (actionButtonVisible == true) return;
        
        auto endBounds = Rectangle<int>(
                                        getLocalBounds().getWidth() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                        getLocalBounds().getHeight() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                        int(MaterialLookAndFeel::convertDpToPixel<float>(80)),
                                        int(MaterialLookAndFeel::convertDpToPixel<float>(80))
                                        );
        addButton.setBounds(endBounds.reduced(int(MaterialLookAndFeel::convertDpToPixel<float>(40))));
        
        Desktop::getInstance().getAnimator().animateComponent(
                                                              &addButton,
                                                              endBounds,
                                                              1.0f,
                                                              200,
                                                              false,
                                                              0.4f,
                                                              0.8f
                                                              );
        addAndMakeVisible(addButton);
        addButton.toFront(false);
        
        actionButtonVisible = true;
    }

    void hideActionButton() {
        if (actionButtonVisible == false) return;
        
        auto endBounds = Rectangle<int>(
                                        getLocalBounds().getWidth() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                        getLocalBounds().getHeight() - int(MaterialLookAndFeel::convertDpToPixel<float>(80) * 1.2),
                                        int(MaterialLookAndFeel::convertDpToPixel<float>(80)),
                                        int(MaterialLookAndFeel::convertDpToPixel<float>(80)))
        .reduced(int(MaterialLookAndFeel::convertDpToPixel<float>(40)));
        
        Desktop::getInstance().getAnimator().animateComponent(
                                                              &addButton,
                                                              endBounds,
                                                              1.0f,
                                                              200,
                                                              false,
                                                              0.4f,
                                                              0.8f
                                                              );
        actionButtonVisible = false;
    }

private:
    bool sideBarVisible = false;
    bool actionButtonVisible = true;

    Component *contentView = nullptr;
    Material::Icon ultraschallIcon{BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize};

    Material::Shadows::_4dp toolbarShadow;
    Material::Shadows::_16dp sideBarShadow;

    Component spacer;

    Material::Icon addIcon{BinaryData::add_svg, BinaryData::add_svgSize};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
