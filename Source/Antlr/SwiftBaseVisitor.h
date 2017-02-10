
// Generated from Swift.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "SwiftVisitor.h"


/**
 * This class provides an empty implementation of SwiftVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SwiftBaseVisitor : public SwiftVisitor {
public:

  virtual antlrcpp::Any visitEval(SwiftParser::EvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditionExp(SwiftParser::AdditionExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplyExp(SwiftParser::MultiplyExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomExp(SwiftParser::AtomExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

