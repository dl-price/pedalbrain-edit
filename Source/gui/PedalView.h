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
class PedalView;
#include "PedalViewComponents.h"
#include "../BoardModel.h"

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
    int getPage();
    void setPage(int i);

private:
    int viewingPage = 1;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalView)
};


#endif  // PEDALVIEW_H_INCLUDED
