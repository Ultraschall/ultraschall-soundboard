#pragma once

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../Models/PlayerModel.h"
#include "../Models/ValueTreeObjectList.h"

#include "../Views/LibraryItem.h"
#include "../Views/LibraryView.h"
#include "ViewController.h"

class BankViewController
	: public drow::ValueTreeObjectList<PlayerModel>,
	public ViewController<Component>
{
public:
	explicit BankViewController(std::shared_ptr<Store> store);

	~BankViewController() override;

	void loadView() override;

	void viewDidLoad() override;

	bool isSuitableType(const juce::ValueTree &tree) const override;

	PlayerModel *createNewObject(const juce::ValueTree &tree) override;

	void deleteObject(PlayerModel *type) override;

	void newObjectAdded(PlayerModel *type) override;

	void objectRemoved(PlayerModel *type) override;

	void objectOrderChanged() override;

	void valueTreePropertyChanged(ValueTree &state, const Identifier &identifier) override;

private:
	void updateContent() const;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankViewController)
};
