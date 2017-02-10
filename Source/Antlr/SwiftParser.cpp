
// Generated from Swift.g4 by ANTLR 4.6


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


//----------------- EvalContext ------------------------------------------------------------------

SwiftParser::EvalContext::EvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SwiftParser::AdditionExpContext* SwiftParser::EvalContext::additionExp() {
  return getRuleContext<SwiftParser::AdditionExpContext>(0);
}


size_t SwiftParser::EvalContext::getRuleIndex() const {
  return SwiftParser::RuleEval;
}

antlrcpp::Any SwiftParser::EvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitEval(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::EvalContext* SwiftParser::eval() {
  EvalContext *_localctx = _tracker.createInstance<EvalContext>(_ctx, getState());
  enterRule(_localctx, 0, SwiftParser::RuleEval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    additionExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditionExpContext ------------------------------------------------------------------

SwiftParser::AdditionExpContext::AdditionExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SwiftParser::MultiplyExpContext *> SwiftParser::AdditionExpContext::multiplyExp() {
  return getRuleContexts<SwiftParser::MultiplyExpContext>();
}

SwiftParser::MultiplyExpContext* SwiftParser::AdditionExpContext::multiplyExp(size_t i) {
  return getRuleContext<SwiftParser::MultiplyExpContext>(i);
}


size_t SwiftParser::AdditionExpContext::getRuleIndex() const {
  return SwiftParser::RuleAdditionExp;
}

antlrcpp::Any SwiftParser::AdditionExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitAdditionExp(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::AdditionExpContext* SwiftParser::additionExp() {
  AdditionExpContext *_localctx = _tracker.createInstance<AdditionExpContext>(_ctx, getState());
  enterRule(_localctx, 2, SwiftParser::RuleAdditionExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    multiplyExp();
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SwiftParser::T__0

    || _la == SwiftParser::T__1) {
      setState(15);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SwiftParser::T__0: {
          setState(11);
          match(SwiftParser::T__0);
          setState(12);
          multiplyExp();
          break;
        }

        case SwiftParser::T__1: {
          setState(13);
          match(SwiftParser::T__1);
          setState(14);
          multiplyExp();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
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

//----------------- MultiplyExpContext ------------------------------------------------------------------

SwiftParser::MultiplyExpContext::MultiplyExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SwiftParser::AtomExpContext *> SwiftParser::MultiplyExpContext::atomExp() {
  return getRuleContexts<SwiftParser::AtomExpContext>();
}

SwiftParser::AtomExpContext* SwiftParser::MultiplyExpContext::atomExp(size_t i) {
  return getRuleContext<SwiftParser::AtomExpContext>(i);
}


size_t SwiftParser::MultiplyExpContext::getRuleIndex() const {
  return SwiftParser::RuleMultiplyExp;
}

antlrcpp::Any SwiftParser::MultiplyExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitMultiplyExp(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::MultiplyExpContext* SwiftParser::multiplyExp() {
  MultiplyExpContext *_localctx = _tracker.createInstance<MultiplyExpContext>(_ctx, getState());
  enterRule(_localctx, 4, SwiftParser::RuleMultiplyExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    atomExp();
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SwiftParser::T__2

    || _la == SwiftParser::T__3) {
      setState(25);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SwiftParser::T__2: {
          setState(21);
          match(SwiftParser::T__2);
          setState(22);
          atomExp();
          break;
        }

        case SwiftParser::T__3: {
          setState(23);
          match(SwiftParser::T__3);
          setState(24);
          atomExp();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(29);
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

//----------------- AtomExpContext ------------------------------------------------------------------

SwiftParser::AtomExpContext::AtomExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SwiftParser::AtomExpContext::Number() {
  return getToken(SwiftParser::Number, 0);
}

SwiftParser::AdditionExpContext* SwiftParser::AtomExpContext::additionExp() {
  return getRuleContext<SwiftParser::AdditionExpContext>(0);
}


size_t SwiftParser::AtomExpContext::getRuleIndex() const {
  return SwiftParser::RuleAtomExp;
}

antlrcpp::Any SwiftParser::AtomExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SwiftVisitor*>(visitor))
    return parserVisitor->visitAtomExp(this);
  else
    return visitor->visitChildren(this);
}

SwiftParser::AtomExpContext* SwiftParser::atomExp() {
  AtomExpContext *_localctx = _tracker.createInstance<AtomExpContext>(_ctx, getState());
  enterRule(_localctx, 6, SwiftParser::RuleAtomExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(35);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SwiftParser::Number: {
        enterOuterAlt(_localctx, 1);
        setState(30);
        match(SwiftParser::Number);
        break;
      }

      case SwiftParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        match(SwiftParser::T__4);
        setState(32);
        additionExp();
        setState(33);
        match(SwiftParser::T__5);
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

// Static vars and initialization.
std::vector<dfa::DFA> SwiftParser::_decisionToDFA;
atn::PredictionContextCache SwiftParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SwiftParser::_atn;
std::vector<uint16_t> SwiftParser::_serializedATN;

std::vector<std::string> SwiftParser::_ruleNames = {
  "eval", "additionExp", "multiplyExp", "atomExp"
};

std::vector<std::string> SwiftParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'", "'('", "')'"
};

std::vector<std::string> SwiftParser::_symbolicNames = {
  "", "", "", "", "", "", "", "Number", "WS"
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
    0x3, 0xa, 0x28, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x12, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x15, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x1c, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x1f, 0xb, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x26, 0xa, 0x5, 0x3, 0x5, 
    0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x2, 0x28, 0x2, 0xa, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0xc, 0x3, 0x2, 0x2, 0x2, 0x6, 0x16, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x5, 0x4, 0x3, 0x2, 0xb, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x13, 0x5, 0x6, 0x4, 0x2, 0xd, 0xe, 0x7, 0x3, 
    0x2, 0x2, 0xe, 0x12, 0x5, 0x6, 0x4, 0x2, 0xf, 0x10, 0x7, 0x4, 0x2, 0x2, 
    0x10, 0x12, 0x5, 0x6, 0x4, 0x2, 0x11, 0xd, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x12, 0x15, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1d, 0x5, 0x8, 
    0x5, 0x2, 0x17, 0x18, 0x7, 0x5, 0x2, 0x2, 0x18, 0x1c, 0x5, 0x8, 0x5, 
    0x2, 0x19, 0x1a, 0x7, 0x6, 0x2, 0x2, 0x1a, 0x1c, 0x5, 0x8, 0x5, 0x2, 
    0x1b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x1e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x20, 0x26, 0x7, 0x9, 0x2, 0x2, 0x21, 0x22, 0x7, 0x7, 
    0x2, 0x2, 0x22, 0x23, 0x5, 0x4, 0x3, 0x2, 0x23, 0x24, 0x7, 0x8, 0x2, 
    0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x25, 0x21, 0x3, 0x2, 0x2, 0x2, 0x26, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7, 
    0x11, 0x13, 0x1b, 0x1d, 0x25, 
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
