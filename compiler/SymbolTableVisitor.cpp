#include "SymbolTableVisitor.h"
#include <iostream>
#include <algorithm>

// ─────────────────────────────────────────────
//  Allocation des slots mémoire
// ─────────────────────────────────────────────

int SymbolTableVisitor::allocSlot() {
    // Chaque variable (et temporaire) fait 4 octets (int 32 bits).
    // offsets 4, 8, 12, … depuis rbp.
    return (int)(4 * (offsets.size() + 1));
}

void SymbolTableVisitor::allocTemporaries(int n) {
    for (int i = 0; i < n; i++) {
        std::string name = "!tmp" + std::to_string(i);
        if (offsets.find(name) == offsets.end()) {
            offsets[name] = allocSlot();
        }
    }
}

// ─────────────────────────────────────────────
//  Visiteurs
// ─────────────────────────────────────────────

antlrcpp::Any SymbolTableVisitor::visitProg(ifccParser::ProgContext *ctx) {
    // Première passe : variables utilisateur + calcul de la profondeur max
    for (auto s : ctx->stmt()) {
        this->visit(s);
    }

    // Allouer les temporaires nécessaires (après les variables utilisateur,
    // pour ne pas perturber leurs offsets)
    allocTemporaries(maxTmpNeeded_);

    // Vérification : toute variable déclarée doit être utilisée
    for (auto& p : offsets) {
        // Les temporaires internes commencent par '!' → on les ignore
        if (p.first[0] == '!') continue;
        if (used.find(p.first) == used.end()) {
            std::cerr << "error: variable declared but never used: " << p.first << "\n";
            hasError = true;
        }
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    for (auto idTok : ctx->ID()) {
        std::string name = idTok->getText();
        if (offsets.count(name)) {
            std::cerr << "error: variable declared twice: " << name << "\n";
            hasError = true;
        } else {
            offsets[name] = allocSlot();
        }
    }
    if (ctx->expr()) {
        // La variable initialisée est utilisée implicitement
        if (!ctx->ID().empty())
            used.insert(ctx->ID(0)->getText());
        this->visit(ctx->expr());
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string lhs = ctx->ID()->getText();
    if (!offsets.count(lhs)) {
        std::cerr << "error: assignment to undeclared variable: " << lhs << "\n";
        hasError = true;
    } else {
        // Une affectation compte comme une utilisation
        used.insert(lhs);
    }
    this->visit(ctx->expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());
    return 0;
}

// ── Expressions : suivi de la profondeur d'imbrication ──────────

antlrcpp::Any SymbolTableVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    auto terms = ctx->term();
    int n = (int)terms.size();

    // Visite du premier terme sans temporaire
    this->visit(terms[0]);

    // Pour chaque opérateur binaire supplémentaire, on a besoin d'un
    // temporaire à la profondeur courante.
    for (int i = 1; i < n; i++) {
        exprDepth_++;
        maxTmpNeeded_ = std::max(maxTmpNeeded_, exprDepth_);
        this->visit(terms[i]);
        exprDepth_--;
    }
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
        // Unaire '-' : même profondeur, pas de temporaire supplémentaire
        this->visit(ctx->factor());
        return 0;
    }

    if (ctx->expr()) {
        // Parenthèses : on descend dans l'expression
        this->visit(ctx->expr());
        return 0;
    }

    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        if (!offsets.count(name)) {
            std::cerr << "error: variable used before declaration: " << name << "\n";
            hasError = true;
        } else {
            used.insert(name);
        }
        return 0;
    }

    // CONST : rien à faire
    return 0;
}