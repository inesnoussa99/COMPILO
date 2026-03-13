
// Generated from ifcc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual std::any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(ifccParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDeclaration(ifccParser::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarAssignment(ifccParser::VarAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(ifccParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlocStmt(ifccParser::BlocStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(ifccParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultExpr(ifccParser::MultExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(ifccParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpr(ifccParser::RelationalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(ifccParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpr(ifccParser::LogicalAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOrExpr(ifccParser::LogicalOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr(ifccParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(ifccParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParExpr(ifccParser::ParExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarExpr(ifccParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftExpr(ifccParser::ShiftExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

