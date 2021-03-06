/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_6BDA80804A924CB0__
#define __JUCE_HEADER_6BDA80804A924CB0__

//[Headers]     -- You can add your own extra header files here --
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../gui/PedalView.h"
#include "../gui/PedalViewComponents.h"
#include "../gui/LedComponent.h"
#include "../gui/ButtonComponent.h"
#include "../gui/LcdComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EpicBoardView  : public PedalView
{
public:
    //==============================================================================
    EpicBoardView ();
    ~EpicBoardView();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void mouseDoubleClick (const MouseEvent& event) override;
    void init() override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ButtonComponent> button1;
    ScopedPointer<LcdComponent> component3;
    ScopedPointer<ButtonComponent> button2;
    ScopedPointer<ButtonComponent> button3;
    ScopedPointer<ButtonComponent> button4;
    ScopedPointer<ButtonComponent> button5;
    ScopedPointer<ButtonComponent> button8;
    ScopedPointer<ButtonComponent> button9;
    ScopedPointer<ButtonComponent> button10;
    ScopedPointer<ButtonComponent> button11;
    ScopedPointer<ButtonComponent> button6;
    ScopedPointer<ButtonComponent> button7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EpicBoardView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_6BDA80804A924CB0__
