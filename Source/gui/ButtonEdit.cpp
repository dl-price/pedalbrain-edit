/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ButtonEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

void ButtonEdit::selectType(int typeId)
{
    comboBox->setSelectedId(typeId);
}
//[/MiscUserDefs]

//==============================================================================
ButtonEdit::ButtonEdit (ComponentController *model)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (closeButton = new TextButton ("close button"));
    closeButton->setButtonText (TRANS("Close"));
    closeButton->addListener (this);

    addAndMakeVisible (mainGroup = new GroupComponent ("new group",
                                                       TRANS("Main Settings")));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Off"), 1);
    comboBox->addItem (TRANS("Normal"), 2);
    comboBox->addItem (TRANS("Bank Up"), 3);
    comboBox->addItem (TRANS("Bank Down"), 4);
    comboBox->addItem (TRANS("Device PC -"), 5);
    comboBox->addItem (TRANS("Device PC +"), 6);
    comboBox->addItem (TRANS("Store"), 7);
    comboBox->addItem (TRANS("Page"), 8);
    comboBox->addItem (TRANS("Page Up"), 9);
    comboBox->addItem (TRANS("Page Down"), 10);
    comboBox->addItem (TRANS("Preset"), 11);
    comboBox->addItem (TRANS("Preset Up"), 12);
    comboBox->addItem (TRANS("Preset Down"), 13);
    comboBox->addListener (this);

    addAndMakeVisible (displayGroup = new GroupComponent ("new group",
                                                          TRANS("Display")));

    addAndMakeVisible (buttonName = new TextEditor ("new text editor"));
    buttonName->setMultiLine (false);
    buttonName->setReturnKeyStartsNewLine (false);
    buttonName->setReadOnly (false);
    buttonName->setScrollbarsShown (true);
    buttonName->setCaretVisible (true);
    buttonName->setPopupMenuEnabled (true);
    buttonName->setText (String());

    addAndMakeVisible (buttonLabel = new TextEditor ("new text editor"));
    buttonLabel->setMultiLine (false);
    buttonLabel->setReturnKeyStartsNewLine (false);
    buttonLabel->setReadOnly (false);
    buttonLabel->setScrollbarsShown (true);
    buttonLabel->setCaretVisible (true);
    buttonLabel->setPopupMenuEnabled (true);
    buttonLabel->setText (String());

    addAndMakeVisible (ledOn = new ComboBox ("new combo box"));
    ledOn->setEditableText (false);
    ledOn->setJustificationType (Justification::centredLeft);
    ledOn->setTextWhenNothingSelected (String());
    ledOn->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ledOn->addListener (this);

    addAndMakeVisible (ledOff = new ComboBox ("new combo box"));
    ledOff->setEditableText (false);
    ledOff->setJustificationType (Justification::centredLeft);
    ledOff->setTextWhenNothingSelected (String());
    ledOff->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ledOff->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    comboBox->clear();

    /*ButtonController *cast_control = dynamic_cast<ButtonController*>(s_model);

    for (int i = 0; i < cast_control->getAvailableTypes().size(); i++)
    {
        comboBox->addItem(cast_control->getAvailableTypes()[i], i+1);
    }*/

    //[/Constructor]
}

ButtonEdit::~ButtonEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    closeButton = nullptr;
    mainGroup = nullptr;
    comboBox = nullptr;
    displayGroup = nullptr;
    buttonName = nullptr;
    buttonLabel = nullptr;
    ledOn = nullptr;
    ledOff = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ButtonEdit::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ButtonEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    closeButton->setBounds (getWidth() - 230, getHeight() - 50, 200, 24);
    mainGroup->setBounds (20, 20, proportionOfWidth (0.4800f), 216);
    comboBox->setBounds (40, 40, proportionOfWidth (0.4800f) - 40, 24);
    displayGroup->setBounds (getWidth() - 20 - proportionOfWidth (0.4800f), 20, proportionOfWidth (0.4800f), 216);
    buttonName->setBounds ((getWidth() - 20 - proportionOfWidth (0.4800f)) + 20, 20 + 20, proportionOfWidth (0.4800f) - 40, 24);
    buttonLabel->setBounds ((getWidth() - 20 - proportionOfWidth (0.4800f)) + 20, (20 + 20) + 24 - -20, proportionOfWidth (0.4800f) - 40, 24);
    ledOn->setBounds ((getWidth() - 20 - proportionOfWidth (0.4800f)) + 20, ((20 + 20) + 24 - -20) + 36, proportionOfWidth (0.4800f) - 40, 24);
    ledOff->setBounds ((getWidth() - 20 - proportionOfWidth (0.4800f)) + 20, (((20 + 20) + 24 - -20) + 36) + 24 - -20, proportionOfWidth (0.4800f) - 40, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ButtonEdit::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == closeButton)
    {
        //[UserButtonCode_closeButton] -- add your button handler code here..
        //[/UserButtonCode_closeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ButtonEdit::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == ledOn)
    {
        //[UserComboBoxCode_ledOn] -- add your combo box handling code here..
        //[/UserComboBoxCode_ledOn]
    }
    else if (comboBoxThatHasChanged == ledOff)
    {
        //[UserComboBoxCode_ledOff] -- add your combo box handling code here..
        //[/UserComboBoxCode_ledOff]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ButtonEdit" componentName=""
                 parentClasses="public ComponentEdit" constructorParams="ComponentController *model"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="close button" id="9225ef9c71f0e7c" memberName="closeButton"
              virtualName="" explicitFocusOrder="0" pos="230R 50R 200 24" buttonText="Close"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="ed7339e39e40b2a2" memberName="mainGroup"
                  virtualName="" explicitFocusOrder="0" pos="20 20 47.994% 216"
                  title="Main Settings"/>
  <COMBOBOX name="new combo box" id="dc30121a21934289" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="40 40 40M 24" posRelativeW="ed7339e39e40b2a2"
            editable="0" layout="33" items="Off&#10;Normal&#10;Bank Up&#10;Bank Down&#10;Device PC -&#10;Device PC +&#10;Store&#10;Page&#10;Page Up&#10;Page Down&#10;Preset&#10;Preset Up&#10;Preset Down"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GROUPCOMPONENT name="new group" id="a08e5079e3d1891d" memberName="displayGroup"
                  virtualName="" explicitFocusOrder="0" pos="20Rr 20 47.994% 216"
                  title="Display"/>
  <TEXTEDITOR name="new text editor" id="812811b0ef74240a" memberName="buttonName"
              virtualName="" explicitFocusOrder="0" pos="20 20 40M 24" posRelativeX="a08e5079e3d1891d"
              posRelativeY="a08e5079e3d1891d" posRelativeW="a08e5079e3d1891d"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="a03a163c8356b4ad" memberName="buttonLabel"
              virtualName="" explicitFocusOrder="0" pos="20 -20R 40M 24" posRelativeX="a08e5079e3d1891d"
              posRelativeY="812811b0ef74240a" posRelativeW="a08e5079e3d1891d"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="ff1b86b2844855ad" memberName="ledOn"
            virtualName="" explicitFocusOrder="0" pos="20 36 40M 24" posRelativeX="a08e5079e3d1891d"
            posRelativeY="a03a163c8356b4ad" posRelativeW="a08e5079e3d1891d"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="6a2706ed59aad5af" memberName="ledOff"
            virtualName="" explicitFocusOrder="0" pos="20 -20R 40M 24" posRelativeX="a08e5079e3d1891d"
            posRelativeY="ff1b86b2844855ad" posRelativeW="a08e5079e3d1891d"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
