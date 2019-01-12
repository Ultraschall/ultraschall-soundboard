#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ActionObject.h"
#include "Store.h"

class Middleware {
protected:
	std::weak_ptr<Middleware> next;
public:
    virtual ~Middleware() {}
	virtual void setNext(std::shared_ptr<Middleware> value) {
		if (!next.expired()) next.lock()->setNext(value);
		else { next = value; }
	}

	virtual ActionObject dispatch(const ActionObject &action, Store &store) = 0;
};

class MiddlewareEnhancer : public Store {
public:
	explicit MiddlewareEnhancer(std::function<ValueTree(ValueTree, ActionObject)> reducer,
		ValueTree preloadedStore, std::shared_ptr<Middleware> chain) : Store(reducer, preloadedStore), chain(chain)
	{
	}

	ActionObject dispatch(const ActionObject &action) override {
		return chain->dispatch(action, *this);
	}

private:
	std::shared_ptr<Middleware> chain;
};

class MiddlewareEnhancerBuilder {
public:
	static MiddlewareEnhancerBuilder New(std::function<ValueTree(ValueTree, ActionObject)> reducer) {
		MiddlewareEnhancerBuilder builder;
		builder.reducer = reducer;
		return builder;
	}

	MiddlewareEnhancerBuilder SetPreloadedStore(ValueTree value) {
		preloadedStore = value;
		return *this;
	}

	template<class T, class... TArgs>
	MiddlewareEnhancerBuilder Use(TArgs&&... args) {
		middlewares.push_back(std::make_shared<T>(std::forward<TArgs>(args)...));
		return *this;
	}

	template<class T>
	MiddlewareEnhancerBuilder Use(std::shared_ptr<T> middleware) {
		middlewares.push_back(middleware);
		return *this;
	}
	std::shared_ptr<MiddlewareEnhancer> Build() {
		auto root = std::make_shared<RootDispatcher>();
		for (const auto &middleware : middlewares) {
			root->setNext(middleware);
		}
		root->setNext(std::make_shared<StoreDispatcher>());
		return std::make_shared<MiddlewareEnhancer>(reducer, preloadedStore, root);
	}
private:
	std::vector<std::shared_ptr<Middleware>> middlewares;
	std::function<ValueTree(ValueTree, ActionObject)> reducer;
	ValueTree preloadedStore;
	MiddlewareEnhancerBuilder() {}

	class RootDispatcher : public Middleware {
	public:
		ActionObject dispatch(const ActionObject &action, Store &store) override {
			if (auto n = next.lock()) {
				return n->dispatch(action, store);
			}
			return action;
		}

		void setNext(std::shared_ptr<Middleware> middleware) override {
			chain.push_back(middleware);
			Middleware::setNext(middleware);
		}
	private:
		std::vector<std::shared_ptr<Middleware>> chain;
	};

	class StoreDispatcher : public Middleware {
	public:
		ActionObject dispatch(const ActionObject &action, Store &store) override {
			return store.rawDispatch(action);
		}
	};
};
