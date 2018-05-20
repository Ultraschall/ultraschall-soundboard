#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "../Models/ValueTreeObjectList.h"
#include "../Models/BankModel.h"

class BankViewController : public ViewController<Component>, public drow::ValueTreeObjectList<BankModel>
{
public:
    explicit BankViewController(Engine &engine);

    ~BankViewController() override;

    void loadView() override;

    void viewDidLoad() override;

    bool isSuitableType(const juce::ValueTree &tree) const override;

    BankModel *createNewObject(const juce::ValueTree &tree) override;

    void deleteObject(BankModel *type) override;

    void newObjectAdded(BankModel *type) override;

    void objectRemoved(BankModel *type) override;

    void objectOrderChanged() override;

    void newBank()
    {
        engine.newBank();
    }

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankViewController)
};
