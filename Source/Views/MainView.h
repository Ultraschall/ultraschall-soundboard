#pragma once

#include "JuceHeader.h"

#include "AppBar.h"
#include "BottomBar.h"
#include "../Material/FloatingActionButton.h"
#include "NavigationDrawer.h"
#include "StartupView.h"

class MainView : public Component
{
public:
    MainView()
    {
        addAndMakeVisible(appBar);
        addAndMakeVisible(bottomBar);
        addAndMakeVisible(floatingActionButton);
        addAndMakeVisible(startup);
        
        addFileButton.setColour(Material::FloatingActionButton::ColourIds::containerColourId, Material::Color::Icons::White::Active);
        addDirectoryButton.setColour(Material::FloatingActionButton::ColourIds::containerColourId, Material::Color::Icons::White::Active);
        loadProjectFileButton.setColour(Material::FloatingActionButton::ColourIds::containerColourId, Material::Color::Icons::White::Active);
        addFileButton.setColour(Material::FloatingActionButton::ColourIds::iconColourId, Material::Color::Icons::Black::Inactive);
        addDirectoryButton.setColour(Material::FloatingActionButton::ColourIds::iconColourId, Material::Color::Icons::Black::Inactive);
        loadProjectFileButton.setColour(Material::FloatingActionButton::ColourIds::iconColourId, Material::Color::Icons::Black::Inactive);
        
        addAndMakeVisible(addFileButton);
        addAndMakeVisible(addDirectoryButton);
        addAndMakeVisible(loadProjectFileButton);
        
        addFileButton.setAlpha(0.0f);
        addDirectoryButton.setAlpha(0.0f);
        loadProjectFileButton.setAlpha(0.0f);
        addFileButton.setVisible(false);
        addDirectoryButton.setVisible(false);
        loadProjectFileButton.setVisible(false);
        
        floatingActionButton.onClick = [this] {
            if (!floatingActionButton.getToggleState()) {
                showExtendedFloatingActionButtons();
            } else {
                hideExtendedFloatingActionButtons();
            }
        };
        
        navigationDrawer.setOwner(this);

        appBar.menuButton.onClick = [this] {
            navigationDrawer.open();
        };

        setSize(1024, 640);
        
        setContentView(&startup);
    }

    ~MainView()
    {
    }

    void paint (Graphics& g) override
    {
        g.fillAll(Material::Color::Surface::Light);
    }

    void resized() override
    {
        FlexBox flexBox;
        flexBox.flexDirection = FlexBox::Direction::column;
        flexBox.alignContent = FlexBox::AlignContent::center;
        
        flexBox.items.add(FlexItem(getWidth(), px(AppBar::height), appBar));
        if (contentView != nullptr) {
            flexBox.items.add(FlexItem(*contentView).withFlex(2));
        }
        flexBox.items.add(FlexItem(getWidth(), px(BottomBar::height), bottomBar));
                
        flexBox.performLayout(getLocalBounds());

        auto fabBottom = static_cast<int>(BottomBar::height + (Material::FloatingActionButton::size * 0.5));
        floatingActionButton.setBounds(getLocalBounds()
                                       .removeFromBottom(px(fabBottom))
                                       .removeFromRight(px(Material::FloatingActionButton::size + 16))
                                       .withWidth(px(Material::FloatingActionButton::size))
                                       .withHeight(px(Material::FloatingActionButton::size))
                                       );
        fabBottom += static_cast<int>(16 + Material::FloatingActionButton::miniSize);
        auto fabRight = static_cast<int>((Material::FloatingActionButton::size + 16) - ((Material::FloatingActionButton::size - Material::FloatingActionButton::miniSize) * 0.5));
        addFileButton.setBounds(getLocalBounds()
                                .removeFromBottom(px(fabBottom))
                                .removeFromRight(px(fabRight))
                                .withWidth(px(Material::FloatingActionButton::miniSize))
                                .withHeight(px(Material::FloatingActionButton::miniSize))
                                );
        fabBottom += static_cast<int>(16 + Material::FloatingActionButton::miniSize);
        addDirectoryButton.setBounds(getLocalBounds()
                                .removeFromBottom(px(fabBottom))
                                  .removeFromRight(px(fabRight))
                                .withWidth(px(Material::FloatingActionButton::miniSize))
                                .withHeight(px(Material::FloatingActionButton::miniSize))
                                );
        fabBottom += static_cast<int>(16 + Material::FloatingActionButton::miniSize);
        loadProjectFileButton.setBounds(getLocalBounds()
                                  .removeFromBottom(px(fabBottom))
                                 .removeFromRight(px(fabRight))
                                  .withWidth(px(Material::FloatingActionButton::miniSize))
                                  .withHeight(px(Material::FloatingActionButton::miniSize))
                                  );
    }
    
    void showExtendedFloatingActionButtons() {
        floatingActionButton.setToggleState(true, dontSendNotification);

        floatingActionButton.setRotation(0.785398f);
        
        addFileButton.setAlpha(1.0f);
        addDirectoryButton.setAlpha(1.0f);
        loadProjectFileButton.setAlpha(1.0f);
        addFileButton.setVisible(true);
        addDirectoryButton.setVisible(true);
        loadProjectFileButton.setVisible(true);
    }
    
    void hideExtendedFloatingActionButtons() {
        floatingActionButton.setToggleState(false, dontSendNotification);
        
        floatingActionButton.setRotation(0);
        
        addFileButton.setAlpha(0.0f);
        addDirectoryButton.setAlpha(0.0f);
        loadProjectFileButton.setAlpha(0.0f);
        addFileButton.setVisible(false);
        addDirectoryButton.setVisible(false);
        loadProjectFileButton.setVisible(false);
    }
    
    void setContentView(Component* view) {
        if (view == contentView) return;
        
        if (contentView != nullptr) {
            removeChildComponent(contentView);
        }
        contentView = view;
        addAndMakeVisible(contentView);
        contentView->toBack();
        if (navigationDrawer.isVisible())
        {
            navigationDrawer.close();
        }
        resized();
        repaint();
    }
    
    AppBar appBar;
    BottomBar bottomBar;
    Material::FloatingActionButton floatingActionButton { Material::Icons::add };

    Material::FloatingActionButton addFileButton { Material::Icons::file_copy };
    Material::FloatingActionButton addDirectoryButton { Material::Icons::create_new_folder };
    Material::FloatingActionButton loadProjectFileButton { Material::Icons::unarchive };

    NavigationDrawer navigationDrawer;
private:
    StartupView startup;
    Component *contentView{nullptr};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainView)
};
