
// Generated from ifcc.g4 by ANTLR 4.13.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct IfccParserStaticData final {
  IfccParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccParserStaticData(const IfccParserStaticData&) = delete;
  IfccParserStaticData(IfccParserStaticData&&) = delete;
  IfccParserStaticData& operator=(const IfccParserStaticData&) = delete;
  IfccParserStaticData& operator=(IfccParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ifccParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<IfccParserStaticData> ifccParserStaticData = nullptr;

void ifccParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ifccParserStaticData != nullptr) {
    return;
  }
#else
  assert(ifccParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<IfccParserStaticData>(
    std::vector<std::string>{
      "axiom", "prog", "statement", "expr"
    },
    std::vector<std::string>{
      "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", 
      "'='", "'if'", "'else'", "'!'", "'~'", "'-'", "'*'", "'/'", "'%'", 
      "'+'", "'<<'", "'>>'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", 
      "'&'", "'^'", "'|'", "'&&'", "'||'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", 
      "CONST", "VAR", "COMMENT", "DIRECTIVE", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,39,122,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,1,1,5,1,18,8,1,10,1,12,1,21,9,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,59,8,2,1,2,1,2,5,2,63,8,
  	2,10,2,12,2,66,9,2,1,2,3,2,69,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,3,3,85,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,5,3,117,8,3,10,3,12,3,120,9,3,1,3,0,1,6,4,0,2,4,6,0,6,1,0,
  	13,15,1,0,16,18,2,0,15,15,19,19,1,0,20,21,1,0,22,25,1,0,26,27,140,0,8,
  	1,0,0,0,2,11,1,0,0,0,4,68,1,0,0,0,6,84,1,0,0,0,8,9,3,2,1,0,9,10,5,0,0,
  	1,10,1,1,0,0,0,11,12,5,1,0,0,12,13,5,2,0,0,13,14,5,3,0,0,14,15,5,4,0,
  	0,15,19,5,5,0,0,16,18,3,4,2,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,
  	0,19,20,1,0,0,0,20,22,1,0,0,0,21,19,1,0,0,0,22,23,5,6,0,0,23,3,1,0,0,
  	0,24,25,5,33,0,0,25,26,3,6,3,0,26,27,5,7,0,0,27,69,1,0,0,0,28,29,5,1,
  	0,0,29,30,5,35,0,0,30,69,5,7,0,0,31,32,5,1,0,0,32,33,5,35,0,0,33,34,5,
  	8,0,0,34,35,3,6,3,0,35,36,5,9,0,0,36,37,5,7,0,0,37,69,1,0,0,0,38,39,5,
  	35,0,0,39,40,5,10,0,0,40,41,3,6,3,0,41,42,5,7,0,0,42,69,1,0,0,0,43,44,
  	5,35,0,0,44,45,5,8,0,0,45,46,3,6,3,0,46,47,5,9,0,0,47,48,5,10,0,0,48,
  	49,3,6,3,0,49,50,5,7,0,0,50,69,1,0,0,0,51,52,5,11,0,0,52,53,5,3,0,0,53,
  	54,3,6,3,0,54,55,5,4,0,0,55,58,3,4,2,0,56,57,5,12,0,0,57,59,3,4,2,0,58,
  	56,1,0,0,0,58,59,1,0,0,0,59,69,1,0,0,0,60,64,5,5,0,0,61,63,3,4,2,0,62,
  	61,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,0,65,67,1,0,0,0,66,
  	64,1,0,0,0,67,69,5,6,0,0,68,24,1,0,0,0,68,28,1,0,0,0,68,31,1,0,0,0,68,
  	38,1,0,0,0,68,43,1,0,0,0,68,51,1,0,0,0,68,60,1,0,0,0,69,5,1,0,0,0,70,
  	71,6,3,-1,0,71,72,5,3,0,0,72,73,3,6,3,0,73,74,5,4,0,0,74,85,1,0,0,0,75,
  	76,7,0,0,0,76,85,3,6,3,14,77,85,5,35,0,0,78,85,5,34,0,0,79,80,5,35,0,
  	0,80,81,5,8,0,0,81,82,3,6,3,0,82,83,5,9,0,0,83,85,1,0,0,0,84,70,1,0,0,
  	0,84,75,1,0,0,0,84,77,1,0,0,0,84,78,1,0,0,0,84,79,1,0,0,0,85,118,1,0,
  	0,0,86,87,10,13,0,0,87,88,7,1,0,0,88,117,3,6,3,14,89,90,10,12,0,0,90,
  	91,7,2,0,0,91,117,3,6,3,13,92,93,10,11,0,0,93,94,7,3,0,0,94,117,3,6,3,
  	12,95,96,10,10,0,0,96,97,7,4,0,0,97,117,3,6,3,11,98,99,10,9,0,0,99,100,
  	7,5,0,0,100,117,3,6,3,10,101,102,10,8,0,0,102,103,5,28,0,0,103,117,3,
  	6,3,9,104,105,10,7,0,0,105,106,5,29,0,0,106,117,3,6,3,8,107,108,10,6,
  	0,0,108,109,5,30,0,0,109,117,3,6,3,7,110,111,10,5,0,0,111,112,5,31,0,
  	0,112,117,3,6,3,6,113,114,10,4,0,0,114,115,5,32,0,0,115,117,3,6,3,5,116,
  	86,1,0,0,0,116,89,1,0,0,0,116,92,1,0,0,0,116,95,1,0,0,0,116,98,1,0,0,
  	0,116,101,1,0,0,0,116,104,1,0,0,0,116,107,1,0,0,0,116,110,1,0,0,0,116,
  	113,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,7,1,0,
  	0,0,120,118,1,0,0,0,7,19,58,64,68,84,116,118
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifccParserStaticData = std::move(staticData);
}

}

ifccParser::ifccParser(TokenStream *input) : ifccParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ifccParser::ifccParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ifccParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ifccParserStaticData->atn, ifccParserStaticData->decisionToDFA, ifccParserStaticData->sharedContextCache, options);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

