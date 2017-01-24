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

DynamicObject::Ptr ButtonModel::toJson()
{
    DynamicObject::Ptr obj = new DynamicObject();
    obj->setProperty("index", _index);
    obj->setProperty("name", name.getValue());
    obj->setProperty("label", label.getValue());
    obj->setProperty("ledOn", ledOn.getValue());
    obj->setProperty("ledOff", ledOff.getValue());
    obj->setProperty("type", buttonType.getValue());
    
    return obj;
}
void ButtonModel::updateFromJson(DynamicObject::Ptr obj)
{
    name.setValue(obj->getProperty("name"));
    label.setValue(obj->getProperty("label"));
    ledOn.setValue(obj->getProperty("ledOn"));
    ledOff.setValue(obj->getProperty("ledOff"));
    buttonType.setValue(obj->getProperty("type"));
}

File ButtonModel::getFile()
{
    File file = _boardController->getProjectDirectory().getChildFile("buttons/p" + String(_pageModel->getIndex()) + "/" + String(_index) + ".txt");
    file.getParentDirectory().createDirectory();
    return file;
}



