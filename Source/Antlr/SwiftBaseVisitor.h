
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

  virtual antlrcpp::Any visitTop_level(SwiftParser::Top_levelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(SwiftParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(SwiftParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_literal(SwiftParser::Numeric_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_literal(SwiftParser::Boolean_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNil_literal(SwiftParser::Nil_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_literal(SwiftParser::Integer_literalContext *ctx) override {
    return visitChildren(ctx);
  }


};

