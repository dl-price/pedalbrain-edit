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
#include "includes.h"
#include "../Application.h"
#include <future>
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

    addAndMakeVisible (nameEditor = new TextEditor ("name editor"));
    nameEditor->setMultiLine (false);
    nameEditor->setReturnKeyStartsNewLine (false);
    nameEditor->setReadOnly (false);
    nameEditor->setScrollbarsShown (false);
    nameEditor->setCaretVisible (true);
    nameEditor->setPopupMenuEnabled (false);
    nameEditor->setColour (TextEditor::outlineColourId, Colours::black);
    nameEditor->setText (String());

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Name:")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("MIDI Channel:")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channelCombo = new ComboBox ("channel combo"));
    channelCombo->setEditableText (false);
    channelCombo->setJustificationType (Justification::centredLeft);
    channelCombo->setTextWhenNothingSelected (String());
    channelCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    channelCombo->addItem (TRANS("1"), 1);
    channelCombo->addItem (TRANS("2"), 2);
    channelCombo->addItem (TRANS("3"), 3);
    channelCombo->addItem (TRANS("4"), 4);
    channelCombo->addItem (TRANS("5"), 5);
    channelCombo->addItem (TRANS("6"), 6);
    channelCombo->addItem (TRANS("7"), 7);
    channelCombo->addItem (TRANS("8"), 8);
    channelCombo->addItem (TRANS("9"), 9);
    channelCombo->addItem (TRANS("10"), 10);
    channelCombo->addItem (TRANS("11"), 11);
    channelCombo->addItem (TRANS("12"), 12);
    channelCombo->addItem (TRANS("13"), 13);
    channelCombo->addItem (TRANS("14"), 14);
    channelCombo->addItem (TRANS("15"), 15);
    channelCombo->addItem (TRANS("16"), 16);
    channelCombo->addListener (this);

    addAndMakeVisible (presetTable = new TableListBox());
    presetTable->setName ("preset table");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    deviceTable->setModel(this);

    // Set up device type lists

    for(int i = 0; i < DeviceManager::getInstance()->manufacturers.size();i++)
    {
        manufacturerCombo->addItem(DeviceManager::getInstance()->manufacturers[i]->name, i+1);
    }

    BoardController::addListener(this);
    nameEditor->addListener(this);

    presetTable->getHeader().addColumn("Preset", 1, 100);
    presetTable->getHeader().addColumn("Name", 2, 100);
    presetTable->autoSizeAllColumns();

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
    nameEditor = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    channelCombo = nullptr;
    presetTable = nullptr;


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
    nameEditor->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + proportionOfWidth (0.6497f) - 20 - (roundFloatToInt (proportionOfWidth (0.6497f) * 0.7795f)), 20 + 80, roundFloatToInt (proportionOfWidth (0.6497f) * 0.7795f), 24);
    label3->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + 20, 20 + 80, 150, 24);
    label4->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + 20, 20 + 120, 150, 24);
    channelCombo->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + proportionOfWidth (0.6497f) - 20 - (roundFloatToInt (proportionOfWidth (0.6497f) * 0.7795f)), 20 + 120, roundFloatToInt (proportionOfWidth (0.6497f) * 0.7795f), 24);
    presetTable->setBounds ((proportionOfWidth (0.9850f) - proportionOfWidth (0.6497f)) + 20, (20 + 120) + 24 - -20, proportionOfWidth (0.6497f) - 40, getHeight() - 230);
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

        Manufacturer * man = DeviceManager::getInstance()->manufacturers[comboBoxThatHasChanged->getSelectedItemIndex()];

        modelCombo->clear();

        for(int i = 0; i < man->deviceTypes.size();i++)
        {
            modelCombo->addItem(man->deviceTypes[i]->name, i+1);
        }
        if(comboBoxThatHasChanged->getSelectedItemIndex() == 0)
        {
            BoardController::getInstance()->devices[showingDevice]->setType(DeviceManager::getInstance()->deviceTypes[0]);
            modelCombo->setTextWhenNothingSelected("None");
            saveToModel();
            presetTable->setModel(BoardController::getInstance()->devices[showingDevice]);
            presetTable->updateContent();
        }

        //[/UserComboBoxCode_manufacturerCombo]
    }
    else if (comboBoxThatHasChanged == modelCombo)
    {
        //[UserComboBoxCode_modelCombo] -- add your combo box handling code here..

        Manufacturer * man = DeviceManager::getInstance()->manufacturers[manufacturerCombo->getSelectedItemIndex()];
        DeviceType *type = man->deviceTypes[comboBoxThatHasChanged->getSelectedItemIndex()];
        BoardController::getInstance()->devices[showingDevice]->setType(type);
        if(showingDevice>=0)
        {
            saveToModel();
        }

        //[/UserComboBoxCode_modelCombo]
    }
    else if (comboBoxThatHasChanged == channelCombo)
    {
        //[UserComboBoxCode_channelCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_channelCombo]
        if(showingDevice>=0)
        {
            saveToModel();
        }
    }

    //[UsercomboBoxChanged_Post]

    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int DevicesTab::getNumRows()
{
    if(BoardController::getInstance())
    {
        return BoardController::getInstance()->getMaxDevices();
    }
    return 0;
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

    BoardController *cntrl = BoardController::getInstance();

    const MessageManagerLock mmlock;
    g.drawText("Device " + text + " - " + cntrl->devices[rowNumber]->getName().getValue().toString(), 2, 0, width - 4, height, Justification::left, true);



}

