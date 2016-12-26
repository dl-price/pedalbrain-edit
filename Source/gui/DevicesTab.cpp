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

#include "DevicesTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DevicesTab::DevicesTab ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (deviceListGroup = new GroupComponent ("device list group",
                                                             TRANS("Device List")));

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("group")));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DevicesTab::~DevicesTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deviceListGroup = nullptr;
    groupComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DevicesTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DevicesTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    deviceListGroup->setBounds (proportionOfWidth (0.0150f), 20, proportionOfWidth (0.3000f), getHeight() - 40);
    groupComponent->setBounds (proportionOfWidth (0.9850f) - proportionOfWidth (0.6500f), 20, proportionOfWidth (0.6500f), getHeight() - 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DevicesTab" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="device list group" id="1800231c5f32097d" memberName="deviceListGroup"
                  virtualName="" explicitFocusOrder="0" pos="1.504% 20 30.014% 40M"
                  title="Device List"/>
  <GROUPCOMPONENT name="new group" id="e8f732dbffd928cb" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="98.496%r 20 64.971% 40M"
                  title="group"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
