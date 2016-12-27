/*
  ==============================================================================

    LayoutTab.cpp
    Created: 27 Dec 2016 6:02:00am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes.h"
#include "LayoutTab.h"

//==============================================================================
LayoutTab::LayoutTab()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    addAndMakeVisible(pageUpButton = new TextButton());
    pageUpButton->setButtonText("Page Up");
    
    addAndMakeVisible(pageDownButton = new TextButton() );
    //TextButton *child = static_cast<TextButton*>(pageDownButton.get());
    pageDownButton->setButtonText("Page Down");
    
    
    addAndMakeVisible(pageCombo = new ComboBox());
    
    for(int i = 1; i <= 16;i++) {
        pageCombo->addItem(String(i), i);
    }
    
    //pageCombo->addListener(this);
    
    
    addAndMakeVisible(pageNameLabel = new Label() );
    pageNameLabel->setText("Page Name", NotificationType::dontSendNotification);
    
    addAndMakeVisible(pageNameEditor = new TextEditor());
    
    layoutCells = OwnedArray<LayoutCell>();
    
    for(int i=1; i<=5;i++) {
        LayoutCell *newCell = new LayoutCell();
        layoutCells.add(newCell);
        addAndMakeVisible(newCell);
        
    }

}

LayoutTab::~LayoutTab()
{
}

void LayoutTab::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::azure);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    int drawWidth = getWidth() - 40;
    
    int drawHeight = getHeight() * 0.8;
    
    int drawY = (getHeight() - drawHeight)/2;
    
    g.setColour(juce::Colours::black);
    g.fillRect(Rectangle<int>(20,drawY,drawWidth,drawHeight));
    
    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("LayoutTab", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void LayoutTab::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    pageDownButton->setBounds(20, 20, 40, 24);
    pageCombo->setBounds(100, 20, 100, 24);
    pageUpButton->setBounds(pageCombo->getX()+pageCombo->getWidth()+20, 20, 40, 24);
    pageNameLabel->setBounds(pageUpButton->getX()+pageUpButton->getWidth()+20, 20, 100, 24);
    pageNameEditor->setBounds(pageNameLabel->getX()+pageNameLabel->getWidth()+20, 20, 200, 24);

    for (int i = 0;i < layoutCells.size();i++) {
        layoutCells[i]->setBounds(40+100*i, 100*i, 100, 100);
    }

}
