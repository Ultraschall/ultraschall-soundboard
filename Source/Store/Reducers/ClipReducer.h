#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Actions/Actions.h"

ValueTree clips(ValueTree state, const ActionObject& action) {
    if (action.type == Init) {

    } else if (action.type == CreateClip) {
        Uuid uuid;
        ValueTree clip(IDs::CLIP);
        clip.setProperty(IDs::clip_id, uuid.toDashedString(), nullptr);
        clip.setProperty(IDs::clip_player_id, action.args.getProperty(IDs::clip_player_id), nullptr);
        clip.setProperty(IDs::clip_bank_id, action.args.getProperty(IDs::clip_bank_id), nullptr);
        state.addChild(clip, -1, nullptr);

    } else if (action.type == UpdateClip) {
        auto clip = state.getChildWithProperty(IDs::clip_id, action.args.getProperty(IDs::clip_id));
        jassert(clip.isValid());

        clip.setProperty(IDs::clip_player_id, action.args.getProperty(IDs::clip_player_id), nullptr);
        clip.setProperty(IDs::clip_bank_id, action.args.getProperty(IDs::clip_bank_id), nullptr);
    } else if (action.type == DeleteClip) {
        auto clip = state.getChildWithProperty(IDs::clip_id, action.args.getProperty(IDs::clip_id));
        jassert(clip.isValid());

        state.removeChild(clip, nullptr);
    }
    return state;
}
