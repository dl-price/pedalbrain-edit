/*
  ==============================================================================

    ComponentEdit.cpp
    Created: 29 Dec 2016 8:20:33pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ComponentEdit.h"
#include "../ComponentModel.h"

//==============================================================================

ComponentEdit::ComponentEdit(ComponentController *model)
{
    s_model = model;
}

ComponentEdit::ComponentEdit()
{
    
}

ComponentEdit::~ComponentEdit()
{
}

void ComponentEdit::paint (Graphics& g)
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
    g.drawText ("ComponentEdit", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void ComponentEdit::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


