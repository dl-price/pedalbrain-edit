/*
  ==============================================================================

    PedalView.cpp
    Created: 27 Dec 2016 9:43:51am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"
#include "../includes.h"

//==============================================================================
PedalView::PedalView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    layoutCells = OwnedArray<LayoutCell>();
    
    for(int i=1; i<=11;i++) {
        LayoutCell *newCell = new LayoutCell();
        layoutCells.add(newCell);
        addAndMakeVisible(newCell);
        
    }

}

PedalView::~PedalView()
{
}

void PedalView::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::black);
    g.fillRect (getLocalBounds());   // draw an outline around the component

}

void PedalView::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    for (int i = 0;i < layoutCells.size();i++) {
        switch(i) {
            case 0:
                layoutCells[i]->setBounds(0, 0, getWidth()/6*3/4, getHeight()/2);
                break;
            case 1:
                layoutCells[i]->setBounds(getWidth()/6*(i+1)+getWidth()/6/4, 0, getWidth()/6*3/4, getHeight()/2);
                break;
            case 2 ... 4:
                layoutCells[i]->setBounds(getWidth()/6*(i+1), 0, getWidth()/6, getHeight()/2);
                break;
            default:
                layoutCells[i]->setBounds(getWidth()/6*(i-5), getHeight()/2, getWidth()/6, getHeight()/2);
                
        }
        layoutCells[i]->features = BoardModel::getInstance()->boardType->getCellFeatures(i);
        
    }

}
