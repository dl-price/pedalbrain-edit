/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_461A36B05BCA5F9C__
#define __JUCE_HEADER_461A36B05BCA5F9C__

//[Headers]     -- You can add your own extra header files here --
#include "../../JuceLibraryCode/JuceHeader.h"
#include "ComponentEdit.h"
#include "ButtonModel.h"
#include "UberFlexBox.h"


//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ButtonEdit  : public Component,
                    public ButtonListener,
                    public ComboBoxListener
{
public:
    //==============================================================================
    ButtonEdit (ButtonModel *model);
    ~ButtonEdit();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void selectType(int typeId);
    void addComboBoxOptions();
    void addLedOptions(ComboBox *box);
    void refreshMainSettingsComponents();
    ButtonModel *_buttonModel;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    ScopedPointer<UberFlexBox> mainSettingsFlexBox;

    void removeFlexBoxComponents(FlexBox *flexBox);
    void addFlexBoxComponents(FlexBox *flexBox, int type = 0);
    void setupFlexItemForLabel(FlexItem *flexItem);
    void setupFlexItemForInput(FlexItem *flexItem);
    FlexItem *createAndAddFlexLabel(String labelValue, FlexBox *flexBox);
    FlexItem *createAndAddFlexTextEditor(TextEditor *editor, FlexBox *flexBox);
    FlexBox *createFullWidthRowInFlexBox(FlexBox *flexBox);
    void addDevicesToCombo(ComboBox *comboBox);
    FlexItem &createDeviceSelectFlexRow(UberFlexBox &flexBox);


    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> closeButton;
    ScopedPointer<GroupComponent> mainGroup;
    ScopedPointer<ComboBox> typeComboBox;
    ScopedPointer<GroupComponent> displayGroup;
    ScopedPointer<TextEditor> buttonName;
    ScopedPointer<TextEditor> buttonLabel;
    ScopedPointer<ComboBox> ledOn;
    ScopedPointer<ComboBox> ledOff;
    ScopedPointer<Component> mainSettingsHolder;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonEdit)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_461A36B05BCA5F9C__
