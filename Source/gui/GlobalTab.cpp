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

#include "GlobalTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GlobalTab::GlobalTab ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (groupComponent = new GroupComponent ("system settings",
                                                            TRANS("System Settings")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);

    addAndMakeVisible (modelCombo = new ComboBox ("new combo box"));
    modelCombo->setEditableText (false);
    modelCombo->setJustificationType (Justification::centredLeft);
    modelCombo->setTextWhenNothingSelected (TRANS("Model (not enabled)"));
    modelCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    modelCombo->addListener (this);

    addAndMakeVisible (currentSetListCombo = new ComboBox ("new combo box"));
    currentSetListCombo->setEditableText (false);
    currentSetListCombo->setJustificationType (Justification::centredLeft);
    currentSetListCombo->setTextWhenNothingSelected (TRANS("Setlist (not enabled)"));
    currentSetListCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    currentSetListCombo->addListener (this);

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Startup script (not enabled)"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addListener (this);

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("Function Switches")));

    addAndMakeVisible (groupComponent3 = new GroupComponent ("new group",
                                                             TRANS("Expression Pedals")));

    addAndMakeVisible (groupComponent4 = new GroupComponent ("new group",
                                                             TRANS("External Switches")));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GlobalTab::~GlobalTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    modelCombo = nullptr;
    currentSetListCombo = nullptr;
    comboBox = nullptr;
    groupComponent2 = nullptr;
    groupComponent3 = nullptr;
    groupComponent4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GlobalTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GlobalTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent->setBounds (20, 20, getWidth() - 580, proportionOfHeight (0.4500f));
    modelCombo->setBounds (20 + 20, 20 + 20, (getWidth() - 580) - 40, 24);
    currentSetListCombo->setBounds (20 + 20, (20 + 20) + 24 - -20, (getWidth() - 580) - 40, 24);
    comboBox->setBounds (32, 112, 600, 24);
    groupComponent2->setBounds (20, 20 + proportionOfHeight (0.4500f) - -20, getWidth() - 580, 150);
    groupComponent3->setBounds ((getWidth() - 20 - 250) + -20 - 250, 20, 250, proportionOfHeight (0.4500f));
    groupComponent4->setBounds (getWidth() - 20 - 250, 20, 250, proportionOfHeight (0.4500f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GlobalTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == modelCombo)
    {
        //[UserComboBoxCode_modelCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_modelCombo]
    }
    else if (comboBoxThatHasChanged == currentSetListCombo)
    {
        //[UserComboBoxCode_currentSetListCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_currentSetListCombo]
    }
    else if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
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

<JUCER_COMPONENT documentType="Component" className="GlobalTab" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="system settings" id="9bf3bfeaeeb81be3" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="20 20 580M 45.043%"
                  title="System Settings" textpos="33"/>
  <COMBOBOX name="new combo box" id="471bda264f2742de" memberName="modelCombo"
            virtualName="" explicitFocusOrder="0" pos="20 20 40M 24" posRelativeX="9bf3bfeaeeb81be3"
            posRelativeY="9bf3bfeaeeb81be3" posRelativeW="9bf3bfeaeeb81be3"
            editable="0" layout="33" items="" textWhenNonSelected="Model (not enabled)"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="c33de4c3d795d94a" memberName="currentSetListCombo"
            virtualName="" explicitFocusOrder="0" pos="20 -20R 40M 24" posRelativeX="9bf3bfeaeeb81be3"
            posRelativeY="471bda264f2742de" posRelativeW="9bf3bfeaeeb81be3"
            editable="0" layout="33" items="" textWhenNonSelected="Setlist (not enabled)"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="934d3eb79fbe99f0" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="32 112 600 24" editable="0"
            layout="33" items="" textWhenNonSelected="Startup script (not enabled)"
            textWhenNoItems="(no choices)"/>
  <GROUPCOMPONENT name="new group" id="81d4edbdf6aa800e" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="20 -20R 580M 150"
                  posRelativeY="9bf3bfeaeeb81be3" title="Function Switches"/>
  <GROUPCOMPONENT name="new group" id="90095d0f4753bed4" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="-20r 20 250 45.043%"
                  posRelativeX="14e164bde519671e" title="Expression Pedals"/>
  <GROUPCOMPONENT name="new group" id="14e164bde519671e" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="20Rr 20 250 45.043%"
                  title="External Switches"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
