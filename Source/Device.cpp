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

DeviceType::DeviceType(String newName)
{
    name = newName;
    
    
}

DeviceType::PotentialCC::PotentialCC(String newName, int newCc, int newOn, int newOff)
{
    name = newName;cc=newCc;on=newOn;off=newOff;
}


