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
    _name = "";
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

String Device::getName()
{
    return _name;
}

void Device::setName(juce::String newName)
{
    setProperty("name", newName);
    _name = newName;
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
    setProperty("channel", newChannel);
    _channel = newChannel;
}

String Device::toJson()
{
    var jVar = var(this);
    return JSON::toString(jVar);
}
