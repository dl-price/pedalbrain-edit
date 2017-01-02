/*
  ==============================================================================

    ComponentControllers.h
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef ComponentControllerS_H_INCLUDED
#define ComponentControllerS_H_INCLUDED

#include "includes.h"
#include "ComponentModel.h"
#include "gui/ComponentEdit.h"
#include "gui/ButtonEdit.h"


/*class LedModel : public ComponentController
{
public:
    String type() const { return "Led"; }
};*/
class ButtonController;

class ButtonController : public ComponentController
{
public:
    ButtonController();
    
    PopupMenu *contextMenu() override;

    class ButtonModel;
    ComponentEdit *createEditComponent() override;
    void updateEditComponentFromModel() override;
    ButtonModel *getModel();
};

class ButtonController::ButtonModel : public ComponentModel
{
public:
    ButtonModel();// : ComponentModel("Button"){}
    enum Type
    {
        None,
        DevicePC
    };
    class Action {};
    class DevicePC : public Action {};

    Type _type;
    OwnedArray<Action> _actions;
protected:
    void provePolymorph(){}
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
