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
#include "../ComponentModels.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ButtonEdit::ButtonEdit ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (closeButton = new TextButton ("close button"));
    closeButton->setButtonText (TRANS("Close"));
    closeButton->addListener (this);

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Main Settings")));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Send PC"), 1);
    comboBox->addItem (TRANS("Send CC"), 2);
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    
    
    
    //[/Constructor]
}

ButtonEdit::~ButtonEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    closeButton = nullptr;
    groupComponent = nullptr;
    comboBox = nullptr;


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
    groupComponent->setBounds (16, 16, 496, 150);
    comboBox->setBounds (40, 40, 456, 24);
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
        s_model->requestCloseEditWindow();
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

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

ButtonEdit::ButtonEdit(ComponentController *model) : ComponentEdit(model)
{
    ButtonEdit();
    
    comboBox->clear();
    
    ButtonController *cast_control = dynamic_cast<ButtonController*>(s_model);
    
    for (int i = 0; i < cast_control->getAvailableTypes().size(); i++)
    {
        comboBox->addItem(cast_control->getAvailableTypes()[i], i+1);
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ButtonEdit" componentName=""
                 parentClasses="public ComponentEdit" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="close button" id="9225ef9c71f0e7c" memberName="closeButton"
              virtualName="" explicitFocusOrder="0" pos="230R 50R 200 24" buttonText="Close"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="ed7339e39e40b2a2" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="16 16 496 150" title="Main Settings"/>
  <COMBOBOX name="new combo box" id="dc30121a21934289" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="40 40 456 24" editable="0"
            layout="33" items="Send PC&#10;Send CC" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
