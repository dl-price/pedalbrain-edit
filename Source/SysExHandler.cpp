/*
  ==============================================================================

    SysExHandler.cpp
    Created: 17 Jan 2017 3:28:04pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "SysExHandler.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardController.h"

SysExHandler::SysExHandler()
{
    int i = MidiOutput::getDevices().indexOf("PBrain");
    usbOutput = MidiOutput::openDevice(i);
    
    i = MidiInput::getDevices().indexOf("PBrain");
    usbInput = MidiInput::openDevice(i, this);
    usbInput->start();
}

SysExHandler::SysExHandler(MidiInputCallback *newCallback)
{
    int i = MidiOutput::getDevices().indexOf("PBrain");
    usbOutput = MidiOutput::openDevice(i);
    
    i = MidiInput::getDevices().indexOf("PBrain");
    usbInput = MidiInput::openDevice(i, newCallback);
    usbInput->start();
}

void SysExHandler::handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message)
{
    if(message.isSysEx())
    {
        String newStr = String::fromUTF8( (char*)message.getSysExData());
        if(newStr.getCharPointer()[0]==(char)0x7D)
        {
            String str = newStr.substring(1);
            var jsonReceived = JSON::parse(str);
            DynamicObject *objReceived = jsonReceived.getDynamicObject();
            if(objReceived)
            {
                sysexReceived(objReceived);
            }
        }
    }
}

void SysExHandler::sysexReceived(DynamicObject::Ptr objReceived)
{
    const MessageManagerLock mmlock;
    String send;
    if (objReceived->hasProperty("send"))
    {
        send = objReceived->getProperty("send");
        if(send == "boardInfo")
        {
            boardInfo.model = objReceived->getProperty("model");
            boardInfo.version = objReceived->getProperty("version");
            boardInfo.name = objReceived->getProperty("name");
            
            Logger::outputDebugString("Found " + boardInfo.name + " of model: " + boardInfo.model);
            Logger::outputDebugString("Firmware version: " + String(boardInfo.version));
            Logger::outputDebugString("Attempting to connect");
            BoardController::tryConnectToUsb(this);
            
        }
        else if(send == "solidified")
        {
            _isSolidified = true;
            Logger::outputDebugString("Connection solidified");
        }
        else if(send == "page")
        {
            PageModel::sysexReceived(objReceived);
        }
        else if(send == "device")
        {
            Device::sysexReceived(objReceived);
        }
    }
    
}

void SysExHandler::sendPBSysex(String message)
{
    String newMessage = "}" + message;
    CharPointer_UTF8 charPnt = newMessage.getCharPointer();
    
    usbOutput->sendMessageNow(MidiMessage::createSysExMessage(charPnt, charPnt.sizeInBytes()));
}

void SysExHandler::sendSysEx(DynamicObject *object)
{
    String newMessage = '}' + JSON::toString(var(object));
    
    CharPointer_UTF8 charPnt = newMessage.getCharPointer();
    
    
    usbOutput->sendMessageNow(MidiMessage::createSysExMessage(charPnt, charPnt.sizeInBytes()));
    
    
}

bool SysExHandler::boardAttached()
{
    return (MidiOutput::getDevices().contains("PBrain") && MidiInput::getDevices().contains("PBrain"));
}

void SysExHandler::requestBoardInfo()
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    obj->setProperty("request", "boardInfo");
    sendSysEx(obj);
    /*sendPBSysex('0' + String::toHexString(MessageType::RequestBoardInfo) + '0' + String::toHexString(RequestBoardInfoMessages::Name));
    sendPBSysex('0' + String::toHexString(MessageType::RequestBoardInfo) + '0' + String::toHexString(RequestBoardInfoMessages::Type));
    sendPBSysex('0' + String::toHexString(MessageType::RequestBoardInfo) + '0' + String::toHexString(RequestBoardInfoMessages::Version));*/

}

void SysExHandler::solidfyConnection()
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    obj->setProperty("request", "solidify");
    sendSysEx(obj);
}

bool SysExHandler::isSolidified()
{
    return _isSolidified;
}

void SysExHandler::sendDevice(ReferenceCountedObjectPtr<Device> device)
{
    int index = BoardController::getInstance()->devices.indexOf(device);
    
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    obj->setProperty("send", "device");
    
    DynamicObject::Ptr json = device->toJson();
    
    jassert((int)json->getProperty("index") == index);
    
    obj->setProperty("model", var(json));
    
    
    sendSysEx(obj);
}

void SysExHandler::sendPage(PageModel *page)
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    obj->setProperty("send", "page");
    obj->setProperty("model", var(page));
    sendSysEx(obj);
}

void SysExHandler::requestAllParameters()
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    obj->setProperty("request", "allParameters");
    
    sendSysEx(obj);
}
