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
#include "Application.h"
#include "Macros.h"
//[/Headers]

#include "ButtonEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

void ButtonEdit::selectType(int typeId)
{
    typeComboBox->setSelectedId(typeId);
}

//[/MiscUserDefs]

//==============================================================================
ButtonEdit::ButtonEdit (ButtonModel *model)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (closeButton = new TextButton ("close button"));
    closeButton->setButtonText (TRANS("Close"));
    closeButton->addListener (this);

    addAndMakeVisible (mainGroup = new GroupComponent ("new group",
                                                       TRANS("Main Settings")));

    addAndMakeVisible (typeComboBox = new ComboBox ("new combo box"));
    typeComboBox->setEditableText (false);
    typeComboBox->setJustificationType (Justification::centredLeft);
    typeComboBox->setTextWhenNothingSelected (String());
    typeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    typeComboBox->addListener (this);

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

    addAndMakeVisible (mainSettingsHolder = new Component());
    mainSettingsHolder->setName ("new component");


    //[UserPreSize]
    mainSettingsFlexBox = new FlexBox();
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    _buttonModel = model;

    addComboBoxOptions();
    addLedOptions(ledOn);
    addLedOptions(ledOff);

    typeComboBox->getSelectedIdAsValue().referTo(_buttonModel->buttonType);
    buttonName->getTextValue().referTo(_buttonModel->name);
    buttonLabel->getTextValue().referTo(_buttonModel->label);
    ledOn->getSelectedIdAsValue().referTo(_buttonModel->ledOn);
    ledOff->getSelectedIdAsValue().referTo(_buttonModel->ledOff);
    
    refreshMainSettingsComponents();

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
    removeFlexBoxComponents(mainSettingsFlexBox);
    //[/Destructor_pre]

    closeButton = nullptr;
    mainGroup = nullptr;
    typeComboBox = nullptr;
    displayGroup = nullptr;
    buttonName = nullptr;
    buttonLabel = nullptr;
    ledOn = nullptr;
    ledOff = nullptr;
    mainSettingsHolder = nullptr;


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
    mainGroup->setBounds (20, 20, proportionOfWidth (0.4799f), 216);
    typeComboBox->setBounds (40, 20 + 20, proportionOfWidth (0.4799f) - 40, 24);
    displayGroup->setBounds (getWidth() - 20 - proportionOfWidth (0.4799f), 20, proportionOfWidth (0.4799f), 216);
    buttonName->setBounds ((getWidth() - 20 - proportionOfWidth (0.4799f)) + 20, 20 + 20, proportionOfWidth (0.4799f) - 40, 24);
    buttonLabel->setBounds ((getWidth() - 20 - proportionOfWidth (0.4799f)) + 20, (20 + 20) + 24 - -20, proportionOfWidth (0.4799f) - 40, 24);
    ledOn->setBounds ((getWidth() - 20 - proportionOfWidth (0.4799f)) + 20, ((20 + 20) + 24 - -20) + 36, proportionOfWidth (0.4799f) - 40, 24);
    ledOff->setBounds ((getWidth() - 20 - proportionOfWidth (0.4799f)) + 20, (((20 + 20) + 24 - -20) + 36) + 24 - -20, proportionOfWidth (0.4799f) - 40, 24);
    mainSettingsHolder->setBounds (20 + 20, (20 + 20) + 24 - -20, proportionOfWidth (0.4799f) - 40, 216 - 88);
    //[UserResized] Add your own custom resize handling here..
    mainSettingsFlexBox->performLayout(mainSettingsHolder->getBounds());
    //[/UserResized]
}

