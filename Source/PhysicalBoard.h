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
#include <boost/optional.hpp>
#include <boost/logic/tribool.hpp>

class PhysicalBoard : public MidiInputCallback, ActionBroadcaster
{
    struct Features {
        String usbMidiIn;
        String usbMidiOut;
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
    PhysicalBoard(String &midiDeviceName, Features features);
    
    const Features &getBoardInfo();
    const Button &getButton(int index);
    const Led &getLed(int index);
    const Relay &getRelay(int index);
    const Mute &getMute(int index);
    
    const MidiInput &getUsbMidiIn();
    const MidiOutput &getUsbMidiOut();
    
    void handleIncomingMidiMessage(MidiInput *source, const MidiMessage &message) override;
    
    void setupScripting();
    
    
    /**
     Sends SysEx to all available MIDI outputs and listens on all MIDI inputs for recognizable response. Listens for max 100 ms. Populates PhysicalBoard::connectedBoards with board info.

     @param callback Callback function when request timeouts
     */
    static void requestBoards(void (*callback)() = NULL);
    static boost::tribool isBoardConnected();
    
private:
    PhysicalBoard() {};
    
    Features boardInfo;
    
    ScopedPointer<MidiInput> usbMidiIn;
    ScopedPointer<MidiOutput> usbMidiOut;
    
    static OwnedArray<MidiInput> tempInputs;
    static OwnedArray<MidiOutput> tempOutputs;
    static ScopedPointer<PhysicalBoard> tempMidiHandler;
    static OwnedArray<Features> connectedBoards;
    static bool attemptedToReceiveBoards;
    static bool finishedReceivingBoards;
    
    
    OwnedArray<Button> buttons;
    OwnedArray<Led> leds;
    OwnedArray<Relay> relays;
    OwnedArray<Mute> mutes;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhysicalBoard)
};



#endif  // PHYSICALBOARD_H_INCLUDED
