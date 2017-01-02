/*
  ==============================================================================

    ComponentControllers.cpp
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/


#include "ComponentModels.h"



ComponentEdit *ButtonController::createEditComponent()
{
    return new ButtonEdit(this);
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



ButtonController::ButtonController() : ComponentController()
{
    _model = new ButtonController::ButtonModel();
}

ButtonController::ButtonModel::ButtonModel() : ComponentModel("Button")
{
    _type = Type::None;
    _actions = OwnedArray<Action>();
}

void ButtonController::updateEditComponentFromModel()
{
    ButtonEdit *cComponent = dynamic_cast<ButtonEdit*>(_editComponent);
    switch(getModel()->_type)
    {
        case ButtonController::ButtonModel::Type::None:
            cComponent->selectType(2);
    }

}

ButtonController::ButtonModel *ButtonController::getModel()
{
    return dynamic_cast<ButtonModel*>( _model);
}
