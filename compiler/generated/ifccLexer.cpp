
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
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "T__32", 
      "RETURN", "CONST", "VAR", "COMMENT", "DIRECTIVE", "WS", "LINE_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,40,227,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,1,1,1,1,
  	1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,
  	9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,
  	1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,
  	1,20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,
  	1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,
  	1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,34,4,34,174,
  	8,34,11,34,12,34,175,1,35,1,35,5,35,180,8,35,10,35,12,35,183,9,35,1,36,
  	1,36,1,36,1,36,5,36,189,8,36,10,36,12,36,192,9,36,1,36,1,36,1,36,1,36,
  	1,36,1,37,1,37,5,37,201,8,37,10,37,12,37,204,9,37,1,37,1,37,1,37,1,37,
  	1,38,4,38,211,8,38,11,38,12,38,212,1,38,1,38,1,39,1,39,1,39,1,39,5,39,
  	221,8,39,10,39,12,39,224,9,39,1,39,1,39,1,190,0,40,1,1,3,2,5,3,7,4,9,
  	5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,
  	35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,
  	29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,
  	1,0,6,1,0,48,57,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,
  	0,10,10,3,0,9,10,13,13,32,32,2,0,10,10,13,13,232,0,1,1,0,0,0,0,3,1,0,
  	0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,
  	1,0,0,0,1,81,1,0,0,0,3,85,1,0,0,0,5,87,1,0,0,0,7,89,1,0,0,0,9,91,1,0,
  	0,0,11,93,1,0,0,0,13,95,1,0,0,0,15,97,1,0,0,0,17,99,1,0,0,0,19,102,1,
  	0,0,0,21,107,1,0,0,0,23,113,1,0,0,0,25,115,1,0,0,0,27,117,1,0,0,0,29,
  	119,1,0,0,0,31,121,1,0,0,0,33,123,1,0,0,0,35,125,1,0,0,0,37,127,1,0,0,
  	0,39,129,1,0,0,0,41,131,1,0,0,0,43,134,1,0,0,0,45,137,1,0,0,0,47,139,
  	1,0,0,0,49,141,1,0,0,0,51,144,1,0,0,0,53,147,1,0,0,0,55,150,1,0,0,0,57,
  	153,1,0,0,0,59,155,1,0,0,0,61,157,1,0,0,0,63,159,1,0,0,0,65,162,1,0,0,
  	0,67,165,1,0,0,0,69,173,1,0,0,0,71,177,1,0,0,0,73,184,1,0,0,0,75,198,
  	1,0,0,0,77,210,1,0,0,0,79,216,1,0,0,0,81,82,5,105,0,0,82,83,5,110,0,0,
  	83,84,5,116,0,0,84,2,1,0,0,0,85,86,5,40,0,0,86,4,1,0,0,0,87,88,5,44,0,
  	0,88,6,1,0,0,0,89,90,5,41,0,0,90,8,1,0,0,0,91,92,5,59,0,0,92,10,1,0,0,
  	0,93,94,5,91,0,0,94,12,1,0,0,0,95,96,5,93,0,0,96,14,1,0,0,0,97,98,5,61,
  	0,0,98,16,1,0,0,0,99,100,5,105,0,0,100,101,5,102,0,0,101,18,1,0,0,0,102,
  	103,5,101,0,0,103,104,5,108,0,0,104,105,5,115,0,0,105,106,5,101,0,0,106,
  	20,1,0,0,0,107,108,5,119,0,0,108,109,5,104,0,0,109,110,5,105,0,0,110,
  	111,5,108,0,0,111,112,5,101,0,0,112,22,1,0,0,0,113,114,5,123,0,0,114,
  	24,1,0,0,0,115,116,5,125,0,0,116,26,1,0,0,0,117,118,5,33,0,0,118,28,1,
  	0,0,0,119,120,5,126,0,0,120,30,1,0,0,0,121,122,5,45,0,0,122,32,1,0,0,
  	0,123,124,5,42,0,0,124,34,1,0,0,0,125,126,5,47,0,0,126,36,1,0,0,0,127,
  	128,5,37,0,0,128,38,1,0,0,0,129,130,5,43,0,0,130,40,1,0,0,0,131,132,5,
  	60,0,0,132,133,5,60,0,0,133,42,1,0,0,0,134,135,5,62,0,0,135,136,5,62,
  	0,0,136,44,1,0,0,0,137,138,5,60,0,0,138,46,1,0,0,0,139,140,5,62,0,0,140,
  	48,1,0,0,0,141,142,5,60,0,0,142,143,5,61,0,0,143,50,1,0,0,0,144,145,5,
  	62,0,0,145,146,5,61,0,0,146,52,1,0,0,0,147,148,5,61,0,0,148,149,5,61,
  	0,0,149,54,1,0,0,0,150,151,5,33,0,0,151,152,5,61,0,0,152,56,1,0,0,0,153,
  	154,5,38,0,0,154,58,1,0,0,0,155,156,5,94,0,0,156,60,1,0,0,0,157,158,5,
  	124,0,0,158,62,1,0,0,0,159,160,5,38,0,0,160,161,5,38,0,0,161,64,1,0,0,
  	0,162,163,5,124,0,0,163,164,5,124,0,0,164,66,1,0,0,0,165,166,5,114,0,
  	0,166,167,5,101,0,0,167,168,5,116,0,0,168,169,5,117,0,0,169,170,5,114,
  	0,0,170,171,5,110,0,0,171,68,1,0,0,0,172,174,7,0,0,0,173,172,1,0,0,0,
  	174,175,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,70,1,0,0,0,177,181,
  	7,1,0,0,178,180,7,2,0,0,179,178,1,0,0,0,180,183,1,0,0,0,181,179,1,0,0,
  	0,181,182,1,0,0,0,182,72,1,0,0,0,183,181,1,0,0,0,184,185,5,47,0,0,185,
  	186,5,42,0,0,186,190,1,0,0,0,187,189,9,0,0,0,188,187,1,0,0,0,189,192,
  	1,0,0,0,190,191,1,0,0,0,190,188,1,0,0,0,191,193,1,0,0,0,192,190,1,0,0,
  	0,193,194,5,42,0,0,194,195,5,47,0,0,195,196,1,0,0,0,196,197,6,36,0,0,
  	197,74,1,0,0,0,198,202,5,35,0,0,199,201,8,3,0,0,200,199,1,0,0,0,201,204,
  	1,0,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,205,1,0,0,0,204,202,1,0,0,
  	0,205,206,5,10,0,0,206,207,1,0,0,0,207,208,6,37,0,0,208,76,1,0,0,0,209,
  	211,7,4,0,0,210,209,1,0,0,0,211,212,1,0,0,0,212,210,1,0,0,0,212,213,1,
  	0,0,0,213,214,1,0,0,0,214,215,6,38,1,0,215,78,1,0,0,0,216,217,5,47,0,
  	0,217,218,5,47,0,0,218,222,1,0,0,0,219,221,8,5,0,0,220,219,1,0,0,0,221,
  	224,1,0,0,0,222,220,1,0,0,0,222,223,1,0,0,0,223,225,1,0,0,0,224,222,1,
  	0,0,0,225,226,6,39,0,0,226,80,1,0,0,0,7,0,175,181,190,202,212,222,2,6,
  	0,0,0,1,0
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
