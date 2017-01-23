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


//==============================================================================
/*
*/


class PageModel : public ReferenceCountedObject, SysExObject, Value::Listener
{
public:
    PageModel(int page);
    ~PageModel();
    ReferenceCountedArray<ButtonModel> buttons;
    void updateFromJson(DynamicObject::Ptr obj);
    static PageModel *createBlankPage();
    void initFromNothing();
    Value getName(){return _name;};
    static void sysexReceived(DynamicObject::Ptr obj);
    void sendSysex();
    void updated();
    DynamicObject::Ptr toJson() override;
    int getIndex() { return _index; };
    int getPageNo() { return _index+1;};
    void valueChanged(Value &value) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageModel)
    Value _name;
    const int _index;
};


#endif  // PAGEMODEL_H_INCLUDED
