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


//==============================================================================
/*
*/


class PageModel : public DynamicObject
{
public:
    PageModel(int page);
    ~PageModel();
    ReferenceCountedArray<ButtonModel> buttons;
    void updateFromJson(DynamicObject::Ptr obj);
    static PageModel *createBlankPage();
    void initFromNothing();
    void setName(String newName);
    String getName(){return getProperty("name");};
    static void sysexReceived(DynamicObject::Ptr obj);
    void sendSysex();
    void updated();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageModel)
};


#endif  // PAGEMODEL_H_INCLUDED
