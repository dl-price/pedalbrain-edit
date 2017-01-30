/*
  ==============================================================================

    AudioFeaturesGroup.h
    Created: 30 Jan 2017 5:55:40am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef AUDIOFEATURESGROUP_H_INCLUDED
#define AUDIOFEATURESGROUP_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioFeaturesGroup    : public Component
{
public:
    AudioFeaturesGroup();
    ~AudioFeaturesGroup();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFeaturesGroup)
};


#endif  // AUDIOFEATURESGROUP_H_INCLUDED
