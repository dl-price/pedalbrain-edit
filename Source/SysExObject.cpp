/*
  ==============================================================================

    SysExObject.cpp
    Created: 23 Jan 2017 1:08:48am
    Author:  Daniel Price

  ==============================================================================
*/

#include "SysExObject.h"

void SaveableSysExObject::saveToFile()
{
    File file = getFile();
    
    if(!file.getParentDirectory().exists())
    {
        file.getParentDirectory().createDirectory();
    }
    
    file.deleteFile();
    
    ScopedPointer<FileOutputStream> stream = file.createOutputStream();
    
    JSON::writeToStream(*(dynamic_cast<OutputStream*>(stream.get())), var(toJson()));
    
    stream->flush();
}

void SaveableSysExObject::loadFromFile()
{
    File file = getFile();
    
    if(file.exists())
    {
    
    ScopedPointer<FileInputStream> stream = file.createInputStream();
    
    updateFromJson(JSON::parse(*dynamic_cast<InputStream*>(stream.get())).getDynamicObject());
    }
}
