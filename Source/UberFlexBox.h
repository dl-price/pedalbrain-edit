/*
  ==============================================================================

    UberFlexBox.h
    Created: 8 Feb 2017 4:24:18pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef UBERFLEXBOX_H_INCLUDED
#define UBERFLEXBOX_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class UberFlexBox    : public FlexBox, public TextEditorListener, public ComboBoxListener
{
public:
    UberFlexBox(Component *newParent);
    ~UberFlexBox();
    
    void textEditorTextChanged(TextEditor &editor) override;
    void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override;
    
    FlexItem &createAndAddFlexRow();
    FlexItem &createAndAddFlexLabel(String labelValue, FlexItem &flexRow);
    FlexItem &createAndAddFlexInput(Component &newComponent, FlexItem &flexRow);

private:
    Component *_parent;
    
    void removeFlexBoxComponents(FlexBox &flexBox);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UberFlexBox)
};


#endif  // UBERFLEXBOX_H_INCLUDED
