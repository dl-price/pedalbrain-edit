/*
  ==============================================================================

    ComponentController.h
    Created: 28 Dec 2016 7:16:12pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef ComponentController_H_INCLUDED
#define ComponentController_H_INCLUDED

#include "includes.h"
#include "../JuceLibraryCode/JuceHeader.h"
class ComponentController;
#include "gui/ComponentEdit.h"

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
    
    PopupMenu virtual *contextMenu() = 0;
    void virtual popupCompleted(int modalResult, PopupMenu *popupMenu){}
    

    class ComponentModel;
    
    ComponentModel *_model;
    ComponentEdit *_editComponent;
    ResizableWindow *_window;
    
    bool editWindowCanClose();
    void closeEditWindow();
    
    ComponentEdit virtual *createEditComponent() = 0;
    void virtual updateEditComponentFromModel() = 0;
};

class ComponentController::ComponentModel
{
public:
    String getTypeName() const;
    
protected:
    String s_typeName;
    
    ComponentModel(String name);
    void virtual provePolymorph() = 0;
};

#endif  // ComponentController_H_INCLUDED
