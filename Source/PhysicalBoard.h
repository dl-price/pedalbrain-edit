/*
  ==============================================================================

    PhysicalBoard.h
    Created: 11 Feb 2017 2:22:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PHYSICALBOARD_H_INCLUDED
#define PHYSICALBOARD_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PhysicalBoard : public MidiInputCallback, ActionBroadcaster
{
    struct Features {
        int buttons;
        int leds;
        int relays;
        int mutes;
    };
    
    class Button {
    public:
        const PhysicalBoard *const physicalBoard;
        
        Button(PhysicalBoard *board) : physicalBoard(board) {};
    };
    
    class Led {
    public:
        const PhysicalBoard *const physicalBoard;
        
        Led(PhysicalBoard *board) : physicalBoard(board) {};
    };
    
    class Relay {
    public:
        const PhysicalBoard *const physicalBoard;
        
        Relay(PhysicalBoard *board) : physicalBoard(board) {};
    };
    
    class Mute {
    public:
        const PhysicalBoard *const physicalBoard;
        
        Mute(PhysicalBoard *board) : physicalBoard(board) {};
    };
    
public:
    PhysicalBoard(String &midiDeviceName, Features &features);
    
    const Button &getButton(int index);
    const Led &getLed(int index);
    const Relay &getRelay(int index);
    const Mute &getMute(int index);
    
    const MidiInput &getUsbMidiIn();
    const MidiOutput &getUsbMidiOut();
    
private:
    ScopedPointer<MidiInput> usbMidiIn;
    ScopedPointer<MidiOutput> usbMidiOut;
    
    OwnedArray<Button> buttons;
    OwnedArray<Led> leds;
    OwnedArray<Relay> relays;
    OwnedArray<Mute> mutes;
};



#endif  // PHYSICALBOARD_H_INCLUDED
