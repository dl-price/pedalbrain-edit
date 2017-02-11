
// Generated from Swift.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "SwiftParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SwiftParser.
 */
class  SwiftListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTop_level(SwiftParser::Top_levelContext *ctx) = 0;
  virtual void exitTop_level(SwiftParser::Top_levelContext *ctx) = 0;

  virtual void enterStatement(SwiftParser::StatementContext *ctx) = 0;
  virtual void exitStatement(SwiftParser::StatementContext *ctx) = 0;

  virtual void enterExpression(SwiftParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SwiftParser::ExpressionContext *ctx) = 0;

  virtual void enterPrefix_expression(SwiftParser::Prefix_expressionContext *ctx) = 0;
  virtual void exitPrefix_expression(SwiftParser::Prefix_expressionContext *ctx) = 0;

  virtual void enterPrimary_expression(SwiftParser::Primary_expressionContext *ctx) = 0;
  virtual void exitPrimary_expression(SwiftParser::Primary_expressionContext *ctx) = 0;

  virtual void enterParenthesized_expression(SwiftParser::Parenthesized_expressionContext *ctx) = 0;
  virtual void exitParenthesized_expression(SwiftParser::Parenthesized_expressionContext *ctx) = 0;

  virtual void enterExplicit_member_expression(SwiftParser::Explicit_member_expressionContext *ctx) = 0;
  virtual void exitExplicit_member_expression(SwiftParser::Explicit_member_expressionContext *ctx) = 0;

  virtual void enterExplicit_property_expression(SwiftParser::Explicit_property_expressionContext *ctx) = 0;
  virtual void exitExplicit_property_expression(SwiftParser::Explicit_property_expressionContext *ctx) = 0;

  virtual void enterFunction_call_expression(SwiftParser::Function_call_expressionContext *ctx) = 0;
  virtual void exitFunction_call_expression(SwiftParser::Function_call_expressionContext *ctx) = 0;

  virtual void enterPrimary(SwiftParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(SwiftParser::PrimaryContext *ctx) = 0;

  virtual void enterLiteral_expression(SwiftParser::Literal_expressionContext *ctx) = 0;
  virtual void exitLiteral_expression(SwiftParser::Literal_expressionContext *ctx) = 0;

  virtual void enterLiteral(SwiftParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(SwiftParser::LiteralContext *ctx) = 0;

  virtual void enterNumeric_literal(SwiftParser::Numeric_literalContext *ctx) = 0;
  virtual void exitNumeric_literal(SwiftParser::Numeric_literalContext *ctx) = 0;

  virtual void enterBoolean_literal(SwiftParser::Boolean_literalContext *ctx) = 0;
  virtual void exitBoolean_literal(SwiftParser::Boolean_literalContext *ctx) = 0;

  virtual void enterNil_literal(SwiftParser::Nil_literalContext *ctx) = 0;
  virtual void exitNil_literal(SwiftParser::Nil_literalContext *ctx) = 0;

  virtual void enterIdentifier(SwiftParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(SwiftParser::IdentifierContext *ctx) = 0;

  virtual void enterInteger_literal(SwiftParser::Integer_literalContext *ctx) = 0;
  virtual void exitInteger_literal(SwiftParser::Integer_literalContext *ctx) = 0;


};
