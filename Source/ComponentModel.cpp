/*
  ==============================================================================

    ComponentModel.cpp
    Created: 28 Dec 2016 7:16:12pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"

//==============================================================================

ComponentModel::ComponentModel()
{
    
}

/*LedModel::LedModel()
{
    type = "Led";
}*/

ComponentEdit *ComponentModel::createEditWindow()
{
    return new ComponentEdit();
}

ComponentEdit *ButtonModel::createEditWindow()
{
    return new ButtonEdit();
}
