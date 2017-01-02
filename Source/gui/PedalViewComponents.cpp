/*
  ==============================================================================

    PedalViewComponents.cpp
    Created: 28 Dec 2016 1:12:50am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"
#include "PedalViewComponents.h"
#include "../BoardModel.h"
#include "ComponentModels.h"
#include "ComponentModel.h"

//==============================================================================
PedalViewComponent::PedalViewComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PedalViewComponent::PedalViewComponent(int newId)
{
    idRef = newId;
}

PedalViewComponent::~PedalViewComponent()
{
}

void PedalViewComponent::mouseDoubleClick(const juce::MouseEvent &event)
{
    getPedalView()->componentDoubleClicked(this, event);
}

void PedalViewComponent::mouseDown(const juce::MouseEvent &event)
{
    if(event.mods.isPopupMenu())
    {
        //ComponentController *newButton = BoardController::getInstance()->pages[0]->components[idRef] ;
        
        PopupMenu *newContext = BoardController::getInstance()->pages[0]->components[idRef]->contextMenu();
        
        newContext->showMenuAsync(PopupMenu::Options().withTargetComponent(this), ModalCallbackFunction::withParam(contextCallback, BoardController::getInstance()->pages[0]->components[idRef], newContext));
    }
}

void PedalViewComponent::contextCallback(int modalResult, ComponentController *component, PopupMenu *popup)
{
    component->popupCompleted(modalResult, popup);
    delete popup;
}

PedalView *PedalViewComponent::getPedalView()
{
    return dynamic_cast<PedalView*>(getParentComponent());
}



