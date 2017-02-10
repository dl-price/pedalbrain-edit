
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
    virtual antlrcpp::Any visitTop_level(SwiftParser::Top_levelContext *context) = 0;

    virtual antlrcpp::Any visitStatement(SwiftParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(SwiftParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_literal(SwiftParser::Numeric_literalContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_literal(SwiftParser::Boolean_literalContext *context) = 0;

    virtual antlrcpp::Any visitNil_literal(SwiftParser::Nil_literalContext *context) = 0;

    virtual antlrcpp::Any visitInteger_literal(SwiftParser::Integer_literalContext *context) = 0;


};

