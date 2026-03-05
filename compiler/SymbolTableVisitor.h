#pragma once
#include "generated/ifccBaseVisitor.h"
#include <map>
#include <set>
#include <string>

class SymbolTableVisitor : public ifccBaseVisitor {
public:
    std::map<std::string,int> offsets;
    std::set<std::string> used;
    bool hasError = false;

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

    // visiter les expressions pour repérer les ID
    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    antlrcpp::Any visitTerm(ifccParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(ifccParser::FactorContext *ctx) override;
};