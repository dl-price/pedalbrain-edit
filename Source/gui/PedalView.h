/*
  ==============================================================================

    PedalView.h
    Created: 27 Dec 2016 9:43:51am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALVIEW_H_INCLUDED
#define PEDALVIEW_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
class PedalView;
#include "PedalViewComponents.h"
#include "../BoardController.h"
#include "ButtonComponent.h"
#include "LayoutTab.h"

//#include "../includes.h"

//==============================================================================
/*
*/
class PedalView    : public Component
{
public:
    PedalView();
    ~PedalView();

    void paint (Graphics&) override;
    void resized() override;
    int getPage();
    void setPage(int i);
    int getPreset();
    void setPreset(int i);
    virtual void init(){};
    
    Array<ButtonComponent*> buttonComponents;
    void mouseDoubleClick(const MouseEvent &event) override;
    int getPageIndex() { return getPage() - 1; }
    bool editButtonOnDoubleClick();
    void editButtonOnDoubleClick(bool val);
    bool buttonClickControlsBoard();
    //void buttonClickControlsBoard(bool val);
    bool showAttachedButtonState();
    void showAttachedButtonState(bool val);
    bool showButtonsOn();
    void showButtonsOn(bool val);
    bool showButtonsOff();
    void showButtonsOff(bool val);
    
    LayoutTab *getLayoutTab();
    
    
    void matchOptionsTo(PedalView *otherView);

private:
    int _viewingPage = 1;
    int _viewingPreset = 1;
    void pageChanged();
    void presetChanged();
    Value _showButtonsOn;
    Value _showButtonsOff;
    Value _showAttachedState;
    Value _editButtonOnDoubleClick;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalView)
};


#endif  // PEDALVIEW_H_INCLUDED
