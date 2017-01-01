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
    ResizableWindow *window = new ResizableWindow("win", false);
    _editComponent = createEditComponent();
    window->setContentOwned(_editComponent, true);
    updateEditComponentFromModel();
    return window;
}

void ComponentController::createEditWindowAndFillMainWindow()
{
    _window = createEditWindow();
    
    TopLevelWindow::getActiveTopLevelWindow()->addAndMakeVisible(_window);
    _window->setBoundsConstrained(Rectangle<int>(0,0,_window->getParentComponent()->getWidth(),_window->getParentComponent()->getHeight()));
}

void ComponentController::createEditWindowAndAddToDesktop()
{
    _window = createEditWindow();
    
    _window->addToDesktop();
    _window->setBounds(0, 0, 500, 500);
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
