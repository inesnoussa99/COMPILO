#include "CodeGenVisitor.h"

#include <iostream>
#include <cstdlib>

static int align16(int n) { return (n + 15) & ~15; }

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
#ifdef __APPLE__
    std::cout << ".globl _main\n";
    std::cout << "_main:\n";
#else
    std::cout << ".globl main\n";
    std::cout << "main:\n";
#endif

    // 1) Assigner des offsets aux variables déclarées
    sym.clear();
    int nextOff = 0;

    for (auto *s : ctx->stmt()) {
        if (auto *d = s->decl_stmt()) {
            std::string name = d->ID()->getText();
            if (sym.count(name)) {
                std::cerr << "error: variable declared twice: " << name << "\n";
                std::exit(1);
            }
            VarType t = d->INT() ? VarType::INT32 : VarType::CHAR8;
            int size = (t == VarType::INT32) ? 4 : 1;

            nextOff += size;
            sym[name] = VarInfo{t, nextOff};
    }
    }
    frameSize = align16(nextOff);

    // 2) Prologue ARM64
    std::cout << "    stp x29, x30, [sp, #-16]!\n";
    std::cout << "    mov x29, sp\n";
    if (frameSize > 0) {
        std::cout << "    sub sp, sp, #" << frameSize << "\n";
    }

    // 3) Statements
    for (auto *s : ctx->stmt()) {
        visit(s);
    }

    // 4) return -> met la valeur dans w0
    visit(ctx->return_stmt());

    // 5) Epilogue + ret
    if (frameSize > 0) {
        std::cout << "    add sp, sp, #" << frameSize << "\n";
    }
    std::cout << "    ldp x29, x30, [sp], #16\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx)
{
    std::string name = ctx->ID()->getText();

    if (!sym.count(name)) {
        std::cerr << "error: internal: missing symbol info for " << name << "\n";
        std::exit(1);
    }

    // Si pas d'initialisation, rien à émettre
    if (!ctx->expr()) return 0;

    // Calculer l'expression -> w0
    visit(ctx->expr());

    auto info = sym[name];
    if (info.type == VarType::INT32) {
        std::cout << "    str w0, [x29, #-" << info.offset << "]\n";
    } else {
        std::cout << "    strb w0, [x29, #-" << info.offset << "]\n";
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx)
{
    std::string name = ctx->ID()->getText();
    if (!sym.count(name)) {
        std::cerr << "error: variable not declared: " << name << "\n";
        std::exit(1);
    }

    // expr -> w0
    visit(ctx->expr());

    // store w0 into var
    auto info = sym[name];
    if (info.type == VarType::INT32) {
        std::cout << "    str w0, [x29, #-" << info.offset << "]\n";
    } else {
        std::cout << "    strb w0, [x29, #-" << info.offset << "]\n";
    }
return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    // return expr;  => expr -> w0
    visit(ctx->expr());
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx)
{   if (ctx->expr().size() == 2) {

    // calculer expr gauche
    visit(ctx->expr(0));
    std::cout << "    str w0, [sp, #-16]!\n";

    // calculer expr droite
    visit(ctx->expr(1));
    std::cout << "    ldr w1, [sp], #16\n";

    if (ctx->getText().find('+') != std::string::npos) {
        std::cout << "    add w0, w1, w0\n";
    }
    else if (ctx->getText().find('-') != std::string::npos) {
        std::cout << "    sub w0, w1, w0\n";
    }
    else if (ctx->getText().find('*') != std::string::npos) {
        std::cout << "    mul w0, w1, w0\n";
    }

    return 0;
}

    if (ctx->CONST()) {
        int v = std::stoi(ctx->CONST()->getText());
        std::cout << "    mov w0, #" << v << "\n";
        return 0;
    }
    if (ctx->CHARCONST()) {
    std::string t = ctx->CHARCONST()->getText(); // ex: "'a'"
    char c = t[1];                               // le caractère au milieu
    int v = static_cast<unsigned char>(c);        // code ASCII 0..255
    std::cout << "    mov w0, #" << v << "\n";
    return 0;
    }
    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        if (!sym.count(name)) {
            std::cerr << "error: variable not declared: " << name << "\n";
            std::exit(1);
        }
        auto info = sym[name];
        if (info.type == VarType::INT32) {
            std::cout << "    str w0, [x29, #-" << info.offset << "]\n";
        } else {
            std::cout << "    strb w0, [x29, #-" << info.offset << "]\n";
            }
        return 0;
    }

    std::cerr << "error: unsupported expression\n";
    std::exit(1);
}