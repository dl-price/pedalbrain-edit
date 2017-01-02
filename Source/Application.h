/*
  ==============================================================================

    Application.h
    Created: 27 Dec 2016 9:51:32pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "includes.h"
#include "PedalEdit.h"
#include "CellEdit.h"
#include "BoardModel.h"

class pedalbraineditApplication  : public JUCEApplication
{
public:
    //==============================================================================
    pedalbraineditApplication() {}
    
    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }
    //ReferenceCountedObjectPtr<BoardModel> BoardModel;
    
    
    //==============================================================================
    void initialise (const String& commandLine) override;
    
    void shutdown() override;
    
    //==============================================================================
    void systemRequestedQuit() override;
    
    void anotherInstanceStarted (const String& commandLine) override;
    
    
    //==============================================================================
    /*
     This class implements the desktop window that contains an instance of
     our MainContentComponent class.
     */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name);
        
        void closeButtonPressed() override;
        
        /* Note: Be careful if you override any DocumentWindow methods - the base
         class uses a lot of them, so by overriding you might break its functionality.
         It's best to do all your work in your content component instead, but if
         you really have to override any DocumentWindow methods, make sure your
         subclass also calls the superclass's method.
         */
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };
    
private:
    
    ScopedPointer<MainWindow> mainWindow;
};



#endif  // APPLICATION_H_INCLUDED
