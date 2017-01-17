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

class SysExHandler : public MidiInputCallback
{
public:
    SysExHandler();
    void handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message);
    void sendPBSysex(String message);
    static bool boardAttached();
    void requestBoardInfo();
    void receivedPBSysEx(String message);
    
private:
    MidiInput *usbInput;
    MidiOutput *usbOutput;
    void finishedReceivingBoardInfo();
};



#endif  // SYSEXHANDLER_H_INCLUDED
