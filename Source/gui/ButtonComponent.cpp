/*
  ==============================================================================

    ButtonComponent.cpp
    Created: 28 Dec 2016 1:44:31am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ButtonComponent.h"
#include "Macros.h"

//==============================================================================
ButtonComponent::ButtonComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    _colorValue->addListener(this);

}

ButtonComponent::ButtonComponent(int newId)
{
    addAndMakeVisible (_label = new Label ("new label",
                                                 TRANS("label text")));
    _label->setFont (Font (15.00f, Font::plain));
    _label->setJustificationType (Justification::centredLeft);
    _label->setEditable (false, false, false);
    _label->setInterceptsMouseClicks(false, false);

    //_label->setColour (TextEditor::textColourId, Colours::black);
    //_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    _colorValue = new Value();
    
    _colorValue->addListener(this);
    _state.addListener(this);
}

ButtonComponent::~ButtonComponent()
{
}

void ButtonComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    
    Colour color = Colour::fromString(_colorValue->toString());
    if(!(color.getRed() + color.getGreen() + color.getBlue()))
    {
        _label->setColour(Label::ColourIds::textColourId, Colours::white);
    }
    else
    {
        _label->setColour(Label::ColourIds::textColourId, Colours::black);
    }

    g.fillAll (Colour::fromString(_colorValue->getValue().toString()) );   // clear the background

    //g.setColour (Colours::grey);
    //g.fill   // draw an outline around the component


}

void ButtonComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    _label->setBounds(0,0,150,24);

}

Value &ButtonComponent::getLabelValue()
{
    return _label->getTextValue();
}

void ButtonComponent::valueChanged(juce::Value &value)
{
    

        if(_state.getValue())
        {
            _colorValue->referTo(*getButtonModel()->_onColor);
        }
        else{
            _colorValue->referTo(*getButtonModel()->_offColor);
        }
    
    
    repaint();
}

void ButtonComponent::mouseDoubleClick(const juce::MouseEvent &event)
{
            /*if(component)
             {
             BoardController *contrl = BoardController::getDefaultInstance();
             int i = buttonComponents.indexOf(component);
             contrl->createEditWindowForButton(contrl->pages[getPage()-1]->buttons[i]);
             Logger::outputDebugString("Clicked page " + String(getPage()) + " button index " + String(i));
             return;
             }*/
    
    if(getPedalView().editButtonOnDoubleClick())
    {
            BoardController::getDefaultInstance()->createEditWindowForButton(getButtonModel());
    }
    
    /*OwnedArray<Value> *arr = appObject->getDefaultBoardController()->buttonStates[getPedalView().getPageIndex() ];
    Value *val = arr->getUnchecked(getButtonModel()->getIndex()) ;
    val->setValue(!val->getValue());
    valueChanged(_state);*/
    
    

    
   // appObject->getDefaultBoardController()->buttonStates[getPedalView().getPageIndex()]->getUnchecked(buttonComponents.indexOf(dynamic_cast<ButtonComponent*>(event.eventComponent->getComponentAt(event.getPosition()))))->setValue(!(appObject->getDefaultBoardController()->buttonStates[getPage()]->getUnchecked(buttonComponents.indexOf(dynamic_cast<ButtonComponent*>(event.eventComponent->getComponentAt(event.getPosition()))))->getValue()));
    
    
}

PedalView &ButtonComponent::getPedalView()
{
    
    Component *comp = this;
    
    while(!dynamic_cast<PedalView*>(comp))
    {
        comp = comp->getParentComponent();
    }
    
    return *(dynamic_cast<PedalView*>(comp));
    
}

ButtonModel *ButtonComponent::getButtonModel()
{
    return appObject->getDefaultBoardController()->getPageForIndex(getPedalView().getPageIndex())->buttons[getPedalView().buttonComponents.indexOf(this)];
    
}

void ButtonComponent::mouseDown(const juce::MouseEvent &event)
{
    if(getPedalView().buttonClickControlsBoard() )
    {
        _state.setValue(!_state.getValue());
    }
}
