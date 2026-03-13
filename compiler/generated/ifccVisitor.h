
// Generated from ifcc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual std::any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual std::any visitProg(ifccParser::ProgContext *context) = 0;

    virtual std::any visitReturnStmt(ifccParser::ReturnStmtContext *context) = 0;

    virtual std::any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual std::any visitArrayDeclaration(ifccParser::ArrayDeclarationContext *context) = 0;

    virtual std::any visitVarAssignment(ifccParser::VarAssignmentContext *context) = 0;

    virtual std::any visitArrayAssignment(ifccParser::ArrayAssignmentContext *context) = 0;

    virtual std::any visitIfStmt(ifccParser::IfStmtContext *context) = 0;

    virtual std::any visitBlocStmt(ifccParser::BlocStmtContext *context) = 0;

    virtual std::any visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *context) = 0;

    virtual std::any visitConstExpr(ifccParser::ConstExprContext *context) = 0;

    virtual std::any visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *context) = 0;

    virtual std::any visitMultExpr(ifccParser::MultExprContext *context) = 0;

    virtual std::any visitAddExpr(ifccParser::AddExprContext *context) = 0;

    virtual std::any visitRelationalExpr(ifccParser::RelationalExprContext *context) = 0;

    virtual std::any visitUnaryExpr(ifccParser::UnaryExprContext *context) = 0;

    virtual std::any visitLogicalAndExpr(ifccParser::LogicalAndExprContext *context) = 0;

    virtual std::any visitLogicalOrExpr(ifccParser::LogicalOrExprContext *context) = 0;

    virtual std::any visitArrayExpr(ifccParser::ArrayExprContext *context) = 0;

    virtual std::any visitEqualityExpr(ifccParser::EqualityExprContext *context) = 0;

    virtual std::any visitParExpr(ifccParser::ParExprContext *context) = 0;

    virtual std::any visitVarExpr(ifccParser::VarExprContext *context) = 0;

    virtual std::any visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *context) = 0;

    virtual std::any visitShiftExpr(ifccParser::ShiftExprContext *context) = 0;


};

