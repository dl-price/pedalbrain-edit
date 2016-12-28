/*
  ==============================================================================

    LcdComponent.h
    Created: 28 Dec 2016 1:44:18am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LCDCOMPONENT_H_INCLUDED
#define LCDCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class LcdComponent    : public Component
{
public:
    LcdComponent();
    ~LcdComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LcdComponent)
};


#endif  // LCDCOMPONENT_H_INCLUDED
