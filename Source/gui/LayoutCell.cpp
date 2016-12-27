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
//#include "../Main.cpp"

//==============================================================================
LayoutCell::LayoutCell()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    addAndMakeVisible(label = new Label());
    label->setText("Label", NotificationType::dontSendNotification);
    label->setColour(Label::ColourIds::textColourId, Colours::white);

    cellEdit = new CellEdit();
    
    //cellEdit->setAlpha(0);
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


    g.setColour (Colours::red);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    
}

void LayoutCell::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    label->setBounds(0, 0, getWidth(), 24);
    
    cellEdit->setBounds(0, 0, TopLevelWindow::getTopLevelWindow(0)->getWidth(), TopLevelWindow::getTopLevelWindow(0)->getHeight());
    

}

void LayoutCell::mouseUp(const juce::MouseEvent &event) {
    Logger::outputDebugString("Poked " + String(event.mods.isPopupMenu()));
}

void LayoutCell::mouseDoubleClick(const juce::MouseEvent &event) {
    Logger::outputDebugString("Double click");
    
    cellEdit->setBounds(TopLevelWindow::getTopLevelWindow(0)->getWidth(), TopLevelWindow::getTopLevelWindow(0)->getHeight(),TopLevelWindow::getTopLevelWindow(0)->getWidth(), TopLevelWindow::getTopLevelWindow(0)->getHeight());
    TopLevelWindow::getActiveTopLevelWindow()->addAndMakeVisible(cellEdit);
    Desktop::getInstance().getAnimator().animateComponent(cellEdit, Rectangle<int>(0, 0, TopLevelWindow::getTopLevelWindow(0)->getWidth(), TopLevelWindow::getTopLevelWindow(0)->getHeight()), 1, 300, false, 1, 1 ) ;
    
}
