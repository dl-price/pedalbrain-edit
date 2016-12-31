/*
  ==============================================================================

    Device.h
    Created: 26 Dec 2016 8:52:49pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED

#include "includes.h"

//==============================================================================
/*
*/


class Device
{
public:
    String name;
    short int channel;
    short int presets;
    short int maxPC;
    bool sendPC;
    
    Device();
    ~Device();

private:
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
    DeviceType(String newName);
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
