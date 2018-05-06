/*
  ==============================================================================

	MainView.h
	Created: 4 May 2018 11:22:54am
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "DrawingTools.h"
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

private:
    bool sideBarVisible = false;

    Component *contentView = nullptr;
    SvgIcon ultraschallIcon{BinaryData::ultraschall_svg, BinaryData::ultraschall_svgSize};
    DropShadower dropShadower{DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.19f), 6, Point<int>(0, 6))};

    DropShadower sideBarShadower{DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.29f), 6, Point<int>(0, 6))};

    Component spacer;

    SvgIcon addIcon{BinaryData::add_svg, BinaryData::add_svgSize};
    DrawableButton addButton{"Add", DrawableButton::ImageFitted};

	float toolbarWidth{ Material::convertDpToPixel<float>(300) };

	float actionButtonSize{ Material::convertDpToPixel<float>(80) };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainView)
};
