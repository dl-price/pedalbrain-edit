
// Generated from Swift.g4 by ANTLR 4.6


#include "SwiftListener.h"
#include "SwiftVisitor.h"

#include "SwiftParser.h"


using namespace antlrcpp;
using namespace antlr4;

SwiftParser::SwiftParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SwiftParser::~SwiftParser() {
  delete _interpreter;
}

std::string SwiftParser::getGrammarFileName() const {
  return "Swift.g4";
}

const std::vector<std::string>& SwiftParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SwiftParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Top_levelContext ------------------------------------------------------------------

SwiftParser::Top_levelContext::Top_levelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SwiftParser::StatementContext *> SwiftParser::Top_levelContext::statement() {
  return getRuleContexts<SwiftParser::StatementContext>();
}

SwiftParser::StatementContext* SwiftParser::Top_levelContext::statement(size_t i) {
  return getRuleContext<SwiftParser::StatementContext>(i);
}


size_t SwiftParser::Top_levelContext::getRuleIndex() const {
  return SwiftParser::RuleTop_level;
}

void SwiftParser::Top_levelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTop_level(this);
}

void SwiftParser::Top_levelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTop_level(this);
}


antlrcpp::Any SwiftParser::Top_levelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitTop_level(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Top_levelContext* SwiftParser::top_level() {
  Top_levelContext *_localctx = _tracker.createInstance<Top_levelContext>(_ctx, getState());
  enterRule(_localctx, 0, SwiftParser::RuleTop_level);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SwiftParser::T__4)
      | (1ULL << SwiftParser::T__5)
      | (1ULL << SwiftParser::T__6)
      | (1ULL << SwiftParser::T__7)
      | (1ULL << SwiftParser::Identifier)
      | (1ULL << SwiftParser::Decimal_literal)
      | (1ULL << SwiftParser::Pure_decimal_digits))) != 0)) {
      setState(28);
      statement();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SwiftParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::ExpressionContext* SwiftParser::StatementContext::expression() {
  return getRuleContext<SwiftParser::ExpressionContext>(0);
}


size_t SwiftParser::StatementContext::getRuleIndex() const {
  return SwiftParser::RuleStatement;
}

void SwiftParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void SwiftParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any SwiftParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::StatementContext* SwiftParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, SwiftParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    expression();
    setState(36);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SwiftParser::T__0) {
      setState(35);
      match(SwiftParser::T__0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SwiftParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::Prefix_expressionContext* SwiftParser::ExpressionContext::prefix_expression() {
  return getRuleContext<SwiftParser::Prefix_expressionContext>(0);
}


size_t SwiftParser::ExpressionContext::getRuleIndex() const {
  return SwiftParser::RuleExpression;
}

void SwiftParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SwiftParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any SwiftParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::ExpressionContext* SwiftParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, SwiftParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    prefix_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Prefix_expressionContext ------------------------------------------------------------------

SwiftParser::Prefix_expressionContext::Prefix_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::Postfix_expressionContext* SwiftParser::Prefix_expressionContext::postfix_expression() {
  return getRuleContext<SwiftParser::Postfix_expressionContext>(0);
}


size_t SwiftParser::Prefix_expressionContext::getRuleIndex() const {
  return SwiftParser::RulePrefix_expression;
}

void SwiftParser::Prefix_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefix_expression(this);
}

void SwiftParser::Prefix_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefix_expression(this);
}


