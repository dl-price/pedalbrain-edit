/*
  ==============================================================================

    ButtonComponent.h
    Created: 28 Dec 2016 1:44:31am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BUTTONCOMPONENT_H_INCLUDED
#define BUTTONCOMPONENT_H_INCLUDED

class ButtonComponent;

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalViewComponents.h"
#include "ButtonModel.h"
#include "PedalView.h"

//==============================================================================
/*
*/
class ButtonComponent : public Component, public ValueListener
{
public:
    ButtonComponent();
    ButtonComponent(int newId);
    ~ButtonComponent();

    void paint (Graphics&) override;
    void resized() override;
    Value &getLabelValue();
    ScopedPointer<Value> _colorValue;
    void valueChanged(Value &value) override;
    void mouseDoubleClick(const MouseEvent &event) override;
    Value _state;
    PedalView &getPedalView();
    ButtonModel *getButtonModel();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonComponent)
    ScopedPointer<Label> _label;
    
    
};


#endif  // BUTTONCOMPONENT_H_INCLUDED
