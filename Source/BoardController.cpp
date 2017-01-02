/*
  ==============================================================================

    BoardController.cpp
    Created: 2 Jan 2017 6:51:21pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "BoardController.h"

BoardController *BoardController::_instance = 0;

BoardController::BoardController()
{
    
}

BoardController *BoardController::getInstance()
{
    return BoardController::_instance;
}

BoardController *BoardController::setInstance(BoardController *newInstance)
{
    return BoardController::_instance = newInstance;
}

ResizableWindow *BoardController::createEditWindowAndAddToDesktop(ComponentModel *model)
{
    ResizableWindow *window = createEditWindowForModel(model);
    
    window->addToDesktop();
    window->setBounds(0, 0, 500, 500);
    
    return window;
}
ResizableWindow *BoardController::createEditWindowAndFillMainWindow(ComponentModel *model)
{
    ResizableWindow *window = createEditWindowForModel(model);
    
    TopLevelWindow::getActiveTopLevelWindow()->addAndMakeVisible(window);
    window->setBoundsConstrained(Rectangle<int>(0,0,window->getParentComponent()->getWidth(),window->getParentComponent()->getHeight()));
    
    return window;
}
ResizableWindow *BoardController::createEditWindowForModel(ComponentModel *model)
{
    ResizableWindow *window = new ResizableWindow("win", false);
    ComponentEdit *editComponent = createEditComponentForModel(model);
    window->setContentOwned(editComponent, true);
    return window;
}


