#pragma once

#include "JuceHeader.h"

namespace IDs
{
#define DECLARE_ID(name) const juce::Identifier name (#name);

    DECLARE_ID(LIBRARY)
    DECLARE_ID(version)
    DECLARE_ID(uuid)
    DECLARE_ID(title)
    DECLARE_ID(PLAYERS)
    DECLARE_ID(BANKS)

    DECLARE_ID(PLAYER)
    // uuid
    // title
    DECLARE_ID(path)
    DECLARE_ID(gain)
    DECLARE_ID(start_sample)
    DECLARE_ID(end_sample)
    DECLARE_ID(fadein_samples)
    DECLARE_ID(fadeout_sanples)
    DECLARE_ID(loop)

    DECLARE_ID(BANK)
    // uuid
    // title
    DECLARE_ID(CLIPS)

    DECLARE_ID(CLIP)
    // uuid
    DECLARE_ID(index)
    DECLARE_ID(player_uuid)


#undef DECLARE_ID
}
