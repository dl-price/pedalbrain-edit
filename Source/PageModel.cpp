/*
  ==============================================================================

    PageModel.cpp
    Created: 27 Dec 2016 7:28:57pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PageModel.h"
#include "BoardModel.h"

//==============================================================================
PageModel::PageModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    components = OwnedArray<ComponentModel>();
    
    for (int i = 0; i < BoardModel::getInstance()->boardType->getMaxComponents();i++)
    {
        ComponentModel* component = BoardModel::getInstance()->boardType->getBlankComponent(i);
        components.add(component);
    }
    

}

PageModel::~PageModel()
{
}

