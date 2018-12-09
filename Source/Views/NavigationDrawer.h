#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Material/Material.h"

#include "NavigationDrawerHeaderItem.h"
#include "NavigationDrawerItem.h"
#include "NavigationDrawerDevider.h"

class NavigationDrawer : public Component, public ChangeListener, private ComponentListener {
public:
    constexpr const static int width = 304;
    constexpr const static int edgeDragWidth = 20;
    constexpr const static int minFlingVelocity = 365;
    constexpr const static int baseSettleDuration = 246;

    NavigationDrawer() noexcept : Component("NavigationDrawer") {
        setOpaque(true);
        setAlwaysOnTop(true);
        //shadow.setOwner(this);
        Desktop::getInstance().getAnimator().addChangeListener(this);
        addAndMakeVisible(header);
        addAndMakeVisible(viewList);
        addAndMakeVisible(viewGrid);
        addAndMakeVisible(viewPlaylist);
        addAndMakeVisible(lockEngine);
        addAndMakeVisible(midiSettings);
        addAndMakeVisible(oscSettings);
        addAndMakeVisible(settings);
        for (auto &d : devider) {
            addAndMakeVisible(d);
        }
        setSize(width, 640);
        addMouseListener(this, true);
    }

    ~NavigationDrawer() noexcept override {
        Desktop::getInstance().getAnimator().removeChangeListener(this);
    }

    void paint(Graphics &g) override {
        g.fillAll(Material::Color::Surface::Main);
    }

    void resized() override {
        FlexBox flexBox;
        flexBox.flexDirection = FlexBox::Direction::column;

        flexBox.items.add(FlexItem(header).withHeight(px(NavigationDrawerHeaderItem::height)));
        flexBox.items.add(FlexItem(viewList).withHeight(px(NavigationDrawerItem::height)).withMargin(FlexItem::Margin(px(16), 0, 0, 0)));
        flexBox.items.add(FlexItem(viewGrid).withHeight(px(NavigationDrawerItem::height)));
        flexBox.items.add(FlexItem(viewPlaylist).withHeight(px(NavigationDrawerItem::height)));
        flexBox.items.add(FlexItem(devider[0]).withHeight(px(NavigationDrawerDevider::height)));
        flexBox.items.add(FlexItem(lockEngine).withHeight(px(NavigationDrawerItem::height)));

        flexBox.items.add(FlexItem(spacer).withFlex(2));

        flexBox.items.add(FlexItem(devider[1]).withHeight(px(NavigationDrawerDevider::height)));
        flexBox.items.add(FlexItem(midiSettings).withHeight(px(NavigationDrawerItem::height)));
        flexBox.items.add(FlexItem(oscSettings).withHeight(px(NavigationDrawerItem::height)));
        flexBox.items.add(FlexItem(settings).withHeight(px(NavigationDrawerItem::height)));

        flexBox.performLayout(getLocalBounds());
    }

    void changeListenerCallback(ChangeBroadcaster *source) override {
        if (!visible && !Desktop::getInstance().getAnimator().isAnimating(this)) {
            owner->removeChildComponent(this);
        }
        if (!visible && !Desktop::getInstance().getAnimator().isAnimating(&scrim)) {
            owner->removeChildComponent(&scrim);
        }
    }

    void open() {
        if (owner == nullptr) return;
        if (visible) return;

        auto endBounds = owner->getLocalBounds().removeFromLeft(px(width));
        auto startBounds = endBounds;
        startBounds.setPosition(-px(width), 0);
        setBounds(startBounds);
        scrim.setBounds(owner->getLocalBounds());

        owner->addAndMakeVisible(scrim);
        owner->addAndMakeVisible(this);

        scrim.toFront(false);

        scrim.onClick = [this] {
            close();
        };

        //Desktop::getInstance().getAnimator().fadeIn(&scrim, 200);
        Desktop::getInstance().getAnimator().animateComponent(
                this,
                endBounds,
                1.0f,
                246,
                true,
                0.4f,
                0.8f
        );

        visible = true;
    }

    void close() {
        if (owner == nullptr) return;
        if (!visible) return;

        auto endBounds = getLocalBounds();
        endBounds.setPosition(-px(width), 0);

        //Desktop::getInstance().getAnimator().fadeOut(&scrim, 200);
		owner->removeChildComponent(&scrim);

        Desktop::getInstance().getAnimator().animateComponent(
                this,
                endBounds,
                1.0f,
                246,
                true,
                0.8f,
                0.4f
        );

        visible = false;
    }

    bool isVisible() {
        return visible;
    }

    void setOwner(Component *componentToFollow) {
        if (componentToFollow != owner) {
            if (owner != nullptr)
                owner->removeComponentListener(this);

            // (the component can't be null)
            jassert (componentToFollow != nullptr);

            owner = componentToFollow;
            jassert (owner != nullptr);

            updateParent();
            owner->addComponentListener(this);
        }
    }

    void updateParent() {
        if (Component *p = lastParentComp)
            p->removeComponentListener(this);

        lastParentComp = owner != nullptr ? owner->getParentComponent() : nullptr;

        if (Component *p = lastParentComp)
            p->addComponentListener(this);
    }

    void mouseDrag(const MouseEvent &event) override {
        if (event.getDistanceFromDragStartX() < 0 && event.getDistanceFromDragStartX() > -(width)) {
            this->setBounds(getLocalBounds().withRightX(width + event.getDistanceFromDragStartX()));
        }
    }

    void mouseUp(const MouseEvent &event) override {
        if (this->getX() <= -edgeDragWidth) {
            close();
        } else {
            auto endBounds = owner->getLocalBounds().removeFromLeft(px(width));
            //auto startBounds = getLocalBounds();
            Desktop::getInstance().getAnimator().animateComponent(
                    this,
                    endBounds,
                    1.0f,
                    200,
                    false,
                    0.4f,
                    0.8f
            );
        }
    }

    NavigationDrawerHeaderItem header;
    NavigationDrawerItem viewList{Material::Icons::format_list_numbered, "Files"};
    NavigationDrawerItem viewGrid{Material::Icons::view_comfy, "Banks"};
    NavigationDrawerItem viewPlaylist{Material::Icons::subscriptions, "Playlists"};
    NavigationDrawerItem lockEngine{Material::Icons::lock_open, "Lock"};

    NavigationDrawerItem midiSettings{Material::Icons::settings_input_svideo, "MIDI"};
    NavigationDrawerItem oscSettings{Material::Icons::settings_input_antenna, "OSC"};
    NavigationDrawerItem settings{Material::Icons::settings, "Settings"};
private:
    class Scrim : public Button {
    public:
        Scrim() : Button("Scrim") {
        }

        ~Scrim() override = default;

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Scrim)

    protected:
        void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override {
            g.fillAll(Colours::black.withAlpha(0.32f));
        }
    };

    //Material::Shadows::DropShadower16dp shadow;
    WeakReference<Component> owner{nullptr};
    Scrim scrim;
    Component spacer;
    NavigationDrawerDevider devider[2];

    bool visible{false};

    WeakReference<Component> lastParentComp;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavigationDrawer)

    void componentMovedOrResized(Component &component, bool wasMoved, bool wasResized) override {
        if (getParentComponent() != nullptr) {
            scrim.setBounds(getParentComponent()->getLocalBounds());
            this->setBounds(getParentComponent()->getLocalBounds().removeFromLeft(px(width)));
        }
    }
};
