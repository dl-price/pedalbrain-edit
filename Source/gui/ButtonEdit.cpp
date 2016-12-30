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
//[/MiscUserDefs]

//==============================================================================
ButtonEdit::ButtonEdit ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ButtonEdit::ButtonEdit(ComponentController *model) : ButtonEdit::ButtonEdit()
{
    s_model = model;
}

ButtonEdit::~ButtonEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;


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

    textButton->setBounds (56, 72, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ButtonEdit::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        s_model->requestCloseEditWindow();
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 parentClasses="public ComponentEdit" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="9225ef9c71f0e7c" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="56 72 150 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
