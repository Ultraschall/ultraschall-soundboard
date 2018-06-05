#pragma once

#include "JuceHeader.h"

#include "ViewController.h"
#include "../Views/MainView.h"

#include "LibraryViewController.h"


class MainViewController : public ViewController<MainView> {
public:
    explicit MainViewController(Engine &engine);
    
    void loadView() override;

    void viewDidLoad() override;
    
    void showLibrary();
    
    void addDirectory();
    
    void addFile();
    
    void loadProjectFile();
private:
    std::unique_ptr<FileChooser> fileChooser;
    std::unique_ptr<ViewController<Component>> contentController;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainViewController)
};
