/*
  ==============================================================================

    LayoutCell.h
    Created: 27 Dec 2016 6:13:24am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LAYOUTCELL_H_INCLUDED
#define LAYOUTCELL_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes.h"

//==============================================================================
/*
*/
class LayoutCell    : public Component
{
public:
    LayoutCell();
    ~LayoutCell();

    void paint (Graphics&) override;
    void resized() override;
    void mouseUp(const MouseEvent &event) override;

private:
    ScopedPointer<Label> label;
    ScopedPointer<Button> led;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LayoutCell)
};


#endif  // LAYOUTCELL_H_INCLUDED
