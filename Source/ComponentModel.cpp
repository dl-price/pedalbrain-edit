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

ResizableWindow *ComponentController::createEditWindow()
{
    ResizableWindow *window = new ResizableWindow("win", true);
    window->setContentOwned(createEditComponent(), true);
    return window;
}

void ComponentController::createEditWindowAndFillMainWindow()
{
    _window = createEditWindow();
    
    TopLevelWindow::getActiveTopLevelWindow()->addAndMakeVisible(_window);
    _window->setBoundsConstrained(Rectangle<int>(0,0,_window->getParentComponent()->getWidth(),_window->getParentComponent()->getHeight()));
}


/*LedModel::LedModel()
{
    type = "Led";
}*/

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
    delete _window;
}
