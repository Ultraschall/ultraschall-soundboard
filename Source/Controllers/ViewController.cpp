/*
  ==============================================================================

    ViewController.cpp
    Created: 19 Jan 2018 10:48:26pm
    Author:  danlin

  ==============================================================================
*/

#include "ViewController.h"

ViewController::ViewController(Core& core) : core(core) {}

void ViewController::loadView() {}

bool ViewController::isViewLoaded() {
    return static_cast<bool>(view);
}

Component* ViewController::getView() const {
    return view.get();
}

void ViewController::loadViewIfNeeded() {
    if (!isViewLoaded()) {
        loadView();
    }
}