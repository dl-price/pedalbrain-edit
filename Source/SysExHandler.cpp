/*
  ==============================================================================

    SysExHandler.cpp
    Created: 17 Jan 2017 3:28:04pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "SysExHandler.h"
#include "../JuceLibraryCode/JuceHeader.h"

SysExHandler::SysExHandler()
{
    int i = MidiOutput::getDevices().indexOf("PBrain");
    usbOutput = MidiOutput::openDevice(i);
    
    i = MidiInput::getDevices().indexOf("PBrain");
    usbInput = MidiInput::openDevice(i, this);
    usbInput->start();
}

void SysExHandler::handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message)
{
    Logger::outputDebugString("Receive");
    if(message.isSysEx())
    {
        String newStr = String::fromUTF8( (char*)message.getSysExData());
        if(newStr.getCharPointer()[0]==(char)0x7D)
        {
            
        }
    }
}

void SysExHandler::sendPBSysex(String message)
{
    String newMessage = "}" + message;
    CharPointer_UTF8 charPnt = newMessage.getCharPointer();
    
    usbOutput->sendMessageNow(MidiMessage::createSysExMessage(charPnt, charPnt.sizeInBytes()));
}

void SysExHandler::sendSysEx(ReferenceCountedObjectPtr<DynamicObject> object)
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
