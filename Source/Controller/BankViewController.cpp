#include "BankViewController.h"
#include "../Views/BankView.h"

BankViewController::BankViewController(Engine &engine)
        : ViewController(engine),
          ValueTreeObjectList<BankModel>(engine.state.getChildWithName(IDs::BANKS))
{
    rebuildObjects();
}

BankViewController::~BankViewController()
{
    freeObjects();
}

void BankViewController::loadView()
{
    view = std::make_unique<BankView>();
}

void BankViewController::viewDidLoad()
{
}

bool BankViewController::isSuitableType(const juce::ValueTree &tree) const
{
    return tree.hasType(IDs::BANK);
}

BankModel *BankViewController::createNewObject(const juce::ValueTree &tree)
{
    return new BankModel(tree);
}

void BankViewController::deleteObject(BankModel *type)
{
    delete type;

}

void BankViewController::newObjectAdded(BankModel *type)
{

}

void BankViewController::objectRemoved(BankModel *type)
{
}

void BankViewController::objectOrderChanged()
{

}
