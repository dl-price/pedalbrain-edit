/*
  ==============================================================================

    EpicBoard.cpp
    Created: 28 Dec 2016 12:54:55am
    Author:  Daniel Price

  ==============================================================================
*/

#include "EpicBoard.h"

PedalView *EpicBoard::createView()
{
    return new EpicBoardView();
}

BoardType::CellFeatures EpicBoard::getCellFeatures(int cell) {
    if (cell==0)
    {
        return BoardType::CellFeatures::Lcd;
    }
    else if (cell<3)
    {
        return BoardType::CellFeatures::Switch;
    }
    else if (cell<8)
    {
        return BoardType::CellFeatures::RgbLed;
    }
    
    return BoardType::CellFeatures::None;
}