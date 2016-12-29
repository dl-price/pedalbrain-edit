/*
  ==============================================================================

    ComponentModel.h
    Created: 28 Dec 2016 7:16:12pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef COMPONENTMODEL_H_INCLUDED
#define COMPONENTMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "gui/ComponentEdit.h"
#include "gui/ButtonEdit.h"

//==============================================================================
/*
*/
class ComponentModel
{
public:
    ComponentModel();
    String virtual type() const = 0;
    ComponentEdit virtual *createEditWindow();
};




#endif  // COMPONENTMODEL_H_INCLUDED
