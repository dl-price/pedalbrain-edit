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
#include "BoardController.h"
#include "BoardTypes/EpicBoard.h"
#include "DeviceManager.h"
#include "Macros.h"
#include "antlr4-runtime.h"
#include "Antlr/SwiftLexer.h"
#include "Antlr/SwiftBaseVisitor.h"
#include "Antlr/SwiftParser.h"



    //==============================================================================
    void pedalbraineditApplication::initialise (const String& commandLine)
    {
        // This method is where you should put your application's initialisation code..

        if (SystemStats::getOperatingSystemType() == SystemStats::OperatingSystemType::iOS) {
            Desktop::getInstance().setOrientationsEnabled(12);
        }
        
        PropertiesFile::Options proptions;
        
        proptions.applicationName = "PedalBrain";
        proptions.filenameSuffix = ".settings";
        proptions.osxLibrarySubFolder = "Application Support";
        proptions.millisecondsBeforeSaving = 1000;
        proptions.ignoreCaseOfKeyNames = true;
        
        _appProperties = new ApplicationProperties();
        _appProperties->setStorageParameters(proptions);
        
        _deviceManager = new DeviceManager();
        mainWindow = new MainWindow (getApplicationName());
        
        if(autoload)
        {
        if(_appProperties->getUserSettings()->containsKey("recentProject"))
        {
            BoardController *ctrl = new EpicBoardController();
            ctrl->init();
            ctrl->setProjectDirectory(File(_appProperties->getUserSettings()->getValue("recentProject")));
            ctrl->loadFromFile();
            setDefaultBoardController(ctrl);
        }
        }
        
        scriptHandler = new ScriptHandler();

        setupScripting();
        
    }

void pedalbraineditApplication::setupScripting()
{
    DynamicObject *stackObject = new DynamicObject();
    
    stackObject->setMethod("printSomething", &pedalbraineditApplication::printSomething);
    
    scriptHandler->stack.setMethod("printSomething", &pedalbraineditApplication::printSomething);
    
    scriptHandler->stack.setProperty("app", new var(stackObject));
}

var pedalbraineditApplication::printSomething(const var::NativeFunctionArgs &args)
{
    Logger::outputDebugString("Print something");
    
    return var();
}

    void pedalbraineditApplication::shutdown()
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
        
        _defaultBoardController = nullptr;
        
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

ApplicationCommandManager *pedalbraineditApplication::getCommandManager()
{
    if(!pedalbraineditApplication::_commandManager)
    {
        pedalbraineditApplication::_commandManager = new ApplicationCommandManager();
        pedalbraineditApplication *app = dynamic_cast<pedalbraineditApplication*>(JUCEApplication::getInstance());
        pedalbraineditApplication::_commandManager->registerAllCommandsForTarget(app);
    }
    
    return pedalbraineditApplication::_commandManager;
}





