#include "SymbolTableVisitor.h"
#include <iostream>
#include <algorithm>

// ─────────────────────────────────────────────
//  Gestion des scopes (avec shadowing)
// ─────────────────────────────────────────────

void SymbolTableVisitor::enterScope() {
    scopes_.push_back({});
}

void SymbolTableVisitor::exitScope() {
    for (auto& [name, used] : scopes_.back()) {
        if (!used)
            std::cerr << "warning: variable declared but never used: " << name << "\n";
    }
    scopes_.pop_back();
}

void SymbolTableVisitor::declareVar(const std::string& name) {
    // Shadowing autorisé : erreur seulement si doublon DANS LE MÊME SCOPE
    if (scopes_.back().count(name)) {
        std::cerr << "error: variable declared twice in the same scope: " << name << "\n";
        hasError = true;
        return;
    }
    scopes_.back()[name] = false;
}

bool SymbolTableVisitor::isVisible(const std::string& name) const {
    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it)
        if (it->count(name)) return true;
    return false;
}

void SymbolTableVisitor::markUsed(const std::string& name) {
    // Marque la déclaration la plus interne
    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) { found->second = true; return; }
    }
}

// ─────────────────────────────────────────────
//  Table des fonctions
// ─────────────────────────────────────────────

void SymbolTableVisitor::registerBuiltins() {
    functions_["putchar"] = {1, Type::INT};
    functions_["getchar"] = {0, Type::INT};
}

void SymbolTableVisitor::collectSignatures(ifccParser::ProgContext* ctx) {
    for (auto* f : ctx->func_def()) {
        std::string name = f->ID()->getText();
        int paramCount = f->params() ? (int)f->params()->param().size() : 0;
        Type retType = (f->rettype()->getText() == "void") ? Type::VOID : Type::INT;
        if (functions_.count(name)) {
            std::cerr << "error: function defined twice: " << name << "\n";
            hasError = true;
        }
        functions_[name] = {paramCount, retType};
    }
}

// ─────────────────────────────────────────────
//  Visiteurs
// ─────────────────────────────────────────────

antlrcpp::Any SymbolTableVisitor::visitProg(ifccParser::ProgContext *ctx) {
    registerBuiltins();
    collectSignatures(ctx);
    for (auto* f : ctx->func_def()) this->visit(f);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitFunc_def(ifccParser::Func_defContext *ctx) {
    scopes_.clear();
    exprDepth_ = 0;
    maxTmpNeeded_ = 0;

    enterScope();  // scope de la fonction

    // Paramètres : déclarés et marqués utilisés (pas de warning "unused")
    if (ctx->params()) {
        for (auto* param : ctx->params()->param()) {
            std::string name = param->ID()->getText();
            declareVar(name);
            markUsed(name);
        }
    }

    for (auto* s : ctx->stmt()) this->visit(s);

    exitScope();
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitBlock_stmt(ifccParser::Block_stmtContext *ctx) {
    enterScope();
    for (auto* s : ctx->stmt()) this->visit(s);
    exitScope();
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    for (auto* idTok : ctx->ID())
        declareVar(idTok->getText());

    if (ctx->expr()) {
        if (!ctx->ID().empty()) markUsed(ctx->ID(0)->getText());
        this->visit(ctx->expr());
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitExpr_stmt(ifccParser::Expr_stmtContext *ctx) {
    this->visit(ctx->expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    if (ctx->expr()) this->visit(ctx->expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitIf_stmt(ifccParser::If_stmtContext *ctx) {
    this->visit(ctx->expr());
    for (auto* s : ctx->stmt()) this->visit(s);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitWhile_stmt(ifccParser::While_stmtContext *ctx) {
    this->visit(ctx->expr());
    this->visit(ctx->stmt());
    return 0;
}

// ── Expressions ──────────────────────────────────────────────────

template<typename List>
static void visitBinaryLevel(SymbolTableVisitor* self, List& children,
                              int& depth, int& maxDepth) {
    self->visit(children[0]);
    int n = (int)children.size();
    for (int i = 1; i < n; i++) {
        depth++;
        maxDepth = std::max(maxDepth, depth);
        self->visit(children[i]);
        depth--;
    }
}

antlrcpp::Any SymbolTableVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        if (!isVisible(name)) {
            std::cerr << "error: assignment to undeclared variable: " << name << "\n";
            hasError = true;
        } else {
            markUsed(name);
        }
        this->visit(ctx->expr());
        return 0;
    }
    this->visit(ctx->eq_expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitEq_expr(ifccParser::Eq_exprContext *ctx) {
    auto ch = ctx->rel_expr();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitRel_expr(ifccParser::Rel_exprContext *ctx) {
    auto ch = ctx->bitor_expr();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitBitor_expr(ifccParser::Bitor_exprContext *ctx) {
    auto ch = ctx->xor_expr();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitXor_expr(ifccParser::Xor_exprContext *ctx) {
    auto ch = ctx->and_expr();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitAnd_expr(ifccParser::And_exprContext *ctx) {
    auto ch = ctx->add_expr();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitAdd_expr(ifccParser::Add_exprContext *ctx) {
    auto ch = ctx->term();
    visitBinaryLevel(this, ch, exprDepth_, maxTmpNeeded_);
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitTerm(ifccParser::TermContext *ctx) {
    auto factors = ctx->factor();
    int n = (int)factors.size();
    this->visit(factors[0]);
    for (int i = 1; i < n; i++) {
        exprDepth_++;
        maxTmpNeeded_ = std::max(maxTmpNeeded_, exprDepth_);
        this->visit(factors[i]);
        exprDepth_--;
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitFactor(ifccParser::FactorContext *ctx) {
    if (ctx->factor()) {
        this->visit(ctx->factor());
        return 0;
    }

    // Appel de fonction
    if (ctx->ID() && ctx->children.size() >= 3 && ctx->children[1]->getText() == "(") {
        std::string name = ctx->ID()->getText();
        int argCount = (int)ctx->expr().size();
        auto it = functions_.find(name);
        if (it == functions_.end()) {
            std::cerr << "error: call to undefined function: " << name << "\n";
            hasError = true;
        } else if (argCount != it->second.paramCount) {
            std::cerr << "error: wrong number of arguments for '" << name
                      << "': expected " << it->second.paramCount
                      << ", got " << argCount << "\n";
            hasError = true;
        }
        for (auto* arg : ctx->expr()) this->visit(arg);
        return 0;
    }

    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        if (!isVisible(name)) {
            std::cerr << "error: variable used before declaration: " << name << "\n";
            hasError = true;
        } else {
            markUsed(name);
        }
        return 0;
    }

    for (auto* e : ctx->expr()) this->visit(e);
    return 0;
}
