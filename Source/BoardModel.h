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
#include "gui/PedalView.h"

//==============================================================================
/*
*/
class LedModel : public ReferenceCountedObject
{
    
};

class ButtonModel : public ReferenceCountedObject
{
    
};

class BoardType : public ReferenceCountedObject
{
public:
    enum CellFeatures {
        None = 0,
        Led = 1<<0,
        RgbLed = 1<<1,
        Lcd = 1<<2,
        Switch = 1<<3
    };
    virtual String getName() = 0;
    virtual int getMaxPages(){return 1;};
    virtual int getMaxDevices(){return 8;};
    virtual int getCellNumber(){return 0;};
    virtual CellFeatures getCellFeatures(int cell) {return CellFeatures::None ;};
    virtual PedalView *createView() = 0;
    virtual int getLedNumber() = 0;
    virtual int getButtonNumber() = 0;
    virtual int getLBNumber() = 0;
    
};

class BoardModel
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




#endif  // BOARDMODEL_H_INCLUDED