antlrcpp::Any SwiftParser::Prefix_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitPrefix_expression(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Prefix_expressionContext* SwiftParser::prefix_expression() {
  Prefix_expressionContext *_localctx = _tracker.createInstance<Prefix_expressionContext>(_ctx, getState());
  enterRule(_localctx, 6, SwiftParser::RulePrefix_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    postfix_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_expressionContext ------------------------------------------------------------------

SwiftParser::Primary_expressionContext::Primary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::IdentifierContext* SwiftParser::Primary_expressionContext::identifier() {
  return getRuleContext<SwiftParser::IdentifierContext>(0);
}

SwiftParser::Literal_expressionContext* SwiftParser::Primary_expressionContext::literal_expression() {
  return getRuleContext<SwiftParser::Literal_expressionContext>(0);
}


size_t SwiftParser::Primary_expressionContext::getRuleIndex() const {
  return SwiftParser::RulePrimary_expression;
}

void SwiftParser::Primary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_expression(this);
}

void SwiftParser::Primary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_expression(this);
}


antlrcpp::Any SwiftParser::Primary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitPrimary_expression(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Primary_expressionContext* SwiftParser::primary_expression() {
  Primary_expressionContext *_localctx = _tracker.createInstance<Primary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 8, SwiftParser::RulePrimary_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(42);
        identifier();
        break;
      }

      case SwiftParser::T__4:
      case SwiftParser::T__5:
      case SwiftParser::T__6:
      case SwiftParser::T__7:
      case SwiftParser::Decimal_literal:
      case SwiftParser::Pure_decimal_digits: {
        enterOuterAlt(_localctx, 2);
        setState(43);
        literal_expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parenthesized_expressionContext ------------------------------------------------------------------

SwiftParser::Parenthesized_expressionContext::Parenthesized_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SwiftParser::Parenthesized_expressionContext::getRuleIndex() const {
  return SwiftParser::RuleParenthesized_expression;
}

void SwiftParser::Parenthesized_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesized_expression(this);
}

void SwiftParser::Parenthesized_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesized_expression(this);
}


antlrcpp::Any SwiftParser::Parenthesized_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitParenthesized_expression(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Parenthesized_expressionContext* SwiftParser::parenthesized_expression() {
  Parenthesized_expressionContext *_localctx = _tracker.createInstance<Parenthesized_expressionContext>(_ctx, getState());
  enterRule(_localctx, 10, SwiftParser::RuleParenthesized_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(SwiftParser::T__1);
    setState(47);
    match(SwiftParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Postfix_expressionContext ------------------------------------------------------------------

SwiftParser::Postfix_expressionContext::Postfix_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SwiftParser::Postfix_expressionContext::getRuleIndex() const {
  return SwiftParser::RulePostfix_expression;
}

void SwiftParser::Postfix_expressionContext::copyFrom(Postfix_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Explicit_member_expressionContext ------------------------------------------------------------------

SwiftParser::Postfix_expressionContext* SwiftParser::Explicit_member_expressionContext::postfix_expression() {
  return getRuleContext<SwiftParser::Postfix_expressionContext>(0);
}

SwiftParser::IdentifierContext* SwiftParser::Explicit_member_expressionContext::identifier() {
  return getRuleContext<SwiftParser::IdentifierContext>(0);
}

SwiftParser::Explicit_member_expressionContext::Explicit_member_expressionContext(Postfix_expressionContext *ctx) { copyFrom(ctx); }

void SwiftParser::Explicit_member_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicit_member_expression(this);
}
void SwiftParser::Explicit_member_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicit_member_expression(this);
}

antlrcpp::Any SwiftParser::Explicit_member_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitExplicit_member_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Explicit_property_expressionContext ------------------------------------------------------------------

SwiftParser::Postfix_expressionContext* SwiftParser::Explicit_property_expressionContext::postfix_expression() {
  return getRuleContext<SwiftParser::Postfix_expressionContext>(0);
}

SwiftParser::IdentifierContext* SwiftParser::Explicit_property_expressionContext::identifier() {
  return getRuleContext<SwiftParser::IdentifierContext>(0);
}

SwiftParser::Explicit_property_expressionContext::Explicit_property_expressionContext(Postfix_expressionContext *ctx) { copyFrom(ctx); }

void SwiftParser::Explicit_property_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicit_property_expression(this);
}
void SwiftParser::Explicit_property_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicit_property_expression(this);
}

antlrcpp::Any SwiftParser::Explicit_property_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitExplicit_property_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Function_call_expressionContext ------------------------------------------------------------------

SwiftParser::Postfix_expressionContext* SwiftParser::Function_call_expressionContext::postfix_expression() {
  return getRuleContext<SwiftParser::Postfix_expressionContext>(0);
}

SwiftParser::Parenthesized_expressionContext* SwiftParser::Function_call_expressionContext::parenthesized_expression() {
  return getRuleContext<SwiftParser::Parenthesized_expressionContext>(0);
}

SwiftParser::Function_call_expressionContext::Function_call_expressionContext(Postfix_expressionContext *ctx) { copyFrom(ctx); }

void SwiftParser::Function_call_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call_expression(this);
}
void SwiftParser::Function_call_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call_expression(this);
}

