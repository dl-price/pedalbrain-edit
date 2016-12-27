/*
  ==============================================================================

    DeviceManager.cpp
    Created: 26 Dec 2016 8:45:08pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "includes.h"
#include "DeviceManager.h"

void DeviceManager::loadDeviceConfig()
{
    File file = File(File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getFullPathName() + "/Contents/Resources/Config/DeviceTypes.json");
    
    var stuff = JSON::parse(file);
    
    //delete [] DeviceManager::manufacturers;
    //&(DeviceManager::manufacturers) = new Array<Manufacturer>[(sizeof(*stuff.getArray())/8)];
    
    //Manufacturer mans[(sizeof(*stuff.getArray())/8)];
    
    for(int i=0; i < sizeof(*stuff.getArray())/8; i++)
    {
        var manJson = (*stuff.getArray())[i];
        Manufacturer * newMan = new Manufacturer(manJson.getProperty("name", var()));
        DeviceManager::manufacturers.add(newMan);
        
        var some = manJson.getProperty("devices", var());
        
        
        for(int j=0; j < some.size();j++)
        {
            Logger::outputDebugString(some[j].getProperty("name", var()));
            DeviceType * dev = new DeviceType(some[j].getProperty("name", var()));
            DeviceManager::deviceTypes.add(dev);
            newMan->deviceTypes.add(dev);
        }
        
    }
    
    
}

OwnedArray<Manufacturer> DeviceManager::manufacturers = OwnedArray<Manufacturer>();
OwnedArray<DeviceType> DeviceManager::deviceTypes = OwnedArray<DeviceType>();

