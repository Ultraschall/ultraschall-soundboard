#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"
#include "ToolbarView.h"
#include "BottomBarView.h"
#include "SideNavbarView.h"

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
    MainView();

    ~MainView();

    void paint(Graphics &) override;

    void resized() override;

    void setContentView(Component *view);

    void showSideNavBar();

    void hideSideNavBar();

    bool isSideBarVisible()
    {
        return sideBarVisible;
    }

    void changeListenerCallback(juce::ChangeBroadcaster * /*source*/) override;

    BottomBarView bottomBar;
    SideNavbarView sideNavbar;
    BackgroundButton sideNavbarBackground;

    ToolbarView toolbar;
    DrawableButton addButton{"Add", DrawableButton::ImageFitted};

    void showActionButton();

    void hideActionButton();

private:
    bool sideBarVisible = false;
    bool actionButtonVisible = true;

    Component *contentView = nullptr;
    Material::Icon ultraschallIcon{BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize};

    Material::Shadow4dp toolbarShadow;
    Material::Shadow16dp sideBarShadow;

    Component spacer;

    Material::Icon addIcon{BinaryData::add_svg, BinaryData::add_svgSize};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
