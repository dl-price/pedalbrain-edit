/*
  ==============================================================================

    PageModel.h
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PAGEMODEL_H_INCLUDED
#define PAGEMODEL_H_INCLUDED

//#include "BoardController.h"

#include "../JuceLibraryCode/JuceHeader.h"
class PageModel;
#include "CellModel.h"
#include "ButtonModel.h"
#include "SysExObject.h"
#include "BoardController.h"


//==============================================================================
/*
*/


class PageModel : public ReferenceCountedObject, SysExObject, Value::Listener
{
public:
    PageModel(BoardController *controller, int page);
    ~PageModel();
    OwnedArray<ButtonModel> buttons;
    void updateFromJson(DynamicObject::Ptr obj);
    static PageModel *createBlankPage();
    void initFromNothing();
    Value &getName(){return _name;};
    static void sysexReceived(DynamicObject::Ptr obj);
    void sendSysex();
    void updated();
    DynamicObject::Ptr toJson() override;
    int getIndex() { return _index; };
    int getPageNo() { return _index+1;};
    void valueChanged(Value &value) override;
    BoardController *getBoardController();
    void saveToFile();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageModel)
    Value _name;
    int _index;
    BoardController *_boardController;
};


#endif  // PAGEMODEL_H_INCLUDED