void ButtonEdit::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == closeButton)
    {
        //[UserButtonCode_closeButton] -- add your button handler code here..

        if(appObject->getDefaultBoardController()->sysexHandler)
        {
            _buttonModel->sendToBoard();
        }
        dynamic_cast<pedalbraineditApplication::MainWindow*>(ResizableWindow::getActiveTopLevelWindow())->removeButtonEdit();

        //[/UserButtonCode_closeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ButtonEdit::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == typeComboBox)
    {
        //[UserComboBoxCode_typeComboBox] -- add your combo box handling code here..
        refreshMainSettingsComponents();
        //[/UserComboBoxCode_typeComboBox]
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
    if(comboBoxThatHasChanged->getName() == "mainDeviceId")
    {
        _buttonModel->setProperty("mainDeviceId", comboBoxThatHasChanged->getSelectedId());
    }
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ButtonEdit::addLedOptions(juce::ComboBox *box)
{
    box->clear();
    if(!appObject->getDefaultBoardController()->ledIsRgbForIndex(_buttonModel->getIndex()))
    {
        box->addItem("Off", ButtonModel::LedColor::Black);
        box->addItem("On", ButtonModel::LedColor::White);
    }
    else {
        box->addItem("Black", ButtonModel::LedColor::Black);
        box->addItem("White", ButtonModel::LedColor::White);
        box->addItem("Red", ButtonModel::LedColor::Red);
        box->addItem("Green", ButtonModel::LedColor::Green);
        box->addItem("Blue", ButtonModel::LedColor::Blue);
        box->addItem("Cyan", ButtonModel::LedColor::Cyan);
        box->addItem("Yellow", ButtonModel::LedColor::Yellow);
        box->addItem("Purple", ButtonModel::LedColor::Purple);
    }
}

void ButtonEdit::addComboBoxOptions()
{
    typeComboBox->clear();
    typeComboBox->addItem("Off", ButtonModel::ButtonType::Off);
    typeComboBox->addItem("Normal", ButtonModel::ButtonType::Normal);
    typeComboBox->addItem("Bank Up", ButtonModel::ButtonType::BankUp);
    typeComboBox->addItem("Bank Down", ButtonModel::ButtonType::BankDown);
    typeComboBox->addItem("Device PC +", ButtonModel::ButtonType::DevicePCUp);
    typeComboBox->addItem("Device PC -", ButtonModel::ButtonType::DevicePCDown);
    typeComboBox->addItem("Device PC", ButtonModel::ButtonType::DevicePC);
    typeComboBox->addItem("Store", ButtonModel::ButtonType::Store);
    typeComboBox->addItem("Page", ButtonModel::ButtonType::Page);
    typeComboBox->addItem("Page Up", ButtonModel::ButtonType::PageUp);
    typeComboBox->addItem("Page Down", ButtonModel::ButtonType::PageDown);
    typeComboBox->addItem("Preset", ButtonModel::ButtonType::Preset);
    typeComboBox->addItem("Preset Up", ButtonModel::ButtonType::PresetUp);
    typeComboBox->addItem("Preset Down", ButtonModel::ButtonType::PresetDown);
}

void ButtonEdit::refreshMainSettingsComponents()
{
    removeFlexBoxComponents(mainSettingsFlexBox);
    
    addFlexBoxComponents(mainSettingsFlexBox, typeComboBox->getSelectedId());
    
    resized();
}

void ButtonEdit::removeFlexBoxComponents(juce::FlexBox *flexBox)
{
    for(int i=0;i< flexBox->items.size(); i++)
    {
        ScopedPointer<Component> child = flexBox->items[i].associatedComponent ;
        removeChildComponent(child);
    }
    
    flexBox->items.clear();
}

void ButtonEdit::addFlexBoxComponents(juce::FlexBox *flexBox, int type)
{
    if(flexBox == mainSettingsFlexBox)
    {
        switch(type)
        {
            case ButtonModel::ButtonType::Page:
            {
                
                createAndAddFlexLabel("Page Number:", mainSettingsFlexBox);
                
                TextEditor *pgEdit = new TextEditor();
                pgEdit->setTextToShowWhenEmpty("Current", Colours::black);
                pgEdit->setName("mainPageName");
                if(_buttonModel->hasProperty("mainPageName"))
                {
                    pgEdit->setText(_buttonModel->getProperty("mainPageName"));
                }
                pgEdit->addListener(this);
                addAndMakeVisible(pgEdit);
                
                FlexItem *flItem2 = new FlexItem(*pgEdit);
                setupFlexItemForInput(flItem2);
                mainSettingsFlexBox->items.add(*flItem2);
                
                break;
            }
            case ButtonModel::ButtonType::DevicePCDown:
            case ButtonModel::ButtonType::DevicePCUp:
            {
                createAndAddFlexLabel("Device:", mainSettingsFlexBox);
                
                ComboBox *deviceCombo = new ComboBox();
                deviceCombo->setTextWhenNothingSelected("No device");
                deviceCombo->setName("mainDeviceId");
                
                for(int i=1; i <= appObject->getDefaultBoardController()->devices.size(); i++)
                {
                    if(appObject->getDefaultBoardController()->devices[i-1]->getName().toString().length())
                    {
                        deviceCombo->addItem(appObject->getDefaultBoardController()->devices[i-1]->getName().toString(), i);
                    }
                }
                
                if(_buttonModel->hasProperty("mainDeviceId"))
                {
                    deviceCombo->setSelectedId(_buttonModel->getProperty("mainDeviceId"));
                }
                addAndMakeVisible(deviceCombo);
                deviceCombo->addListener(this);
                
                FlexItem *flexItem = new FlexItem(*deviceCombo);
                setupFlexItemForInput(flexItem);
                mainSettingsFlexBox->items.add(*flexItem);
                
                break;
            }
            case ButtonModel::ButtonType::DevicePC:
            {
                createAndAddFlexLabel("Device:", mainSettingsFlexBox);
                
                ComboBox *deviceCombo = new ComboBox();
                deviceCombo->setTextWhenNothingSelected("No device");
                deviceCombo->setName("mainDeviceId");
                
                for(int i=1; i <= appObject->getDefaultBoardController()->devices.size(); i++)
                {
                    if(appObject->getDefaultBoardController()->devices[i-1]->getName().toString().length())
                    {
                        deviceCombo->addItem(appObject->getDefaultBoardController()->devices[i-1]->getName().toString(), i);
                    }
                }
                
                if(_buttonModel->hasProperty("mainDeviceId"))
                {
                    deviceCombo->setSelectedId(_buttonModel->getProperty("mainDeviceId"));
                }
                addAndMakeVisible(deviceCombo);
                deviceCombo->addListener(this);
                
                FlexItem *flexItem = new FlexItem(*deviceCombo);
                setupFlexItemForInput(flexItem);
                mainSettingsFlexBox->items.add(*flexItem);
                
                createAndAddFlexLabel("PC Number", mainSettingsFlexBox);
                
                break;
            }
        }
    }
}

void ButtonEdit::setupFlexItemForInput(juce::FlexItem *flexItem)
{
    flexItem->minWidth = 150;
    flexItem->minHeight = 24;
    flexItem->maxHeight = 24;
    flexItem->flexGrow = 3;
}

void ButtonEdit::setupFlexItemForLabel(juce::FlexItem *flexItem)
{
    flexItem->minWidth = 150;
    flexItem->minHeight = 24;
    flexItem->flexGrow = 1;
    flexItem->maxHeight = 24;
}

void ButtonEdit::valueChanged(Value &valueChanged)
{
    
}

void ButtonEdit::textEditorTextChanged(juce::TextEditor &editor)
{
    if(editor.getName() == "mainPageName")
    {
        _buttonModel->setProperty(editor.getName(), editor.getTextValue().toString());
    }
}

FlexItem *ButtonEdit::createAndAddFlexLabel(juce::String labelValue, juce::FlexBox *flexBox)
{
    Label *ed = new Label();
    ed->setText(labelValue, NotificationType::dontSendNotification);
    addAndMakeVisible(ed);
    
    FlexItem *flItem = new FlexItem(*ed);
    setupFlexItemForLabel(flItem);
    flexBox->items.add(*flItem);
    
    return flItem;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ButtonEdit" componentName=""
                 parentClasses="public Component" constructorParams="ButtonModel *model"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="close button" id="9225ef9c71f0e7c" memberName="closeButton"
              virtualName="" explicitFocusOrder="0" pos="230R 50R 200 24" buttonText="Close"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="ed7339e39e40b2a2" memberName="mainGroup"
                  virtualName="" explicitFocusOrder="0" pos="20 20 47.872% 216"
                  title="Main Settings"/>
  <COMBOBOX name="new combo box" id="dc30121a21934289" memberName="typeComboBox"
            virtualName="" explicitFocusOrder="0" pos="40 20 40M 24" posRelativeY="ed7339e39e40b2a2"
            posRelativeW="ed7339e39e40b2a2" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GROUPCOMPONENT name="new group" id="a08e5079e3d1891d" memberName="displayGroup"
                  virtualName="" explicitFocusOrder="0" pos="20Rr 20 47.872% 216"
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
  <GENERICCOMPONENT name="new component" id="a8f3fa89279730c0" memberName="mainSettingsHolder"
                    virtualName="" explicitFocusOrder="0" pos="20 -20R 40M 88M" posRelativeX="ed7339e39e40b2a2"
                    posRelativeY="dc30121a21934289" posRelativeW="ed7339e39e40b2a2"
                    posRelativeH="ed7339e39e40b2a2" class="Component" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
