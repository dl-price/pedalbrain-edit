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

#include "../includes.h"
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
                                                            TRANS("Device Settings")));

    addAndMakeVisible (deviceTable = new ListBox());
    deviceTable->setName ("device table");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Manufacturer:")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Model:")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (manufacturerCombo = new ComboBox ("manufactrer combo"));
    manufacturerCombo->setEditableText (false);
    manufacturerCombo->setJustificationType (Justification::centredLeft);
    manufacturerCombo->setTextWhenNothingSelected (String());
    manufacturerCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    manufacturerCombo->addListener (this);

    addAndMakeVisible (modelCombo = new ComboBox ("model combo"));
    modelCombo->setEditableText (false);
    modelCombo->setJustificationType (Justification::centredLeft);
    modelCombo->setTextWhenNothingSelected (String());
    modelCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    modelCombo->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    deviceTable->setModel(this);
    
    // Set up device type lists
    
    for(int i = 0; i < DeviceManager::manufacturers.size();i++)
    {
        manufacturerCombo->addItem(DeviceManager::manufacturers[i]->name, i+1);
    }



    //[/Constructor]
}

DevicesTab::~DevicesTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deviceListGroup = nullptr;
    groupComponent = nullptr;
    deviceTable = nullptr;
    label = nullptr;
    label2 = nullptr;
    manufacturerCombo = nullptr;
    modelCombo = nullptr;


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

    deviceListGroup->setBounds (proportionOfWidth (0.0150f), 20, proportionOfWidth (0.3001f), getHeight() - 40);
    groupComponent->setBounds (proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f), 20, proportionOfWidth (0.6497f), getHeight() - 40);
    deviceTable->setBounds (proportionOfWidth (0.0150f) + 20, 20 + 20, proportionOfWidth (0.3001f) - 40, (getHeight() - 40) - 40);
    label->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + 20, 20 + 40, 150, 24);
    label2->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + proportionOfWidth (0.6497f) / 2 + 20, 20 + 40, 150, 24);
    manufacturerCombo->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + proportionOfWidth (0.6497f) / 2 - (roundFloatToInt (proportionOfWidth (0.6497f) * 0.2999f)), 20 + 40, roundFloatToInt (proportionOfWidth (0.6497f) * 0.2999f), 24);
    modelCombo->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + proportionOfWidth (0.6497f) - 20 - (roundFloatToInt (proportionOfWidth (0.6497f) * 0.2999f)), 20 + 40, roundFloatToInt (proportionOfWidth (0.6497f) * 0.2999f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DevicesTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == manufacturerCombo)
    {
        //[UserComboBoxCode_manufacturerCombo] -- add your combo box handling code here..
        
        Manufacturer * man = DeviceManager::manufacturers[comboBoxThatHasChanged->getSelectedItemIndex()];
        
        modelCombo->clear();
        
        for(int i = 0; i < man->deviceTypes.size();i++)
        {
            modelCombo->addItem(man->deviceTypes[i]->name, i+1);
        }
        
        //[/UserComboBoxCode_manufacturerCombo]
    }
    else if (comboBoxThatHasChanged == modelCombo)
    {
        //[UserComboBoxCode_modelCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_modelCombo]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int DevicesTab::getNumRows()
{

    return 16;
}

void DevicesTab::paintListBoxItem(int rowNumber, juce::Graphics &g, int width, int height, bool rowIsSelected)
{
    if(rowIsSelected)
    {
        g.setColour(Colours::cornflowerblue);
    }
    else {
        g.setColour(Colours::white);
    }
    g.fillAll();

    g.setColour(Colours::black);
    char buffer[20];
    sprintf(buffer, "%03d", rowNumber+1);
    const String text(buffer);
    g.drawText("Device " + text + " - ", 2, 0, width - 4, height, Justification::left, true);

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DevicesTab" componentName=""
                 parentClasses="public Component, ListBoxModel" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="device list group" id="1800231c5f32097d" memberName="deviceListGroup"
                  virtualName="" explicitFocusOrder="0" pos="1.504% 20 30.014% 40M"
                  title="Device List"/>
  <GROUPCOMPONENT name="new group" id="e8f732dbffd928cb" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="98.496%r 20 64.971% 40M"
                  title="Device Settings"/>
  <GENERICCOMPONENT name="device table" id="63bf6443f48fe433" memberName="deviceTable"
                    virtualName="" explicitFocusOrder="0" pos="20 20 40M 40M" posRelativeX="1800231c5f32097d"
                    posRelativeY="1800231c5f32097d" posRelativeW="1800231c5f32097d"
                    posRelativeH="1800231c5f32097d" class="ListBox" params=""/>
  <LABEL name="new label" id="bde35a5d9f859491" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="20 40 150 24" posRelativeX="e8f732dbffd928cb"
         posRelativeY="e8f732dbffd928cb" edTextCol="ff000000" edBkgCol="0"
         labelText="Manufacturer:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6b032936723c3db" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="20C 40 150 24" posRelativeX="e8f732dbffd928cb"
         posRelativeY="e8f732dbffd928cb" edTextCol="ff000000" edBkgCol="0"
         labelText="Model:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="manufactrer combo" id="aadf83bdc8474a8a" memberName="manufacturerCombo"
            virtualName="" explicitFocusOrder="0" pos="0Cr 40 29.989% 24"
            posRelativeX="e8f732dbffd928cb" posRelativeY="1800231c5f32097d"
            posRelativeW="e8f732dbffd928cb" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="model combo" id="f22149194db014db" memberName="modelCombo"
            virtualName="" explicitFocusOrder="0" pos="20Rr 40 29.989% 24"
            posRelativeX="e8f732dbffd928cb" posRelativeY="e8f732dbffd928cb"
            posRelativeW="e8f732dbffd928cb" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
