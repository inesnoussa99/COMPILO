
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
      "axiom", "prog", "functionDef", "statement", "expr"
    },
    std::vector<std::string>{
      "", "'int'", "'('", "','", "')'", "';'", "'['", "']'", "'='", "'if'", 
      "'else'", "'while'", "'{'", "'}'", "'!'", "'~'", "'-'", "'*'", "'/'", 
      "'%'", "'+'", "'<<'", "'>>'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "RETURN", "CONST", "VAR", "COMMENT", "DIRECTIVE", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,153,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,0,1,1,4,
  	1,15,8,1,11,1,12,1,16,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,27,8,2,10,2,
  	12,2,30,9,2,3,2,32,8,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,71,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,5,3,81,8,3,10,3,12,3,84,9,3,1,3,3,3,87,8,3,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,101,8,4,10,4,12,4,104,9,4,3,4,106,8,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,116,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,5,4,148,8,4,10,4,12,4,151,9,4,1,4,0,1,8,5,0,2,
  	4,6,8,0,6,1,0,14,16,1,0,17,19,2,0,16,16,20,20,1,0,21,22,1,0,23,26,1,0,
  	27,28,176,0,10,1,0,0,0,2,14,1,0,0,0,4,18,1,0,0,0,6,86,1,0,0,0,8,115,1,
  	0,0,0,10,11,3,2,1,0,11,12,5,0,0,1,12,1,1,0,0,0,13,15,3,4,2,0,14,13,1,
  	0,0,0,15,16,1,0,0,0,16,14,1,0,0,0,16,17,1,0,0,0,17,3,1,0,0,0,18,19,5,
  	1,0,0,19,20,5,36,0,0,20,31,5,2,0,0,21,22,5,1,0,0,22,28,5,36,0,0,23,24,
  	5,3,0,0,24,25,5,1,0,0,25,27,5,36,0,0,26,23,1,0,0,0,27,30,1,0,0,0,28,26,
  	1,0,0,0,28,29,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,31,21,1,0,0,0,31,32,
  	1,0,0,0,32,33,1,0,0,0,33,34,5,4,0,0,34,35,3,6,3,0,35,5,1,0,0,0,36,37,
  	5,34,0,0,37,38,3,8,4,0,38,39,5,5,0,0,39,87,1,0,0,0,40,41,5,1,0,0,41,42,
  	5,36,0,0,42,87,5,5,0,0,43,44,5,1,0,0,44,45,5,36,0,0,45,46,5,6,0,0,46,
  	47,3,8,4,0,47,48,5,7,0,0,48,49,5,5,0,0,49,87,1,0,0,0,50,51,5,36,0,0,51,
  	52,5,8,0,0,52,53,3,8,4,0,53,54,5,5,0,0,54,87,1,0,0,0,55,56,5,36,0,0,56,
  	57,5,6,0,0,57,58,3,8,4,0,58,59,5,7,0,0,59,60,5,8,0,0,60,61,3,8,4,0,61,
  	62,5,5,0,0,62,87,1,0,0,0,63,64,5,9,0,0,64,65,5,2,0,0,65,66,3,8,4,0,66,
  	67,5,4,0,0,67,70,3,6,3,0,68,69,5,10,0,0,69,71,3,6,3,0,70,68,1,0,0,0,70,
  	71,1,0,0,0,71,87,1,0,0,0,72,73,5,11,0,0,73,74,5,2,0,0,74,75,3,8,4,0,75,
  	76,5,4,0,0,76,77,3,6,3,0,77,87,1,0,0,0,78,82,5,12,0,0,79,81,3,6,3,0,80,
  	79,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,82,83,1,0,0,0,83,85,1,0,0,0,84,
  	82,1,0,0,0,85,87,5,13,0,0,86,36,1,0,0,0,86,40,1,0,0,0,86,43,1,0,0,0,86,
  	50,1,0,0,0,86,55,1,0,0,0,86,63,1,0,0,0,86,72,1,0,0,0,86,78,1,0,0,0,87,
  	7,1,0,0,0,88,89,6,4,-1,0,89,90,5,2,0,0,90,91,3,8,4,0,91,92,5,4,0,0,92,
  	116,1,0,0,0,93,94,7,0,0,0,94,116,3,8,4,15,95,96,5,36,0,0,96,105,5,2,0,
  	0,97,102,3,8,4,0,98,99,5,3,0,0,99,101,3,8,4,0,100,98,1,0,0,0,101,104,
  	1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,
  	0,105,97,1,0,0,0,105,106,1,0,0,0,106,107,1,0,0,0,107,116,5,4,0,0,108,
  	116,5,36,0,0,109,116,5,35,0,0,110,111,5,36,0,0,111,112,5,6,0,0,112,113,
  	3,8,4,0,113,114,5,7,0,0,114,116,1,0,0,0,115,88,1,0,0,0,115,93,1,0,0,0,
  	115,95,1,0,0,0,115,108,1,0,0,0,115,109,1,0,0,0,115,110,1,0,0,0,116,149,
  	1,0,0,0,117,118,10,14,0,0,118,119,7,1,0,0,119,148,3,8,4,15,120,121,10,
  	13,0,0,121,122,7,2,0,0,122,148,3,8,4,14,123,124,10,12,0,0,124,125,7,3,
  	0,0,125,148,3,8,4,13,126,127,10,11,0,0,127,128,7,4,0,0,128,148,3,8,4,
  	12,129,130,10,10,0,0,130,131,7,5,0,0,131,148,3,8,4,11,132,133,10,9,0,
  	0,133,134,5,29,0,0,134,148,3,8,4,10,135,136,10,8,0,0,136,137,5,30,0,0,
  	137,148,3,8,4,9,138,139,10,7,0,0,139,140,5,31,0,0,140,148,3,8,4,8,141,
  	142,10,6,0,0,142,143,5,32,0,0,143,148,3,8,4,7,144,145,10,5,0,0,145,146,
  	5,33,0,0,146,148,3,8,4,6,147,117,1,0,0,0,147,120,1,0,0,0,147,123,1,0,
  	0,0,147,126,1,0,0,0,147,129,1,0,0,0,147,132,1,0,0,0,147,135,1,0,0,0,147,
  	138,1,0,0,0,147,141,1,0,0,0,147,144,1,0,0,0,148,151,1,0,0,0,149,147,1,
  	0,0,0,149,150,1,0,0,0,150,9,1,0,0,0,151,149,1,0,0,0,11,16,28,31,70,82,
  	86,102,105,115,147,149
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
    setState(10);
    prog();
    setState(11);
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

std::vector<ifccParser::FunctionDefContext *> ifccParser::ProgContext::functionDef() {
  return getRuleContexts<ifccParser::FunctionDefContext>();
}

ifccParser::FunctionDefContext* ifccParser::ProgContext::functionDef(size_t i) {
  return getRuleContext<ifccParser::FunctionDefContext>(i);
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
    setState(14); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(13);
      functionDef();
      setState(16); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ifccParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefContext ------------------------------------------------------------------

ifccParser::FunctionDefContext::FunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ifccParser::FunctionDefContext::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::FunctionDefContext::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::StatementContext* ifccParser::FunctionDefContext::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}


size_t ifccParser::FunctionDefContext::getRuleIndex() const {
  return ifccParser::RuleFunctionDef;
}


std::any ifccParser::FunctionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitFunctionDef(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::FunctionDefContext* ifccParser::functionDef() {
  FunctionDefContext *_localctx = _tracker.createInstance<FunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleFunctionDef);
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
    setState(18);
    match(ifccParser::T__0);
    setState(19);
    match(ifccParser::VAR);
    setState(20);
    match(ifccParser::T__1);
    setState(31);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__0) {
      setState(21);
      match(ifccParser::T__0);
      setState(22);
      match(ifccParser::VAR);
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ifccParser::T__2) {
        setState(23);
        match(ifccParser::T__2);
        setState(24);
        match(ifccParser::T__0);
        setState(25);
        match(ifccParser::VAR);
        setState(30);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(33);
    match(ifccParser::T__3);
    setState(34);
    antlrcpp::downCast<FunctionDefContext *>(_localctx)->blocStmt = statement();
   
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
//----------------- WhileStmtContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::WhileStmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::StatementContext* ifccParser::WhileStmtContext::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}

ifccParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ifccParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
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
  enterRule(_localctx, 6, ifccParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ifccParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(36);
      match(ifccParser::RETURN);
      setState(37);
      expr(0);
      setState(38);
      match(ifccParser::T__4);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ifccParser::DeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(40);
      match(ifccParser::T__0);
      setState(41);
      match(ifccParser::VAR);
      setState(42);
      match(ifccParser::T__4);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ifccParser::ArrayDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(43);
      match(ifccParser::T__0);
      setState(44);
      match(ifccParser::VAR);
      setState(45);
      match(ifccParser::T__5);
      setState(46);
      expr(0);
      setState(47);
      match(ifccParser::T__6);
      setState(48);
      match(ifccParser::T__4);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ifccParser::VarAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(50);
      match(ifccParser::VAR);
      setState(51);
      match(ifccParser::T__7);
      setState(52);
      expr(0);
      setState(53);
      match(ifccParser::T__4);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ifccParser::ArrayAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(55);
      match(ifccParser::VAR);
      setState(56);
      match(ifccParser::T__5);
      setState(57);
      antlrcpp::downCast<ArrayAssignmentContext *>(_localctx)->index = expr(0);
      setState(58);
      match(ifccParser::T__6);
      setState(59);
      match(ifccParser::T__7);
      setState(60);
      antlrcpp::downCast<ArrayAssignmentContext *>(_localctx)->val = expr(0);
      setState(61);
      match(ifccParser::T__4);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ifccParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(63);
      match(ifccParser::T__8);
      setState(64);
      match(ifccParser::T__1);
      setState(65);
      expr(0);
      setState(66);
      match(ifccParser::T__3);
      setState(67);
      antlrcpp::downCast<IfStmtContext *>(_localctx)->thenStmt = statement();
      setState(70);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(68);
        match(ifccParser::T__9);
        setState(69);
        antlrcpp::downCast<IfStmtContext *>(_localctx)->elseStmt = statement();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ifccParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(72);
      match(ifccParser::T__10);
      setState(73);
      match(ifccParser::T__1);
      setState(74);
      expr(0);
      setState(75);
      match(ifccParser::T__3);
      setState(76);
      antlrcpp::downCast<WhileStmtContext *>(_localctx)->bodyStmt = statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ifccParser::BlocStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(78);
      match(ifccParser::T__11);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 85899352578) != 0)) {
        setState(79);
        antlrcpp::downCast<BlocStmtContext *>(_localctx)->statements = statement();
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(85);
      match(ifccParser::T__12);
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
//----------------- CallExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::CallExprContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

std::vector<ifccParser::ExprContext *> ifccParser::CallExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::CallExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, ifccParser::RuleExpr, precedence);

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
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(89);
      match(ifccParser::T__1);
      setState(90);
      expr(0);
      setState(91);
      match(ifccParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(93);
      antlrcpp::downCast<UnaryExprContext *>(_localctx)->OU = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 114688) != 0))) {
        antlrcpp::downCast<UnaryExprContext *>(_localctx)->OU = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(94);
      expr(15);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(95);
      match(ifccParser::VAR);
      setState(96);
      match(ifccParser::T__1);
      setState(105);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 103079329796) != 0)) {
        setState(97);
        expr(0);
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ifccParser::T__2) {
          setState(98);
          match(ifccParser::T__2);
          setState(99);
          expr(0);
          setState(104);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(107);
      match(ifccParser::T__3);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VarExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(108);
      match(ifccParser::VAR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(109);
      match(ifccParser::CONST);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(110);
      match(ifccParser::VAR);
      setState(111);
      match(ifccParser::T__5);
      setState(112);
      expr(0);
      setState(113);
      match(ifccParser::T__6);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(117);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(118);
          antlrcpp::downCast<MultExprContext *>(_localctx)->OM = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 917504) != 0))) {
            antlrcpp::downCast<MultExprContext *>(_localctx)->OM = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(119);
          expr(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(120);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(121);
          antlrcpp::downCast<AddExprContext *>(_localctx)->OA = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__15

          || _la == ifccParser::T__19)) {
            antlrcpp::downCast<AddExprContext *>(_localctx)->OA = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(122);
          expr(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(123);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(124);
          antlrcpp::downCast<ShiftExprContext *>(_localctx)->OS = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__20

          || _la == ifccParser::T__21)) {
            antlrcpp::downCast<ShiftExprContext *>(_localctx)->OS = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(125);
          expr(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(126);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(127);
          antlrcpp::downCast<RelationalExprContext *>(_localctx)->OR = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 125829120) != 0))) {
            antlrcpp::downCast<RelationalExprContext *>(_localctx)->OR = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(128);
          expr(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualityExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(129);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(130);
          antlrcpp::downCast<EqualityExprContext *>(_localctx)->OE = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__26

          || _la == ifccParser::T__27)) {
            antlrcpp::downCast<EqualityExprContext *>(_localctx)->OE = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(131);
          expr(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwiseAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(132);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(133);
          match(ifccParser::T__28);
          setState(134);
          expr(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseXorExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(135);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(136);
          match(ifccParser::T__29);
          setState(137);
          expr(9);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(138);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(139);
          match(ifccParser::T__30);
          setState(140);
          expr(8);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicalAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(141);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(142);
          match(ifccParser::T__31);
          setState(143);
          expr(7);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(144);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(145);
          match(ifccParser::T__32);
          setState(146);
          expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(151);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 5);

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