pedalbraineditApplication::MainWindow::MainWindow (String name)  : DocumentWindow (name,
                                                    Colours::lightgrey,
                                                    DocumentWindow::allButtons)
        {
            DeviceManager::getInstance()->loadDeviceConfig();
            
            
            setUsingNativeTitleBar (true);
            
                
            contentComponent = new PedalEdit();
            setContentOwned (contentComponent, true);
        

            setMenuBar(contentComponent);
            if (SystemStats::getOperatingSystemType() != SystemStats::OperatingSystemType::iOS) {
            setResizable(true, true);
            setResizeLimits(1200, 900, 2000, 2000);
                centreWithSize (getWidth(), getHeight());
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

pedalbraineditApplication::MainWindow::~MainWindow()
{
    setMenuBar(nullptr);
}

void pedalbraineditApplication::MainWindow::resized()
{
    DocumentWindow::resized();
    
    if(btnEditComponent)
    {
        btnEditComponent->setBoundsInset(BorderSize<int>(0,0,0,0));
    }
}

void pedalbraineditApplication::MainWindow::addButtonEdit(ButtonEdit *newWin)
{
    jassert(!btnEditComponent);
    btnEditComponent = newWin;
    juce::Component::addAndMakeVisible(btnEditComponent);
    btnEditComponent->setBoundsInset(BorderSize<int>(0,0,0,0));
    btnEditComponent->setAlpha(0);
    Desktop::getInstance().getAnimator().fadeIn(btnEditComponent, 250);
}

void pedalbraineditApplication::MainWindow::removeButtonEdit()
{
    jassert(btnEditComponent);
    removeChildComponent(btnEditComponent);
    btnEditComponent = nullptr;
}

void pedalbraineditApplication::getAllCommands(Array<CommandID> &commands)
{
    
    commands.add(0x2001);
    commands.add(PedalBrainCommandTypes::saveProjectCmd);
    commands.add(PedalBrainCommandTypes::saveProjectAsCmd);
    commands.add(PedalBrainCommandTypes::connectToBoardCmd);
    commands.add(PedalBrainCommandTypes::loadProjectCmd);
    commands.add(PedalBrainCommandTypes::openTerminalCmd);
}
bool pedalbraineditApplication::perform (const InvocationInfo &info)
{
    
    if(info.commandID == 0x2001)
    {
        createNewProject();
        return true;
    }
    if(info.commandID == 0x2002)
    {

        saveProject();
        return true;
    }
    if(info.commandID == 0x2003)
    {

        saveProjectAs();
        return true;
    }
    if(info.commandID == PedalBrainCommandTypes::connectToBoardCmd)
    {
        connectToBoard();
        return true;
    }
    if(info.commandID == PedalBrainCommandTypes::loadProjectCmd)
    {
        loadProject();
        return true;
    }
    if(info.commandID == PedalBrainCommandTypes::openTerminalCmd)
    {
        openTerminal();
        return true;
    }
    
    
    
    return false;
}

void pedalbraineditApplication::getCommandInfo (CommandID commandID, ApplicationCommandInfo &result)
{
    
    if(commandID == PedalBrainCommandTypes::newProject)
    {
        result.shortName = "New Project";
        result.commandID = commandID;
        result.setActive(true);
        return;
    }
    if(commandID == PedalBrainCommandTypes::saveProjectCmd)
    {
        result.shortName = "Save Project";
        result.commandID = commandID;
            result.setActive(true);
        
    }
    if(commandID == PedalBrainCommandTypes::saveProjectAsCmd)
    {
        result.shortName = "Save Project As";
        result.commandID = commandID;

            result.setActive(true);

    }
    if(commandID == PedalBrainCommandTypes::connectToBoardCmd)
    {
        result.shortName = "Connect to board";
        result.commandID = commandID;
        result.setActive(true);
    }
    if(commandID == PedalBrainCommandTypes::loadProjectCmd)
    {
        result.shortName = "Load project";
        result.setActive(true);
    }
    if(commandID == PedalBrainCommandTypes::openTerminalCmd)
    {
        result.shortName = "Open Terminal";
        result.setActive(true);
    }
    
}

ApplicationCommandTarget *pedalbraineditApplication::getNextCommandTarget()
{
    return nullptr;
}

void pedalbraineditApplication::createNewProject()
{
    BoardController *cntrl = new EpicBoardController();
    cntrl->init();
    setDefaultBoardController(cntrl);

}

void pedalbraineditApplication::saveProject()
{
    /*if(BoardController::getDefaultInstance()->getProjectDirectory())
    {
        saveProjectAs();
        return;
    }*/
    
    _defaultBoardController->saveToFile();
    
    Logger::outputDebugString("Save project");
}

void pedalbraineditApplication::saveProjectAs()
{
    FileChooser fileChooser ("Select file to save", File::getSpecialLocation( File::userHomeDirectory ), "", true);
    
    if(fileChooser.browseForDirectory())
    {
        _defaultBoardController->setProjectDirectory(fileChooser.getResult());
        saveProject();
    }
    
    
}

void pedalbraineditApplication::connectToBoard()
{
    BoardController::tryConnectToUsb();
    
    
}

void pedalbraineditApplication::setDefaultBoardController(BoardController *newCtrl)
{
    _defaultBoardController = newCtrl;
    
    const MessageManagerLock mmlock;
    for(int i=0; i<BoardController::listeners.size();i++ )
    {
        BoardController::listeners[i]->boardControllerChanged();
    }
    
    appObject->refreshMainComponent();
}

BoardController *pedalbraineditApplication::getDefaultBoardController()
{
    return _defaultBoardController;
}

DeviceManager *pedalbraineditApplication::getDeviceManager()
{
    return _deviceManager;
}

void pedalbraineditApplication::deleteDefaultBoardController()
{
    _defaultBoardController = nullptr;
    
    for(int i=0; i<BoardController::listeners.size();i++ )
    {
        BoardController::listeners[i]->boardControllerChanged();
    }
}

void pedalbraineditApplication::loadProject()
{
    FileChooser fileChooser ("Select file to save", File::getSpecialLocation( File::userHomeDirectory ), "", true);
    
    if(fileChooser.browseForDirectory())
    {
        BoardController *ctrl = new EpicBoardController();
        ctrl->init();
        ctrl->setProjectDirectory(fileChooser.getResult());
        ctrl->loadFromFile();
        
        setDefaultBoardController(ctrl);
    }
    
    refreshMainComponent();
    
}

ApplicationProperties *pedalbraineditApplication::getAppProperties()
{
    return _appProperties;
}

void pedalbraineditApplication::refreshMainComponent()
{
    mainWindow->refreshMainComponent();
}

void pedalbraineditApplication::MainWindow::refreshMainComponent()
{
    setMenuBar(nullptr);
    
    contentComponent = new PedalEdit();
    
    setContentOwned(contentComponent, true);
    
    setMenuBar(contentComponent);
}

void pedalbraineditApplication::openTerminal()
{
    DialogWindow::LaunchOptions opts;
    
    opts.dialogTitle = "Terminal";
    TextEditor *text = new TextEditor();
    text->setName("Terminal");
    text->addListener(this);
    text->setBounds(0, 0, 500, 24);
    opts.content.set(text, true);
    
    opts.launchAsync();
}

void pedalbraineditApplication::textEditorEscapeKeyPressed(juce::TextEditor &editor)
{
    if (editor.getName() == "Terminal")
    {
        scriptHandler->runScript(editor.getText());
    }
}




//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (pedalbraineditApplication)
