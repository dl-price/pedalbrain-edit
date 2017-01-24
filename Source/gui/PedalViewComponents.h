/*
  ==============================================================================

    PedalViewComponents.h
    Created: 28 Dec 2016 1:12:50am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALVIEWCOMPONENTS_H_INCLUDED
#define PEDALVIEWCOMPONENTS_H_INCLUDED

class PedalViewComponent;

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"



//==============================================================================
/*
*/
class PedalViewComponent    : public Component
{
public:
    PedalViewComponent(int newId);
    PedalViewComponent();
    ~PedalViewComponent();
    PedalView *getPedalView();


    int idRef;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalViewComponent)
};




#endif  // PEDALVIEWCOMPONENTS_H_INCLUDED
