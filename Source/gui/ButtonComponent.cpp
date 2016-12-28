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

ButtonComponent::ButtonComponent(int newId) : PedalViewComponent(newId)
{
    
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
    g.fillEllipse((getWidth()-jmin( getWidth(), getHeight()))/2, (getHeight()-jmin( getWidth(), getHeight()))/2, jmin( getWidth(), getHeight()), jmin( getWidth(), getHeight()));   // draw an outline around the component


}

void ButtonComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
