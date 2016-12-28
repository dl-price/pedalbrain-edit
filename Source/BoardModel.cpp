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
    
    boardType = new EpicBoard();

}

BoardModel* BoardModel::getInstance()
{
    if(!s_instance)
    {
        s_instance = new BoardModel();
        Logger::outputDebugString("Loaded board model of type: " + s_instance->boardType->getName());
    }
    return s_instance;
}





/*BoardModel::~BoardModel()
{
}
*/



