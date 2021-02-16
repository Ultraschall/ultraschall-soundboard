#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../Models/BankModel.h"
#include "../Models/ValueTreeObjectList.h"

#include "../Views/BankView.h"
#include "ClipViewController.h"
#include "ViewController.h"

class BankViewController
	: public drow::ValueTreeObjectList<BankModel>,
	public ViewController<Component>
{
public:
	explicit BankViewController(std::shared_ptr<Store> store);

	~BankViewController() override;

	void loadView() override;

	void viewDidLoad() override;

	bool isSuitableType(const juce::ValueTree &tree) const override;

    BankModel *createNewObject(const juce::ValueTree &tree) override;

	void deleteObject(BankModel *type) override;

	void newObjectAdded(BankModel *type) override;

	void objectRemoved(BankModel *type) override;

	void objectOrderChanged() override;

	void valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) override;

private:
	void updateContent() const;
    std::unique_ptr<ClipViewController> clipViewController;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankViewController)
};
