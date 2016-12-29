/*
  ==============================================================================

    ComponentModels.h
    Created: 29 Dec 2016 9:18:19pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef COMPONENTMODELS_H_INCLUDED
#define COMPONENTMODELS_H_INCLUDED

#include "ComponentModel.h"


class LedModel : public ComponentModel
{
public:
    String type() const { return "Led"; }
};

class ButtonModel : public ComponentModel
{
    String type() const { return "Button"; }
    ComponentEdit *createEditWindow() override;
};

class LBModel : public ComponentModel
{
    String type() const { return "Led"; }
};

class LcdModel : public ComponentModel
{
    String type() const { return "Lcd"; }
};


#endif  // COMPONENTMODELS_H_INCLUDED
