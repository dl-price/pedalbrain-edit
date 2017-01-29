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
public:
    EpicBoardController();
    const String boardModel = "TestBoardA";
    const int getNumberOfButtons() override {return 11;}
    const int getNumberOfPages() override {return 15;};
    PedalView *createView() override;
    //void initFromNothing() override { BoardController::initFromNothing();};
};





#endif  // EPICBOARD_H_INCLUDED
