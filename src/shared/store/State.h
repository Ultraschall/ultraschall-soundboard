//
// Created by Daniel Lindenfelser on 07.03.21.
//

#include <juce_core/juce_core.h>
#include <juce_data_structures/juce_data_structures.h>

namespace IDs
{
    const juce::Identifier Application("Application");

    const juce::Identifier UserInterface("UserInterface");
    const juce::Identifier theme("theme");

    const juce::Identifier Osc("Osc");
    const juce::Identifier Receiver("Receiver");
    const juce::Identifier Remote("Remote");
    const juce::Identifier Repeater("Repeater");

    const juce::Identifier enabled("enabled");
    const juce::Identifier host("host");
    const juce::Identifier port("port");

    const juce::Identifier Project("Project");

    const juce::Identifier name("name");

    const juce::Identifier fadeout("fadeout");
    const juce::Identifier gain("gain");
    const juce::Identifier Ducking("Ducking");
    const juce::Identifier percentage("percentage");
    const juce::Identifier attack("attack");
    const juce::Identifier release("release");

    const juce::Identifier Players("Players");
    const juce::Identifier Player("Player");

    const juce::Identifier identifier("identifier");
    const juce::Identifier state("state");
    const juce::Identifier looping("looping");
    const juce::Identifier progress("progress");
    const juce::Identifier title("title");
    const juce::Identifier time("time");
    const juce::Identifier remaining("remaining");

}

struct UserInterfaceState
{
public:
    UserInterfaceState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::UserInterface));
        theme.referTo(state, IDs::theme, nullptr);
    }

    juce::ValueTree state;
    juce::CachedValue<juce::String> theme;
};

struct PlayerState
{
public:
    PlayerState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Player));
        identifier.referTo(state, IDs::identifier, nullptr);
    }
    juce::ValueTree state;
    juce::CachedValue<juce::Uuid> identifier;
};

struct ProjectState
{
public:
    ProjectState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Project));
        name.referTo(state, IDs::name, nullptr);
    }
    juce::ValueTree state;
    juce::CachedValue<juce::String> name;
    juce::ValueTree getPlayersState()
    {
        return state.getChildWithName(IDs::Players);
    }
    juce::ValueTree getPlayerState(juce::Uuid identifier)
    {
        return state.getChildWithName(IDs::Players).getChildWithProperty(IDs::identifier, identifier.toDashedString());
    }
};

struct RemoteState
{
public:
    RemoteState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Receiver));
        enabled.referTo(state, IDs::enabled, nullptr);
        host.referTo(state, IDs::host, nullptr);
        port.referTo(state, IDs::port, nullptr);
    }
    juce::ValueTree state;
    juce::CachedValue<bool> enabled;
    juce::CachedValue<juce::String> host;
    juce::CachedValue<int> port;
};

struct ReceiverState
{
public:
    ReceiverState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Receiver));
        enabled.referTo(state, IDs::enabled, nullptr);
        host.referTo(state, IDs::host, nullptr);
        port.referTo(state, IDs::port, nullptr);
    }
    juce::ValueTree state;
    juce::CachedValue<bool> enabled;
    juce::CachedValue<juce::String> host;
    juce::CachedValue<int> port;
};

struct RepeaterState
{
public:
    RepeaterState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Receiver));
        enabled.referTo(state, IDs::enabled, nullptr);
        host.referTo(state, IDs::host, nullptr);
        port.referTo(state, IDs::port, nullptr);
    }
    juce::ValueTree state;
    juce::CachedValue<bool> enabled;
    juce::CachedValue<juce::String> host;
    juce::CachedValue<int> port;
};

struct OscState
{
    OscState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Osc));
    }

    juce::ValueTree state;
    juce::ValueTree getReceiverState()
    {
        return state.getChildWithName(IDs::Receiver);
    }
    juce::ValueTree getRemoteState()
    {
        return state.getChildWithName(IDs::Remote);
    }
    juce::ValueTree getRepeaterState()
    {
        return state.getChildWithName(IDs::Repeater);
    }
};

struct ApplicationState
{
public:
    ApplicationState(juce::ValueTree v) : state(v)
    {
        jassert(v.hasType(IDs::Application));
    }

    juce::ValueTree state;
    juce::ValueTree getUserInterfaceState()
    {
        return state.getChildWithName(IDs::UserInterface);
    }
    juce::ValueTree getOscState()
    {
        return state.getChildWithName(IDs::Osc);
    }
    juce::ValueTree getProjectState()
    {
        return state.getChildWithName(IDs::Project);
    }
};
