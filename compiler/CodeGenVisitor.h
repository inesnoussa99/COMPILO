#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

class CodeGenVisitor : public ifccBaseVisitor {
public:
    CodeGenVisitor(std::map<antlr4::ParserRuleContext*, int> addressTable, int totalOffset) 
        : addressTable(addressTable), totalOffset(totalOffset) {}
    
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
protected:
    std::map<antlr4::ParserRuleContext*, int> addressTable;
    int totalOffset;
    int labelCounter = 0;

    int tempOffset = 0; 
    
    // 替代 pushq %rax
    void storeTempReg() {
        tempOffset += 8;
        std::cout << "    movq %rax, -" << tempOffset << "(%rbp)\n";
    }

    // 替代 popq，需传入目标寄存器名称（如 "rdx", "rax"）
    void loadTempReg(const std::string& reg) {
        std::cout << "    movq -" << tempOffset << "(%rbp), %" << reg << "\n";
        tempOffset -= 8;
    }
};