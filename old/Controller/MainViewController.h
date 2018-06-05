#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "LibraryViewController.h"
#include "BankViewController.h"
#include "../Views/MainView.h"

class MainViewController : public ViewController<MainView>
{
public:
    explicit MainViewController(Engine &engine) : ViewController(engine)
	{
	}

	void loadView() override;

    void loadFile();

	void importFile();

	void exportFile();

    void importDirectory();

    void viewDidLoad() override;

    void showLibrary();

    void showBanks();

private:
    std::unique_ptr<FileChooser> fileChooser;
    std::unique_ptr<ViewController<Component>> contentController;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainViewController)
};