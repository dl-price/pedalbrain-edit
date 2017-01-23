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
#include "SysExObject.h"


//==============================================================================
/*
*/


class Device : public ReferenceCountedObject, public TableListBoxModel, SysExObject
{
public:
    Device();
    ~Device();
    DeviceType *getType();
    void setType(DeviceType *newType);
    int getChannel();
    void setChannel(int newChannel);
    DynamicObject::Ptr toJson() override;
    String name = "";
    void updateFromJson(DynamicObject::Ptr obj) override;
    OwnedArray<String> presetNames;
    int getNumRows() override;
    void paintRowBackground (Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    void paintCell (Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    static void sysexReceived(DynamicObject::Ptr obj);
    

private:
    DeviceType *_deviceType = 0;
    int _channel = 1;
    int _presets = 0;
    int _maxPC = 0;
    bool _sendPC = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Device)
};

class DeviceType
{
public:
    String name;
    String unique;
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
    int presets = 0;
    int presetGroups = 1;
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
