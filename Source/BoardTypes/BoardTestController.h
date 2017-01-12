/*
  ==============================================================================

    BoardTestController.h
    Created: 2 Jan 2017 7:33:38pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BOARDTESTCONTROLLER_H_INCLUDED
#define BOARDTESTCONTROLLER_H_INCLUDED

class BoardTestController;

#include "../BoardController.h"

class BoardTestController : BoardController
{
public:
    BoardTestController();
    
    PedalView *createPedalView() override;

    
};



#endif  // BOARDTESTCONTROLLER_H_INCLUDED