void DevicesTab::boardControllerChanged()
{
    const MessageManagerLock mmLock;
    deviceTable->updateContent();
}

void DevicesTab::textEditorTextChanged(juce::TextEditor &editor)
{

    saveToModel();


    deviceTable->repaintRow(showingDevice);


}

void DevicesTab::selectedRowsChanged(int lastRowSelected)
{


    showingDevice = deviceTable->getSelectedRow();
    refreshFromSelectedModel();

}

void DevicesTab::saveToModel()
{
    BoardController *cntrl = BoardController::getInstance();

    ReferenceCountedObjectPtr<Device> currDevice = cntrl->devices[showingDevice];


}

void DevicesTab::refreshFromSelectedModel()
{
    BoardController *cntrl = BoardController::getInstance();

    Device *currDevice = cntrl->devices[showingDevice];

    if(currDevice->getType())
    {

        manufacturerCombo->setSelectedItemIndex(DeviceManager::getInstance()->manufacturers.indexOf(currDevice->getType()->manufacturer));
        modelCombo->clear();
        modelCombo->setTextWhenNothingSelected(currDevice->getType()->name);
        //modelCombo->setSelectedItemIndex(currDevice->deviceType->manufacturer->deviceTypes.indexOf(currDevice->deviceType));
        //Manufacturer * man = DeviceManager::getInstance()->manufacturers[manufacturerCombo->getSelectedItemIndex()];

    }
    else
    {
        manufacturerCombo->setSelectedItemIndex(0);

        modelCombo->clear();
        modelCombo->setTextWhenNothingSelected("None");


    }



    nameEditor->getTextValue().referTo(currDevice->getName());

    channelCombo->getSelectedIdAsValue().referTo(currDevice->getChannel());
    presetTable->setModel(currDevice);
    presetTable->updateContent();
}



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DevicesTab" componentName=""
                 parentClasses="public Component, ListBoxModel, BoardControllerListener, TextEditorListener, TableListBoxModel"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="device list group" id="1800231c5f32097d" memberName="deviceListGroup"
                  virtualName="" explicitFocusOrder="0" pos="1.596% 20 30.053% 40M"
                  title="Device List"/>
  <GROUPCOMPONENT name="new group" id="e8f732dbffd928cb" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="98.404%r 20 64.894% 40M"
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
            virtualName="" explicitFocusOrder="0" pos="0Cr 40 29.918% 24"
            posRelativeX="e8f732dbffd928cb" posRelativeY="1800231c5f32097d"
            posRelativeW="e8f732dbffd928cb" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="model combo" id="f22149194db014db" memberName="modelCombo"
            virtualName="ComboBox" explicitFocusOrder="0" pos="20Rr 40 29.918% 24"
            posRelativeX="e8f732dbffd928cb" posRelativeY="e8f732dbffd928cb"
            posRelativeW="e8f732dbffd928cb" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="name editor" id="11b1fe24822e9e8" memberName="nameEditor"
              virtualName="" explicitFocusOrder="0" pos="20Rr 80 77.869% 24"
              posRelativeX="e8f732dbffd928cb" posRelativeY="e8f732dbffd928cb"
              posRelativeW="e8f732dbffd928cb" outlinecol="ff000000" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="0"/>
  <LABEL name="new label" id="c38b846e67c7b662" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="20 80 150 24" posRelativeX="e8f732dbffd928cb"
         posRelativeY="e8f732dbffd928cb" edTextCol="ff000000" edBkgCol="0"
         labelText="Name:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2be0348d58ff23bf" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="20 120 150 24" posRelativeX="e8f732dbffd928cb"
         posRelativeY="e8f732dbffd928cb" edTextCol="ff000000" edBkgCol="0"
         labelText="MIDI Channel:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="channel combo" id="ff774dc4ca6d2f79" memberName="channelCombo"
            virtualName="" explicitFocusOrder="0" pos="20Rr 120 77.869% 24"
            posRelativeX="e8f732dbffd928cb" posRelativeY="e8f732dbffd928cb"
            posRelativeW="e8f732dbffd928cb" editable="0" layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11&#10;12&#10;13&#10;14&#10;15&#10;16"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GENERICCOMPONENT name="preset table" id="ba0a834c934bd158" memberName="presetTable"
                    virtualName="TableListBox" explicitFocusOrder="0" pos="20 -20R 40M 230M"
                    posRelativeX="e8f732dbffd928cb" posRelativeY="ff774dc4ca6d2f79"
                    posRelativeW="e8f732dbffd928cb" class="Component" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
