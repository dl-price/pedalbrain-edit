/*
  ==============================================================================

    PedalView.h
    Created: 27 Dec 2016 9:43:51am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALVIEW_H_INCLUDED
#define PEDALVIEW_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
//#include "../includes.h"

//==============================================================================
/*
*/
class PedalView    : public Component
{
public:
    PedalView();
    ~PedalView();

    void paint (Graphics&) override;
    void resized() override;

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalView)
};


#endif  // PEDALVIEW_H_INCLUDED
