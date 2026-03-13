#pragma once
#include "generated/ifccBaseVisitor.h"
#include <map>
#include <set>
#include <string>

/**
 * SymbolTableVisitor
 *
 * Parcourt l'AST pour :
 *   1. Associer à chaque variable utilisateur un offset mémoire.
 *   2. Effectuer les vérifications sémantiques statiques.
 *   3. Calculer la profondeur maximale des expressions binaires et
 *      pré-allouer les slots temporaires "!tmp0", "!tmp1", …
 *      utilisés par CodeGenVisitor à la place des push/pop.
 */
class SymbolTableVisitor : public ifccBaseVisitor {
public:
    std::map<std::string,int> offsets;   ///< nom → offset (positif, depuis rbp)
    std::set<std::string>     used;      ///< variables utilisées
    bool hasError = false;

    // ── Visiteurs principaux ──────────────────────────────────────
    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
    antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

    antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    antlrcpp::Any visitTerm(ifccParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(ifccParser::FactorContext *ctx) override;

private:
    int exprDepth_    = 0;   ///< profondeur courante d'imbrication lors du parcours
    int maxTmpNeeded_ = 0;   ///< nb de temporaires simultanés nécessaires

    /// Alloue un nouvel offset pour une variable ou un temporaire.
    int allocSlot();

    /// Alloue les slots !tmp0 … !tmp(n-1) dans la table.
    void allocTemporaries(int n);
};