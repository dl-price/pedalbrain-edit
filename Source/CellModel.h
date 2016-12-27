/*
  ==============================================================================

    CellModel.h
    Created: 27 Dec 2016 7:29:27pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef CELLMODEL_H_INCLUDED
#define CELLMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class CellModel    : public ReferenceCountedObject
{
public:
    CellModel();
    ~CellModel();



private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CellModel)
};


#endif  // CELLMODEL_H_INCLUDED
