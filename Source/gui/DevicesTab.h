/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_4316FF605E2229EC__
#define __JUCE_HEADER_4316FF605E2229EC__

//[Headers]     -- You can add your own extra header files here --
#include "../../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DevicesTab  : public Component,
                    ListBoxModel
{
public:
    //==============================================================================
    DevicesTab ();
    ~DevicesTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    int getNumRows() override;
    void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override;


    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.


    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> deviceListGroup;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<ListBox> deviceTable;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DevicesTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_4316FF605E2229EC__
