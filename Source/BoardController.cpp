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
ReferenceCountedArray<BoardControllerListener> BoardController::listeners = ReferenceCountedArray<BoardControllerListener>();

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
    delete s_instance;
    s_instance = newBoard;
    Logger::outputDebugString(String(BoardController::listeners.size()));
    for(int i=0; i<BoardController::listeners.size();i++ )
    {
        BoardController::listeners[i]->boardControllerChanged();
    }
    return s_instance;
}


/**
 Returns a pointer to the current BoardController - up to one may exist at a time

 @return Current BoardController
 */
BoardController *BoardController::getInstance()
{

    return s_instance;
}

void BoardController::addListener(BoardControllerListener *newListener)
{
    listeners.add(newListener);
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

void BoardController::createEditWindowForButton(ButtonModel *selectedButton)
{
    Logger::outputDebugString("Button edit open");
}






