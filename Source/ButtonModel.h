/*
  ==============================================================================

    ButtonModel.h
    Created: 13 Jan 2017 1:59:59am
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef BUTTONMODEL_H_INCLUDED
#define BUTTONMODEL_H_INCLUDED

class ButtonModel;
#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"
#include "BoardController.h"

class ComponentModel
{
};
class ButtonModel
{
public:
    
    ButtonModel(PageModel *parentPage, int index);
    void sendToBoard();
    enum ButtonType {
        Off = 1,
        Normal = 2,
        BankUp = 3,
        BankDown = 4,
        DevicePC = 5,
        DevicePCUp = 6,
        DevicePCDown = 7,
        Store = 8,
        Page = 9,
        PageUp = 10,
        PageDown = 11,
        Preset = 12,
        PresetUp = 13,
        PresetDown = 14
    };
    Value buttonType;
    Value name;
    Value label;
private:
    BoardController *_boardController;
    PageModel *_pageModel;
    int _index;
    
};



#endif  // BUTTONMODEL_H_INCLUDED
