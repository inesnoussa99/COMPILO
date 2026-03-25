#pragma once
#include "generated/ifccBaseVisitor.h"
#include "IR.h"
#include <string>
#include <vector>

/**
 * CodeGenVisitor — construit le CFG (IR) à partir de l'AST ANTLR.
 *
 * Pipeline :
 *   AST  →  CodeGenVisitor  →  CFGs  →  gen_asm()  →  assembleur
 *
 * Convention :
 *   Chaque visit(expr/term/factor) retourne le NOM de la variable IR
 *   (temporaire ou variable utilisateur) qui contient le résultat.
 *   On utilise antlrcpp::Any pour transporter ce std::string.
 */
class CodeGenVisitor : public ifccBaseVisitor {
public:
    CodeGenVisitor() = default;

    void gen_asm(std::ostream& o);

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitFunc_def(ifccParser::Func_defContext *ctx) override;
    antlrcpp::Any visitBlock_stmt(ifccParser::Block_stmtContext *ctx) override;
    antlrcpp::Any visitIf_stmt(ifccParser::If_stmtContext *ctx) override;
    antlrcpp::Any visitWhile_stmt(ifccParser::While_stmtContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitExpr_stmt(ifccParser::Expr_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    antlrcpp::Any visitEq_expr(ifccParser::Eq_exprContext *ctx) override;
    antlrcpp::Any visitRel_expr(ifccParser::Rel_exprContext *ctx) override;
    antlrcpp::Any visitBitor_expr(ifccParser::Bitor_exprContext *ctx) override;
    antlrcpp::Any visitXor_expr(ifccParser::Xor_exprContext *ctx) override;
    antlrcpp::Any visitAnd_expr(ifccParser::And_exprContext *ctx) override;
    antlrcpp::Any visitAdd_expr(ifccParser::Add_exprContext *ctx) override;
    antlrcpp::Any visitTerm(ifccParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(ifccParser::FactorContext *ctx) override;

private:
    CFG* cfg_ = nullptr;
    std::vector<CFG*> cfgs_;

    // ── Résolution des noms avec shadowing ───────────────────────
    // nameScopes_[i] : nom logique → nom IR dans le scope i
    // Le nom IR = nom logique pour les déclarations non shadowées,
    // nom@N pour les déclarations qui shadowent une variable externe.
    std::vector<std::map<std::string, std::string>> nameScopes_;
    int shadowCounter_ = 0;

    void        enterBlockScope();
    void        exitBlockScope();
    std::string declareIRVar(const std::string& name);   // alloue + retourne nom IR
    std::string resolveVar(const std::string& name) const; // cherche de l'intérieur

    /// Évalue une expression et retourne le nom de la variable IR résultat
    std::string evalExpr(antlr4::tree::ParseTree* node);
};
