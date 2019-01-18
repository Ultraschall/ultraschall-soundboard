#include "BankViewController.h"
#include "../../Redux/Actions/Actions.h"
#include "../../Engine/Player.h"

BankViewController::BankViewController(std::shared_ptr<Store> store)
	: ValueTreeObjectList<PlayerModel>(store->getState().getChildWithName(IDs::PLAYLISTS)), ViewController(store)
{
	rebuildObjects();
}

BankViewController::~BankViewController()
{
	freeObjects();
}

void BankViewController::loadView()
{
	view = std::make_unique<LibraryView>();
}

void BankViewController::viewDidLoad()
{
}

bool BankViewController::isSuitableType(const juce::ValueTree &tree) const
{
	return tree.hasType(IDs::PLAYER);
	;
}

PlayerModel *BankViewController::createNewObject(const juce::ValueTree &tree)
{
	return new PlayerModel(tree);
}

void BankViewController::deleteObject(PlayerModel *type)
{
	delete type;
}

void BankViewController::newObjectAdded(PlayerModel * /*type*/)
{
	updateContent();
}

void BankViewController::objectRemoved(PlayerModel * /*type*/)
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
