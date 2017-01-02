/*
  ==============================================================================

    ComponentController.cpp
    Created: 28 Dec 2016 7:16:12pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"

//==============================================================================

ComponentController::ComponentController()
{
    
}

ComponentController::ComponentModel::ComponentModel(String name)
{
    s_typeName = name;
}

String ComponentController::ComponentModel::getTypeName() const
{
    return s_typeName;
}



String ComponentController::getComponentType()
{
    return _model->getTypeName();
}

void ComponentController::requestCloseEditWindow()
{
    if(editWindowCanClose())
    {
        closeEditWindow();
    }
}

bool ComponentController::editWindowCanClose()
{
    return true;
}

void ComponentController::closeEditWindow()
{
    delete _editComponent;
    delete _window;
}