const atn::ATN& ifccParser::getATN() const {
  return *ifccParserStaticData->atn;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return ifccParserStaticData->ruleNames;
}

const dfa::Vocabulary& ifccParser::getVocabulary() const {
  return ifccParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccParser::getSerializedATN() const {
  return ifccParserStaticData->serializedATN;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}


std::any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    prog();
    setState(9);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::StatementContext *> ifccParser::ProgContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::ProgContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}


std::any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    match(ifccParser::T__0);
    setState(12);
    match(ifccParser::T__1);
    setState(13);
    match(ifccParser::T__2);
    setState(14);
    match(ifccParser::T__3);
    setState(15);
    match(ifccParser::T__4);
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 42949675042) != 0)) {
      setState(16);
      statement();
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(22);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ifccParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::StatementContext::getRuleIndex() const {
  return ifccParser::RuleStatement;
}

void ifccParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ArrayDeclarationContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprContext* ifccParser::ArrayDeclarationContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ArrayDeclarationContext::ArrayDeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::IfStmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

std::vector<ifccParser::StatementContext *> ifccParser::IfStmtContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}

ifccParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlocStmtContext ------------------------------------------------------------------

std::vector<ifccParser::StatementContext *> ifccParser::BlocStmtContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::BlocStmtContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}

ifccParser::BlocStmtContext::BlocStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BlocStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBlocStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::DeclarationContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::DeclarationContext::DeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VarAssignmentContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprContext* ifccParser::VarAssignmentContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::VarAssignmentContext::VarAssignmentContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::VarAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVarAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ReturnStmtContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

ifccParser::ExprContext* ifccParser::ReturnStmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ArrayAssignmentContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

