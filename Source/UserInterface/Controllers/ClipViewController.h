#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../Models/ClipModel.h"
#include "../Models/ValueTreeObjectList.h"

#include "../Views/BankSelectorView.h"
#include "../Views/BankView.h"
#include "../Views/ClipItem.h"
#include "../Views/ClipView.h"
#include "ViewController.h"

class ClipViewController
        : public drow::ValueTreeObjectList<ClipModel>,
          public ViewController<Component>
{
public:
    explicit ClipViewController(std::shared_ptr<Store> store, ValueTree bank);

    ~ClipViewController() override;

    void loadView() override;

    void viewDidLoad() override;

    bool isSuitableType(const juce::ValueTree &tree) const override;

    ClipModel *createNewObject(const juce::ValueTree &tree) override;

    void deleteObject(ClipModel *type) override;

    void newObjectAdded(ClipModel *type) override;

    void objectRemoved(ClipModel *type) override;

    void objectOrderChanged() override;

    void valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) override;

private:
    void updateContent() const;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClipViewController)
};
