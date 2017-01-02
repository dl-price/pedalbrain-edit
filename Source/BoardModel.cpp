/*
  ==============================================================================

    BoardController.cpp
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardModel.h"
#include "BoardTypes/EpicBoardView.h"
#include "BoardTypes/EpicBoard.h"
#include "ComponentModel.h"

//==============================================================================
BoardController *BoardController::s_instance = 0;

BoardController::BoardController(BoardType *newType)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    pages = OwnedArray<PageModel>();
    
    boardType = newType;
    

}

void BoardController::initFromNothing()
{
    boardType = new EpicBoard();
    
    for (int i=0; i < boardType->getMaxPages(); i++)
    {
        pages.add(new PageModel());
    }
}


/**
 Returns a pointer to the current BoardController - up to one may exist at a time

 @return Current BoardController
 */
BoardController *BoardController::getInstance()
{
    if(!s_instance)
    {
        s_instance = new BoardController(new EpicBoard());
        s_instance->initFromNothing();
        Logger::outputDebugString("Loaded board model of type: " + s_instance->boardType->getName());
        Logger::outputDebugString("Board has: " + String(s_instance->boardType->getLBNumber()) + " LED/button pairs");
        Logger::outputDebugString("Board had: " + String(s_instance->boardType->getLCDNumber()) + " LCD screens");
        
        for (int i = 0; i < s_instance->pages[0]->components.size(); i++)
        {
            Logger::outputDebugString(s_instance->pages[0]->components[i]->getComponentType());
        }
    }
    return s_instance;
}


/**
 Creates a PedalView subclass designated by the current Board Type and adds it to the Controller's list of views to manage

 @return The created view
 */
PedalView *BoardController::createView()
{
    return pedalViews.add(boardType->createView());
}

void BoardController::mouseDoubleClick(const MouseEvent &event)
{
    //createEditWindowForComponent(pages[0]->components[0]->_model);
}

void BoardController::mouseDown(const MouseEvent &event)
{
    if(event.mods.isPopupMenu())
    {
        //ComponentController *newButton = BoardController::getInstance()->pages[0]->components[idRef] ;
        
        /*PopupMenu *newContext = dynamic_cast<PedalViewComponent*>(event.eventComponent)->contextMenu();
        
        newContext->showMenuAsync(PopupMenu::Options().withTargetComponent(event.eventComponent), ModalCallbackFunction::withParam( contextMenuFinished, event.eventComponent, newContext));*/
        
    }
    
}

void BoardController::contextMenuFinished(int ModalResult, PedalViewComponent *component, PopupMenu *menu)
{
    
}

void BoardController::createEditWindowAndAddToDesktop(ComponentModel *model)
{
    ResizableWindow *window = createEditWindowForComponent(model);
    
    window->addToDesktop();
    window->setBounds(0, 0, 500, 500);
}
void BoardController::createEditWindowAndFillMainWindow(ComponentModel *model)
{
    ResizableWindow *window = createEditWindowForComponent(model);
    
    TopLevelWindow::getActiveTopLevelWindow()->addAndMakeVisible(window);
    window->setBoundsConstrained(Rectangle<int>(0,0,window->getParentComponent()->getWidth(),window->getParentComponent()->getHeight()));
}
ResizableWindow *BoardController::createEditWindowForComponent(ComponentModel *model)
{
    ResizableWindow *window = new ResizableWindow("win", false);
    PedalViewComponent *editComponent = new PedalViewComponent();
    window->setContentOwned(editComponent, true);
    return window;
}

BoardController::~BoardController()
{
    
}




