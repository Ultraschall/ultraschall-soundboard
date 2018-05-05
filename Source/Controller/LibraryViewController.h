/*
  ==============================================================================

    LibraryViewController.h
    Created: 4 May 2018 11:04:34am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "../Models/ValueTreeObjectList.h"
#include "../Models/PlayerModel.h"
//==============================================================================
/*
*/
class LibraryViewController
		: public ViewController<Component>,
		  public drow::ValueTreeObjectList<PlayerModel>
{
public:
	explicit LibraryViewController(Engine &engine)
			: ViewController(engine),
			  drow::ValueTreeObjectList<PlayerModel>(engine.state.getChildWithName(IDs::PLAYERS))
	{

	}

	bool isSuitableType(const juce::ValueTree &tree) const override;

	PlayerModel *createNewObject(const juce::ValueTree &tree) override;

	void deleteObject(PlayerModel *type) override;

	void newObjectAdded(PlayerModel *type) override;

	void objectRemoved(PlayerModel *type) override;

	void objectOrderChanged() override;

	void loadView() override;

	void viewDidLoad() override;;

private:
    TableListBox* getTableListBox() {
        return dynamic_cast<TableListBox*>(getView());
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryViewController)
};
