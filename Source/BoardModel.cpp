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

//==============================================================================
BoardModel *BoardModel::s_instance = 0;

BoardModel::BoardModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    pages = OwnedArray<PageModel>();
    
    
    int yes = pages.size();
    
    boardType = new EpicBoard();
    
    for (int i=0; i < boardType->getMaxPages(); i++)
    {
        pages.add(new PageModel());
    }

}

BoardModel* BoardModel::getInstance()
{
    if(!s_instance)
    {
        s_instance = new BoardModel();
        Logger::outputDebugString("Loaded board model of type: " + s_instance->boardType->getName());
        Logger::outputDebugString("Board has: " + String(s_instance->boardType->getLBNumber()) + " LED/button pairs");
        Logger::outputDebugString("Board had: " + String(s_instance->boardType->getLCDNumber()) + " LCD screens");
    }
    return s_instance;
}





/*BoardModel::~BoardModel()
{
}
*/



