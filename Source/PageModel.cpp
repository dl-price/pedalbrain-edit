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
#include "Macros.h"

//==============================================================================
PageModel::PageModel(BoardController *controller, int page) : _index(page-1),  _boardController(controller)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    _name.setValue(var(String::empty));
    
    buttons.ensureStorageAllocated(_boardController->getNumberOfButtons());
    
    for(int i=0;i < _boardController->getNumberOfButtons(); i++)
    {
        ButtonModel *btn = new ButtonModel(this, i);
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
    BoardController::getDefaultInstance()->pages[obj->getProperty("model").getDynamicObject()->getProperty("index")]->updateFromJson(obj->getProperty("model").getDynamicObject());
}

void PageModel::updated()
{
    sendSysex();
}

void PageModel::sendSysex()
{
    if(appObject->getDefaultBoardController()->sysexHandler)
    {
        BoardController::getDefaultInstance()->sysexHandler->sendPage(this);
    }
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

BoardController *PageModel::getBoardController()
{
    return _boardController;
}

File PageModel::getFile()
{
    return _boardController->getProjectDirectory().getChildFile("pages/" + (String)getIndex() + ".txt");
}

