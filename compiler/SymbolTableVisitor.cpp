#include "SymbolTableVisitor.h"
#include <iostream>

static int nextOffsetFromSize(size_t n) {
    return (int)(4 * (n + 1)); // 4,8,12,...
}

antlrcpp::Any SymbolTableVisitor::visitProg(ifccParser::ProgContext *ctx) {
    for (auto s : ctx->stmt()) {
        this->visit(s);
    }

    for (auto &p : offsets) {
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
            offsets[name] = nextOffsetFromSize(offsets.size());
        }
    }
    if (ctx->expr()) {
        this->visit(ctx->expr());
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string lhs = ctx->ID()->getText();
    if (!offsets.count(lhs)) {
        std::cerr << "error: assignment to undeclared variable: " << lhs << "\n";
        hasError = true;
    }
    this->visit(ctx->expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    for (auto t : ctx->term()) {
        this->visit(t);
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitTerm(ifccParser::TermContext *ctx) {
    for (auto f : ctx->factor()) {
        this->visit(f);
    }
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitFactor(ifccParser::FactorContext *ctx) {
    // factor : '-' factor | CONST | ID | '(' expr ')'

    // unary minus : '-' factor
    // Dans ANTLR C++ (ton runtime), on ne peut pas utiliser getChildCount/getChild ici.
    // On détecte le cas unaire via la présence du sous-factor.
    if (ctx->factor() != nullptr) {
        this->visit(ctx->factor());
        return 0;
    }

    // parenthèses : '(' expr ')'
    if (ctx->expr() != nullptr) {
        this->visit(ctx->expr());
        return 0;
    }

    // ID : vérifier déclaration + marquer used
    if (ctx->ID() != nullptr) {
        std::string name = ctx->ID()->getText();
        if (!offsets.count(name)) {
            std::cerr << "error: variable used before declaration: " << name << "\n";
            hasError = true;
        } else {
            used.insert(name);
        }
        return 0;
    }

    // CONST : rien à vérifier
    return 0;
}