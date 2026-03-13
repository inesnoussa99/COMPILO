#pragma once

#include <string>
#include <unordered_map>

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

class VarIndexVisitor : public ifccBaseVisitor {
public:
  struct Info {
    int offset;   // 0,4,8,...
    bool used;    // vrai si la variable est lue dans une expression
  };

  antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
  antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
  antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
  antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
  antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;

  const std::unordered_map<std::string, Info>& table() const { return vars; }

private:
  std::unordered_map<std::string, Info> vars;
  int nextOffset = 0; // +4 à chaque déclaration

  void error(antlr4::ParserRuleContext* ctx, const std::string& msg) const;
  void declareVar(antlr4::ParserRuleContext* ctx, const std::string& name);
  Info& requireVar(antlr4::ParserRuleContext* ctx, const std::string& name);
};