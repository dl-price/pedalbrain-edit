/*
  ==============================================================================

    UberFlexBox.cpp
    Created: 8 Feb 2017 4:24:18pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "UberFlexBox.h"
#include "gui/ButtonEdit.h"

//==============================================================================

UberFlexBox::UberFlexBox(Component *newParent) : _parent(newParent)
{
    flexWrap = FlexBox::Wrap::wrap;
}

UberFlexBox::~UberFlexBox()
{
    removeFlexBoxComponents(*this);
    
    _parent = nullptr;
}

void UberFlexBox::removeFlexBoxComponents(juce::FlexBox &flexBox)
{
    for(int i=0;i< flexBox.items.size(); i++)
    {
        if(flexBox.items[i].associatedFlexBox)
        {
            ScopedPointer<FlexBox> toDelete = flexBox.items[i].associatedFlexBox;
            removeFlexBoxComponents(*toDelete);
        }
        else if(flexBox.items[i].associatedComponent)
        {
            
            ScopedPointer<Component> child = flexBox.items[i].associatedComponent ;
            _parent->removeChildComponent(child);
        }
    }
    
    flexBox.items.clear();
}

FlexItem &UberFlexBox::createAndAddFlexRow()
{
    FlexBox *newBox = new FlexBox();
    FlexItem *newItem = new FlexItem(*newBox);
    
    newItem->minWidth = 450;
    newItem->flexGrow = 1;
    newItem->minHeight = 40;
    newItem->maxHeight = 80;
    
    items.add(*newItem);
    
    return *newItem;
}

FlexItem &UberFlexBox::createAndAddFlexLabel(juce::String labelValue, FlexItem &flexRow)
{
    Label *ed = new Label();
    ed->setText(labelValue, NotificationType::dontSendNotification);
    _parent->addAndMakeVisible(ed);
    
    FlexItem *flexItem = new FlexItem(*ed);
    flexItem->minWidth = 150;
    flexItem->minHeight = 24;
    flexItem->flexGrow = 1;
    flexItem->maxHeight = 24;
    
    flexRow.associatedFlexBox->items.add(*flexItem);
    
    return *flexItem;
}

FlexItem &UberFlexBox::createAndAddFlexInput(juce::Component &newComponent, FlexItem &flexRow)
{
    // Stop if editor in flex box doesn't have a name. This will be a useless editor. Pls fix. K thnks bye.
    jassert(newComponent.getName().length());
            
    ButtonEdit *parent = dynamic_cast<ButtonEdit*>(_parent);
    
    // Try again
    jassert(parent);
    
    if(parent->_buttonModel->hasProperty(newComponent.getName()))
    {
        TextEditor *textEditor = dynamic_cast<TextEditor*>(&newComponent);
        ComboBox *comboBox = dynamic_cast<ComboBox*>(&newComponent);
        
        if(textEditor)
        {
            textEditor->setText(parent->_buttonModel->getProperty(textEditor->getName()));
            textEditor->addListener(this);
        }
        if(comboBox)
        {
            comboBox->setSelectedId(parent->_buttonModel->getProperty(comboBox->getName()));
            comboBox->addListener(this);
        }
        
    }
    
    parent->addAndMakeVisible(newComponent);
    
    FlexItem *flexItem = new FlexItem(newComponent);
    flexItem->minWidth = 150;
    flexItem->minHeight = 24;
    flexItem->maxHeight = 24;
    flexItem->flexGrow = 3;
    
    flexRow.associatedFlexBox->items.add(*flexItem);
    
    return *flexItem;
    
}

void UberFlexBox::textEditorTextChanged(juce::TextEditor &editor)
{
    ButtonEdit *parent = dynamic_cast<ButtonEdit*>(_parent);
    
    // Try again
    jassert(parent);
    
    if(editor.getText().containsOnly("0123456789"))
    {
        parent->_buttonModel->setProperty(editor.getName(), (int)editor.getTextValue().getValue());
    }
    else
    {
        parent->_buttonModel->setProperty(editor.getName(), editor.getText());
    }
}

void UberFlexBox::comboBoxChanged(juce::ComboBox *comboBoxThatHasChanged)
{
    ButtonEdit *parent = dynamic_cast<ButtonEdit*>(_parent);
    
    // Try again
    jassert(parent);
    
    parent->_buttonModel->setProperty(comboBoxThatHasChanged->getName(), comboBoxThatHasChanged->getSelectedIdAsValue());
}
