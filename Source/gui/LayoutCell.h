/*
  ==============================================================================

    LayoutCell.h
    Created: 27 Dec 2016 6:13:24am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef LAYOUTCELL_H_INCLUDED
#define LAYOUTCELL_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "CellEdit.h"
//#include "../includes.h"
#include "../BoardModel.h"

//==============================================================================
/*
*/
class LayoutCell    : public Component
{
public:
    LayoutCell();
    ~LayoutCell();

    void paint (Graphics&) override;
    void resized() override;
    void mouseUp(const MouseEvent &event) override;
    void mouseDoubleClick(const MouseEvent &event) override;
    BoardType::CellFeatures features = BoardType::CellFeatures::None;

private:
    ScopedPointer<CellEdit> cellEdit;
    ScopedPointer<Label> label;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LayoutCell)
};


#endif  // LAYOUTCELL_H_INCLUDED
