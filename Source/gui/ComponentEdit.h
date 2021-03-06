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
#include "../ButtonModel.h"
class ComponentController;

//==============================================================================
/*
*/
class ComponentEdit    : public Component
{
public:
    ComponentEdit(ComponentModel *model);
    ComponentEdit();
    ~ComponentEdit();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentEdit)
protected:
    ComponentModel *s_model;
};


#endif  // COMPONENTEDIT_H_INCLUDED
