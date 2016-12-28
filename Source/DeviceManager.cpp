/*
  ==============================================================================

    DeviceManager.cpp
    Created: 26 Dec 2016 8:45:08pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "includes.h"
#include "DeviceManager.h"

DeviceManager* DeviceManager::getInstance() {
    if(!s_instance)
        s_instance = new DeviceManager();
    return s_instance;
}

DeviceManager *DeviceManager::s_instance = 0;

void DeviceManager::loadDeviceConfig()
{
    File file;
    if((SystemStats::getOperatingSystemType() & SystemStats::OperatingSystemType::MacOSX) !=0) {
        file = File(File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getFullPathName() + "/Contents/Resources/Config/DeviceTypes.json");
    }
    else if (SystemStats::getOperatingSystemType() == SystemStats::OperatingSystemType::iOS) {
        file = File(File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getFullPathName() + "/Config/DeviceTypes.json");
    }
    
    var stuff = JSON::parse(file);
    
    
    Array<var> manArray = *stuff.getArray();
    
    for(int i=0; i < sizeof(*stuff.getArray())/8; i++)
    {
        
        if(sizeof(*stuff.getArray()) == 0 ){
            break;
        }
        var manJson = (*stuff.getArray())[i];
        Manufacturer * newMan = new Manufacturer(manJson.getProperty("name", var()));
        DeviceManager::manufacturers.add(newMan);
        
        var some = manJson.getProperty("devices", var());
        
        
        for(int j=0; j < some.size();j++)
        {
            DeviceType * dev = new DeviceType(some[j].getProperty("name", var()));
            DeviceManager::deviceTypes.add(dev);
            newMan->deviceTypes.add(dev);
        }
        
    }
    
    
}

DeviceManager::DeviceManager()
{
    manufacturers = OwnedArray<Manufacturer>();
    deviceTypes = OwnedArray<DeviceType>();
}