antlrcpp::Any SwiftParser::Function_call_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitFunction_call_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrimaryContext ------------------------------------------------------------------

SwiftParser::Primary_expressionContext* SwiftParser::PrimaryContext::primary_expression() {
  return getRuleContext<SwiftParser::Primary_expressionContext>(0);
}

SwiftParser::PrimaryContext::PrimaryContext(Postfix_expressionContext *ctx) { copyFrom(ctx); }

void SwiftParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}
void SwiftParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}

antlrcpp::Any SwiftParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Postfix_expressionContext* SwiftParser::postfix_expression() {
   return postfix_expression(0);
}

SwiftParser::Postfix_expressionContext* SwiftParser::postfix_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SwiftParser::Postfix_expressionContext *_localctx = _tracker.createInstance<Postfix_expressionContext>(_ctx, parentState);
  SwiftParser::Postfix_expressionContext *previousContext = _localctx;
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, SwiftParser::RulePostfix_expression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<PrimaryContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(50);
    primary_expression();
    _ctx->stop = _input->LT(-1);
    setState(65);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(63);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Function_call_expressionContext>(_tracker.createInstance<Postfix_expressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfix_expression);
          setState(52);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(53);
          parenthesized_expression();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Explicit_member_expressionContext>(_tracker.createInstance<Postfix_expressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfix_expression);
          setState(54);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(55);
          match(SwiftParser::T__3);
          setState(56);
          identifier();
          setState(57);
          match(SwiftParser::T__1);
          setState(58);
          match(SwiftParser::T__2);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Explicit_property_expressionContext>(_tracker.createInstance<Postfix_expressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfix_expression);
          setState(60);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(61);
          match(SwiftParser::T__3);
          setState(62);
          identifier();
          break;
        }

        } 
      }
      setState(67);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Literal_expressionContext ------------------------------------------------------------------

SwiftParser::Literal_expressionContext::Literal_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::LiteralContext* SwiftParser::Literal_expressionContext::literal() {
  return getRuleContext<SwiftParser::LiteralContext>(0);
}


size_t SwiftParser::Literal_expressionContext::getRuleIndex() const {
  return SwiftParser::RuleLiteral_expression;
}

void SwiftParser::Literal_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_expression(this);
}

void SwiftParser::Literal_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_expression(this);
}


antlrcpp::Any SwiftParser::Literal_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitLiteral_expression(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Literal_expressionContext* SwiftParser::literal_expression() {
  Literal_expressionContext *_localctx = _tracker.createInstance<Literal_expressionContext>(_ctx, getState());
  enterRule(_localctx, 14, SwiftParser::RuleLiteral_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

SwiftParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::Numeric_literalContext* SwiftParser::LiteralContext::numeric_literal() {
  return getRuleContext<SwiftParser::Numeric_literalContext>(0);
}

SwiftParser::Boolean_literalContext* SwiftParser::LiteralContext::boolean_literal() {
  return getRuleContext<SwiftParser::Boolean_literalContext>(0);
}

SwiftParser::Nil_literalContext* SwiftParser::LiteralContext::nil_literal() {
  return getRuleContext<SwiftParser::Nil_literalContext>(0);
}


size_t SwiftParser::LiteralContext::getRuleIndex() const {
  return SwiftParser::RuleLiteral;
}

void SwiftParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void SwiftParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any SwiftParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::LiteralContext* SwiftParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 16, SwiftParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::T__4:
      case SwiftParser::Decimal_literal:
      case SwiftParser::Pure_decimal_digits: {
        enterOuterAlt(_localctx, 1);
        setState(70);
        numeric_literal();
        break;
      }

      case SwiftParser::T__5:
      case SwiftParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(71);
        boolean_literal();
        break;
      }

      case SwiftParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(72);
        nil_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_literalContext ------------------------------------------------------------------

SwiftParser::Numeric_literalContext::Numeric_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::Integer_literalContext* SwiftParser::Numeric_literalContext::integer_literal() {
  return getRuleContext<SwiftParser::Integer_literalContext>(0);
}


size_t SwiftParser::Numeric_literalContext::getRuleIndex() const {
  return SwiftParser::RuleNumeric_literal;
}

void SwiftParser::Numeric_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric_literal(this);
}

void SwiftParser::Numeric_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric_literal(this);
}


