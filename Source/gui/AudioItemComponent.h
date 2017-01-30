/*
  ==============================================================================

    AudioItemComponent.h
    Created: 30 Jan 2017 5:55:57am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef AUDIOITEMCOMPONENT_H_INCLUDED
#define AUDIOITEMCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioItemComponent    : public Component
{
public:
    AudioItemComponent();
    ~AudioItemComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioItemComponent)
};


#endif  // AUDIOITEMCOMPONENT_H_INCLUDED
