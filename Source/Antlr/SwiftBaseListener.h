
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

  virtual void enterEval(SwiftParser::EvalContext * /*ctx*/) override { }
  virtual void exitEval(SwiftParser::EvalContext * /*ctx*/) override { }

  virtual void enterAdditionExp(SwiftParser::AdditionExpContext * /*ctx*/) override { }
  virtual void exitAdditionExp(SwiftParser::AdditionExpContext * /*ctx*/) override { }

  virtual void enterMultiplyExp(SwiftParser::MultiplyExpContext * /*ctx*/) override { }
  virtual void exitMultiplyExp(SwiftParser::MultiplyExpContext * /*ctx*/) override { }

  virtual void enterAtomExp(SwiftParser::AtomExpContext * /*ctx*/) override { }
  virtual void exitAtomExp(SwiftParser::AtomExpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

