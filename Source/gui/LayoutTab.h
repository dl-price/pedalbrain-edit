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
#include "../includes.h"

//==============================================================================
/*
*/
class LayoutTab    : public Component
{
public:
    LayoutTab();
    ~LayoutTab();

    void paint (Graphics&) override;
    void resized() override;

private:
    ScopedPointer<Button> pageDownButton;
    ScopedPointer<Button> pageUpButton;
    ScopedPointer<ComboBox> pageCombo;
    ScopedPointer<Label> pageNameLabel;
    ScopedPointer<TextEditor> pageNameEditor;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LayoutTab)
};


#endif  // LAYOUTTAB_H_INCLUDED
