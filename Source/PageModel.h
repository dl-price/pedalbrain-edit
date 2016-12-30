/*
  ==============================================================================

    PageModel.h
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PAGEMODEL_H_INCLUDED
#define PAGEMODEL_H_INCLUDED

//#include "BoardModel.h"

#include "../JuceLibraryCode/JuceHeader.h"
#include "CellModel.h"
#include "ComponentModel.h"


//==============================================================================
/*
*/


class PageModel 
{
public:
    PageModel();
    ~PageModel();
    OwnedArray<ComponentController> components;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageModel)
};


#endif  // PAGEMODEL_H_INCLUDED
