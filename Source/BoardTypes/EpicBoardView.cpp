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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EpicBoardView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EpicBoardView::EpicBoardView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (button1 = new ButtonComponent (1));
    button1->setName ("new component");

    addAndMakeVisible (component3 = new LcdComponent());
    component3->setName ("new component");

    addAndMakeVisible (button2 = new ButtonComponent (2));
    button2->setName ("new component");

    addAndMakeVisible (button3 = new ButtonComponent (3));
    button3->setName ("new component");

    addAndMakeVisible (button4 = new ButtonComponent (4));
    button4->setName ("new component");

    addAndMakeVisible (button5 = new ButtonComponent (5));
    button5->setName ("new component");

    addAndMakeVisible (button8 = new ButtonComponent (2));
    button8->setName ("new component");

    addAndMakeVisible (button9 = new ButtonComponent (2));
    button9->setName ("new component");

    addAndMakeVisible (button10 = new ButtonComponent (2));
    button10->setName ("new component");

    addAndMakeVisible (button11 = new ButtonComponent (2));
    button11->setName ("new component");

    addAndMakeVisible (button6 = new ButtonComponent (6));
    button6->setName ("new component");

    addAndMakeVisible (button7 = new ButtonComponent (2));
    button7->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..

    buttonComponents = Array<ButtonComponent*>();

    buttonComponents.add(button1);
    buttonComponents.add(button2);
    buttonComponents.add(button3);
    buttonComponents.add(button4);
    buttonComponents.add(button5);
    buttonComponents.add(button6);
    buttonComponents.add(button7);
    buttonComponents.add(button8);
    buttonComponents.add(button9);
    buttonComponents.add(button10);
    buttonComponents.add(button11);

    //[/Constructor]
}

EpicBoardView::~EpicBoardView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    button1 = nullptr;
    component3 = nullptr;
    button2 = nullptr;
    button3 = nullptr;
    button4 = nullptr;
    button5 = nullptr;
    button8 = nullptr;
    button9 = nullptr;
    button10 = nullptr;
    button11 = nullptr;
    button6 = nullptr;
    button7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EpicBoardView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EpicBoardView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    button1->setBounds (0, 216, 150, 100);
    component3->setBounds (152, 16, 264, 184);
    button2->setBounds (408, 216, 150, 100);
    button3->setBounds (560, 216, 150, 100);
    button4->setBounds (712, 216, 150, 100);
    button5->setBounds (864, 216, 150, 100);
    button8->setBounds (368, 432, 150, 100);
    button9->setBounds (528, 432, 150, 100);
    button10->setBounds (704, 432, 150, 100);
    button11->setBounds (848, 432, 150, 100);
    button6->setBounds (32, 432, 150, 100);
    button7->setBounds (192, 432, 150, 100);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void EpicBoardView::init()
{
    int numChild = getNumChildComponents();

    for(int i=0; i < numChild; i++)
    {


        ButtonComponent *component = dynamic_cast<ButtonComponent*>(getChildComponent(i));
        {
            if(component)
            {
                const MessageManagerLock mmLock;
                component->addMouseListener(this, true);



                /* Arduino code for SysEx
                 Serial.println("Hello world");
                 digitalWrite(13, HIGH);
                 uint8_t toSend[] = "a}Hello" ;
                 toSend[0] = 0xF0;
                 toSend[sizeof(toSend)-1] = 0xF7;
                 usbMIDI.sendSysEx(8, toSend);
                 //usbMIDI.send_now();
                 delay(100);
                 digitalWrite(13, LOW);
                 delay(900);
                 */


            }
        }
    }
}

void EpicBoardView::mouseDoubleClick(const MouseEvent &event)
{
    
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EpicBoardView" componentName=""
                 parentClasses="public PedalView" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GENERICCOMPONENT name="new component" id="ddf151a0b324bd1a" memberName="button1"
                    virtualName="" explicitFocusOrder="0" pos="0 216 150 100" class="ButtonComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="7573fced4d31e22c" memberName="component3"
                    virtualName="" explicitFocusOrder="0" pos="152 16 264 184" class="LcdComponent"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="861bf97a116da038" memberName="button2"
                    virtualName="" explicitFocusOrder="0" pos="408 216 150 100" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cca2991e83211b03" memberName="button3"
                    virtualName="" explicitFocusOrder="0" pos="560 216 150 100" class="ButtonComponent"
                    params="3"/>
  <GENERICCOMPONENT name="new component" id="55078e15f0f63310" memberName="button4"
                    virtualName="" explicitFocusOrder="0" pos="712 216 150 100" class="ButtonComponent"
                    params="4"/>
  <GENERICCOMPONENT name="new component" id="4e2c39eb9901bafa" memberName="button5"
                    virtualName="" explicitFocusOrder="0" pos="864 216 150 100" class="ButtonComponent"
                    params="5"/>
  <GENERICCOMPONENT name="new component" id="7d197ce88964b076" memberName="button8"
                    virtualName="" explicitFocusOrder="0" pos="368 432 150 100" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cf84319870e14f59" memberName="button9"
                    virtualName="" explicitFocusOrder="0" pos="528 432 150 100" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="58d87616809bd36b" memberName="button10"
                    virtualName="" explicitFocusOrder="0" pos="704 432 150 100" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="90f3cc09fbe0200c" memberName="button11"
                    virtualName="" explicitFocusOrder="0" pos="848 432 150 100" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="b5b5c0f7c3d665ea" memberName="button6"
                    virtualName="" explicitFocusOrder="0" pos="32 432 150 100" class="ButtonComponent"
                    params="6"/>
  <GENERICCOMPONENT name="new component" id="475cf3242e81e9fa" memberName="button7"
                    virtualName="" explicitFocusOrder="0" pos="192 432 150 100" class="ButtonComponent"
                    params="2"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
