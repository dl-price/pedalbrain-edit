/*
  ==============================================================================

    Device.cpp
    Created: 26 Dec 2016 8:52:49pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "includes.h"
#include "Device.h"

//==============================================================================
Device::Device()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    name = String::empty;
    _deviceType = DeviceManager::getInstance()->deviceTypes[0];
    
}

Device::~Device()
{
}

Manufacturer::Manufacturer()
{
    name = "";
    deviceTypes = OwnedArray<DeviceType>();
}

Manufacturer::Manufacturer(String newName)
{
    name = newName;
    deviceTypes = OwnedArray<DeviceType>();
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

DeviceType *Device::getType()
{
    return _deviceType;
}

void Device::setType(DeviceType *newType)
{
    _deviceType = newType;
}

int Device::getChannel()
{
    return _channel;
}

void Device::setChannel(int newChannel)
{
    _channel = newChannel;
}

ReferenceCountedObjectPtr<DynamicObject> Device::toJson()
{
    ReferenceCountedObjectPtr<DynamicObject> obj = ReferenceCountedObjectPtr<DynamicObject>(new DynamicObject());
    
    BoardController *inst = BoardController::getInstance();
    
    int index = inst->devices.indexOf(this);
    
    obj->setProperty("name", name);
    obj->setProperty("index", index);
    
    obj->setProperty("channel", _channel);
    
    return obj;
}

void Device::updateFromJson(juce::DynamicObject *obj)
{
    name = obj->getProperty("name");
    _channel = obj->getProperty("channel");
}
