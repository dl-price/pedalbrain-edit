
// Generated from Swift.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "SwiftParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SwiftParser.
 */
class  SwiftVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SwiftParser.
   */
    virtual antlrcpp::Any visitEval(SwiftParser::EvalContext *context) = 0;

    virtual antlrcpp::Any visitAdditionExp(SwiftParser::AdditionExpContext *context) = 0;

    virtual antlrcpp::Any visitMultiplyExp(SwiftParser::MultiplyExpContext *context) = 0;

    virtual antlrcpp::Any visitAtomExp(SwiftParser::AtomExpContext *context) = 0;


};

