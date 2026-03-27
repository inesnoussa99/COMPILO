#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "IR.h"

class CodeGenVisitor : public ifccBaseVisitor {
public:
    CodeGenVisitor(std::map<antlr4::ParserRuleContext*, int> addressTable, int totalOffset);
    ~CodeGenVisitor();
    
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override;
    virtual antlrcpp::Any visitReturnStmt(ifccParser::ReturnStmtContext *ctx) override;
    virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override;
    virtual antlrcpp::Any visitAddExpr(ifccParser::AddExprContext *ctx) override;
    virtual antlrcpp::Any visitMultExpr(ifccParser::MultExprContext *ctx) override;
    virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *ctx) override;
    virtual antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *ctx) override;
    virtual antlrcpp::Any visitArrayExpr(ifccParser::ArrayExprContext *ctx) override;
    virtual antlrcpp::Any visitRelationalExpr(ifccParser::RelationalExprContext *ctx) override;
    virtual antlrcpp::Any visitEqualityExpr(ifccParser::EqualityExprContext *ctx) override;
    virtual antlrcpp::Any visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) override;
    virtual antlrcpp::Any visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) override;
    virtual antlrcpp::Any visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) override;
    virtual antlrcpp::Any visitShiftExpr(ifccParser::ShiftExprContext *ctx) override;
    virtual antlrcpp::Any visitIfStmt(ifccParser::IfStmtContext *ctx) override;
    virtual antlrcpp::Any visitBlocStmt(ifccParser::BlocStmtContext *ctx) override;
    virtual antlrcpp::Any visitUnaryExpr(ifccParser::UnaryExprContext *ctx) override;
    virtual antlrcpp::Any visitLogicalAndExpr(ifccParser::LogicalAndExprContext *ctx) override;
    virtual antlrcpp::Any visitLogicalOrExpr(ifccParser::LogicalOrExprContext *ctx) override;
    virtual antlrcpp::Any visitVarAssignment(ifccParser::VarAssignmentContext *ctx) override;
    virtual antlrcpp::Any visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) override;
    virtual antlrcpp::Any visitWhileStmt(ifccParser::WhileStmtContext *ctx) override;

    CFG* getCFG() { return cfg; }

protected:
    std::map<antlr4::ParserRuleContext*, int> addressTable;
    CFG* cfg;
};