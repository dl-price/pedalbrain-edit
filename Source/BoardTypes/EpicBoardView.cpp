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

#include "EpicBoardView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EpicBoardView::EpicBoardView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component2 = new LedComponent (1));
    component2->setName ("new component");

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

    addAndMakeVisible (component8 = new LedComponent (1));
    component8->setName ("new component");

    addAndMakeVisible (component9 = new LedComponent (1));
    component9->setName ("new component");

    addAndMakeVisible (component10 = new LedComponent (1));
    component10->setName ("new component");

    addAndMakeVisible (component11 = new LedComponent (1));
    component11->setName ("new component");

    addAndMakeVisible (button8 = new ButtonComponent (2));
    button8->setName ("new component");

    addAndMakeVisible (button9 = new ButtonComponent (2));
    button9->setName ("new component");

    addAndMakeVisible (button10 = new ButtonComponent (2));
    button10->setName ("new component");

    addAndMakeVisible (button11 = new ButtonComponent (2));
    button11->setName ("new component");

    addAndMakeVisible (component16 = new LedComponent (1));
    component16->setName ("new component");

    addAndMakeVisible (component17 = new LedComponent (1));
    component17->setName ("new component");

    addAndMakeVisible (component18 = new LedComponent (1));
    component18->setName ("new component");

    addAndMakeVisible (component19 = new LedComponent (1));
    component19->setName ("new component");

    addAndMakeVisible (button6 = new ButtonComponent (6));
    button6->setName ("new component");

    addAndMakeVisible (button7 = new ButtonComponent (2));
    button7->setName ("new component");

    addAndMakeVisible (component22 = new LedComponent (1));
    component22->setName ("new component");

    addAndMakeVisible (component23 = new LedComponent (1));
    component23->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..

    buttonComponents = OwnedArray<ButtonComponent>();

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

    component2 = nullptr;
    button1 = nullptr;
    component3 = nullptr;
    button2 = nullptr;
    button3 = nullptr;
    button4 = nullptr;
    button5 = nullptr;
    component8 = nullptr;
    component9 = nullptr;
    component10 = nullptr;
    component11 = nullptr;
    button8 = nullptr;
    button9 = nullptr;
    button10 = nullptr;
    button11 = nullptr;
    component16 = nullptr;
    component17 = nullptr;
    component18 = nullptr;
    component19 = nullptr;
    button6 = nullptr;
    button7 = nullptr;
    component22 = nullptr;
    component23 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EpicBoardView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EpicBoardView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component2->setBounds (8, 120, 150, 24);
    button1->setBounds (0, 216, 152, 32);
    component3->setBounds (160, 64, 264, 184);
    button2->setBounds (424, 216, 143, 32);
    button3->setBounds (584, 216, 127, 32);
    button4->setBounds (720, 216, 143, 32);
    button5->setBounds (864, 216, 135, 32);
    component8->setBounds (424, 120, 150, 24);
    component9->setBounds (576, 120, 150, 24);
    component10->setBounds (728, 120, 128, 24);
    component11->setBounds (872, 120, 126, 24);
    button8->setBounds (368, 432, 199, 32);
    button9->setBounds (584, 432, 127, 32);
    button10->setBounds (720, 432, 143, 32);
    button11->setBounds (864, 432, 135, 32);
    component16->setBounds (376, 336, 198, 24);
    component17->setBounds (576, 336, 150, 24);
    component18->setBounds (728, 336, 128, 24);
    component19->setBounds (872, 336, 126, 24);
    button6->setBounds (32, 432, 143, 32);
    button7->setBounds (192, 432, 160, 32);
    component22->setBounds (32, 336, 150, 24);
    component23->setBounds (184, 336, 184, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void EpicBoardView::init()
{
    int numChild = getNumChildComponents();

    MidiOutput *output = MidiOutput::createNewDevice("Juce Device");

    for(int i=0; i < numChild; i++)
    {


        ButtonComponent *component = dynamic_cast<ButtonComponent*>(getChildComponent(i));
        {
            if(component)
            {
                const MessageManagerLock mmLock;
                component->addMouseListener(this, true);

                MidiMessage msg =  MidiMessage::createSysExMessage("}Hello", strlen("}Hello"));
                //msg.sys
                output->sendMessageNow(msg);

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
    ButtonComponent *component = dynamic_cast<ButtonComponent*>(event.eventComponent);
    if(component)
    {
        BoardController *contrl = BoardController::getInstance();
        int i = buttonComponents.indexOf(component);
        contrl->createEditWindowForButton(contrl->pages[getPage()-1]->buttons[i]);
        Logger::outputDebugString("Clicked page " + String(getPage()) + " button index " + String(i));
        return;
    }
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
  <GENERICCOMPONENT name="new component" id="71c4041d257d0261" memberName="component2"
                    virtualName="" explicitFocusOrder="0" pos="8 120 150 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="ddf151a0b324bd1a" memberName="button1"
                    virtualName="" explicitFocusOrder="0" pos="0 216 152 32" class="ButtonComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="7573fced4d31e22c" memberName="component3"
                    virtualName="" explicitFocusOrder="0" pos="160 64 264 184" class="LcdComponent"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="861bf97a116da038" memberName="button2"
                    virtualName="" explicitFocusOrder="0" pos="424 216 143 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cca2991e83211b03" memberName="button3"
                    virtualName="" explicitFocusOrder="0" pos="584 216 127 32" class="ButtonComponent"
                    params="3"/>
  <GENERICCOMPONENT name="new component" id="55078e15f0f63310" memberName="button4"
                    virtualName="" explicitFocusOrder="0" pos="720 216 143 32" class="ButtonComponent"
                    params="4"/>
  <GENERICCOMPONENT name="new component" id="4e2c39eb9901bafa" memberName="button5"
                    virtualName="" explicitFocusOrder="0" pos="864 216 135 32" class="ButtonComponent"
                    params="5"/>
  <GENERICCOMPONENT name="new component" id="b59a825875107423" memberName="component8"
                    virtualName="" explicitFocusOrder="0" pos="424 120 150 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="4ba0ded83b3bceb2" memberName="component9"
                    virtualName="" explicitFocusOrder="0" pos="576 120 150 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="53a92b7b77bc25df" memberName="component10"
                    virtualName="" explicitFocusOrder="0" pos="728 120 128 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="5aa954f93febfc6d" memberName="component11"
                    virtualName="" explicitFocusOrder="0" pos="872 120 126 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="7d197ce88964b076" memberName="button8"
                    virtualName="" explicitFocusOrder="0" pos="368 432 199 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cf84319870e14f59" memberName="button9"
                    virtualName="" explicitFocusOrder="0" pos="584 432 127 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="58d87616809bd36b" memberName="button10"
                    virtualName="" explicitFocusOrder="0" pos="720 432 143 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="90f3cc09fbe0200c" memberName="button11"
                    virtualName="" explicitFocusOrder="0" pos="864 432 135 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="f91a9f945e002c97" memberName="component16"
                    virtualName="" explicitFocusOrder="0" pos="376 336 198 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="183fdab9a96d6dea" memberName="component17"
                    virtualName="" explicitFocusOrder="0" pos="576 336 150 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="36e2dd4c6a06b46" memberName="component18"
                    virtualName="" explicitFocusOrder="0" pos="728 336 128 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="fff7c30441a194b0" memberName="component19"
                    virtualName="" explicitFocusOrder="0" pos="872 336 126 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="b5b5c0f7c3d665ea" memberName="button6"
                    virtualName="" explicitFocusOrder="0" pos="32 432 143 32" class="ButtonComponent"
                    params="6"/>
  <GENERICCOMPONENT name="new component" id="475cf3242e81e9fa" memberName="button7"
                    virtualName="" explicitFocusOrder="0" pos="192 432 160 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="aa07d746e15a8bde" memberName="component22"
                    virtualName="" explicitFocusOrder="0" pos="32 336 150 24" class="LedComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="990c829bf9e7223f" memberName="component23"
                    virtualName="" explicitFocusOrder="0" pos="184 336 184 24" class="LedComponent"
                    params="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
