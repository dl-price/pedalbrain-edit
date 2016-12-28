/*
  ==============================================================================

    ButtonComponent.cpp
    Created: 28 Dec 2016 1:44:31am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ButtonComponent.h"

//==============================================================================
ButtonComponent::ButtonComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

ButtonComponent::~ButtonComponent()
{
}

void ButtonComponent::paint (Graphics& g)
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
    g.drawText ("ButtonComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void ButtonComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
