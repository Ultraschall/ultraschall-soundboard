#include "BankViewController.h"
#include "../../Store/Actions/Actions.h"
#include "../../Engine/Player.h"

BankViewController::BankViewController(std::shared_ptr<Store> store)
	: ValueTreeObjectList<BankModel>(store->getState().getChildWithName(IDs::BANKS)), ViewController(store), clipViewController(std::make_unique<ClipViewController>(store))
{
	rebuildObjects();
}

BankViewController::~BankViewController()
{
	freeObjects();
}

void BankViewController::loadView()
{
    clipViewController->loadView();
    view = std::make_unique<BankView>();
}

void BankViewController::viewDidLoad()
{
    auto bankView = dynamic_cast<BankView*>(view.get());
    if (bankView == nullptr) {
        return;
    }
    bankView->setClipView(clipViewController->getView());
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

void BankViewController::newObjectAdded(BankModel * /*type*/)
{
	updateContent();
}

void BankViewController::objectRemoved(BankModel * /*type*/)
{
	updateContent();
}

void BankViewController::objectOrderChanged()
{
	updateContent();
}

void BankViewController::valueTreePropertyChanged(ValueTree & /*state*/, const Identifier & /*identifier*/)
{

}

void BankViewController::updateContent() const
{

}
