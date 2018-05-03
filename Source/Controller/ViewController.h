/*
  ==============================================================================

	ViewController.h
	Created: 27 Apr 2018 4:35:54pm
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "../Engine/Library.h"


class ViewController {
public:
	explicit ViewController(Library& core)
		: engine(core) {

	}

	virtual ~ViewController() {
		ViewController::viewDidUnload();
	}

	void init() {
		loadViewIfNeeded();
		viewDidLoad();
	}

	Component* getView() const { return view.get(); }

	virtual bool isViewLoaded() { return static_cast<bool>(view); }
	virtual void loadView() {};
	virtual void viewDidLoad() {};
	void loadViewIfNeeded() {
		if (!isViewLoaded()) {
			loadView();
		}
	}
	virtual void viewDidUnload() { view = nullptr; }

protected:
	std::unique_ptr<Component> view;
	Library& engine;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ViewController)
};
