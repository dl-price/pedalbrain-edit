/*
  ==============================================================================

    PedalViewComponents.cpp
    Created: 28 Dec 2016 1:12:50am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalViewComponents.h"

//==============================================================================
PedalViewComponent::PedalViewComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PedalViewComponent::PedalViewComponent(int newId)
{
    idRef = newId;
}

PedalViewComponent::~PedalViewComponent()
{
}


