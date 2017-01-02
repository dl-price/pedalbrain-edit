/*
  ==============================================================================

    PedalViewComponents.h
    Created: 28 Dec 2016 1:12:50am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALVIEWCOMPONENTS_H_INCLUDED
#define PEDALVIEWCOMPONENTS_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
class PedalViewComponent;
#include "../ComponentModel.h"

//==============================================================================
/*
*/
class PedalViewComponent    : public Component
{
public:
    PedalViewComponent(int newId);
    PedalViewComponent();
    ~PedalViewComponent();
    void mouseDoubleClick(const MouseEvent &event) override;
    void mouseDown(const MouseEvent &event) override;
    static void contextCallback(int modalResult, ComponentController *component, PopupMenu *popup);
    PedalView *getPedalView();


    int idRef;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalViewComponent)
};




#endif  // PEDALVIEWCOMPONENTS_H_INCLUDED
