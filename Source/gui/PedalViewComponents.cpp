/*
  ==============================================================================

    PedalViewComponents.cpp
    Created: 28 Dec 2016 1:12:50am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"
#include "PedalViewComponents.h"
#include "../BoardController.h"


//==============================================================================
PedalViewComponent::PedalViewComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    


}

PedalViewComponent::PedalViewComponent(int newId) : PedalViewComponent::PedalViewComponent()
{
    idRef = newId;
}

PedalViewComponent::~PedalViewComponent()
{
}

PedalView *PedalViewComponent::getPedalView()
{
    return dynamic_cast<PedalView*>(getParentComponent());
}



