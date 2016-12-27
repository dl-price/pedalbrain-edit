/*
  ==============================================================================

    PageModel.h
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PAGEMODEL_H_INCLUDED
#define PAGEMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CellModel.h"

//==============================================================================
/*
*/
class PageModel    : public Component
{
public:
    PageModel();
    ~PageModel();
    
    ReferenceCountedArray<CellModel> cellModels;

    void paint (Graphics&) override;
    void resized() override;
    
    

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageModel)
};


#endif  // PAGEMODEL_H_INCLUDED
