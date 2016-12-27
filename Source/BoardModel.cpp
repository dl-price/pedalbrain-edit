/*
  ==============================================================================

    BoardModel.cpp
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardModel.h"

//==============================================================================
BoardModel *BoardModel::s_instance = 0;

BoardModel::BoardModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    boardType = new EpicBoard();
    Logger::outputDebugString(String(boardType->getMaxDevices()));

}

BoardModel* BoardModel::instance()
{
    if(!s_instance)
        s_instance = new BoardModel();
    return s_instance;
}


/*BoardModel::~BoardModel()
{
}
*/



