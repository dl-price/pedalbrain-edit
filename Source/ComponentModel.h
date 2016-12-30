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





class ComponentController
{
public:
    ComponentController();
    String getComponentType();
    ResizableWindow *createEditWindow();
    void createEditWindowAndFillMainWindow();
    void createEditWindowAndAddToDesktop();
    void requestCloseEditWindow();
    
    
    
    PopupMenu virtual *contextMenu() { return 0;}
    void virtual popupCompleted(int modalResult, PopupMenu *popupMenu){}
protected:
    class ComponentModel;
    ComponentEdit virtual *createEditComponent() = 0;
    ComponentModel *_model;
    ResizableWindow *_window;
    bool editWindowCanClose();
    void closeEditWindow();
};

class ComponentController::ComponentModel
{
public:
    String getTypeName() const;
    
protected:
    ComponentModel(String name);
    String s_typeName;
};




#endif  // ComponentController_H_INCLUDED
