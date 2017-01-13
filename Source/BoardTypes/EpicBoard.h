/*
  ==============================================================================

    EpicBoard.h
    Created: 28 Dec 2016 12:54:55am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef EPICBOARD_H_INCLUDED
#define EPICBOARD_H_INCLUDED

#include "../BoardController.h"
#include "EpicBoardView.h"
#include "../ComponentModel.h"
#include "../ComponentModels.h"


class EpicBoard : public BoardType
{
public:
    //EpicBoard();
    String getName(){return "Epic Board";};
    int getMaxPages(){return 15;};
    int getMaxDevices(){return 16;};
    int getCellNumber(){return 12;};
    CellFeatures getCellFeatures(int cell);
    PedalView *createView();
    int getLedNumber(){return 11;};
    int getButtonNumber(){return 11;};
    int getLBNumber(){return 11;};
    int getLCDNumber(){return 1;};

    
};

class EpicBoardController : public BoardController
{
    int getNumberOfButtons() override {return 10;}
};





#endif  // EPICBOARD_H_INCLUDED
