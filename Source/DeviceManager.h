/*
  ==============================================================================

    DeviceManager.h
    Created: 26 Dec 2016 8:45:08pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef DEVICEMANAGER_H_INCLUDED
#define DEVICEMANAGER_H_INCLUDED

#include "includes.h"
#include "Device.h"

class DeviceManager {
public:
    DeviceManager();
    ReferenceCountedArray<Manufacturer> manufacturers;
    ReferenceCountedArray<DeviceType> deviceTypes;
    
    void loadDeviceConfig();
    static DeviceManager *getInstance();
    
private:
    static DeviceManager *_instance;

};

#endif  // DEVICEMANAGER_H_INCLUDED
