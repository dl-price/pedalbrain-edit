
// Generated from Swift.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "SwiftListener.h"


/**
 * This class provides an empty implementation of SwiftListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SwiftBaseListener : public SwiftListener {
public:

  virtual void enterTop_level(SwiftParser::Top_levelContext * /*ctx*/) override { }
  virtual void exitTop_level(SwiftParser::Top_levelContext * /*ctx*/) override { }

  virtual void enterStatement(SwiftParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(SwiftParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression(SwiftParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SwiftParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPrimary_expression(SwiftParser::Primary_expressionContext * /*ctx*/) override { }
  virtual void exitPrimary_expression(SwiftParser::Primary_expressionContext * /*ctx*/) override { }

  virtual void enterLiteral_expression(SwiftParser::Literal_expressionContext * /*ctx*/) override { }
  virtual void exitLiteral_expression(SwiftParser::Literal_expressionContext * /*ctx*/) override { }

  virtual void enterLiteral(SwiftParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(SwiftParser::LiteralContext * /*ctx*/) override { }

  virtual void enterNumeric_literal(SwiftParser::Numeric_literalContext * /*ctx*/) override { }
  virtual void exitNumeric_literal(SwiftParser::Numeric_literalContext * /*ctx*/) override { }

  virtual void enterBoolean_literal(SwiftParser::Boolean_literalContext * /*ctx*/) override { }
  virtual void exitBoolean_literal(SwiftParser::Boolean_literalContext * /*ctx*/) override { }

  virtual void enterNil_literal(SwiftParser::Nil_literalContext * /*ctx*/) override { }
  virtual void exitNil_literal(SwiftParser::Nil_literalContext * /*ctx*/) override { }

  virtual void enterIdentifier(SwiftParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(SwiftParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterInteger_literal(SwiftParser::Integer_literalContext * /*ctx*/) override { }
  virtual void exitInteger_literal(SwiftParser::Integer_literalContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

