/*
  ==============================================================================

    ButtonModel.cpp
    Created: 13 Jan 2017 1:59:59am
    Author:  Daniel Price

  ==============================================================================
*/

#include "ButtonModel.h"
#include "BoardController.h"
#include "SysExHandler.h"
#include "PageModel.h"

ButtonModel::ButtonModel(PageModel *parentPage, int index) : _pageModel(parentPage), _index(index)
{
    _boardController = parentPage->getBoardController();
}

void ButtonModel::sendToBoard()
{
    ReferenceCountedObjectPtr< DynamicObject> message = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    message->setProperty("send", "button");
    message->setProperty("model", var(this));
    
    BoardController::getDefaultInstance()->sysexHandler->sendSysEx(message);
}

int ButtonModel::getIndex()
{
    return _index;
}
