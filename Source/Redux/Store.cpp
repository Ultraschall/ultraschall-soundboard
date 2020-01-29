#include <utility>

#include "Store.h"

std::function<ValueTree(ValueTree, ActionObject)> Store::combineReducers(std::map<Identifier, std::function<ValueTree(ValueTree, ActionObject)>> reducers) {
	return [reducers](ValueTree state, ActionObject action) -> ValueTree {
		bool hasChanged = false;
		ValueTree nextState;
		for (auto const &reducer : reducers) {
			auto previousStateForKey = state.getOrCreateChildWithName(reducer.first, nullptr);
			auto nextStateForKey = reducer.second(previousStateForKey, action);

			if (!nextStateForKey.isValid()) {
				throw std::runtime_error("Given ${actionDescription}, reducer \"${key}\" returned undefined.\n"
					"To ignore an action, you must explicitly return the previous state.\n"
					"If you want this reducer to hold no value, you can return null instead of undefined.");
			}

			nextState.getOrCreateChildWithName(reducer.first, nullptr) = nextStateForKey;
			hasChanged = hasChanged || nextStateForKey != previousStateForKey;
		}
		return hasChanged ? nextState : state;
	};
}

Store::Store(std::function<ValueTree(ValueTree, ActionObject)> reducer, ValueTree preloadedState)
	: currentReducer(std::move(reducer)), currentState(std::move(preloadedState))
{
	const auto _ = Store::dispatch(INIT);
}

ValueTree Store::getState() {
	if (isDispatching) {
		throw std::runtime_error("You may not call store.getState() while the reducer is executing.\n"
			"The reducer has already received the state as an argument.\n"
			"Pass it down from the top reducer instead of reading it from the store.");
	}

	return currentState;
}

ActionObject Store::dispatch(const ActionObject &action) {
    return rawDispatch(action);
}

ActionObject Store::rawDispatch(const ActionObject &action) {
	if (action.type == Identifier()) {
		throw std::runtime_error("Actions may not have an undefined \"type\" property.\n"
			"Have you misspelled a constant?");
	}

	if (isDispatching) {
		throw std::runtime_error("Reducers may not dispatch actions.");
	}

	isDispatching = true;
	currentState = currentReducer(currentState, action);
	isDispatching = false;

	for (auto const &listener : currentListeners) {
		listener();
	}

	return action;
}

void Store::subscribe(const std::function<void()> listener) {
	if (isDispatching) {
		throw std::runtime_error("You may not call store.subscribe() while the reducer is executing.\n"
			"If you would like to be notified after the store has been updated, subscribe from a\n"
			"component and invoke store.getState() in the callback to access the latest state.\n"
			"See https://redux.js.org/api-reference/store#subscribe(listener) for more details.");
	}

	currentListeners.push_back(listener);
}

//void Store::unsubscribe(const std::function<void()> listener) {
//	if (isDispatching) {
//		throw std::runtime_error("You may not unsubscribe from a store listener while the reducer is executing.\n"
//			"See https://redux.js.org/api-reference/store#subscribe(listener) for more details.");
//	}
//	currentListeners.remove(listener);
//}

void Store::replaceReducer(std::function<ValueTree(ValueTree, ActionObject)> nextReducer) {
	currentReducer = std::move(nextReducer);
	const auto _ = dispatch(REPLACE);
}
