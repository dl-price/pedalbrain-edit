/*
  ==============================================================================

    ComponentEdit.h
    Created: 29 Dec 2016 8:20:33pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef COMPONENTEDIT_H_INCLUDED
#define COMPONENTEDIT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../ComponentModel.h"

//==============================================================================
/*
*/
class ComponentEdit    : public Component
{
public:
    ComponentEdit();
    //ComponentEdit(ComponentModel *model);
    ~ComponentEdit();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentEdit)
    //ComponentModel *s_model;
};


#endif  // COMPONENTEDIT_H_INCLUDED
