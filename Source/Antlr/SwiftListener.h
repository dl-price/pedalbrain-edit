
// Generated from Swift.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "SwiftParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SwiftParser.
 */
class  SwiftListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterEval(SwiftParser::EvalContext *ctx) = 0;
  virtual void exitEval(SwiftParser::EvalContext *ctx) = 0;

  virtual void enterAdditionExp(SwiftParser::AdditionExpContext *ctx) = 0;
  virtual void exitAdditionExp(SwiftParser::AdditionExpContext *ctx) = 0;

  virtual void enterMultiplyExp(SwiftParser::MultiplyExpContext *ctx) = 0;
  virtual void exitMultiplyExp(SwiftParser::MultiplyExpContext *ctx) = 0;

  virtual void enterAtomExp(SwiftParser::AtomExpContext *ctx) = 0;
  virtual void exitAtomExp(SwiftParser::AtomExpContext *ctx) = 0;


};

