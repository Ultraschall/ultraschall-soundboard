#pragma once

#include "JuceHeader.h"

#include "ViewController.h"

#include "../Models/ValueTreeObjectList.h"
#include "../Models/PlayerModel.h"

#include "../Views/LibraryView.h"
#include "../Views/LibraryRowView.h"

class LibraryViewController
        : public drow::ValueTreeObjectList<PlayerModel>,
          public ListBoxModel,
          public ViewController<Component> {
public:
    explicit LibraryViewController(Engine &engine);

    ~LibraryViewController() override;

    bool isSuitableType(const juce::ValueTree &tree) const override;

    PlayerModel *createNewObject(const juce::ValueTree &tree) override;

    void deleteObject(PlayerModel *type) override;

    void newObjectAdded(PlayerModel *type) override;

    void objectRemoved(PlayerModel *type) override;

    void objectOrderChanged() override;

    void loadView() override;

    void viewDidLoad() override;;

    int getNumRows() override;

    void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override;

    Component *refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate) override;

    void refreshLibraryRow(LibraryRowView *libraryRowView, PlayerModel &playerModel);
    void intLibraryRow(LibraryRowView *libraryRowView, PlayerModel &playerModel);

    void valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) override;

private:
    LibraryView *getLibraryView() const;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LibraryViewController)
};
