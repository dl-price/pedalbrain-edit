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

//==============================================================================
ReferenceCountedArray<BoardControllerListener> BoardController::listeners = ReferenceCountedArray<BoardControllerListener>();

BoardController *BoardController::s_instance = 0;
SysExHandler *BoardController::tempSysExHandler = 0;

BoardController::BoardController()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    devices = ReferenceCountedArray<Device>();
    
    s_instance = this;
    
    
}

void BoardController::init()
{
    pages.ensureStorageAllocated(getNumberOfPages());
    for (int i=1; i <= getNumberOfPages(); i++)
    {
        PageModel *newPage = new PageModel(i);
        
        pages.add(newPage);
    }
    devices.ensureStorageAllocated(16);
    for (int i=0; i < getMaxDevices(); i++)
    {
        devices.add(new Device());
    }
    
    for(int i=0; i<BoardController::listeners.size();i++ )
    {
        BoardController::listeners[i]->boardControllerChanged();
    }
}

BoardController *BoardController::setInstance(BoardController *newBoard)
{
    delete s_instance;
    s_instance = newBoard;
    for(int i=0; i<BoardController::listeners.size();i++ )
    {
        BoardController::listeners[i]->boardControllerChanged();
    }
    return s_instance;
}


/**
 Returns a pointer to the current BoardController - up to one may exist at a time

 @return Current BoardController
 */
BoardController *BoardController::getInstance()
{

    return s_instance;
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
    
    if(BoardController::getInstance())
    {
        if(BoardController::getInstance()->sysexHandler)
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

void BoardController::handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message)
{
    Logger::outputDebugString("Receive");
    if(message.isSysEx())
    {
        Logger::outputDebugString(String::fromUTF8( (char*)message.getSysExData()).dropLastCharacters(1));
    }
}

void BoardController::sendPBSysex(String message)
{
    String newMessage = "}" + message;
    CharPointer_UTF8 charPnt = newMessage.getCharPointer();
    
    usbOutput->sendMessageNow(MidiMessage::createSysExMessage(charPnt, charPnt.sizeInBytes()));
}

void BoardController::tryConnectToUsb(SysExHandler *handler)
{
    if(BoardController::getInstance())
    {
        BoardController *boardInstance = BoardController::getInstance();
        if(boardInstance->boardModel.compare( handler->boardInfo.model));
        {
            switch(AlertWindow::showYesNoCancelBox(AlertWindow::AlertIconType::QuestionIcon, "Connect to " + handler->boardInfo.name, "There is already a project open. Would you like to write this project to the board or close this project and read the data from the board?", "Read from board", "Write to board", "Cancel connection"))
            {
                case 1:
                    // Read from board
                    Logger::outputDebugString("Not yet implemented");
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

bool BoardController::createAndReadFromBoard(SysExHandler *handler)
{
    BoardController *newCntrl;
    if(handler->boardInfo.model == "TestBoardA")
    {
        newCntrl = new EpicBoardController();
        newCntrl->init();
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








