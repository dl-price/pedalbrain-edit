/*
  ==============================================================================

    BoardController.h
    Created: 27 Dec 2016 7:21:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BoardController_H_INCLUDED
#define BoardController_H_INCLUDED



#include "../JuceLibraryCode/JuceHeader.h"
class BoardType;
class BoardController;
class BoardControllerListener;




//==============================================================================
/*
*/


class BoardControllerListener : public ReferenceCountedObject
{
public:
    BoardControllerListener(){};
    ~BoardControllerListener(){};
    virtual void boardControllerChanged(){};
};

#include "SysExHandler.h"



#include "PageModel.h"
#include "gui/PedalView.h"
#include "ComponentEdit.h"
#include "Device.h"

class BoardType : public ReferenceCountedObject
{
public:
    enum CellFeatures {
        None = 0,
        Led = 1<<0,
        RgbLed = 1<<1,
        Lcd = 1<<2,
        Switch = 1<<3
    };
    virtual String getName() = 0;
    virtual int getMaxPages(){return 1;};
    virtual int getMaxDevices(){return 8;};
    virtual int getCellNumber(){return 0;};
    virtual PedalView *createView() = 0;
    virtual int getLedNumber(){return 0;};
    virtual int getButtonNumber(){return 0;};
    virtual int getLBNumber(){return 0;};
    virtual int getLCDNumber(){return 0;};
    virtual int getMaxComponents(){return 0;};

    
};

class BoardController : public MidiInputCallback
{
    
public:
    BoardController();
    BoardController(BoardType *newType);
    ~BoardController();
    
    BoardType *boardType;
    ReferenceCountedArray<PageModel> pages;
    OwnedArray<PedalView> pedalViews;
    ReferenceCountedArray<Device> devices;
    String projectFile;
    static ReferenceCountedArray<BoardControllerListener> listeners;
    virtual PedalView *createView() = 0;
    static BoardController *getInstance();
    static BoardController *setInstance(BoardController *newBoard);
    virtual int getNumberOfButtons() {return 5;}
    virtual int getNumberOfPages() = 0;
    static void addListener(BoardControllerListener *newListener);
    static void createAndReadFromBoard(SysExHandler *handler);
    const String boardModel;
    void init();
    PageModel *getPage(int id) { return pages[id-1];};

    //static void contextMenuFinished(int ModalResult, PedalViewComponent *component, PopupMenu *menu );
    virtual void createEditWindowForButton(ButtonModel *selectedButton);
    virtual int getMaxDevices() {return 16;};
    static void tryConnectToUsb();
    static void tryConnectToUsb(SysExHandler *handler);
    SysExHandler *sysexHandler = 0;
    MidiInput *usbInput;
    MidiOutput *usbOutput;
    void handleIncomingMidiMessage(MidiInput *source, const MidiMessage &message) override;
    void sendPBSysex(String message);
    
protected:
    static BoardController *s_instance;
    static SysExHandler *tempSysExHandler;
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BoardController)
};










#endif  // BoardController_H_INCLUDED
