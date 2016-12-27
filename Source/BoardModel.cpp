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
BoardModel::BoardModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    ReferenceCountedObjectPtr<BoardType> boardType = new EpicBoard();
    //Logger::outputDebugString(String(boardType->getPages()));
}

/*BoardModel::~BoardModel()
{
}
*/



