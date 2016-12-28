/*
  ==============================================================================

    LedComponent.cpp
    Created: 28 Dec 2016 1:29:19am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LedComponent.h"

//==============================================================================
LedComponent::LedComponent(int newId) : PedalViewComponent(newId)
{
    
}

void LedComponent::paint(juce::Graphics &g)
{
    g.setColour(Colours::red);
    g.fillEllipse((getWidth()-jmin( getWidth(), getHeight()))/2, (getHeight()-jmin( getWidth(), getHeight()))/2, jmin( getWidth(), getHeight()), jmin( getWidth(), getHeight()));   // draw an outline around the component
}
