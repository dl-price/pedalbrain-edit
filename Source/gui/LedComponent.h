/*
  ==============================================================================

    LedComponent.h
    Created: 28 Dec 2016 1:29:19am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LEDCOMPONENT_H_INCLUDED
#define LEDCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalViewComponents.h"

//==============================================================================
/*
*/
class LedComponent : public PedalViewComponent
{
public:
    LedComponent(int newId);
    void paint (Graphics&) override;
    void setOn(bool on);
    bool isOn();
    void setColour(Colour colour);
    void mouseDown(const juce::MouseEvent &event) override;
    
private:
    Colour colour;
    bool state;
    
};


#endif  // LEDCOMPONENT_H_INCLUDED
