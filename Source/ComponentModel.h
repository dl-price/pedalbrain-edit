/*
  ==============================================================================

    ComponentController.h
    Created: 28 Dec 2016 7:16:12pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef ComponentController_H_INCLUDED
#define ComponentController_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
class ComponentController;
#include "gui/ComponentEdit.h"
#include "gui/ButtonEdit.h"

//==============================================================================
/*
*/

class ComponentModel
{
public:
    String getTypeName() const;
    
protected:
    ComponentModel(String name);
    String s_typeName;
};

class ButtonModel : public ComponentModel
{
public:
    ButtonModel();// : ComponentModel("Button"){}
};

class ComponentController
{
public:
    ComponentController();
    String getComponentType();
    String virtual type() const = 0;
    ComponentEdit virtual *createEditWindow() = 0;
    PopupMenu virtual *contextMenu() { return 0;}
    void virtual saveFromEditWindow(ComponentEdit *window) = 0;
    void virtual popupCompleted(int modalResult, PopupMenu *popupMenu){}
protected:
    ComponentModel *_model;
};




#endif  // ComponentController_H_INCLUDED
