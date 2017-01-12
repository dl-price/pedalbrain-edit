/*
  ==============================================================================

    BoardModel.cpp
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardModel.h"
#include "BoardTypes/EpicBoardView.h"
#include "BoardTypes/EpicBoard.h"
#include "ComponentModel.h"
#include "ComponentEdit.h"

//==============================================================================
BoardModel *BoardModel::s_instance = 0;

BoardModel::BoardModel(BoardType *newType)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    pages = OwnedArray<PageModel>();
    
    boardType = newType;
    

}

void BoardModel::initFromNothing()
{
    boardType = new EpicBoard();
    
    for (int i=0; i < boardType->getMaxPages(); i++)
    {
        pages.add(new PageModel());
    }
}


/**
 Returns a pointer to the current BoardModel - up to one may exist at a time

 @return Current BoardModel
 */
BoardModel *BoardModel::getInstance()
{
    if(!s_instance)
    {
        s_instance = new BoardModel(new EpicBoard());
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
PedalView *BoardModel::createView()
{
    return pedalViews.add(boardType->createView());
}




void BoardModel::contextMenuFinished(int ModalResult, PedalViewComponent *component, PopupMenu *menu)
{
    
}



BoardModel::~BoardModel()
{
    
}




