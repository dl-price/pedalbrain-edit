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

class Manufacturer
{
public:
    String name;
    Manufacturer(String newName);
};

class DeviceType
{
public:
    String name;
};



#endif  // DEVICE_H_INCLUDED
