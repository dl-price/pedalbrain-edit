/*
  ==============================================================================

    ButtonComponent.h
    Created: 28 Dec 2016 1:44:31am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BUTTONCOMPONENT_H_INCLUDED
#define BUTTONCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ButtonComponent    : public Component
{
public:
    ButtonComponent();
    ~ButtonComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonComponent)
};


#endif  // BUTTONCOMPONENT_H_INCLUDED
