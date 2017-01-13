/*
  ==============================================================================

    BoardController.h
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BoardController_H_INCLUDED
#define BoardController_H_INCLUDED

class BoardType;
class BoardController;
#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"
#include "PageModel.h"
#include "gui/PedalView.h"
#include "ComponentEdit.h"



//==============================================================================
/*
*/


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
    virtual PedalView *createView() = 0;
    virtual int getLedNumber(){return 0;};
    virtual int getButtonNumber(){return 0;};
    virtual int getLBNumber(){return 0;};
    virtual int getLCDNumber(){return 0;};
    virtual int getMaxComponents(){return 0;};

    
};

class BoardController
{
    
public:
    BoardController();
    BoardController(BoardType *newType);
    ~BoardController();
    
    BoardType *boardType;
    OwnedArray<PageModel> pages;
    OwnedArray<PedalView> pedalViews;
    PedalView *createView();
    static BoardController *getInstance();
    static BoardController *setInstance(BoardController *newBoard);
    virtual int getNumberOfButtons() {return 5;}
    virtual int getNumberOfPages() {return 5;}
    void initFromNothing();

    static void contextMenuFinished(int ModalResult, PedalViewComponent *component, PopupMenu *menu );
    virtual void createEditWindowForButton(ButtonModel *selectedButton);
    
protected:
    static BoardController *s_instance;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BoardController)
};






#endif  // BoardController_H_INCLUDED