/*
  ==============================================================================

	ViewController.h
	Created: 19 Jan 2018 10:48:26pm
	Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "../Shared/Engine/Core.h"

class ViewController {
public:
	explicit ViewController(Core& core) 
		: core(core) {
		
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
	virtual void loadView();
	virtual void viewDidLoad() {};
	void loadViewIfNeeded() {
		if (!isViewLoaded()) {
			loadView();
		}
	}
	virtual void viewDidUnload() { view = nullptr; }

protected:
	std::unique_ptr<Component> view;
	Core& core;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ViewController)
};
