/*
  ==============================================================================

    PhysicalBoard.cpp
    Created: 11 Feb 2017 2:22:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "PhysicalBoard.h"
#include "Application.h"
#include "Macros.h"
#include "ScriptHandler.h"
#include <algorithm>
#include <thread>
#include <chrono>
#include <boost/optional.hpp>
#include <boost/logic/tribool.hpp>

OwnedArray<MidiInput> PhysicalBoard::tempInputs;
OwnedArray<MidiOutput> PhysicalBoard::tempOutputs;
ScopedPointer<PhysicalBoard> PhysicalBoard::tempMidiHandler;
OwnedArray<PhysicalBoard::Features> PhysicalBoard::connectedBoards;
bool PhysicalBoard::attemptedToReceiveBoards = false;
bool PhysicalBoard::finishedReceivingBoards = false;

PhysicalBoard::PhysicalBoard(String &midiDeviceName, Features features) : boardInfo(features)
{
    const int inIndex = MidiInput::getDevices().indexOf(midiDeviceName);
    const int outIndex = MidiOutput::getDevices().indexOf(midiDeviceName);
    
    usbMidiIn = MidiInput::openDevice(inIndex, this);
    usbMidiOut = MidiOutput::openDevice(outIndex);
    
    buttons.ensureStorageAllocated(features.buttons);
    leds.ensureStorageAllocated(features.leds);
    relays.ensureStorageAllocated(features.relays);
    mutes.ensureStorageAllocated(features.relays);
    
    for ( int i = 0; i < features.buttons ; i++)
    {
        buttons.add(new Button(this));
    }
    
    for ( int i = 0; i < features.leds ; i++)
    {
        leds.add(new Led(this));
    }
    
    for ( int i = 0; i < features.relays ; i++)
    {
        relays.add(new Relay(this));
    }
    
    for ( int i = 0; i < features.mutes ; i++)
    {
        mutes.add(new Mute(this));
    }
    
    setupScripting();
}

void PhysicalBoard::setupScripting()
{
    appObject->scriptHandler->stack.removeProperty("physicalBoard");
    
    DynamicObject::Ptr stackObject = new DynamicObject();
    
    appObject->scriptHandler->stack.setProperty("physicalBoard", var(stackObject));
}

const PhysicalBoard::Button &PhysicalBoard::getButton(int index)
{
    return *buttons[index];
}

const PhysicalBoard::Led &PhysicalBoard::getLed(int index)
{
    return *leds[index];
}

const PhysicalBoard::Relay &PhysicalBoard::getRelay(int index)
{
    return *relays[index];
}

const PhysicalBoard::Mute &PhysicalBoard::getMute(int index)
{
    return *mutes[index];
}

const MidiInput &PhysicalBoard::getUsbMidiIn()
{
    return *usbMidiIn;
}

const MidiOutput &PhysicalBoard::getUsbMidiOut()
{
    return *usbMidiOut;
}

void PhysicalBoard::requestBoards()
{
    // If not temp MIDI handler exists, create it
    
    /*if(!PhysicalBoard::tempMidiHandler)
    {
        PhysicalBoard::tempMidiHandler = new PhysicalBoard();
    }*/
    
    // Setup all temp inputs
    
    for(int i=0; i < MidiInput::getDevices().size(); i++)
    {
        PhysicalBoard::tempInputs.add(MidiInput::openDevice(i, static_cast<MidiInputCallback*>(PhysicalBoard::tempMidiHandler)));
    }
    
    // Setup all temp outputs
    
    for(int i=0; i < MidiOutput::getDevices().size(); i++)
    {
        PhysicalBoard::tempOutputs.add(MidiOutput::openDevice(i));
    }
    
    // Send request message to all outputs, send slightly different message on each channel so in and out can be identified
    
    // For every message received store temp features (Done in handleIncomingMidiMessage)
    
    // After some time elapses move temp features to static array and notify that it's finished
    
    PhysicalBoard::connectedBoards.clear();
    PhysicalBoard::attemptedToReceiveBoards = true;
    
    std::thread([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        PhysicalBoard::finishedReceivingBoards = true;
    }).detach();
}

boost::tribool PhysicalBoard::isBoardConnected()
{
    if(PhysicalBoard::connectedBoards.size())
        return true;
    
    if(PhysicalBoard::finishedReceivingBoards)
        return false;
    
    return boost::indeterminate;
}

void PhysicalBoard::handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message)
{
    
}
