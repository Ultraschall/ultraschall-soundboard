#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../../Store/Store.h"

template <typename ViewType>
class ViewController
{
  public:
    explicit ViewController(std::shared_ptr<Store> store)
        : store(store)
    {
    }

    virtual ~ViewController()
    {
        ViewController::viewDidUnload();
    }

    void init()
    {
        loadViewIfNeeded();
        viewDidLoad();
    }

    ViewType *getView() const
    {
        return view.get();
    }

    virtual bool isViewLoaded()
    {
        return static_cast<bool>(view);
    }

    virtual void loadView(){};

    virtual void viewDidLoad(){};

    void loadViewIfNeeded()
    {
        if (!isViewLoaded())
        {
            loadView();
        }
    }

    virtual void viewDidUnload()
    {
        view = nullptr;
    }

  protected:
    std::unique_ptr<ViewType> view;
    std::shared_ptr<Store> store;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ViewController)
};
