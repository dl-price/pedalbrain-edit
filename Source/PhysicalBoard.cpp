/*
  ==============================================================================

    PhysicalBoard.cpp
    Created: 11 Feb 2017 2:22:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "PhysicalBoard.h"

PhysicalBoard::PhysicalBoard(String &midiDeviceName, Features &features)
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
