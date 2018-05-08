/*
  ==============================================================================

    BankViewController.cpp
    Created: 8 May 2018 3:11:08pm
    Author:  danlin

  ==============================================================================
*/

#include "BankViewController.h"


BankViewController::BankViewController(Engine & engine) : ViewController(engine)
  {
  }

BankViewController::~BankViewController()
{
}

void BankViewController::loadView()
{
	view = std::make_unique<BankView>();
}

void BankViewController::viewDidLoad()
{
}
