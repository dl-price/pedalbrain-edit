/*
  ==============================================================================

    ButtonComponent.cpp
    Created: 28 Dec 2016 1:44:31am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ButtonComponent.h"

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
    //_label->setColour (TextEditor::textColourId, Colours::black);
    //_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    _colorValue = new Value();
    
    _colorValue->addListener(this);
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
    
    repaint();
}

void ButtonComponent::mouseDoubleClick(const juce::MouseEvent &event)
{
    if(event.eventComponent == this)
    {

            /*if(component)
             {
             BoardController *contrl = BoardController::getDefaultInstance();
             int i = buttonComponents.indexOf(component);
             contrl->createEditWindowForButton(contrl->pages[getPage()-1]->buttons[i]);
             Logger::outputDebugString("Clicked page " + String(getPage()) + " button index " + String(i));
             return;
             }*/
            BoardController *ctrl = BoardController::getDefaultInstance();
            PageModel *page = ctrl->getPage(dynamic_cast<PedalView*>(getParentComponent())->getPage());
            ButtonModel *btn = page->buttons[dynamic_cast<PedalView*>(getParentComponent())->buttonComponents.indexOf(this)];
            BoardController::getDefaultInstance()->createEditWindowForButton(btn);
        
    }
}
