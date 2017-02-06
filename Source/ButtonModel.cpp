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
#include "Macros.h"

ButtonModel::ButtonModel(PageModel *parentPage, int index) : _pageModel(parentPage), _index(index)
{
    _boardController = parentPage->getBoardController();
    
    ledOn.addListener(this);
    ledOff.addListener(this);
    
    _onColor = new Value();
    _offColor = new Value();
    
    ledOn.setValue((int)LedColor::White);
    ledOff.setValue((int)LedColor::Black);
    buttonType.setValue(ButtonType::Off);
    label.setValue(String::empty);
    name.setValue(String::empty);
}

void ButtonModel::sendToBoard()
{
    ReferenceCountedObjectPtr< DynamicObject> message = clone();
    
    message->setProperty("send", "button");
    message->setProperty("model", var(toJson()));
    
    BoardController::getDefaultInstance()->sysexHandler->sendSysEx(message);
}

int ButtonModel::getIndex()
{
    return _index;
}

DynamicObject::Ptr ButtonModel::toJson()
{
    DynamicObject::Ptr obj = clone();
    obj->setProperty("pageIndex", _pageModel->getIndex());
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
    NamedValueSet values = obj->getProperties();
    for(int i=0; i < values.size(); i++)
    {
        // List of property names not to copy into object (they are handled later on)
        String tmpName = values.getName(i).toString();
        if(!(tmpName == "name" ||
             tmpName == "label" ||
             tmpName == "ledOn" ||
             tmpName == "ledOff" ||
             tmpName == "type"))
        {
            setProperty(tmpName, values.getValueAt(i));
        }
    }
    // Handle properties that need to be dealt with differently than just copying values into DynamicObject
    Logger::outputDebugString(obj->getProperty("name"));
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

void ButtonModel::valueChanged(juce::Value &value)
{
    if(value.refersToSameSourceAs(ledOn))
    {
        _onColor->setValue(convertColorToString((ButtonModel::LedColor)(int)ledOn.getValue()));
    }
    if(value.refersToSameSourceAs(ledOff))
    {
        _offColor->setValue(convertColorToString((ButtonModel::LedColor)(int)ledOff.getValue()));
    }
}

String ButtonModel::convertColorToString(ButtonModel::LedColor color)
{
    Colour newColor;
    if(color == LedColor::Black)
    {
        newColor = Colours::black;
    }
    else if (color==LedColor::Blue)
    {
        newColor = Colours::blue;
    }
    else if (color == LedColor::Red)
    {
        newColor = Colours::red;
    }
    else if(color ==  LedColor::Cyan)
    {
        newColor = Colours::cyan;
    }
    else if(color== LedColor::Green)
    {
        newColor = Colours::green;
    }
    else if(color == LedColor::Purple)
    {
        newColor = Colours::purple;
    }
    else if(color == LedColor::White)
    {
        newColor = Colours::white;
    }
    else if(color == LedColor::Yellow)
    {
        newColor = Colours::yellow;
    }
    
    return newColor.toString();
}

void ButtonModel::sysexReceived(DynamicObject::Ptr obj)
{
    if(obj->getProperty("send") == "buttonState")
    {
        OwnedArray<Value> *page = appObject->getDefaultBoardController()->buttonStates[obj->getProperty("pageIndex")];
        Value *btn = page->getUnchecked(obj->getProperty("buttonIndex"));
        btn->setValue(obj->getProperty("state"));
        
        
    }
    if(obj->hasProperty("model"))
    {
    DynamicObject::Ptr obj2 = obj->getProperty("model").getDynamicObject() ;
    
    PageModel *page = BoardController::getDefaultInstance()->pages[obj2->getProperty("pageIndex")];
    ButtonModel *btn = page->buttons[obj2->getProperty("index")];
    btn->updateFromJson(obj2);
    }
    
}

void ButtonModel::sendDownToBoard()
{
    ReferenceCountedObjectPtr< DynamicObject> message = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    message->setProperty("send", "buttonState");
    message->setProperty("pageIndex", _pageModel->getIndex());
    message->setProperty("buttonIndex", _index);
    message->setProperty("state", true);
    
    BoardController::getDefaultInstance()->sysexHandler->sendSysEx(message);
}

void ButtonModel::sendUpToBoard()
{
    ReferenceCountedObjectPtr< DynamicObject> message = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    message->setProperty("send", "buttonState");
    message->setProperty("pageIndex", _pageModel->getIndex());
    message->setProperty("buttonIndex", _index);
    message->setProperty("state", false);
    
    BoardController::getDefaultInstance()->sysexHandler->sendSysEx(message);
}



