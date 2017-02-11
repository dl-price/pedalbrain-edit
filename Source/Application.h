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
#include "BoardController.h"
#include "ButtonEdit.h"
#include "ScriptHandler.h"

class pedalbraineditApplication  : public JUCEApplication, public TextEditorListener
{
public:
    //==============================================================================
    pedalbraineditApplication() {};
    
    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }
    
    
    //==============================================================================
    void initialise (const String& commandLine) override;
    
    void shutdown() override;
    
    //==============================================================================
    void systemRequestedQuit() override;
    
    void anotherInstanceStarted (const String& commandLine) override;
    
    ApplicationCommandManager *getCommandManager();
    
    ApplicationCommandTarget *getNextCommandTarget() override;
    void getAllCommands(Array<CommandID> &commands) override;
    bool perform (const InvocationInfo &info) override;
    void getCommandInfo (CommandID commandID, ApplicationCommandInfo &result) override;
    void setDefaultBoardController(BoardController *newCtrl);
    BoardController *getDefaultBoardController();
    DeviceManager *getDeviceManager();
    void deleteDefaultBoardController();
    ApplicationProperties *getAppProperties();
    
    const bool autoload = true;
    
    void refreshMainComponent();
    
    void textEditorEscapeKeyPressed(TextEditor &editor) override;
    
    DynamicObject globalMethods;
    
    ScopedPointer<ScriptHandler> scriptHandler;
    
    void setupScripting();
    
    static var printSomething(const var::NativeFunctionArgs&);
    
    //==============================================================================
    /*
     This class implements the desktop window that contains an instance of
     our MainContentComponent class.
     */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name);
        ~MainWindow();
        
        void closeButtonPressed() override;
        
        
        
        /* Note: Be careful if you override any DocumentWindow methods - the base
         class uses a lot of them, so by overriding you might break its functionality.
         It's best to do all your work in your content component instead, but if
         you really have to override any DocumentWindow methods, make sure your
         subclass also calls the superclass's method.
         */
        
        void resized() override;
        void addButtonEdit(ButtonEdit* newWin);
        void removeButtonEdit();
        
        void refreshMainComponent();
        
    private:
        ScopedPointer<ButtonEdit> btnEditComponent;
        ScopedPointer<PedalEdit> contentComponent;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };
    enum PedalBrainCommandTypes
    {
        newProject = 0x2001,
        saveProjectCmd = 0x2002,
        saveProjectAsCmd = 0x2003,
        connectToBoardCmd = 0x2004,
        loadProjectCmd = 0x2005,
        openTerminalCmd = 0x2006
    };
    
private:
    ScopedPointer<ApplicationCommandManager> _commandManager;
    BoardController::Ptr _defaultBoardController;
    ScopedPointer<MainWindow> mainWindow;
    ScopedPointer<DeviceManager> _deviceManager;
    ScopedPointer<ApplicationProperties> _appProperties;
    
    void createNewProject();
    void saveProject();
    void saveProjectAs();
    void connectToBoard();
    void loadProject();
    void openTerminal();
};



#endif  // APPLICATION_H_INCLUDED