antlrcpp::Any SwiftParser::Numeric_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitNumeric_literal(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Numeric_literalContext* SwiftParser::numeric_literal() {
  Numeric_literalContext *_localctx = _tracker.createInstance<Numeric_literalContext>(_ctx, getState());
  enterRule(_localctx, 18, SwiftParser::RuleNumeric_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SwiftParser::T__4) {
      setState(75);
      match(SwiftParser::T__4);
    }
    setState(78);
    integer_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_literalContext ------------------------------------------------------------------

SwiftParser::Boolean_literalContext::Boolean_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SwiftParser::Boolean_literalContext::getRuleIndex() const {
  return SwiftParser::RuleBoolean_literal;
}

void SwiftParser::Boolean_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean_literal(this);
}

void SwiftParser::Boolean_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean_literal(this);
}


antlrcpp::Any SwiftParser::Boolean_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitBoolean_literal(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Boolean_literalContext* SwiftParser::boolean_literal() {
  Boolean_literalContext *_localctx = _tracker.createInstance<Boolean_literalContext>(_ctx, getState());
  enterRule(_localctx, 20, SwiftParser::RuleBoolean_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _la = _input->LA(1);
    if (!(_la == SwiftParser::T__5

    || _la == SwiftParser::T__6)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nil_literalContext ------------------------------------------------------------------

SwiftParser::Nil_literalContext::Nil_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SwiftParser::Nil_literalContext::getRuleIndex() const {
  return SwiftParser::RuleNil_literal;
}

void SwiftParser::Nil_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNil_literal(this);
}

void SwiftParser::Nil_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNil_literal(this);
}


antlrcpp::Any SwiftParser::Nil_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitNil_literal(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Nil_literalContext* SwiftParser::nil_literal() {
  Nil_literalContext *_localctx = _tracker.createInstance<Nil_literalContext>(_ctx, getState());
  enterRule(_localctx, 22, SwiftParser::RuleNil_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(SwiftParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

SwiftParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SwiftParser::IdentifierContext::Identifier() {
  return getToken(SwiftParser::Identifier, 0);
}


size_t SwiftParser::IdentifierContext::getRuleIndex() const {
  return SwiftParser::RuleIdentifier;
}

void SwiftParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void SwiftParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any SwiftParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::IdentifierContext* SwiftParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 24, SwiftParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(SwiftParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_literalContext ------------------------------------------------------------------

SwiftParser::Integer_literalContext::Integer_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SwiftParser::Integer_literalContext::Decimal_literal() {
  return getToken(SwiftParser::Decimal_literal, 0);
}

tree::TerminalNode* SwiftParser::Integer_literalContext::Pure_decimal_digits() {
  return getToken(SwiftParser::Pure_decimal_digits, 0);
}


size_t SwiftParser::Integer_literalContext::getRuleIndex() const {
  return SwiftParser::RuleInteger_literal;
}

void SwiftParser::Integer_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_literal(this);
}

void SwiftParser::Integer_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SwiftListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_literal(this);
}


antlrcpp::Any SwiftParser::Integer_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitInteger_literal(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::Integer_literalContext* SwiftParser::integer_literal() {
  Integer_literalContext *_localctx = _tracker.createInstance<Integer_literalContext>(_ctx, getState());
  enterRule(_localctx, 26, SwiftParser::RuleInteger_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!(_la == SwiftParser::Decimal_literal

    || _la == SwiftParser::Pure_decimal_digits)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SwiftParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return postfix_expressionSempred(dynamic_cast<Postfix_expressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SwiftParser::postfix_expressionSempred(Postfix_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SwiftParser::_decisionToDFA;
atn::PredictionContextCache SwiftParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SwiftParser::_atn;
std::vector<uint16_t> SwiftParser::_serializedATN;

std::vector<std::string> SwiftParser::_ruleNames = {
  "top_level", "statement", "expression", "prefix_expression", "primary_expression", 
  "parenthesized_expression", "postfix_expression", "literal_expression", 
  "literal", "numeric_literal", "boolean_literal", "nil_literal", "identifier", 
  "integer_literal"
};

std::vector<std::string> SwiftParser::_literalNames = {
  "", "';'", "'('", "')'", "'.'", "'-'", "'true'", "'false'", "'nil'"
};

std::vector<std::string> SwiftParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "Identifier", "Decimal_literal", "Pure_decimal_digits", 
  "WS"
};

dfa::Vocabulary SwiftParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SwiftParser::_tokenNames;

SwiftParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 
    0x3, 0xe, 0x5b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2f, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x42, 0xa, 0x8, 0xc, 0x8, 
    0xe, 0x8, 0x45, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x4c, 0xa, 0xa, 0x3, 0xb, 0x5, 0xb, 0x4f, 0xa, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x2, 0x3, 0xe, 0x10, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 
    0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0xc, 0xd, 0x55, 0x2, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x24, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x33, 0x3, 0x2, 0x2, 0x2, 0x10, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x52, 0x3, 0x2, 0x2, 0x2, 0x18, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x56, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 0x6, 0x4, 0x2, 0x25, 0x27, 0x7, 0x3, 
    0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x5, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x8, 0x5, 0x2, 
    0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0xe, 0x8, 0x2, 0x2b, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x5, 0x1a, 0xe, 0x2, 0x2d, 0x2f, 
    0x5, 0x10, 0x9, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x4, 
    0x2, 0x2, 0x31, 0x32, 0x7, 0x5, 0x2, 0x2, 0x32, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x34, 0x8, 0x8, 0x1, 0x2, 0x34, 0x35, 0x5, 0xa, 0x6, 0x2, 
    0x35, 0x43, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0xc, 0x5, 0x2, 0x2, 0x37, 
    0x42, 0x5, 0xc, 0x7, 0x2, 0x38, 0x39, 0xc, 0x4, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0x6, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x1a, 0xe, 0x2, 0x3b, 0x3c, 0x7, 
    0x4, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x5, 0x2, 0x2, 0x3d, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3f, 0xc, 0x3, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x6, 0x2, 
    0x2, 0x40, 0x42, 0x5, 0x1a, 0xe, 0x2, 0x41, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x38, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0xf, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0x12, 0xa, 0x2, 0x47, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x49, 0x4c, 0x5, 0x16, 0xc, 
    0x2, 0x4a, 0x4c, 0x5, 0x18, 0xd, 0x2, 0x4b, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x7, 0x7, 0x2, 0x2, 0x4e, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 0x1c, 0xf, 0x2, 0x51, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x53, 0x9, 0x2, 0x2, 0x2, 0x53, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x7, 0xa, 0x2, 0x2, 0x55, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x57, 0x7, 0xb, 0x2, 0x2, 0x57, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x59, 0x9, 0x3, 0x2, 0x2, 0x59, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x9, 0x21, 
    0x26, 0x2e, 0x41, 0x43, 0x4b, 0x4e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SwiftParser::Initializer SwiftParser::_init;
