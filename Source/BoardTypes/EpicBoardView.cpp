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

    addAndMakeVisible (component = new ButtonComponent (1));
    component->setName ("new component");

    addAndMakeVisible (component3 = new LcdComponent());
    component3->setName ("new component");

    addAndMakeVisible (component4 = new ButtonComponent (2));
    component4->setName ("new component");

    addAndMakeVisible (component5 = new ButtonComponent (3));
    component5->setName ("new component");

    addAndMakeVisible (component6 = new ButtonComponent (4));
    component6->setName ("new component");

    addAndMakeVisible (component7 = new ButtonComponent (5));
    component7->setName ("new component");

    addAndMakeVisible (component8 = new LedComponent (1));
    component8->setName ("new component");

    addAndMakeVisible (component9 = new LedComponent (1));
    component9->setName ("new component");

    addAndMakeVisible (component10 = new LedComponent (1));
    component10->setName ("new component");

    addAndMakeVisible (component11 = new LedComponent (1));
    component11->setName ("new component");

    addAndMakeVisible (component12 = new ButtonComponent (2));
    component12->setName ("new component");

    addAndMakeVisible (component13 = new ButtonComponent (2));
    component13->setName ("new component");

    addAndMakeVisible (component14 = new ButtonComponent (2));
    component14->setName ("new component");

    addAndMakeVisible (component15 = new ButtonComponent (2));
    component15->setName ("new component");

    addAndMakeVisible (component16 = new LedComponent (1));
    component16->setName ("new component");

    addAndMakeVisible (component17 = new LedComponent (1));
    component17->setName ("new component");

    addAndMakeVisible (component18 = new LedComponent (1));
    component18->setName ("new component");

    addAndMakeVisible (component19 = new LedComponent (1));
    component19->setName ("new component");

    addAndMakeVisible (component20 = new ButtonComponent (6));
    component20->setName ("new component");

    addAndMakeVisible (component21 = new ButtonComponent (2));
    component21->setName ("new component");

    addAndMakeVisible (component22 = new LedComponent (1));
    component22->setName ("new component");

    addAndMakeVisible (component23 = new LedComponent (1));
    component23->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..
    
    
    
    //[/Constructor]
}

EpicBoardView::~EpicBoardView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component2 = nullptr;
    component = nullptr;
    component3 = nullptr;
    component4 = nullptr;
    component5 = nullptr;
    component6 = nullptr;
    component7 = nullptr;
    component8 = nullptr;
    component9 = nullptr;
    component10 = nullptr;
    component11 = nullptr;
    component12 = nullptr;
    component13 = nullptr;
    component14 = nullptr;
    component15 = nullptr;
    component16 = nullptr;
    component17 = nullptr;
    component18 = nullptr;
    component19 = nullptr;
    component20 = nullptr;
    component21 = nullptr;
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
    component->setBounds (0, 216, 152, 32);
    component3->setBounds (160, 64, 264, 184);
    component4->setBounds (424, 216, 143, 32);
    component5->setBounds (584, 216, 127, 32);
    component6->setBounds (720, 216, 143, 32);
    component7->setBounds (864, 216, 135, 32);
    component8->setBounds (424, 120, 150, 24);
    component9->setBounds (576, 120, 150, 24);
    component10->setBounds (728, 120, 128, 24);
    component11->setBounds (872, 120, 126, 24);
    component12->setBounds (368, 432, 199, 32);
    component13->setBounds (584, 432, 127, 32);
    component14->setBounds (720, 432, 143, 32);
    component15->setBounds (864, 432, 135, 32);
    component16->setBounds (376, 336, 198, 24);
    component17->setBounds (576, 336, 150, 24);
    component18->setBounds (728, 336, 128, 24);
    component19->setBounds (872, 336, 126, 24);
    component20->setBounds (32, 432, 143, 32);
    component21->setBounds (192, 432, 160, 32);
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
                component->addMouseListener(this, true);
                Logger::outputDebugString("Added");
                
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
  <GENERICCOMPONENT name="new component" id="ddf151a0b324bd1a" memberName="component"
                    virtualName="" explicitFocusOrder="0" pos="0 216 152 32" class="ButtonComponent"
                    params="1"/>
  <GENERICCOMPONENT name="new component" id="7573fced4d31e22c" memberName="component3"
                    virtualName="" explicitFocusOrder="0" pos="160 64 264 184" class="LcdComponent"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="861bf97a116da038" memberName="component4"
                    virtualName="" explicitFocusOrder="0" pos="424 216 143 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cca2991e83211b03" memberName="component5"
                    virtualName="" explicitFocusOrder="0" pos="584 216 127 32" class="ButtonComponent"
                    params="3"/>
  <GENERICCOMPONENT name="new component" id="55078e15f0f63310" memberName="component6"
                    virtualName="" explicitFocusOrder="0" pos="720 216 143 32" class="ButtonComponent"
                    params="4"/>
  <GENERICCOMPONENT name="new component" id="4e2c39eb9901bafa" memberName="component7"
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
  <GENERICCOMPONENT name="new component" id="7d197ce88964b076" memberName="component12"
                    virtualName="" explicitFocusOrder="0" pos="368 432 199 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="cf84319870e14f59" memberName="component13"
                    virtualName="" explicitFocusOrder="0" pos="584 432 127 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="58d87616809bd36b" memberName="component14"
                    virtualName="" explicitFocusOrder="0" pos="720 432 143 32" class="ButtonComponent"
                    params="2"/>
  <GENERICCOMPONENT name="new component" id="90f3cc09fbe0200c" memberName="component15"
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
  <GENERICCOMPONENT name="new component" id="b5b5c0f7c3d665ea" memberName="component20"
                    virtualName="" explicitFocusOrder="0" pos="32 432 143 32" class="ButtonComponent"
                    params="6"/>
  <GENERICCOMPONENT name="new component" id="475cf3242e81e9fa" memberName="component21"
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
