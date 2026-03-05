
// Generated from ifcc.g4 by ANTLR 4.13.2


#include "ifccLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct IfccLexerStaticData final {
  IfccLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccLexerStaticData(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData(IfccLexerStaticData&&) = delete;
  IfccLexerStaticData& operator=(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData& operator=(IfccLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ifcclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<IfccLexerStaticData> ifcclexerLexerStaticData = nullptr;

void ifcclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ifcclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ifcclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<IfccLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "RETURN", "INT", "MAIN", "CHAR", "CONST", "CHARCONST", "ID", "COMMENT", 
      "DIRECTIVE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'{'", "'}'", "';'", "'='", "'+'", "'-'", "'*'", 
      "'return'", "'int'", "'main'", "'char'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "RETURN", "INT", "MAIN", "CHAR", 
      "CONST", "CHARCONST", "ID", "COMMENT", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,123,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,
  	1,12,1,13,4,13,80,8,13,11,13,12,13,81,1,14,1,14,1,14,1,14,1,15,1,15,5,
  	15,90,8,15,10,15,12,15,93,9,15,1,16,1,16,1,16,1,16,5,16,99,8,16,10,16,
  	12,16,102,9,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,5,17,111,8,17,10,17,
  	12,17,114,9,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,2,100,112,0,19,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,
  	4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,126,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,41,1,0,0,0,5,43,1,0,0,0,7,45,1,0,0,0,
  	9,47,1,0,0,0,11,49,1,0,0,0,13,51,1,0,0,0,15,53,1,0,0,0,17,55,1,0,0,0,
  	19,57,1,0,0,0,21,64,1,0,0,0,23,68,1,0,0,0,25,73,1,0,0,0,27,79,1,0,0,0,
  	29,83,1,0,0,0,31,87,1,0,0,0,33,94,1,0,0,0,35,108,1,0,0,0,37,119,1,0,0,
  	0,39,40,5,40,0,0,40,2,1,0,0,0,41,42,5,41,0,0,42,4,1,0,0,0,43,44,5,123,
  	0,0,44,6,1,0,0,0,45,46,5,125,0,0,46,8,1,0,0,0,47,48,5,59,0,0,48,10,1,
  	0,0,0,49,50,5,61,0,0,50,12,1,0,0,0,51,52,5,43,0,0,52,14,1,0,0,0,53,54,
  	5,45,0,0,54,16,1,0,0,0,55,56,5,42,0,0,56,18,1,0,0,0,57,58,5,114,0,0,58,
  	59,5,101,0,0,59,60,5,116,0,0,60,61,5,117,0,0,61,62,5,114,0,0,62,63,5,
  	110,0,0,63,20,1,0,0,0,64,65,5,105,0,0,65,66,5,110,0,0,66,67,5,116,0,0,
  	67,22,1,0,0,0,68,69,5,109,0,0,69,70,5,97,0,0,70,71,5,105,0,0,71,72,5,
  	110,0,0,72,24,1,0,0,0,73,74,5,99,0,0,74,75,5,104,0,0,75,76,5,97,0,0,76,
  	77,5,114,0,0,77,26,1,0,0,0,78,80,7,0,0,0,79,78,1,0,0,0,80,81,1,0,0,0,
  	81,79,1,0,0,0,81,82,1,0,0,0,82,28,1,0,0,0,83,84,5,39,0,0,84,85,9,0,0,
  	0,85,86,5,39,0,0,86,30,1,0,0,0,87,91,7,1,0,0,88,90,7,2,0,0,89,88,1,0,
  	0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,32,1,0,0,0,93,91,1,0,
  	0,0,94,95,5,47,0,0,95,96,5,42,0,0,96,100,1,0,0,0,97,99,9,0,0,0,98,97,
  	1,0,0,0,99,102,1,0,0,0,100,101,1,0,0,0,100,98,1,0,0,0,101,103,1,0,0,0,
  	102,100,1,0,0,0,103,104,5,42,0,0,104,105,5,47,0,0,105,106,1,0,0,0,106,
  	107,6,16,0,0,107,34,1,0,0,0,108,112,5,35,0,0,109,111,9,0,0,0,110,109,
  	1,0,0,0,111,114,1,0,0,0,112,113,1,0,0,0,112,110,1,0,0,0,113,115,1,0,0,
  	0,114,112,1,0,0,0,115,116,5,10,0,0,116,117,1,0,0,0,117,118,6,17,0,0,118,
  	36,1,0,0,0,119,120,7,3,0,0,120,121,1,0,0,0,121,122,6,18,1,0,122,38,1,
  	0,0,0,5,0,81,91,100,112,2,6,0,0,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifcclexerLexerStaticData = std::move(staticData);
}

}

ifccLexer::ifccLexer(CharStream *input) : Lexer(input) {
  ifccLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ifcclexerLexerStaticData->atn, ifcclexerLexerStaticData->decisionToDFA, ifcclexerLexerStaticData->sharedContextCache);
}

ifccLexer::~ifccLexer() {
  delete _interpreter;
}

std::string ifccLexer::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccLexer::getRuleNames() const {
  return ifcclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ifccLexer::getChannelNames() const {
  return ifcclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ifccLexer::getModeNames() const {
  return ifcclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ifccLexer::getVocabulary() const {
  return ifcclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccLexer::getSerializedATN() const {
  return ifcclexerLexerStaticData->serializedATN;
}

const atn::ATN& ifccLexer::getATN() const {
  return *ifcclexerLexerStaticData->atn;
}




void ifccLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ifcclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ifcclexerLexerOnceFlag, ifcclexerLexerInitialize);
#endif
}
