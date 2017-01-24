/*
  ==============================================================================

    Device.cpp
    Created: 26 Dec 2016 8:52:49pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "includes.h"
#include "Device.h"
#include "BoardController.h"
#include "Macros.h"

//==============================================================================
Device::Device() : saveTimer(this)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    _name.setValue(String::empty);
    _channel.setValue(1);
    _name.addListener(this);
    _channel.addListener(this);
    _deviceType = DeviceManager::getInstance()->deviceTypes[0];
    
    

    
}

Device::~Device()
{
}

Manufacturer::Manufacturer()
{
    name = "";
    //deviceTypes = OwnedArray<DeviceType>();
}

Manufacturer::Manufacturer(String newName)
{
    name = newName;
    //deviceTypes = OwnedArray<DeviceType>();
}

DeviceType::DeviceType(Manufacturer *newManufacturer, String newName)
{
    name = newName;
    manufacturer = newManufacturer;
    
}

DeviceType::PotentialCC::PotentialCC(String newName, int newCc, int newOn, int newOff)
{
    name = newName;cc=newCc;on=newOn;off=newOff;
}

ReferenceCountedObjectPtr<DeviceType> Device::getType()
{
    return _deviceType;
}

void Device::setType(DeviceType *newType)
{
    _deviceType = newType;
    updated();
}

Value &Device::getChannel()
{
    return _channel;
}



ReferenceCountedObjectPtr<DynamicObject> Device::toJson()
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    BoardController *inst = BoardController::getDefaultInstance();
    
    int index = inst->devices.indexOf(this);
    
    obj->setProperty("name", _name.getValue());
    obj->setProperty("index", index);
    if(getType())
    {
    obj->setProperty("type", getType()->unique);
    }
    
    obj->setProperty("channel", _channel.getValue());
    
    return obj;
}

void Device::updateFromJson(DynamicObject::Ptr obj)
{
    _name.setValue(obj->getProperty("name"));
    _channel.setValue(obj->getProperty("channel"));
    int index = obj->getProperty("index");
    jassert(BoardController::getDefaultInstance()->devices.indexOf(this) == index);
    if(obj->hasProperty("type"))
    {

    for(int i=0; i< DeviceManager::getInstance()->deviceTypes.size() ;i++)
    {
        if(DeviceManager::getInstance()->deviceTypes[i]->unique == obj->getProperty("type").toString())
        {
            _deviceType = DeviceManager::getInstance()->deviceTypes[i];
            return;
        }
    }
        
    }
    
}

int Device::getNumRows()
{
    if(_deviceType)
    {
    return _deviceType->presets;
    }
    return 0;
}

void Device::paintRowBackground (Graphics &g, int rowNumber, int width, int height, bool rowIsSelected) {
    if(rowIsSelected)
    {
        g.setColour(Colours::cornflowerblue);
    }
    else {
        g.setColour(Colours::white);
    }
    g.fillAll();
}
void Device::paintCell (Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) {
    
    
    g.setColour(Colours::black);
    char buffer[4];
    sprintf(buffer, "%03d", (int)(rowNumber) / _deviceType->presetGroups);
    String text(buffer);
    int letter = (int)(rowNumber) % _deviceType->presetGroups;
    char cletter;
    switch(letter)
    {
        case 0:
            cletter = 'A';
            break;
        case 1:
            cletter = 'B';
            break;
        case 2:
            cletter = 'C';
            break;
    }
    
    
    if(columnId == 1){
    g.drawText("Preset " + text + cletter, 2, 0, width - 4, height, Justification::left, true);
    }
    else if(columnId == 2)
    {
        g.drawText("Name here", 2, 0, width - 4, height, Justification::left, true);
    }
}

void Device::sysexReceived(DynamicObject::Ptr obj)
{
    BoardController::getDefaultInstance()->devices[obj->getProperty("model").getDynamicObject()->getProperty("index")]->updateFromJson(obj->getProperty("model").getDynamicObject());
}

void Device::updated()
{
    saveTimer.startTimer(saveTimer.saveInterval);
}

void Device::sendSysex()
{
    if(appObject->getDefaultBoardController()->sysexHandler)
    {
        BoardController::getDefaultInstance()->sysexHandler->sendDevice(this);
    }
}

Value &Device::getName()
{
    return _name;
}

void DeviceTimer::timerCallback()
{
    stopTimer();
    device->sendSysex();
}

void Device::valueChanged(Value &value)
{
    updated();
}
