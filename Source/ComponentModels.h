/*
  ==============================================================================

    ComponentControllers.h
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef ComponentControllerS_H_INCLUDED
#define ComponentControllerS_H_INCLUDED

#include "ComponentModel.h"
#include "gui/ComponentEdit.h"


/*class LedModel : public ComponentController
{
public:
    String type() const { return "Led"; }
};*/

class ButtonController : public ComponentController
{
public:
    String type() const override { return "Button"; }
    ComponentEdit *createEditWindow() override;
    PopupMenu *contextMenu() override;
    void saveFromEditWindow(ComponentEdit *window) override;
    void popupCompleted(int modalResult, PopupMenu *popupMenu) override;

};

/*class LBModel : public ComponentController
{
    String type() const { return "Led"; }
};

class LcdModel : public ComponentController
{
    String type() const { return "Lcd"; }
};*/


#endif  // ComponentControllerS_H_INCLUDED
