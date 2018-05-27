#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"
#include "ToolbarView.h"
#include "BottomBarView.h"
#include "SideNavbarView.h"
#include "FloatingActionButton.h"

class MainView : public Component, public ChangeListener
{
public:
    MainView() {
        Desktop::getInstance().getAnimator().addChangeListener(this);
        
        addAndMakeVisible(toolbar);

        addAndMakeVisible(spacer);
        addAndMakeVisible(bottomBar);
        
        addAndMakeVisible(sideNavbar);
        toolbar.menuButton.onClick = [this]
        {
            sideNavbar.showSideBar();
        };
        
        addAndMakeVisible(addButton);
        addButton.toFront(true);
    };

    ~MainView() override {
        Desktop::getInstance().getAnimator().removeChangeListener(this);
    }

    void paint(Graphics &g) override {
        if (getLocalBounds().getWidth() < 250 || getLocalBounds().getHeight() < 250)
        {
            return;
        }
        g.fillAll(Material::Theme::Pallete::Background);
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
        
        if (sideNavbar.isSideBarVisible())
        {
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
        if (sideNavbar.isSideBarVisible())
        {
            sideNavbar.hideSideBar();
        }
        resized();
        repaint();
    };

    void changeListenerCallback(juce::ChangeBroadcaster * /*source*/) override {
        if (!Desktop::getInstance().getAnimator().isAnimating(&addButton)) {
            if (!actionButtonVisible) {
                removeChildComponent(&addButton);
            } else {
                repaint();
            }
        }
    }

    BottomBarView bottomBar;
    SideNavbarView sideNavbar;

    ToolbarView toolbar;
    FloatingActionButton addButton;

    void showActionButton() {
        if (actionButtonVisible) return;

        Desktop::getInstance().getAnimator().fadeIn(&addButton, 200);
        addAndMakeVisible(addButton);
        addButton.toFront(false);

        actionButtonVisible = true;
    }

    void hideActionButton() {
        if (!actionButtonVisible) return;

        Desktop::getInstance().getAnimator().fadeOut(&addButton, 200);
        actionButtonVisible = false;
    }

private:
    bool actionButtonVisible = true;

    Component *contentView = nullptr;
    Material::Icon ultraschallIcon{BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize};

    Component spacer;

    Material::Icon addIcon{BinaryData::add_svg, BinaryData::add_svgSize};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
