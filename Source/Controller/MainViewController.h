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

class MainViewController : public ViewController {
public:
    MainViewController(Library &core);

    void loadView() override;

    void loadFile();

    void viewDidLoad() override;

private:
    enum MainToolbarItemIds {
        showGrid = 1,
        showLibrary = 2,
		talkover = 3,
		addFile = 4,
		settings = 5,
		gain = 6

    };
    class MainToolbarItemFactory : public ToolbarItemFactory {
    public:
        explicit MainToolbarItemFactory() = default;

        void getAllToolbarItemIds(Array<int> &ids) override;

        void getDefaultItemSet(Array<int> &ids) override;

        ToolbarItemComponent *createItem(int itemId) override;
    };
    MainToolbarItemFactory mainToolbarItemFactory;
};