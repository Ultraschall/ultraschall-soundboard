#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "../Actions/ActionObject.h"

#include <map>
#include <list>
#include <numeric>

class Store {
public:
	static std::function<ValueTree(ValueTree, ActionObject)> combineReducers(std::map<Identifier, std::function<ValueTree(ValueTree, ActionObject)>> reducers);

    explicit Store(std::function<ValueTree(ValueTree, ActionObject)> reducer, ValueTree preloadedState = ValueTree("state"));

	ValueTree getState();;

	virtual ActionObject dispatch(const ActionObject &action);

	void subscribe(const std::function<void()> &listener);;

	void unsubscribe(const std::function<void()> &listener);

	void replaceReducer(std::function<ValueTree(ValueTree, ActionObject)> nextReducer);

private:
    std::function<ValueTree(ValueTree, ActionObject)> currentReducer;
    ValueTree currentState;
    std::list<std::function<void()>> currentListeners;
    bool isDispatching {false};

    /**
    * These are private action types reserved by Redux.
    * For any unknown actions, you must return the current state.
    * If the current state is undefined, you must return the initial state.
    * Do not reference these action types directly in your code.
    */
    ActionObject INIT{"@@redux/INIT" + Uuid().toString()};
    ActionObject REPLACE{"@@redux/REPLACE" + Uuid().toString()};
    ActionObject PROBE_UNKNOWN_ACTION{"@@redux/REPLACE" + Uuid().toString()};
};
