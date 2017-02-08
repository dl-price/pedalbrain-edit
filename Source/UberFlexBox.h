/*
  ==============================================================================

    UberFlexBox.h
    Created: 8 Feb 2017 4:24:18pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef UBERFLEXBOX_H_INCLUDED
#define UBERFLEXBOX_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class UberFlexBox    : public Component
{
public:
    UberFlexBox();
    ~UberFlexBox();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UberFlexBox)
};


#endif  // UBERFLEXBOX_H_INCLUDED
