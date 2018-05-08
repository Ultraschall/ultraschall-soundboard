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
#include "BankViewController.h"
#include "../Views/MainView.h"

class MainViewController : public ViewController<MainView> {
public:
	explicit MainViewController(Engine &engine) : ViewController(engine) {};

    void loadView() override;

    void loadFile();

    void viewDidLoad() override;

	void showLibrary();
	void showBanks();

private:
	std::unique_ptr<ViewController<Component>> contentController;
};