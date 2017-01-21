/*
  ==============================================================================

    PedalEdit.h
    Created: 26 Dec 2016 5:22:14pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef PEDALEDIT_H_INCLUDED
#define PEDALEDIT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentEdit.h"
#include "DevicesTab.h"

//==============================================================================
/*
*/
class PedalEdit    
                : public Component
                , public MenuBarModel
{
public:
    PedalEdit();
    ~PedalEdit();

    void paint (Graphics&) override;
    void resized() override;
    
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;
    
    ComponentEdit *componentEditor;
    
    PedalEdit *getDefaultComponent();
    
    

protected:
    ScopedPointer<TabbedComponent> superTabComponent;
    ScopedPointer<GlobalTab> globalTab;
    ScopedPointer<LayoutTab> layoutTab;
    ScopedPointer<DevicesTab> devicesTab;

    
    private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalEdit)
};


#endif  // PEDALEDIT_H_INCLUDED
