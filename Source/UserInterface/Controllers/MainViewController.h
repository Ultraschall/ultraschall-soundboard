#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../Views/MainView.h"
#include "ViewController.h"

#include "LibraryViewController.h"
#include "BankViewController.h"
#include "PlaylistViewController.h"

#include "../Models/ApplicationModel.h"
#include "../Models/Utilities.h"

class MainViewController : public ViewController<MainView>, public ValueTreePropertyChangeListener, public AsyncUpdater
{
public:
	explicit MainViewController(std::shared_ptr<Store> store);

	void loadView() override;
	void viewDidLoad() override;
	void viewDidUnload() override;

	void showLibrary();
    void showBank();
    void showPlaylist();

	void loadProjectFile();

	void valueTreePropertyChanged(ValueTree &treeWhosePropertyHasChanged, const Identifier &property) override;
	void handleAsyncUpdate() override;
private:
	std::unique_ptr<FileChooser> fileChooser;
	std::unique_ptr<ViewController<Component>> contentController;

	ApplicationModel model;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainViewController)
};
