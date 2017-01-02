/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Application.h"
#include "includes.h"
#include "PedalEdit.h"
#include "CellEdit.h"
#include "BoardModel.h"
#include "BoardTypes/EpicBoard.h"



    

    //==============================================================================
    void pedalbraineditApplication::initialise (const String& commandLine)
    {
        // This method is where you should put your application's initialisation code..

        if (SystemStats::getOperatingSystemType() == SystemStats::OperatingSystemType::iOS) {
            Desktop::getInstance().setOrientationsEnabled(12);
        }
        
        mainWindow = new MainWindow (getApplicationName());
        new BoardController(new EpicBoard());
    }

    void pedalbraineditApplication::shutdown()
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void pedalbraineditApplication::systemRequestedQuit()
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void pedalbraineditApplication::anotherInstanceStarted (const String& commandLine)
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }
    



pedalbraineditApplication::MainWindow::MainWindow (String name)  : DocumentWindow (name,
                                                    Colours::lightgrey,
                                                    DocumentWindow::allButtons)
        {
            DeviceManager::getInstance()->loadDeviceConfig();
            
            
            setUsingNativeTitleBar (true);
            PedalEdit* const contentComponent = new PedalEdit();
            setContentOwned (contentComponent, true);

            centreWithSize (getWidth(), getHeight());
            
            setMenuBar(contentComponent);
            if (SystemStats::getOperatingSystemType() != SystemStats::OperatingSystemType::iOS) {
            setResizable(true, true);
            setResizeLimits(1000, 700, 2000, 2000);
            }
            else
            {
                setResizable(false, false);
                setFullScreen(true);
            }
            
            setVisible (true);
            
            
        }

        void pedalbraineditApplication::MainWindow::closeButtonPressed()
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */





//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (pedalbraineditApplication)
