/*
  ==============================================================================

    ClipView.h
    Created: 29 Apr 2018 12:22:06pm

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "../Engine/Identifier.h"

class ClipView : public ValueTree::Listener, 
				 public Component
{
public:
	explicit ClipView(const ValueTree v)
		: state(v) {
		state.addListener(this);
	}

	~ClipView()
	{
		
	}

	void paint(Graphics& g) override;

	void valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property) override {}
	void valueTreeChildAdded(ValueTree& parentTree, ValueTree& childWhichHasBeenAdded) override {}
	void valueTreeChildRemoved(ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved, int indexFromWhichChildWasRemoved) override {}
	void valueTreeChildOrderChanged(ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex, int newIndex) override {}
	void valueTreeParentChanged(ValueTree& treeWhoseParentHasChanged) override {}
private:
	ValueTree state;

public:
	explicit ClipView() {
		state = ValueTree(IDs::CLIP);
	}

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClipView)
};
