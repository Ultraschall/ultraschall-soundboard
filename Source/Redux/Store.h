#pragma once

#include <map>
#include <list>
#include <numeric>

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ActionObject.h"

class StoreDispatcher;
class Store : public ChangeBroadcaster {
public:
    friend class StoreDispatcher;

	static std::function<ValueTree(ValueTree, ActionObject)> combineReducers(std::map<Identifier, std::function<ValueTree(ValueTree, ActionObject)>> reducers);

    explicit Store(std::function<ValueTree(ValueTree, ActionObject)> reducer, ValueTree preloadedState = ValueTree("state"));
    virtual ~Store(){}

	ValueTree getState();

	virtual ActionObject dispatch(const ActionObject &action);

	void subscribe(const std::function<void()> listener);

	//void unsubscribe(const std::function<void()> listener);

	void replaceReducer(std::function<ValueTree(ValueTree, ActionObject)> nextReducer);

    ActionObject rawDispatch(const ActionObject &action);
    
private:
    std::function<ValueTree(ValueTree, ActionObject)> currentReducer;
    ValueTree currentState;
    std::vector<std::function<void()>> currentListeners;
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
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Store)
};
