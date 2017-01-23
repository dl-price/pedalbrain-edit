/*
  ==============================================================================

    PageModel.cpp
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"
#include "BoardController.h"

//==============================================================================
PageModel::PageModel(int page) : _index(page-1)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    _name.setValue(var(String::empty));
    
    buttons = ReferenceCountedArray<ButtonModel>();
    
    buttons.ensureStorageAllocated(BoardController::getInstance()->getNumberOfButtons());
    
    for(int i=0;i < BoardController::getInstance()->getNumberOfButtons(); i++)
    {
        ButtonModel *btn = new ButtonModel(page, i);
        buttons.add(btn);
    }

    _name.addListener(this);
}

PageModel::~PageModel()
{
}

PageModel *PageModel::createBlankPage()
{
    //PageModel *newModel = new PageModel();
    
    return NULL;
}

void PageModel::initFromNothing()
{
    /*for (int i = 0; i< 10;i++)
    {
        buttons.add(new ButtonModel);
    }*/
}



void PageModel::updateFromJson(DynamicObject::Ptr obj)
{
    _name.setValue(obj->getProperty("name"));

    
}

void PageModel::sysexReceived(DynamicObject::Ptr obj)
{
    BoardController::getInstance()->pages[obj->getProperty("model").getDynamicObject()->getProperty("index")]->updateFromJson(obj->getProperty("model").getDynamicObject());
}

void PageModel::updated()
{
    sendSysex();
}

void PageModel::sendSysex()
{
    BoardController::getInstance()->sysexHandler->sendPage(this);
}

DynamicObject::Ptr PageModel::toJson()
{
    DynamicObject::Ptr obj = new DynamicObject();
    obj->setProperty("index", _index);
    obj->setProperty("page", _index+1);
    obj->setProperty("name", _name.getValue());
    
    return obj;
}

void PageModel::valueChanged(juce::Value &value)
{
    sendSysex();
}
