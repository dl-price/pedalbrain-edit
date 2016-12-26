/*
  ==============================================================================

    PedalEdit.cpp
    Created: 26 Dec 2016 5:07:35pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalEdit.h"

//==============================================================================
PedalEdit::PedalEdit()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setSize(600,400);

}

PedalEdit::~PedalEdit()
{
}

void PedalEdit::paint (Graphics& g)
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
    g.drawText ("PedalEdit", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void PedalEdit::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

StringArray PedalEdit::getMenuBarNames()
{
    const char* const names[] = { "File", "Transfer", 0 };

    return StringArray ((const char**) names);   
}

PopupMenu PedalEdit::getMenuForIndex(int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    
    return menu;
}

void PedalEdit::menuItemSelected(int menuItemID, int topLevelMenuIndex)
{
    
}
