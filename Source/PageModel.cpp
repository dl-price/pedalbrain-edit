/*
  ==============================================================================

    PageModel.cpp
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"

//==============================================================================
PageModel::PageModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PageModel::~PageModel()
{
}

void PageModel::paint (Graphics& g)
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
    g.drawText ("PageModel", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void PageModel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
