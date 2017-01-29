/*
  ==============================================================================

    PedalView.cpp
    Created: 27 Dec 2016 9:43:51am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "PedalView.h"
#include "../includes.h"
#include "Macros.h"


//==============================================================================
PedalView::PedalView()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    /*layoutCells = OwnedArray<LayoutCell>();
    
    for(int i=1; i<=11;i++) {
        LayoutCell *newCell = new LayoutCell();
        layoutCells.add(newCell);
        addAndMakeVisible(newCell);
        
    }*/
    
    _showButtonsOff = true;
    _editButtonOnDoubleClick = false;

}

PedalView::~PedalView()
{
}

int PedalView::getPage()
{
    return _viewingPage;
}

void PedalView::setPage(int i) {
    _viewingPage = i;
    pageChanged();
}

int PedalView::getPreset()
{
    return _viewingPreset;
}

void PedalView::setPreset(int i) {
    _viewingPreset = i;
    presetChanged();
}

void PedalView::paint (Graphics& g)
{
    g.setColour (Colours::black);
    g.fillRect (getLocalBounds());   // draw an outline around the component

}

void PedalView::resized()
{

}

void PedalView::pageChanged()
{
    Logger::outputDebugString(String(_viewingPage));
    
    for(int i=0; i < appObject->getDefaultBoardController()->getPageForIndex (getPageIndex())->buttons.size(); i++)
    {
        buttonComponents[i]->getLabelValue().referTo( appObject->getDefaultBoardController()->getPage(getPage())->buttons[i]->name);
        if(_showButtonsOn.getValue())
        {
            buttonComponents[i]->_colorValue->referTo(*appObject->getDefaultBoardController()->getPage(getPage())->buttons[i]->_onColor);
        }
        else if(_showButtonsOff.getValue())
        {
            buttonComponents[i]->_colorValue->referTo(*appObject->getDefaultBoardController()->getPage(getPage())->buttons[i]->_offColor);
        }
        else if(_showAttachedState.getValue())
        {
            OwnedArray<Value> *valArray = appObject->getDefaultBoardController()->buttonStates[getPageIndex()];
            
            Value *val = valArray->getUnchecked(i) ;
            
            buttonComponents[i]->_state.referTo(*val);
            
            if(val->getValue())
            {
                buttonComponents[i]->_colorValue->referTo(*appObject->getDefaultBoardController()->getPage(getPage())->buttons[i]->_onColor);
            }
            else{
                buttonComponents[i]->_colorValue->referTo(*appObject->getDefaultBoardController()->getPage(getPage())->buttons[i]->_offColor);
            }
        }
        else {
            buttonComponents[i]->_colorValue->setValue(Colours::yellow.toString());
        }
        
    }
    repaint();
}

void PedalView::presetChanged()
{
    
}

void PedalView::mouseDoubleClick(const MouseEvent &event)
{
    
    /*if(dynamic_cast<ButtonComponent*>(event.eventComponent->getComponentAt(event.getPosition())));
    {
        appObject->getDefaultBoardController()->buttonStates[getPage()]->getUnchecked(buttonComponents.indexOf(dynamic_cast<ButtonComponent*>(event.eventComponent->getComponentAt(event.getPosition()))))->setValue(!(appObject->getDefaultBoardController()->buttonStates[getPage()]->getUnchecked(buttonComponents.indexOf(dynamic_cast<ButtonComponent*>(event.eventComponent->getComponentAt(event.getPosition()))))->getValue()));
        repaint();
    }*/
}

bool PedalView::editButtonOnDoubleClick()
{
    return _editButtonOnDoubleClick.getValue();
}

void PedalView::editButtonOnDoubleClick(bool val)
{
    _editButtonOnDoubleClick.setValue(val);
}

LayoutTab *PedalView::getLayoutTab()
{
    return dynamic_cast<LayoutTab*>(getParentComponent());
}

bool PedalView::buttonClickControlsBoard()
{
    return getLayoutTab()->getButtonClickControlsBoard().getValue();
}

void PedalView::matchOptionsTo(PedalView *otherView)
{
    _showButtonsOn.referTo(otherView->_showButtonsOn);
    _showButtonsOff.referTo(otherView->_showButtonsOff);
    _showAttachedState.referTo(otherView->_showAttachedState);
    _editButtonOnDoubleClick.referTo(otherView->_editButtonOnDoubleClick);
}

bool PedalView::showAttachedButtonState()
{
    return _showAttachedState.getValue();
}

void PedalView::showAttachedButtonState(bool val)
{
    if(val)
    {
        _showAttachedState.setValue(true);
        _showButtonsOn.setValue(false);
        _showButtonsOff.setValue(false);
    }
    else {
        _showAttachedState.setValue(false);
    }
}

bool PedalView::showButtonsOn()
{
    return _showButtonsOn.getValue();
}

void PedalView::showButtonsOn(bool val)
{
    if(val)
    {
        _showButtonsOn.setValue(true);
        _showButtonsOff.setValue(false);
        _showAttachedState.setValue(false);
    }
    else {
        _showButtonsOn.setValue(false);
    }
}

bool PedalView::showButtonsOff()
{
    return _showButtonsOff.getValue();
}

void PedalView::showButtonsOff(bool val)
{
    if (val)
    {
        _showButtonsOff.setValue(true);
        _showButtonsOn.setValue(false);
        _showAttachedState.setValue(false);
    }
    else{
        _showButtonsOff.setValue(false);
    }
}

