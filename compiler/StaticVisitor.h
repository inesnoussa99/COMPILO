#pragma once
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <map>
#include <string>
#include <vector>

class StaticVisitor : public ifccBaseVisitor {
public:
    StaticVisitor();
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override;
    virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *ctx) override;
    virtual antlrcpp::Any visitVarAssignment(ifccParser::VarAssignmentContext *ctx) override;
    virtual antlrcpp::Any visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) override;
    virtual antlrcpp::Any visitReturnStmt(ifccParser::ReturnStmtContext *ctx) override;
    virtual antlrcpp::Any visitIfStmt(ifccParser::IfStmtContext *ctx) override;
    virtual antlrcpp::Any visitBlocStmt(ifccParser::BlocStmtContext *ctx) override;
    virtual antlrcpp::Any visitArrayExpr(ifccParser::ArrayExprContext *ctx) override;
    virtual antlrcpp::Any visitArrayDeclaration(ifccParser::ArrayDeclarationContext *ctx) override;
    int getTotalOffset() { return -currentOffset; }
    std::map<antlr4::ParserRuleContext*, int> getAddressTable() { return addressTable; }

private:
    std::vector<std::map<std::string, int>> scopeStack;
    std::map<antlr4::ParserRuleContext*, int> addressTable;
    
    int currentOffset = 0;
    int findVariable(std::string name);
};