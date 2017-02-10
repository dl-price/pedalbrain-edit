
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
    setState(25);
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
      setState(22);
      statement();
      setState(27);
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
    setState(28);
    expression();
    setState(30);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SwiftParser::T__0) {
      setState(29);
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

SwiftParser::Primary_expressionContext* SwiftParser::ExpressionContext::primary_expression() {
  return getRuleContext<SwiftParser::Primary_expressionContext>(0);
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
    setState(32);
    primary_expression(0);
   
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

SwiftParser::Primary_expressionContext* SwiftParser::Primary_expressionContext::primary_expression() {
  return getRuleContext<SwiftParser::Primary_expressionContext>(0);
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
   return primary_expression(0);
}

SwiftParser::Primary_expressionContext* SwiftParser::primary_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SwiftParser::Primary_expressionContext *_localctx = _tracker.createInstance<Primary_expressionContext>(_ctx, parentState);
  SwiftParser::Primary_expressionContext *previousContext = _localctx;
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, SwiftParser::RulePrimary_expression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::Identifier: {
        setState(35);
        dynamic_cast<Primary_expressionContext *>(_localctx)->member = identifier();
        setState(36);
        match(SwiftParser::T__1);
        setState(37);
        match(SwiftParser::T__2);
        break;
      }

      case SwiftParser::T__4:
      case SwiftParser::T__5:
      case SwiftParser::T__6:
      case SwiftParser::T__7:
      case SwiftParser::Decimal_literal:
      case SwiftParser::Pure_decimal_digits: {
        setState(39);
        literal_expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(50);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Primary_expressionContext>(parentContext, parentState);
        _localctx->parentexp = previousContext;
        pushNewRecursionContext(_localctx, startState, RulePrimary_expression);
        setState(42);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(43);
        match(SwiftParser::T__3);
        setState(44);
        dynamic_cast<Primary_expressionContext *>(_localctx)->member = identifier();
        setState(45);
        match(SwiftParser::T__1);
        setState(46);
        match(SwiftParser::T__2); 
      }
      setState(52);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
  enterRule(_localctx, 8, SwiftParser::RuleLiteral_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
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
  enterRule(_localctx, 10, SwiftParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(58);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::T__4:
      case SwiftParser::Decimal_literal:
      case SwiftParser::Pure_decimal_digits: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        numeric_literal();
        break;
      }

      case SwiftParser::T__5:
      case SwiftParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(56);
        boolean_literal();
        break;
      }

      case SwiftParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(57);
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
  enterRule(_localctx, 12, SwiftParser::RuleNumeric_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SwiftParser::T__4) {
      setState(60);
      match(SwiftParser::T__4);
    }
    setState(63);
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
  enterRule(_localctx, 14, SwiftParser::RuleBoolean_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
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
  enterRule(_localctx, 16, SwiftParser::RuleNil_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
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
  enterRule(_localctx, 18, SwiftParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
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
  enterRule(_localctx, 20, SwiftParser::RuleInteger_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
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
    case 3: return primary_expressionSempred(dynamic_cast<Primary_expressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SwiftParser::primary_expressionSempred(Primary_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

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
  "top_level", "statement", "expression", "primary_expression", "literal_expression", 
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
    0x3, 0xe, 0x4c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x7, 0x2, 0x1a, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x2b, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x33, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x36, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0x3d, 0xa, 0x7, 0x3, 0x8, 0x5, 0x8, 0x40, 0xa, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x3, 0x8, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x4, 0x3, 0x2, 0x8, 0x9, 0x3, 
    0x2, 0xc, 0xd, 0x47, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x22, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x37, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x43, 0x3, 0x2, 0x2, 0x2, 0x12, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x47, 0x3, 0x2, 0x2, 0x2, 0x16, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1f, 
    0x21, 0x7, 0x3, 0x2, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x5, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 
    0x8, 0x5, 0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x8, 0x5, 
    0x1, 0x2, 0x25, 0x26, 0x5, 0x14, 0xb, 0x2, 0x26, 0x27, 0x7, 0x4, 0x2, 
    0x2, 0x27, 0x28, 0x7, 0x5, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x2b, 0x5, 0xa, 0x6, 0x2, 0x2a, 0x24, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x34, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 
    0xc, 0x4, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x6, 0x2, 0x2, 0x2e, 0x2f, 0x5, 
    0x14, 0xb, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 0x31, 0x7, 0x5, 
    0x2, 0x2, 0x31, 0x33, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x9, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x5, 0xc, 0x7, 0x2, 0x38, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3d, 0x5, 0xe, 0x8, 0x2, 0x3a, 0x3d, 0x5, 
    0x10, 0x9, 0x2, 0x3b, 0x3d, 0x5, 0x12, 0xa, 0x2, 0x3c, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x7, 0x2, 0x2, 
    0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0x16, 0xc, 0x2, 0x42, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x9, 0x2, 0x2, 0x2, 0x44, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0xa, 0x2, 0x2, 0x46, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x7, 0xb, 0x2, 0x2, 0x48, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4a, 0x9, 0x3, 0x2, 0x2, 0x4a, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x1b, 0x20, 0x2a, 0x34, 0x3c, 0x3f, 
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
