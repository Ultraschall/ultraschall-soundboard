#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "../Models/PlayerModel.h"
#include "../Models/ValueTreeObjectList.h"

#include "../Views/LibraryItem.h"
#include "../Views/LibraryView.h"
#include "ViewController.h"

class LibraryViewController
    : public drow::ValueTreeObjectList<PlayerModel>,
      public ListBoxModel,
      public ViewController<Component>
{
  public:
    explicit LibraryViewController(Engine &engine);

    ~LibraryViewController() override;

    void loadView() override;

    void viewDidLoad() override;

    bool isSuitableType(const juce::ValueTree &tree) const override;

    PlayerModel *createNewObject(const juce::ValueTree &tree) override;

    void deleteObject(PlayerModel *type) override;

    void newObjectAdded(PlayerModel *type) override;

    void objectRemoved(PlayerModel *type) override;

    void objectOrderChanged() override;

    void valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) override;

    LibraryView *getLibraryView() const;

    int getNumRows() override;

    void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override {}

    Component *refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate) override;

    void intLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel);

    void refreshLibraryRow(LibraryItem *libraryItem, PlayerModel &playerModel);

  private:
    void updateContent() const;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LibraryViewController)
};
