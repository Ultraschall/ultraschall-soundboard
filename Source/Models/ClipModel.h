/*
  ==============================================================================

    Clip.h
    Created: 2 May 2018 2:19:32pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "../Engine/Identifier.h"
#include "../Engine/Player.h"

struct BankModel {
public:
    BankModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::CLIP));

        uuid.referTo(state, IDs::uuid, nullptr);
        title.referTo(state, IDs::title, nullptr);


    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<String> title;
};

struct ClipModel {
public:
    ClipModel(ValueTree v)
            : state(v)
    {
        jassert(v.hasType(IDs::CLIP));

        uuid.referTo(state, IDs::uuid, nullptr);
        index.referTo(state, IDs::index, nullptr);
        playerId.referTo(state, IDs::playerId, nullptr);
    }

    ValueTree state;
    CachedValue<String> uuid;
    CachedValue<int> index;
    CachedValue<String> playerId;

    Player *player;
};