#pragma once
#include "generated/ifccBaseVisitor.h"
#include "Type.h"
#include <map>
#include <string>
#include <vector>

/**
 * SymbolTableVisitor
 *
 * Vérifications sémantiques avec scopes imbriqués et shadowing.
 * Une variable d'un scope interne peut porter le même nom qu'une variable
 * externe (shadowing C standard).
 */
class SymbolTableVisitor : public ifccBaseVisitor {
public:
    bool hasError = false;

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    antlrcpp::Any visitFunc_def(ifccParser::Func_defContext *ctx) override;
    antlrcpp::Any visitBlock_stmt(ifccParser::Block_stmtContext *ctx) override;
    antlrcpp::Any visitIf_stmt(ifccParser::If_stmtContext *ctx) override;
    antlrcpp::Any visitWhile_stmt(ifccParser::While_stmtContext *ctx) override;
    antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    antlrcpp::Any visitDecl_item(ifccParser::Decl_itemContext *ctx) override;
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
    // ── Table des fonctions ───────────────────────────────────────
    struct FuncInfo { int paramCount; Type retType; };
    std::map<std::string, FuncInfo> functions_;

    // ── Pile de scopes ────────────────────────────────────────────
    // Chaque scope est une map nom → a-t-il été utilisé ?
    // Le shadowing est autorisé : même nom possible dans plusieurs scopes.
    std::vector<std::map<std::string, bool>> scopes_;

    void enterScope();
    void exitScope();

    /// Déclare dans le scope courant ; erreur seulement si doublon DANS CE SCOPE.
    void declareVar(const std::string& name);

    /// Cherche de l'intérieur vers l'extérieur ; retourne true si visible.
    bool isVisible(const std::string& name) const;

    /// Marque utilisée la déclaration la plus interne du nom.
    void markUsed(const std::string& name);

    int exprDepth_    = 0;
    int maxTmpNeeded_ = 0;

    void registerBuiltins();
    void collectSignatures(ifccParser::ProgContext* ctx);
};
