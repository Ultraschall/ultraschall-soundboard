/*
  ==============================================================================

	MainView.h
	Created: 4 May 2018 11:22:54am
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "MaterialLookAndFeel.h"
#include "ToolbarView.h"
#include "BottomBarView.h"
#include "SideNavbarView.h"

//==============================================================================
/*
*/
class BackgroundButton : public Button {
public:
    BackgroundButton() : Button("Background") {}

protected:
    void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override {
        g.fillAll(Colours::black.withAlpha(0.8f));
    }
};

class MainView : public Component {
public:
    MainView();

    void paint(Graphics &) override;

    void resized() override;

    void setContentView(Component *view);

    void showSideNavBar();

    void hideSideNavBar();

    bool isSideBarVisible() {
        return sideBarVisible;
    }

    BottomBarView bottomBar;
    SideNavbarView sideNavbar;
    ComponentAnimator sideNavbarAnimator;
    ComponentAnimator sideNavbarBackgroundAnimator;
    BackgroundButton sideNavbarBackground;

    ToolbarView toolbar;
	DrawableButton addButton{ "Add", DrawableButton::ImageFitted };

private:
    bool sideBarVisible = false;

    Component *contentView = nullptr;
	Material::Icon ultraschallIcon{BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize};
    
	Material::Shadow4dp toolbarShadow;
	Material::Shadow16dp sideBarShadow;

    Component spacer;

	Material::Icon addIcon{BinaryData::add_svg, BinaryData::add_svgSize};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
