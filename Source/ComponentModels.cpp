/*
  ==============================================================================

    ComponentModels.cpp
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/


#include "ComponentModels.h"

ComponentEdit *ComponentModel::createEditWindow()
{
    return new ComponentEdit(this);
}

ComponentEdit *ButtonModel::createEditWindow()
{
    return new ButtonEdit(this);
}

void ButtonModel::saveFromEditWindow(ComponentEdit *window)
{
    delete window->getParentComponent();
}

PopupMenu *ButtonModel::contextMenu()
{
    PopupMenu *newMenu = new PopupMenu();
    PopupMenu::Item newItem = PopupMenu::Item();
    newItem.text = "Menu";
    newItem.itemID = 1;
    
    newMenu->addItem(newItem);
    return newMenu;
}
