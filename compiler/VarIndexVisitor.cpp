#include "VarIndexVisitor.h"

#include <iostream>
#include <stdexcept>

using std::string;

void VarIndexVisitor::error(antlr4::ParserRuleContext* ctx, const string& msg) const {
  auto* t = ctx->getStart();
  int line = t ? t->getLine() : -1;
  int col  = t ? t->getCharPositionInLine() : -1;
  throw std::runtime_error("error:" + std::to_string(line) + ":" + std::to_string(col) + ": " + msg);
}

void VarIndexVisitor::declareVar(antlr4::ParserRuleContext* ctx, const string& name) {
  if (vars.count(name)) error(ctx, "variable declaree plusieurs fois: '" + name + "'");
  vars[name] = Info{ nextOffset, false };
  nextOffset += 4; // int32 => 4 octets
}

VarIndexVisitor::Info& VarIndexVisitor::requireVar(antlr4::ParserRuleContext* ctx, const string& name) {
  std::unordered_map<string, Info>::iterator it = vars.find(name);
  if (it == vars.end()) error(ctx, "variable non declaree: '" + name + "'");
  return it->second;
}

antlrcpp::Any VarIndexVisitor::visitProg(ifccParser::ProgContext *ctx) {
  for (auto* s : ctx->stmt()) visit(s);
  visit(ctx->return_stmt());

  std::cerr << "[VarIndexVisitor] Variables (name -> offset)\n";
  for (auto& kv : vars) {
    std::cerr << "  " << kv.first << " -> " << kv.second.offset << "\n";
  }

  for (auto& kv : vars) {
    if (!kv.second.used) {
      throw std::runtime_error("error: variable declaree mais jamais utilisee: '" + kv.first + "'");
    }
  }

  return 0;
}

antlrcpp::Any VarIndexVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
  const string name = ctx->ID()->getText();
  declareVar(ctx, name);
  if (ctx->expr()) visit(ctx->expr()); // init => lecture(s) éventuelle(s)
  return 0;
}

antlrcpp::Any VarIndexVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
  const string lhs = ctx->ID()->getText();
  requireVar(ctx, lhs); // doit exister (écriture, pas "used")
  visit(ctx->expr());   // RHS => lectures
  return 0;
}

antlrcpp::Any VarIndexVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
  visit(ctx->expr());
  return 0;
}

antlrcpp::Any VarIndexVisitor::visitExpr(ifccParser::ExprContext *ctx) {
  if (ctx->ID()) {
    const string name = ctx->ID()->getText();
    requireVar(ctx, name).used = true; // lecture
  }
  return 0;
}