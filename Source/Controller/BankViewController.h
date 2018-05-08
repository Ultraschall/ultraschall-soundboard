/*
  ==============================================================================

    BankViewController.h
    Created: 8 May 2018 3:11:08pm
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ViewController.h"
#include "../Views/BankView.h"

class BankViewController : public ViewController<Component>
{
public:
	explicit BankViewController(Engine &engine);

	~BankViewController();

	void loadView() override;

	void viewDidLoad() override;
private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankViewController)
};