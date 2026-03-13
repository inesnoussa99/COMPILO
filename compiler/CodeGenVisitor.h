#pragma once
#include "generated/ifccBaseVisitor.h"
#include "IR.h"
#include <string>

/**
 * CodeGenVisitor — construit le CFG (IR) à partir de l'AST ANTLR.
 *
 * Pipeline :
 *   AST  →  CodeGenVisitor  →  CFG  →  CFG::gen_asm()  →  assembleur x86
 *
 * Convention :
 *   Chaque visit(expr/term/factor) retourne le NOM de la variable IR
 *   (temporaire ou variable utilisateur) qui contient le résultat.
 *   On utilise antlrcpp::Any pour transporter ce std::string.
 *
 * Avantages par rapport au CodeGenVisitor direct :
 *   - Pas de push/pop ni de temporaires gérés à la main dans le visiteur.
 *   - L'IR est indépendante de l'architecture cible.
 *   - On pourra ajouter des optimisations sur l'IR avant gen_asm().
 */
class CodeGenVisitor : public ifccBaseVisitor {
public:
    explicit CodeGenVisitor(CFG& cfg);

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    antlrcpp::Any visitTerm(ifccParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(ifccParser::FactorContext *ctx) override;

private:
    CFG& cfg_;

    /// Évalue une expression et retourne le nom de la variable IR résultat
    std::string evalExpr(antlr4::tree::ParseTree* node);
};