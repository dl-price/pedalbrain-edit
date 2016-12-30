/*
  ==============================================================================

    ComponentControllers.cpp
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/


#include "ComponentModels.h"

ComponentEdit *ComponentController::createEditWindow()
{
    return new ComponentEdit(this);
}

ComponentEdit *ButtonController::createEditWindow()
{
    return new ButtonEdit(this);
}

void ButtonController::saveFromEditWindow(ComponentEdit *window)
{
    delete window->getParentComponent();
}

PopupMenu *ButtonController::contextMenu()
{
    PopupMenu *newMenu = new PopupMenu();
    PopupMenu::Item newItem = PopupMenu::Item();
    newItem.text = "Menu";
    newItem.itemID = 1;
    
    
    
    PopupMenu::Item new2 = PopupMenu::Item(newItem);
    newItem.isTicked = true;
    
    new2.itemID = 2;
    newMenu->addItem(newItem);
    newMenu->addItem(new2);
    
    return newMenu;
}

void ButtonController::popupCompleted(int modalResult, juce::PopupMenu *popupMenu)
{
    Logger::outputDebugString(String(modalResult));

}

