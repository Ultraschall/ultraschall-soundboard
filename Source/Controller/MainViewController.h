/*
  ==============================================================================

    MainViewController.h
    Created: 27 Apr 2018 4:35:25pm
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "LibraryViewController.h"
#include "../Views/MainView.h"

class MainViewController : public ViewController<MainView>, public ToolbarItemFactory {
public:
	explicit MainViewController(Engine &engine) : ViewController(engine) {};

    void loadView() override;

    void loadFile();

    void viewDidLoad() override;

	void showLibrary();

	void getAllToolbarItemIds(Array<int> &ids) override;

	void getDefaultItemSet(Array<int> &ids) override;

	ToolbarItemComponent *createItem(int itemId) override;

private:
	std::unique_ptr<ViewController<Component>> contentController;

    enum MainToolbarItemIds {
        grid = 1,
        library = 2,
		talkover = 3,
		addFile = 4,
		settings = 5,
		gain = 6

    };
};