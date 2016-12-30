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
class ComponentModel;
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
    ComponentEdit virtual *createEditWindow() = 0;
    PopupMenu virtual *contextMenu() { return 0;}
    void virtual saveFromEditWindow(ComponentEdit *window) = 0;
    void virtual popupCompleted(int modalResult, PopupMenu *popupMenu){}
};




#endif  // COMPONENTMODEL_H_INCLUDED
