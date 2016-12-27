/*
  ==============================================================================

    BoardModel.h
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BOARDMODEL_H_INCLUDED
#define BOARDMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"

//==============================================================================
/*
*/
class BoardType : public ReferenceCountedObject
{
public:

    virtual int getMaxPages(){return 1;};
    virtual int getMaxDevices(){return 8;};
};

class BoardModel : public ReferenceCountedObject
{
    static BoardModel *s_instance;
public:
    BoardModel();
    //~BoardModel();
    
    ReferenceCountedObjectPtr<BoardType> boardType;
    OwnedArray<PageModel> pages;
    static BoardModel *getInstance();
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BoardModel)
};

class EpicBoard : public BoardType
{
public:
    //EpicBoard();
    int getMaxPages(){return 15;};
    int getMaxDevices(){return 16;};
};


#endif  // BOARDMODEL_H_INCLUDED
