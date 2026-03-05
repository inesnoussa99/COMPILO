#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

#include <unordered_map>
#include <string>
enum class VarType { INT32, CHAR8 };

struct VarInfo {
    VarType type;
    int offset;   // en bytes
};
class CodeGenVisitor : public ifccBaseVisitor {
public:
    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;

private:
    std::unordered_map<std::string, VarInfo> sym;
    int frameSize = 0;
};