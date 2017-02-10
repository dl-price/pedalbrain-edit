
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

    virtual antlrcpp::Any visitExpression(SwiftParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrefix_expression(SwiftParser::Prefix_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_expression(SwiftParser::Primary_expressionContext *context) = 0;

    virtual antlrcpp::Any visitParenthesized_expression(SwiftParser::Parenthesized_expressionContext *context) = 0;

    virtual antlrcpp::Any visitExplicit_member_expression(SwiftParser::Explicit_member_expressionContext *context) = 0;

    virtual antlrcpp::Any visitExplicit_property_expression(SwiftParser::Explicit_property_expressionContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call_expression(SwiftParser::Function_call_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(SwiftParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_expression(SwiftParser::Literal_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(SwiftParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_literal(SwiftParser::Numeric_literalContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_literal(SwiftParser::Boolean_literalContext *context) = 0;

    virtual antlrcpp::Any visitNil_literal(SwiftParser::Nil_literalContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(SwiftParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitInteger_literal(SwiftParser::Integer_literalContext *context) = 0;


};

