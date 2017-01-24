/*
  ==============================================================================

    SysExObject.h
    Created: 23 Jan 2017 1:08:48am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef SYSEXOBJECT_H_INCLUDED
#define SYSEXOBJECT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SysExObject
{
public:
    virtual DynamicObject::Ptr toJson() = 0;
    virtual void updateFromJson(DynamicObject::Ptr obj) = 0;
};

class SaveableSysExObject : public SysExObject
{
public:
    void saveToFile();
    virtual File getFile() = 0;
    void loadFromFile();
};



#endif  // SYSEXOBJECT_H_INCLUDED