std::vector<ifccParser::ExprContext *> ifccParser::ArrayAssignmentContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::ArrayAssignmentContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::ArrayAssignmentContext::ArrayAssignmentContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ArrayAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitArrayAssignment(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StatementContext* ifccParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ifccParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(24);
      match(ifccParser::RETURN);
      setState(25);
      expr(0);
      setState(26);
      match(ifccParser::T__6);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ifccParser::DeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(28);
      match(ifccParser::T__0);
      setState(29);
      match(ifccParser::VAR);
      setState(30);
      match(ifccParser::T__6);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ifccParser::ArrayDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(31);
      match(ifccParser::T__0);
      setState(32);
      match(ifccParser::VAR);
      setState(33);
      match(ifccParser::T__7);
      setState(34);
      expr(0);
      setState(35);
      match(ifccParser::T__8);
      setState(36);
      match(ifccParser::T__6);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ifccParser::VarAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(38);
      match(ifccParser::VAR);
      setState(39);
      match(ifccParser::T__9);
      setState(40);
      expr(0);
      setState(41);
      match(ifccParser::T__6);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ifccParser::ArrayAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(43);
      match(ifccParser::VAR);
      setState(44);
      match(ifccParser::T__7);
      setState(45);
      antlrcpp::downCast<ArrayAssignmentContext *>(_localctx)->index = expr(0);
      setState(46);
      match(ifccParser::T__8);
      setState(47);
      match(ifccParser::T__9);
      setState(48);
      antlrcpp::downCast<ArrayAssignmentContext *>(_localctx)->val = expr(0);
      setState(49);
      match(ifccParser::T__6);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ifccParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(51);
      match(ifccParser::T__10);
      setState(52);
      match(ifccParser::T__2);
      setState(53);
      expr(0);
      setState(54);
      match(ifccParser::T__3);
      setState(55);
      antlrcpp::downCast<IfStmtContext *>(_localctx)->thenStmt = statement();
      setState(58);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(56);
        match(ifccParser::T__11);
        setState(57);
        antlrcpp::downCast<IfStmtContext *>(_localctx)->elseStmt = statement();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ifccParser::BlocStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(60);
      match(ifccParser::T__4);
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 42949675042) != 0)) {
        setState(61);
        antlrcpp::downCast<BlocStmtContext *>(_localctx)->statements = statement();
        setState(66);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(67);
      match(ifccParser::T__5);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ifccParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

void ifccParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseAndExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseAndExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseAndExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseAndExprContext::BitwiseAndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstExprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstExprContext::ConstExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseOrExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseOrExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseOrExprContext::BitwiseOrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MultExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MultExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::MultExprContext::MultExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::MultExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMultExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::AddExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::AddExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::AddExprContext::AddExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::RelationalExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::RelationalExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::RelationalExprContext::RelationalExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::UnaryExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::LogicalAndExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::LogicalAndExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::LogicalAndExprContext::LogicalAndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::LogicalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::LogicalOrExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::LogicalOrExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::LogicalOrExprContext::LogicalOrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::LogicalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ArrayExprContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprContext* ifccParser::ArrayExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ArrayExprContext::ArrayExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::EqualityExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::EqualityExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::EqualityExprContext::EqualityExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParExprContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::ParExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ParExprContext::ParExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ParExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VarExprContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::VarExprContext::VarExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::VarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseXorExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseXorExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseXorExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseXorExprContext::BitwiseXorExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseXorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseXorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShiftExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::ShiftExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::ShiftExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::ShiftExprContext::ShiftExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitShiftExpr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
   return expr(0);
}

ifccParser::ExprContext* ifccParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ifccParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, ifccParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(84);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(71);
      match(ifccParser::T__2);
      setState(72);
      expr(0);
      setState(73);
      match(ifccParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(75);
      antlrcpp::downCast<UnaryExprContext *>(_localctx)->OU = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 57344) != 0))) {
        antlrcpp::downCast<UnaryExprContext *>(_localctx)->OU = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(76);
      expr(14);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VarExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(77);
      match(ifccParser::VAR);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(78);
      match(ifccParser::CONST);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(79);
      match(ifccParser::VAR);
      setState(80);
      match(ifccParser::T__7);
      setState(81);
      expr(0);
      setState(82);
      match(ifccParser::T__8);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(118);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(116);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(86);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(87);
          antlrcpp::downCast<MultExprContext *>(_localctx)->OM = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 458752) != 0))) {
            antlrcpp::downCast<MultExprContext *>(_localctx)->OM = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(88);
          expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(89);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(90);
          antlrcpp::downCast<AddExprContext *>(_localctx)->OA = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__14

          || _la == ifccParser::T__18)) {
            antlrcpp::downCast<AddExprContext *>(_localctx)->OA = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(91);
          expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(92);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(93);
          antlrcpp::downCast<ShiftExprContext *>(_localctx)->OS = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__19

          || _la == ifccParser::T__20)) {
            antlrcpp::downCast<ShiftExprContext *>(_localctx)->OS = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(94);
          expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(95);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(96);
          antlrcpp::downCast<RelationalExprContext *>(_localctx)->OR = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 62914560) != 0))) {
            antlrcpp::downCast<RelationalExprContext *>(_localctx)->OR = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(97);
          expr(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualityExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(98);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(99);
          antlrcpp::downCast<EqualityExprContext *>(_localctx)->OE = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__25

          || _la == ifccParser::T__26)) {
            antlrcpp::downCast<EqualityExprContext *>(_localctx)->OE = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(100);
          expr(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwiseAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(101);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(102);
          match(ifccParser::T__27);
          setState(103);
          expr(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseXorExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(104);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(105);
          match(ifccParser::T__28);
          setState(106);
          expr(8);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(107);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(108);
          match(ifccParser::T__29);
          setState(109);
          expr(7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicalAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(110);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(111);
          match(ifccParser::T__30);
          setState(112);
          expr(6);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(113);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(114);
          match(ifccParser::T__31);
          setState(115);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(120);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void ifccParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ifccParserInitialize();
#else
  ::antlr4::internal::call_once(ifccParserOnceFlag, ifccParserInitialize);
#endif
}
