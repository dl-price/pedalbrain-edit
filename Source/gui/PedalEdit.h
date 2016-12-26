/*
  ==============================================================================

    PedalEdit.h
    Created: 26 Dec 2016 5:22:14pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALEDIT_H_INCLUDED
#define PEDALEDIT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class PedalEdit    : public Component
{
public:
    PedalEdit();
    ~PedalEdit();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalEdit)
};


#endif  // PEDALEDIT_H_INCLUDED
