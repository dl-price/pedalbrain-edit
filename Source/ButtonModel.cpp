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

ButtonModel::ButtonModel(int page, int index)
{
    setProperty("page", page);
    setProperty("index'", index);
}

void ButtonModel::sendToBoard()
{
    ReferenceCountedObjectPtr< DynamicObject> message = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    message->setProperty("send", "button");
    message->setProperty("model", var(this));
    
    BoardController::getInstance()->sysexHandler->sendSysEx(message);
}
