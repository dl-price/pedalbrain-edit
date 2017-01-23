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
#include "PageModel.h"

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
    void sendSysEx(DynamicObject *object);
    static bool boardAttached();
    void requestBoardInfo();
    void receivedPBSysEx(String message);
    void sysexReceived(DynamicObject::Ptr objReceived);
    BoardInfo boardInfo;
    void solidfyConnection();
    bool isSolidified();
    void sendDevice(ReferenceCountedObjectPtr<Device> device);
    void sendPage(PageModel *page);
    void requestAllParameters();
    
private:
    ScopedPointer< MidiInput> usbInput;
    ScopedPointer< MidiOutput> usbOutput;
    void finishedReceivingBoardInfo();
    bool _isSolidified;
};




#endif  // SYSEXHANDLER_H_INCLUDED
