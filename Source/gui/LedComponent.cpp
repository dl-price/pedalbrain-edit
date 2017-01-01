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
    colour = Colours::red;
}

void LedComponent::paint(juce::Graphics &g)
{
    if(!state)
    {
        g.setColour(Colours::black);
    }
    else
    {
        g.setColour(colour);
    }
    g.fillEllipse((getWidth()-jmin( getWidth(), getHeight()))/2, (getHeight()-jmin( getWidth(), getHeight()))/2, jmin( getWidth(), getHeight()), jmin( getWidth(), getHeight()));   // draw an outline around the component
}

void LedComponent::setOn(bool on)
{
    state = on;
    repaint();
}

bool LedComponent::isOn()
{
    return state;
}

void LedComponent::setColour(Colour colour)
{
    this->colour = colour;
}

void LedComponent::mouseDown(const juce::MouseEvent &event)
{
    PedalViewComponent::mouseDown(event);
    
    if(!event.mods.isPopupMenu())
    {
        setOn(!isOn());
    }
}
