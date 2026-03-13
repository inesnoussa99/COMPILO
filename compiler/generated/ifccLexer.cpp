
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
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "RETURN", 
      "CONST", "VAR", "COMMENT", "DIRECTIVE", "WS", "LINE_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,39,222,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,
  	1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,
  	1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,33,4,33,169,8,33,11,33,12,33,170,1,34,
  	1,34,5,34,175,8,34,10,34,12,34,178,9,34,1,35,1,35,1,35,1,35,5,35,184,
  	8,35,10,35,12,35,187,9,35,1,35,1,35,1,35,1,35,1,35,1,36,1,36,5,36,196,
  	8,36,10,36,12,36,199,9,36,1,36,1,36,1,36,1,36,1,37,4,37,206,8,37,11,37,
  	12,37,207,1,37,1,37,1,38,1,38,1,38,1,38,5,38,216,8,38,10,38,12,38,219,
  	9,38,1,38,1,38,1,185,0,39,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,
  	43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,
  	33,67,34,69,35,71,36,73,37,75,38,77,39,1,0,6,1,0,48,57,3,0,65,90,95,95,
  	97,122,4,0,48,57,65,90,95,95,97,122,1,0,10,10,3,0,9,10,13,13,32,32,2,
  	0,10,10,13,13,227,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,
  	1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,
  	0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,
  	0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,
  	1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,
  	0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,
  	0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,
  	1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,1,79,1,0,0,0,3,83,1,0,0,0,5,88,1,0,
  	0,0,7,90,1,0,0,0,9,92,1,0,0,0,11,94,1,0,0,0,13,96,1,0,0,0,15,98,1,0,0,
  	0,17,100,1,0,0,0,19,102,1,0,0,0,21,104,1,0,0,0,23,107,1,0,0,0,25,112,
  	1,0,0,0,27,114,1,0,0,0,29,116,1,0,0,0,31,118,1,0,0,0,33,120,1,0,0,0,35,
  	122,1,0,0,0,37,124,1,0,0,0,39,126,1,0,0,0,41,129,1,0,0,0,43,132,1,0,0,
  	0,45,134,1,0,0,0,47,136,1,0,0,0,49,139,1,0,0,0,51,142,1,0,0,0,53,145,
  	1,0,0,0,55,148,1,0,0,0,57,150,1,0,0,0,59,152,1,0,0,0,61,154,1,0,0,0,63,
  	157,1,0,0,0,65,160,1,0,0,0,67,168,1,0,0,0,69,172,1,0,0,0,71,179,1,0,0,
  	0,73,193,1,0,0,0,75,205,1,0,0,0,77,211,1,0,0,0,79,80,5,105,0,0,80,81,
  	5,110,0,0,81,82,5,116,0,0,82,2,1,0,0,0,83,84,5,109,0,0,84,85,5,97,0,0,
  	85,86,5,105,0,0,86,87,5,110,0,0,87,4,1,0,0,0,88,89,5,40,0,0,89,6,1,0,
  	0,0,90,91,5,41,0,0,91,8,1,0,0,0,92,93,5,123,0,0,93,10,1,0,0,0,94,95,5,
  	125,0,0,95,12,1,0,0,0,96,97,5,59,0,0,97,14,1,0,0,0,98,99,5,91,0,0,99,
  	16,1,0,0,0,100,101,5,93,0,0,101,18,1,0,0,0,102,103,5,61,0,0,103,20,1,
  	0,0,0,104,105,5,105,0,0,105,106,5,102,0,0,106,22,1,0,0,0,107,108,5,101,
  	0,0,108,109,5,108,0,0,109,110,5,115,0,0,110,111,5,101,0,0,111,24,1,0,
  	0,0,112,113,5,33,0,0,113,26,1,0,0,0,114,115,5,126,0,0,115,28,1,0,0,0,
  	116,117,5,45,0,0,117,30,1,0,0,0,118,119,5,42,0,0,119,32,1,0,0,0,120,121,
  	5,47,0,0,121,34,1,0,0,0,122,123,5,37,0,0,123,36,1,0,0,0,124,125,5,43,
  	0,0,125,38,1,0,0,0,126,127,5,60,0,0,127,128,5,60,0,0,128,40,1,0,0,0,129,
  	130,5,62,0,0,130,131,5,62,0,0,131,42,1,0,0,0,132,133,5,60,0,0,133,44,
  	1,0,0,0,134,135,5,62,0,0,135,46,1,0,0,0,136,137,5,60,0,0,137,138,5,61,
  	0,0,138,48,1,0,0,0,139,140,5,62,0,0,140,141,5,61,0,0,141,50,1,0,0,0,142,
  	143,5,61,0,0,143,144,5,61,0,0,144,52,1,0,0,0,145,146,5,33,0,0,146,147,
  	5,61,0,0,147,54,1,0,0,0,148,149,5,38,0,0,149,56,1,0,0,0,150,151,5,94,
  	0,0,151,58,1,0,0,0,152,153,5,124,0,0,153,60,1,0,0,0,154,155,5,38,0,0,
  	155,156,5,38,0,0,156,62,1,0,0,0,157,158,5,124,0,0,158,159,5,124,0,0,159,
  	64,1,0,0,0,160,161,5,114,0,0,161,162,5,101,0,0,162,163,5,116,0,0,163,
  	164,5,117,0,0,164,165,5,114,0,0,165,166,5,110,0,0,166,66,1,0,0,0,167,
  	169,7,0,0,0,168,167,1,0,0,0,169,170,1,0,0,0,170,168,1,0,0,0,170,171,1,
  	0,0,0,171,68,1,0,0,0,172,176,7,1,0,0,173,175,7,2,0,0,174,173,1,0,0,0,
  	175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,70,1,0,0,0,178,176,
  	1,0,0,0,179,180,5,47,0,0,180,181,5,42,0,0,181,185,1,0,0,0,182,184,9,0,
  	0,0,183,182,1,0,0,0,184,187,1,0,0,0,185,186,1,0,0,0,185,183,1,0,0,0,186,
  	188,1,0,0,0,187,185,1,0,0,0,188,189,5,42,0,0,189,190,5,47,0,0,190,191,
  	1,0,0,0,191,192,6,35,0,0,192,72,1,0,0,0,193,197,5,35,0,0,194,196,8,3,
  	0,0,195,194,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,
  	200,1,0,0,0,199,197,1,0,0,0,200,201,5,10,0,0,201,202,1,0,0,0,202,203,
  	6,36,0,0,203,74,1,0,0,0,204,206,7,4,0,0,205,204,1,0,0,0,206,207,1,0,0,
  	0,207,205,1,0,0,0,207,208,1,0,0,0,208,209,1,0,0,0,209,210,6,37,1,0,210,
  	76,1,0,0,0,211,212,5,47,0,0,212,213,5,47,0,0,213,217,1,0,0,0,214,216,
  	8,5,0,0,215,214,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,
  	0,218,220,1,0,0,0,219,217,1,0,0,0,220,221,6,38,0,0,221,78,1,0,0,0,7,0,
  	170,176,185,197,207,217,2,6,0,0,0,1,0
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
