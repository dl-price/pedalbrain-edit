/*
  ==============================================================================

    AudioFeaturesGroup.cpp
    Created: 30 Jan 2017 5:55:40am
    Author:  Daniel Price

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "AudioFeaturesGroup.h"
#include "AudioItemComponent.h"
#include "../Macros.h"
#include "../Application.h"

//==============================================================================
AudioFeaturesGroup::AudioFeaturesGroup()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    _loopsFlex = new FlexBox();
    
    /*for (int i=0; i < appObject->getDefaultBoardController()->getMaxAudioLoops(); i++)
    {
        
        FlexItem *item = new FlexItem(*new AudioItemComponent());
        item->minWidth = 150;
        item->minHeight = 24;
        item->maxWidth = 550;
        item->maxHeight = 30;
        item->flexGrow = 1;
        addAndMakeVisible(item->associatedComponent);
        _loopsFlex->items.add(*item);
        _loopsFlex->justifyContent = FlexBox::JustifyContent::center;
        _loopsFlex->alignItems = FlexBox::AlignItems::stretch;
        _loopsFlex->alignContent = FlexBox::AlignContent::stretch;
    }*/
    
    

}

AudioFeaturesGroup::~AudioFeaturesGroup()
{
}

void AudioFeaturesGroup::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::mintcream);
    g.fillRect( getLocalBounds());   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("AudioFeaturesGroup", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void AudioFeaturesGroup::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    _loopsFlex->performLayout(getLocalBounds());

}
