/*
  ==============================================================================

    AudioItemComponent.cpp
    Created: 30 Jan 2017 5:55:57am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "AudioItemComponent.h"

//==============================================================================
AudioItemComponent::AudioItemComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AudioItemComponent::~AudioItemComponent()
{
}

void AudioItemComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("AudioItemComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void AudioItemComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
