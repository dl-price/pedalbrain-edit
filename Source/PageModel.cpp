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
PageModel::PageModel(int page)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setProperty("page", page);
    setProperty("name", String::empty);
    
    buttons = ReferenceCountedArray<ButtonModel>();
    
    buttons.ensureStorageAllocated(BoardController::getInstance()->getNumberOfButtons());
    
    for(int i=0;i < BoardController::getInstance()->getNumberOfButtons(); i++)
    {
        ButtonModel *btn = new ButtonModel(page, i);
        buttons.add(btn);
    }

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

void PageModel::setName(juce::String newName)
{
    setProperty("name", newName);
    BoardController::getInstance()->sysexHandler->sendPage(this);
}

void PageModel::updateFromJson(DynamicObject::Ptr obj)
{
    setProperty("name", obj->getProperty("name"));
    
}

void PageModel::sysexReceived(DynamicObject::Ptr obj)
{
    BoardController::getInstance()->pages[obj->getProperty("model").getDynamicObject()->getProperty("index")]->updateFromJson(obj->getProperty("model").getDynamicObject());
}
