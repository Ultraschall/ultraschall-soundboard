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
#include "../Views/LibraryView.h"

//==============================================================================
/*
*/
class LibraryViewController
		: public drow::ValueTreeObjectList<PlayerModel>, 
		  public ListBoxModel,
		  public ViewController<Component>,
		  public ChangeListener
{
public:
	explicit LibraryViewController(Engine &engine);

	~LibraryViewController();

	bool isSuitableType(const juce::ValueTree &tree) const override;

	PlayerModel *createNewObject(const juce::ValueTree &tree) override;

	void deleteObject(PlayerModel *type) override;

	void newObjectAdded(PlayerModel *type) override;

	void objectRemoved(PlayerModel *type) override;

	void objectOrderChanged() override;

	void loadView() override;

	void viewDidLoad() override;;

	virtual int getNumRows() override;

	virtual void paintListBoxItem(int rowNumber, Graphics & g, int width, int height, bool rowIsSelected) override;

	virtual Component* refreshComponentForRow(int rowNumber, bool isRowSelected, Component* existingComponentToUpdate) override;

	virtual void changeListenerCallback(ChangeBroadcaster * source) override;
private:
	LibraryView * getLibraryView();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryViewController)
};
