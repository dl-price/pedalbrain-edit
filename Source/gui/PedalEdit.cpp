/*
  ==============================================================================

    PedalEdit.cpp
    Created: 26 Dec 2016 5:07:35pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes.h"
#include "Application.h"
#include "PedalEdit.h"
#include "GlobalTab.h"
#include "DevicesTab.h"

//==============================================================================
PedalEdit::PedalEdit()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    devicesTab = new DevicesTab();
    layoutTab = new LayoutTab();
    globalTab = new GlobalTab();
    
    addAndMakeVisible(superTabComponent = new TabbedComponent(TabbedButtonBar::Orientation::TabsAtTop));
    superTabComponent->addTab("Global", juce::Colours::blue, globalTab, false);
    superTabComponent->addTab("Devices", juce::Colours::green, devicesTab, false);
    superTabComponent->addTab("Layout", juce::Colours::blue, layoutTab, false);
    
    setSize(600,400);

}

PedalEdit::~PedalEdit()
{
    dynamic_cast<pedalbraineditApplication::MainWindow*>(ResizableWindow::getActiveTopLevelWindow())->setMenuBar(NULL);
}

void PedalEdit::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

}

void PedalEdit::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    superTabComponent->setBounds(10, 10, getWidth()-20, getHeight()-20);
    
    if(componentEditor)
    {
        //componentEditor->setBounds(0, 0, getWidth(), getHeight());
    }

}

StringArray PedalEdit::getMenuBarNames()
{
    const char* const names[] = { "File", "Transfer", 0 };

    return StringArray ((const char**) names);   
}

PopupMenu PedalEdit::getMenuForIndex(int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    
    if(topLevelMenuIndex==0 && menuName == "File")
    {
        ApplicationCommandManager *manager = dynamic_cast<pedalbraineditApplication*>(JUCEApplication::getInstance())->getCommandManager();
        menu.addCommandItem(manager, 0x2001);
        menu.addCommandItem(manager, pedalbraineditApplication::PedalBrainCommandTypes::loadProjectCmd);

        if(BoardController::getDefaultInstance())
        {
        menu.addCommandItem(manager, pedalbraineditApplication::PedalBrainCommandTypes::saveProjectCmd);
        
       
            menu.addCommandItem(manager, pedalbraineditApplication::PedalBrainCommandTypes::saveProjectAsCmd);
        }
        
    }
    if(topLevelMenuIndex==1)
    {
        ApplicationCommandManager *manager = dynamic_cast<pedalbraineditApplication*>(JUCEApplication::getInstance())->getCommandManager();
        menu.addCommandItem(manager, pedalbraineditApplication::PedalBrainCommandTypes::connectToBoardCmd);
    }
    
    
    
    return menu;
}

void PedalEdit::menuItemSelected(int menuItemID, int topLevelMenuIndex)
{
    
}


