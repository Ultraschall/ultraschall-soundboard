/*
  ==============================================================================

    Player.h
    Created: 2 May 2018 2:19:39pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "Identifier.h"
#include "ValueTreeObjectList.h"

struct PlayerModel {
public:
    PlayerModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::PLAYER));

        uuid.referTo(state, IDs::uuid, nullptr);
        path.referTo(state, IDs::path, nullptr);
        title.referTo(state, IDs::title, nullptr);
    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<String> path;
    CachedValue<String> title;

    Player *player;
};

class PlayerList : public drow::ValueTreeObjectList<PlayerModel> {
public:
    explicit PlayerList(const ValueTree &parentTree) : ValueTreeObjectList(parentTree) {
    }

    ~PlayerList() {
        freeObjects();
    }

    bool isSuitableType(const juce::ValueTree &tree) const override {
        return tree.hasType(IDs::PLAYER);
    }

    PlayerModel *createNewObject(const juce::ValueTree &tree) override {
        return new PlayerModel(tree);
    }

    void deleteObject(PlayerModel *type) override {
        delete type;
    }

    void newObjectAdded(PlayerModel *type) override {

    }

    void objectRemoved(PlayerModel *type) override {

    }

    void objectOrderChanged() override {

    }
};