/*
  ==============================================================================

    LayoutCell.cpp
    Created: 27 Dec 2016 6:13:24am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes.h"
#include "LayoutCell.h"

//==============================================================================
LayoutCell::LayoutCell()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

LayoutCell::~LayoutCell()
{
}

void LayoutCell::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::red);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("LayoutCell", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
    
    Logger::outputDebugString("paint");
}

void LayoutCell::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void LayoutCell::mouseUp(const juce::MouseEvent &event) {
    Logger::outputDebugString("Poked " + String(event.getNumberOfClicks()));
}
