/*
  ==============================================================================

    ScriptHandler.h
    Created: 10 Feb 2017 9:18:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#ifndef SCRIPTHANDLER_H_INCLUDED
#define SCRIPTHANDLER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "antlr4-runtime.h"
#include "Antlr/SwiftLexer.h"
#include "Antlr/SwiftBaseVisitor.h"
#include "Antlr/SwiftParser.h"

//==============================================================================
/*
*/
class ScriptHandler
{
public:
    ScriptHandler();
    ~ScriptHandler();

    void runScript(String script);
    
    void setupStack();
    
    DynamicObject stack;
    
    static var log(const var::NativeFunctionArgs &args) {
        Logger::outputDebugString("Logger called");
        return var();
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScriptHandler)
};


#endif  // SCRIPTHANDLER_H_INCLUDED
