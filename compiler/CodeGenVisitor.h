#pragma once
#include "generated/ifccBaseVisitor.h"
#include <map>
#include <string>

class CodeGenVisitor : public ifccBaseVisitor {
public:
    explicit CodeGenVisitor(const std::map<std::string,int>& offsets);

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

    // expression codegen (new grammar)
    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    antlrcpp::Any visitTerm(ifccParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(ifccParser::FactorContext *ctx) override;

private:
    const std::map<std::string,int>& offsets;
    int stackSize = 0;

    static int align16(int n);
};