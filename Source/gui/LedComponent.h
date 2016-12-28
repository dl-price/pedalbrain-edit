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
    
};


#endif  // LEDCOMPONENT_H_INCLUDED
