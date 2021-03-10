/*
  ==============================================================================

    GridCell.h
    Created: 23 Jan 2015 7:02:25pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef GRIDCELL_H_INCLUDED
#define GRIDCELL_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>
#include "../LookAndFeel.h"
#include "../../player/Player.h"

using namespace juce;

class SoundboardGridCell : public Component, public ChangeListener
{
public:
    explicit SoundboardGridCell(Player *p);
    ~SoundboardGridCell();
    
    void mouseUp(const MouseEvent &event) override;
    void paint(Graphics &g) override;
    void changeListenerCallback(ChangeBroadcaster * /*source*/) override;
    void setIndex(int value);
    int  getIndex();
private:
    Player *player;
    int  index;
    bool progressState;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundboardGridCell)
};

#endif  // GRIDCELL_H_INCLUDED
