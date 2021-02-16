#include "ClipViewController.h"
#include "BankViewController.h"
#include "../../Store/Actions/Actions.h"
#include "../../Engine/Player.h"

ClipViewController::ClipViewController(std::shared_ptr<Store> store)
        : ValueTreeObjectList<ClipModel>(store->getState().getChildWithName(IDs::CLIPS)), ViewController(store)
{
    rebuildObjects();
}

ClipViewController::~ClipViewController()
{
    freeObjects();
}

void ClipViewController::loadView()
{
    view = std::make_unique<ClipView>();
}

void ClipViewController::viewDidLoad()
{
}

bool ClipViewController::isSuitableType(const juce::ValueTree &tree) const
{
    return tree.hasType(IDs::CLIP);
}

ClipModel *ClipViewController::createNewObject(const juce::ValueTree &tree)
{
    return new ClipModel(tree);
}

void ClipViewController::deleteObject(ClipModel *type)
{
    delete type;
}

void ClipViewController::newObjectAdded(ClipModel * /*type*/)
{
    updateContent();
}

void ClipViewController::objectRemoved(ClipModel * /*type*/)
{
    updateContent();
}

void ClipViewController::objectOrderChanged()
{
    updateContent();
}

void ClipViewController::valueTreePropertyChanged(ValueTree & /*state*/, const Identifier & /*identifier*/)
{

}

void ClipViewController::updateContent() const
{
}
