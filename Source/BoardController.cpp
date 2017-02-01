/*
  ==============================================================================

    BoardController.cpp
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BoardController.h"
#include "BoardTypes/EpicBoardView.h"
#include "BoardTypes/EpicBoard.h"
#include "ButtonModel.h"
#include "ComponentEdit.h"
#include "ButtonEdit.h"
#include "Application.h"
#include "PedalEdit.h"
#include "Macros.h"

//==============================================================================
Array<BoardControllerListener*> BoardController::listeners = Array<BoardControllerListener*>();

SysExHandler *BoardController::tempSysExHandler = 0;

BoardController::BoardController()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    devices = ReferenceCountedArray<Device>();

    _projectDirectory = String::empty;
    
    
    
    
}

void BoardController::init()
{
    pages.ensureStorageAllocated(getNumberOfPages());
    for (int i=0; i < getNumberOfPages(); i++)
    {
        PageModel *newPage = new PageModel(this, i);
        
        pages.add(newPage);
        
        OwnedArray<Value> *values = new OwnedArray<Value>();
        
        for(int i2=0;i2 < getNumberOfButtons(); i2++)
        {
            values->add(new Value(false) );
        }
        
        buttonStates.add(values);
    }
    devices.ensureStorageAllocated(16);
    for (int i=0; i < getMaxDevices(); i++)
    {
        devices.add(new Device(this, i));
    }
    
    
    
   

}




/**
 Returns a pointer to the current BoardController - up to one may exist at a time

 @return Current BoardController
 */
BoardController *BoardController::getDefaultInstance()
{

    return appObject->getDefaultBoardController();
}

void BoardController::addListener(BoardControllerListener *newListener)
{
    listeners.add(newListener);
}

void BoardController::tryConnectToUsb()
{

    
    
    /*if(SysExHandler::boardAttached())
    {
        int i = MidiOutput::getDevices().indexOf("PBrain");
        usbOutput = MidiOutput::openDevice(i);
        
        i = MidiInput::getDevices().indexOf("PBrain");
        usbInput = MidiInput::openDevice(i, this);
        usbInput->start();
        return true;
    }*/
    
    if(BoardController::getDefaultInstance())
    {
        if(BoardController::getDefaultInstance()->sysexHandler)
        {
        // Already connected to board
        Logger::outputDebugString("Already connected to board - aborting connect attempt");
            return;
        }
        
    }
    if(SysExHandler::boardAttached())
    {
        // Board attached but not connected
        Logger::outputDebugString("Board found - attempting to connect");
        BoardController::tempSysExHandler = new SysExHandler();
        BoardController::tempSysExHandler->requestBoardInfo();
    }
    else
    {
        Logger::outputDebugString("No board found - aborting connect attempt");
    }
    
}

BoardController::~BoardController()
{
}

void BoardController::createEditWindowForButton(ButtonModel *selectedButton)
{
    ButtonEdit *editComponent = new ButtonEdit(dynamic_cast<ButtonModel*>(selectedButton));
    
    dynamic_cast<pedalbraineditApplication::MainWindow*>(ResizableWindow::getActiveTopLevelWindow())->addButtonEdit(editComponent);
    
}





void BoardController::tryConnectToUsb(SysExHandler *handler)
{
    if(BoardController::getDefaultInstance())
    {
        BoardController *boardInstance = BoardController::getDefaultInstance();
        if(boardInstance->boardModel.compare( handler->boardInfo.model));
        {
            switch(AlertWindow::showYesNoCancelBox(AlertWindow::AlertIconType::QuestionIcon, "Connect to " + handler->boardInfo.name, "There is already a project open. Would you like to write this project to the board or close this project and read the data from the board?", "Read from board", "Write to board", "Cancel connection"))
            {
                case 1:
                    createAndReadFromBoard(handler);
                    break;
                case 2:
                    // Write to board
                    Logger::outputDebugString("Not yet implemented");
                    break;
                default:
                    // Cancel
                    Logger::outputDebugString("Cancelled connection");
                    BoardController::tempSysExHandler = 0;
                    
            }
        }
        
    }
    else{
        createAndReadFromBoard(handler);
        
    }
}

void BoardController::createAndReadFromBoard(SysExHandler *handler)
{
    BoardController::Ptr newCntrl;
    if(handler->boardInfo.model == "TestBoardA")
    {
        newCntrl = new EpicBoardController();
        newCntrl->init();
        appObject->setDefaultBoardController(newCntrl);
        
        newCntrl->sysexHandler = handler;
        handler->solidfyConnection();
        handler->requestAllParameters();
    }
    
    Logger::outputDebugString("Created and set new project for connected board");
    
    Logger::outputDebugString("Reading data from board: " + handler->boardInfo.name);
    
    // Code for getting stored data from board

    if (handler == BoardController::tempSysExHandler)
    {
        tempSysExHandler = 0;
    }
}

BoardControllerListener::~BoardControllerListener()
{

}

File BoardController::getProjectDirectory()
{
    return _projectDirectory;
}

void BoardController::setProjectDirectory(juce::File newDirectory)
{
    _projectDirectory = newDirectory;
}

void BoardController::loadFromFile()
{
    for(int i=0;i < pages.size();i++)
    {
        PageModel *pg = pages[i];
        pg->loadFromFile();
        for(int i2=0; i2 < pg->buttons.size(); i2++)
        {
            pg->buttons[i2]->loadFromFile();
        }
    }
    for(int i=0;i < devices.size();i++)
    {
        devices[i]->loadFromFile();
    }
    
    appObject->getAppProperties()->getUserSettings()->setValue("recentProject", _projectDirectory.getFullPathName());
    
    
}

void BoardController::saveToFile()
{
    for(int i=0;i < pages.size();i++)
    {
        PageModel *pg = pages[i];
        pg->saveToFile();
        for(int i2=0; i2 < pg->buttons.size();i2++ )
        {
            pg->buttons[i2]->saveToFile();
        }
    }
    for(int i=0;i < devices.size();i++)
    {
        devices[i]->saveToFile();
    }
    
    appObject->getAppProperties()->getUserSettings()->setValue("recentProject", _projectDirectory.getFullPathName());
}









