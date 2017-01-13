/*
  ==============================================================================

    PageModel.cpp
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"
#include "BoardController.h"

//==============================================================================
PageModel::PageModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    buttons = OwnedArray<ButtonModel>();
    

}

PageModel::~PageModel()
{
}

PageModel *PageModel::createBlankPage()
{
    PageModel *newModel = new PageModel();
    
    return newModel;
}

void PageModel::initFromNothing()
{
    for (int i = 0; i< BoardController::getInstance()->getNumberOfButtons();i++)
    {
        buttons.add(new ButtonModel);
    }
}
