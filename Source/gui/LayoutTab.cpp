/*
  ==============================================================================

    LayoutTab.cpp
    Created: 27 Dec 2016 6:02:00am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes.h"
#include "LayoutTab.h"
#include "../BoardController.h"

//==============================================================================
LayoutTab::LayoutTab()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    addAndMakeVisible(pageUpButton = new TextButton());
    pageUpButton->setButtonText("Page Up");
    
    addAndMakeVisible(pageDownButton = new TextButton() );
    //TextButton *child = static_cast<TextButton*>(pageDownButton.get());
    pageDownButton->setButtonText("Page Down");
    
    
    addAndMakeVisible(pageCombo = new ComboBox());
    
    
    
    pageCombo->addListener(this);
    
    
    addAndMakeVisible(pageNameLabel = new Label() );
    pageNameLabel->setText("Page Name", NotificationType::dontSendNotification);
    
    addAndMakeVisible(pageNameEditor = new TextEditor());
    
    BoardController::addListener(this);
    pageNameEditor->addListener(this);
    
    

    
    

}

LayoutTab::~LayoutTab()
{
}

void LayoutTab::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::azure);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

}

void LayoutTab::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    int drawWidth = getWidth() - 40;
    
    int drawHeight = getHeight() * 0.8;
    
    int drawY = (getHeight() - drawHeight)/2;
    
    if(pedalView)
    {
    pedalView->setBounds(Rectangle<int>(20,drawY,drawWidth,drawHeight));
    }
    
    pageDownButton->setBounds(20, 20, 40, 24);
    pageDownButton->addListener(this);
    
    pageCombo->setBounds(100, 20, 100, 24);
    pageUpButton->setBounds(pageCombo->getX()+pageCombo->getWidth()+20, 20, 40, 24);
    pageUpButton->addListener(this);
    pageNameLabel->setBounds(pageUpButton->getX()+pageUpButton->getWidth()+20, 20, 100, 24);
    pageNameEditor->setBounds(pageNameLabel->getX()+pageNameLabel->getWidth()+20, 20, 200, 24);

    

}

void LayoutTab::buttonClicked(juce::Button *button)
{
    if(button == pageDownButton)
    {
        if(pageCombo->getSelectedId()>1)
        {
            pageCombo->setSelectedId(pageCombo->getSelectedId()-1);
        }
    }
    if(button==pageUpButton)
    {
        if(pageCombo->getSelectedId()<pageCombo->getNumItems())
        {
            pageCombo->setSelectedId(pageCombo->getSelectedId()+1);
        }
    }
}

void LayoutTab::boardControllerChanged()
{
    for(int i = 1; i <= BoardController::getDefaultInstance()->getNumberOfPages();i++) {
     pageCombo->addItem(String(i), i);
     }
    pageCombo->setSelectedId(1);
    addAndMakeVisible(pedalView = BoardController::getDefaultInstance()->createView());
    pageNameEditor->getTextValue().referTo(BoardController::getDefaultInstance()->getPage(1)->getName());
    resized();
}

void LayoutTab::comboBoxChanged(juce::ComboBox *comboBoxThatHasChanged)
{
    if(pedalView)
    {
    pedalView->setPage(comboBoxThatHasChanged->getSelectedId());
        //pageNameEditor->setText(BoardController::getDefaultInstance()->getPage(pedalView->getPage())->getName());
        pageNameEditor->getTextValue().referTo(BoardController::getDefaultInstance()->getPage(pedalView->getPage())->getName());
    }
}

void LayoutTab::textEditorTextChanged(TextEditor &editor)
{
    /*PageModel *page = BoardController::getDefaultInstance()->getPage( pedalView->getPage() );
    page->setName(editor.getTextValue().toString());
    Logger::outputDebugString("Changed");*/
}
