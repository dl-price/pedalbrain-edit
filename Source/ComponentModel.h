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
    //ComponentModel();
    String virtual type() const = 0;
    ComponentEdit virtual *createEditWindow() {return new ComponentEdit();}
};

class LedModel : public ComponentModel
{
public:
    String type() const { return "Led"; }
};

class ButtonModel : public ComponentModel
{
    String type() const { return "Button"; }
    ComponentEdit *createEditWindow() {return new ButtonEdit();}
};

class LBModel : public ComponentModel
{
    String type() const { return "Led"; }
};

class LcdModel : public ComponentModel
{
    String type() const { return "Lcd"; }
};


#endif  // COMPONENTMODEL_H_INCLUDED
