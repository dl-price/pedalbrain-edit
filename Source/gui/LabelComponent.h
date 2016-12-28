/*
  ==============================================================================

    LabelComponent.h
    Created: 28 Dec 2016 1:43:58am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LABELCOMPONENT_H_INCLUDED
#define LABELCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class LabelComponent    : public Component
{
public:
    LabelComponent();
    ~LabelComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabelComponent)
};


#endif  // LABELCOMPONENT_H_INCLUDED
