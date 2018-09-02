#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "../Views/MainView.h"
#include "ViewController.h"

#include "LibraryViewController.h"

#include "../Models/LibraryModel.h"
#include "../Models/Utilities.h"

class MainViewController : public ViewController<MainView>, public ValueTreePropertyChangeListener
{
  public:
    explicit MainViewController(Engine &engine);

    void loadView() override;

    void viewDidLoad() override;

    void viewDidUnload() override;

    void showLibrary();

    void addDirectory();

    void addFile();

    void loadProjectFile();

    void valueTreePropertyChanged(ValueTree &treeWhosePropertyHasChanged, const Identifier &property) override;

private:
    std::unique_ptr<FileChooser> fileChooser;
    std::unique_ptr<ViewController<Component>> contentController;

    LibraryModel library;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainViewController)
};
