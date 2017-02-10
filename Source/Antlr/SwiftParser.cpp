
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
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SwiftParser::T__0)
      | (1ULL << SwiftParser::T__1)
      | (1ULL << SwiftParser::T__2)
      | (1ULL << SwiftParser::T__3)
      | (1ULL << SwiftParser::Decimal_literal)
      | (1ULL << SwiftParser::Pure_decimal_digits))) != 0)) {
      setState(14);
      statement();
      setState(19);
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

SwiftParser::LiteralContext* SwiftParser::StatementContext::literal() {
  return getRuleContext<SwiftParser::LiteralContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
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
  enterRule(_localctx, 4, SwiftParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(25);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::T__0:
      case SwiftParser::Decimal_literal:
      case SwiftParser::Pure_decimal_digits: {
        enterOuterAlt(_localctx, 1);
        setState(22);
        numeric_literal();
        break;
      }

      case SwiftParser::T__1:
      case SwiftParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        boolean_literal();
        break;
      }

      case SwiftParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(24);
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
  enterRule(_localctx, 6, SwiftParser::RuleNumeric_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SwiftParser::T__0) {
      setState(27);
      match(SwiftParser::T__0);
    }
    setState(30);
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
  enterRule(_localctx, 8, SwiftParser::RuleBoolean_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    _la = _input->LA(1);
    if (!(_la == SwiftParser::T__1

    || _la == SwiftParser::T__2)) {
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
  enterRule(_localctx, 10, SwiftParser::RuleNil_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    match(SwiftParser::T__3);
   
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
  enterRule(_localctx, 12, SwiftParser::RuleInteger_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
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

// Static vars and initialization.
std::vector<dfa::DFA> SwiftParser::_decisionToDFA;
atn::PredictionContextCache SwiftParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SwiftParser::_atn;
std::vector<uint16_t> SwiftParser::_serializedATN;

std::vector<std::string> SwiftParser::_ruleNames = {
  "top_level", "statement", "literal", "numeric_literal", "boolean_literal", 
  "nil_literal", "integer_literal"
};

std::vector<std::string> SwiftParser::_literalNames = {
  "", "'-'", "'true'", "'false'", "'nil'"
};

std::vector<std::string> SwiftParser::_symbolicNames = {
  "", "", "", "", "", "Decimal_literal", "Pure_decimal_digits", "WS"
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
    0x3, 0x9, 0x29, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x7, 0x2, 0x12, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x15, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x1c, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x1f, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x2, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x4, 0x3, 
    0x2, 0x4, 0x5, 0x3, 0x2, 0x7, 0x8, 0x25, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x22, 0x3, 0x2, 0x2, 0x2, 0xc, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x26, 0x3, 0x2, 0x2, 0x2, 0x10, 0x12, 0x5, 0x4, 0x3, 
    0x2, 0x11, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 
    0x5, 0x6, 0x4, 0x2, 0x17, 0x5, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1c, 0x5, 
    0x8, 0x5, 0x2, 0x19, 0x1c, 0x5, 0xa, 0x6, 0x2, 0x1a, 0x1c, 0x5, 0xc, 
    0x7, 0x2, 0x1b, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x5, 0xe, 0x8, 0x2, 0x21, 0x9, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x9, 
    0x2, 0x2, 0x2, 0x23, 0xb, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0x6, 
    0x2, 0x2, 0x25, 0xd, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x9, 0x3, 0x2, 
    0x2, 0x27, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5, 0x13, 0x1b, 0x1e, 
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
