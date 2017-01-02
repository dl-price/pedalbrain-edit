/*
  ==============================================================================

    BoardController.h
    Created: 2 Jan 2017 6:51:21pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BOARDCONTROLLER_H_INCLUDED
#define BOARDCONTROLLER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class BoardController;

#include "ComponentModel.h"
#include "BoardModel.h"
#include "gui/PedalEdit.h"
#include "gui/PedalView.h"

class BoardController
{
public:
    BoardController();
    virtual ~BoardController(){}
    
    static BoardController *getInstance();
    static BoardController *setInstance(BoardController *newInstance);
    virtual PedalView *createPedalView() = 0;
    ResizableWindow *createEditWindowAndAddToDesktop(ComponentModel *model);
    ResizableWindow *createEditWindowAndFillMainWindow(ComponentModel *model);
    
    /**
     Use subclass template to automatically load correct model type
     */
    virtual void createBlankModel() = 0;

protected:
    static BoardController *_instance;
    BoardModel *_model;
    OwnedArray<PedalView> *pedalViews;
    
    ResizableWindow *createEditWindowForModel(ComponentModel *model);
    virtual ComponentEdit *createEditComponentForModel(ComponentModel *model)=0;
};



#endif  // BOARDCONTROLLER_H_INCLUDED
