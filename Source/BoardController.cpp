/*
  ==============================================================================

    BoardController.cpp
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardController.h"
#include "BoardTypes/EpicBoardView.h"
#include "BoardTypes/EpicBoard.h"
#include "ComponentModel.h"
#include "ComponentEdit.h"

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
    for (int i=0; i < getNumberOfPages(); i++)
    {
        PageModel *newPage = new PageModel();
        newPage->initFromNothing();
        pages.add(newPage);
    }
}

BoardController *BoardController::setInstance(BoardController *newBoard)
{
    return s_instance = newBoard;
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




void BoardController::contextMenuFinished(int ModalResult, PedalViewComponent *component, PopupMenu *menu)
{
    
}

BoardController::BoardController()
{
    pages = OwnedArray<PageModel>();
}

BoardController::~BoardController()
{
    
}






