/*
  ==============================================================================

    EpicBoard.h
    Created: 28 Dec 2016 12:54:55am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef EPICBOARD_H_INCLUDED
#define EPICBOARD_H_INCLUDED

#include "../BoardModel.h"
#include "EpicBoardView.h"

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
    
};



#endif  // EPICBOARD_H_INCLUDED
