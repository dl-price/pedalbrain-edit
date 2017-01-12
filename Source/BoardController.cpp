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



