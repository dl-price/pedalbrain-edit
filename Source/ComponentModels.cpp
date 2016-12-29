/*
  ==============================================================================

    ComponentModels.cpp
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/


#include "ComponentModels.h"

ComponentEdit *ComponentModel::createEditWindow()
{
    return new ComponentEdit();
}

ComponentEdit *ButtonModel::createEditWindow()
{
    return new ButtonEdit();
}
