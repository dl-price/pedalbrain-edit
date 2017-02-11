/*
  ==============================================================================

    ScriptHandler.cpp
    Created: 10 Feb 2017 9:18:53pm
    Author:  Daniel Price

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ScriptHandler.h"
#include "antlr4-runtime.h"
#include "Antlr/SwiftLexer.h"
#include "Antlr/SwiftBaseVisitor.h"
#include "Antlr/SwiftParser.h"
#include "Application.h"
#include "Macros.h"
#include <boost/optional.hpp>
//==============================================================================

class SomethingVisitor : public SwiftBaseVisitor
{
    antlrcpp::Any visitPrimary_expression(SwiftParser::Primary_expressionContext *context) override {
        
        if(context->identifier())
        {
            String id = (String)context->identifier()->getText();
            if(!appObject->scriptHandler->stack.hasProperty(id))
            {
                Logger::outputDebugString("Nope");
                return antlrcpp::Any() ;
            }
            
            return appObject->scriptHandler->stack.getProperty(id);
        }
        
        return NULL;
        
    }
    
    antlrcpp::Any visitExplicit_member_expression(SwiftParser::Explicit_member_expressionContext *ctx) override {
        
        antlrcpp::Any returnVal = visit(ctx->postfix_expression());
        
        if(returnVal.isNull())
        {
            return NULL;
        }
        
        var vars = returnVal.as<var>();
        
        DynamicObject *obj = vars.getDynamicObject();
        
        if(obj->hasMethod((String)ctx->identifier()->getText()))
        {
            juce::var::NativeFunction func = obj->getProperty((String)ctx->identifier()->getText()).getNativeFunction();
            func( var::NativeFunctionArgs(var(), new var(), 0) );
        }
        else
        {
            Logger::outputDebugString("No method. Blow up");
        }
    return NULL;
    }
    
    antlrcpp::Any visitFunction_call_expression(SwiftParser::Function_call_expressionContext *context) override {
        
        String id = (String)context->postfix_expression()->getText();
        
        appObject->scriptHandler->stack.invokeMethod(id, var::NativeFunctionArgs(var(), new var(), 0));
        
        return NULL;
    }

    
};

ScriptHandler::ScriptHandler()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setupStack();
    
}

ScriptHandler::~ScriptHandler()
{
}

void ScriptHandler::runScript(juce::String script)
{
    SwiftLexer *lexer = new SwiftLexer(new antlr4::ANTLRInputStream(script.toStdString()));
    
    antlr4::CommonTokenStream *tokens = new antlr4::CommonTokenStream(lexer);
    
    SwiftParser *parser = new SwiftParser(tokens);
    
    SomethingVisitor *visitor = new SomethingVisitor();
    
    visitor->visit(parser->top_level());
}

void ScriptHandler::setupStack()
{
    stack.setMethod("log", &ScriptHandler::log);
}
