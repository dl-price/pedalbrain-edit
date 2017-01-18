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

//==============================================================================
ReferenceCountedArray<BoardControllerListener> BoardController::listeners = ReferenceCountedArray<BoardControllerListener>();

BoardController *BoardController::s_instance = 0;
SysExHandler *BoardController::tempSysExHandler = 0;

BoardController::BoardController(BoardType *newType)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    pages = OwnedArray<PageModel>();
    
    boardType = newType;
    

}

void BoardController::initFromNothing()
{
    for (int i=0; i < getNumberOfPages(); i++)
    {
        PageModel *newPage = new PageModel();
        newPage->initFromNothing();
        pages.add(newPage);
    }
    for (int i=0; i < getMaxDevices(); i++)
    {
        devices.add(new Device());
    }
}

BoardController *BoardController::setInstance(BoardController *newBoard)
{
    delete s_instance;
    s_instance = newBoard;
    Logger::outputDebugString(String(BoardController::listeners.size()));
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

BoardController::BoardController()
{
    pages = OwnedArray<PageModel>();
}

BoardController::~BoardController()
{
    
}

void BoardController::createEditWindowForButton(ButtonModel *selectedButton)
{
    ButtonEdit *editComponent = new ButtonEdit(dynamic_cast<ButtonModel*>(selectedButton));
    //ResizableWindow *window = new ResizableWindow();
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

void BoardController::tryConnectToUsb(DynamicObject *boardInfo)
{
    if(BoardController::getInstance())
    {
        Logger::outputDebugString("Project already open - not set up to deal with this yet. Abort");
    }
    else{
        BoardController *newCntrl = new EpicBoardController();
        newCntrl->initFromNothing();
        SysExHandler *handler = newCntrl->sysexHandler = BoardController::tempSysExHandler;
        BoardController::setInstance(newCntrl);
        
        Logger::outputDebugString("Connected to board:");
        
        Logger::outputDebugString("Name: " + boardInfo->getProperty("name").toString());
        Logger::outputDebugString("Model: " + boardInfo->getProperty("model").toString());
        Logger::outputDebugString("Version: " + String((double)boardInfo->getProperty("version")));
        
        BoardController::tempSysExHandler = 0;
    }
}






