/*
  ==============================================================================

    LayoutTab.h
    Created: 27 Dec 2016 6:02:00am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LAYOUTTAB_H_INCLUDED
#define LAYOUTTAB_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"
//#include "../includes.h"
#include "../BoardController.h"


//==============================================================================
/*
*/
class LayoutTab    : public Component, ComboBox::Listener, ButtonListener, BoardControllerListener, TextEditorListener, ValueListener
{
public:
    LayoutTab();
    ~LayoutTab();

    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override;
    void boardControllerChanged() override;
    void buttonClicked(Button *button) override;
    void textEditorTextChanged(TextEditor &editor) override;
    void editButtonOnDoubleClick(bool val);
    bool showPageChangeInterface(bool val = true);
    bool showingPageChangeInterface();
    
    Value &getButtonClickControlsBoard();
    PedalView *getPedalView();
    
    void valueChanged(Value &value);

private:
    ScopedPointer<Button> pageDownButton;
    ScopedPointer<Button> pageUpButton;
    ScopedPointer<ComboBox> pageCombo;
    ScopedPointer<Label> pageNameLabel;
    ScopedPointer<TextEditor> pageNameEditor;
    ScopedPointer<PedalView> pedalView;
    
    Value _buttonClickControlsBoard;
    Value _showPageChangeInterface;
    
    void changePedalView(PedalView *newView);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LayoutTab)
};


#endif  // LAYOUTTAB_H_INCLUDED
