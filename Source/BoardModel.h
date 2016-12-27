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
public:
    BoardModel();
    //~BoardModel();
    
    ReferenceCountedObjectPtr<BoardType> boardType;
    OwnedArray<PageModel> pages;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BoardModel)
};

class EpicBoard : public BoardType
{
public:

    int getMaxPages(){return 15;};
};


#endif  // BOARDMODEL_H_INCLUDED
