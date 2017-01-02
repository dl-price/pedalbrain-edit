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
    
    /*layoutCells = OwnedArray<LayoutCell>();
    
    for(int i=1; i<=11;i++) {
        LayoutCell *newCell = new LayoutCell();
        layoutCells.add(newCell);
        addAndMakeVisible(newCell);
        
    }*/

}

PedalView::~PedalView()
{
}

int PedalView::getPage()
{
    return viewingPage;
}

void PedalView::setPage(int i) {
    viewingPage = i;
    Logger::outputDebugString(String(viewingPage));
}

void PedalView::paint (Graphics& g)
{
    g.setColour (Colours::black);
    g.fillRect (getLocalBounds());   // draw an outline around the component

}

void PedalView::resized()
{

}

void PedalView::componentDoubleClicked(PedalViewComponent *component, const MouseEvent &event)
{
    BoardController::getInstance()->pages[0]->components[component->idRef]->createEditWindowAndFillMainWindow() ;
}
