/*
  ==============================================================================

    BoardTestController.cpp
    Created: 2 Jan 2017 7:33:38pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "BoardTestController.h"

BoardTestController::BoardTestController()
{
    
}

PedalView *BoardTestController::createPedalView()
{
    return new PedalView();
}

