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
    g.fillEllipse(0, 0, 20, 20);
}
