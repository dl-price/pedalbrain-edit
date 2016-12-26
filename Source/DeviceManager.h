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
    //static Manufacturer manufacturers[3];
    static Manufacturer manufacturers[];
    static DeviceType deviceTypes[];
    
    static void loadDeviceConfig();

};

#endif  // DEVICEMANAGER_H_INCLUDED
