/*
  ==============================================================================

    PresetModel.h
    Created: 27 Dec 2016 7:29:44pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PRESETMODEL_H_INCLUDED
#define PRESETMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class PresetModel    : public Component
{
public:
    PresetModel();
    ~PresetModel();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetModel)
};


#endif  // PRESETMODEL_H_INCLUDED
