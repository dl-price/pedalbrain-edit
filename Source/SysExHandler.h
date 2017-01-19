/*
  ==============================================================================

    SysExHandler.h
    Created: 17 Jan 2017 3:28:04pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef SYSEXHANDLER_H_INCLUDED
#define SYSEXHANDLER_H_INCLUDED

class SysExHandler;

#include "../JuceLibraryCode/JuceHeader.h"
#include "Device.h"

struct BoardInfo
{
    String model;
    String name;
    double version;
};

class SysExHandler : public MidiInputCallback
{
public:
    SysExHandler();
    SysExHandler(MidiInputCallback *newCallback);
    void handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message);
    void sendPBSysex(String message);
    void sendSysEx(ReferenceCountedObjectPtr<DynamicObject> object);
    static bool boardAttached();
    void requestBoardInfo();
    void receivedPBSysEx(String message);
    void sysexReceived(DynamicObject *objReceived);
    BoardInfo boardInfo;
    void solidfyConnection();
    bool isSolidified();
    void sendDevice(ReferenceCountedObjectPtr<Device> device);
    void requestAllParameters();
    
private:
    MidiInput *usbInput = 0;
    MidiOutput *usbOutput = 0;
    void finishedReceivingBoardInfo();
    bool _isSolidified;
};



#endif  // SYSEXHANDLER_H_INCLUDED
