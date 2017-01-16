/*
  ==============================================================================

    Device.h
    Created: 26 Dec 2016 8:52:49pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED

class DeviceType;
class Device;
class Manufacturer;
#include "includes.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/


class Device : DynamicObject
{
public:
    Device();
    ~Device();
    String getName();
    void setName(String newName);
    DeviceType *getType();
    void setType(DeviceType *newType);
    int getChannel();
    void setChannel(int newChannel);
    String toJson();
    
    

private:
    String _name;
    DeviceType *_deviceType;
    int _channel;
    int _presets;
    int _maxPC;
    bool _sendPC;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Device)
};

class DeviceType
{
public:
    String name;
    struct PotentialCC
    {
        PotentialCC(String newName, int newCc, int newOn, int newOff);
        String name;
        int cc;
        int on;
        int off;
    };
    OwnedArray<PotentialCC> potentialCC;
    DeviceType(Manufacturer *newManufacturer, String newName);
    Manufacturer *manufacturer;
};

class Manufacturer
{
public:
    String name;
    OwnedArray<DeviceType> deviceTypes;
    Manufacturer();
    Manufacturer(String newName);
};





#endif  // DEVICE_H_INCLUDED
