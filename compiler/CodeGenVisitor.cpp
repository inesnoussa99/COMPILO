#include "CodeGenVisitor.h"
#include <string>
#include <iostream>
#include <cstdlib>  // std::abort
#include <algorithm>

static int align16(int n) {
    return (n + 15) / 16 * 16;
}

int CodeGenVisitor::dispOf(const std::string& name) const {
    std::unordered_map<std::string, VarIndexVisitor::Info>::const_iterator it = vars.find(name);
    if (it == vars.end()) {
        // Normalement impossible car VarIndexVisitor a déjà vérifié
        std::cerr << "internal error: unknown variable '" << name << "'\n";
        std::abort();
    }
    return it->second.offset + 4;
}

int CodeGenVisitor::stackSizeBytes() const {
    // nbVars * 4 puis alignement 16 pour rester propre ABI
    int bytes = (int)vars.size() * 4;
    return align16(bytes);
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
#ifdef __APPLE__
    std::cout << ".globl _main\n";
    std::cout << "_main:\n";
#else
    std::cout << ".globl main\n";
    std::cout << "main:\n";
#endif

    // Prologue
    std::cout << "    pushq %rbp\n";
    std::cout << "    movq %rsp, %rbp\n";

    int sz = stackSizeBytes();
    if (sz > 0) {
        std::cout << "    subq $" << sz << ", %rsp\n";
    }

    // Générer les statements
    for (auto *s : ctx->stmt()) {
        visit(s);
    }

    // Générer le return (met le résultat dans %eax)
    visit(ctx->return_stmt());

    // Epilogue
    std::cout << "    leave\n";
    std::cout << "    ret\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx)
{
    std::string name = ctx->ID()->getText();
    int disp = dispOf(name);

    if (ctx->expr()) {
        // évaluer expr -> %eax, puis stocker
        visit(ctx->expr());
        std::cout << "    movl %eax, -" << disp << "(%rbp)\n";
    } else {
        // optionnel (c-like non obligatoire), mais pratique pour éviter du garbage
        std::cout << "    movl $0, -" << disp << "(%rbp)\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx)
{
    std::string name = ctx->ID()->getText();
    int disp = dispOf(name);

    // RHS -> %eax
    visit(ctx->expr());
    // store %eax dans la variable
    std::cout << "    movl %eax, -" << disp << "(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    // évaluer expr -> %eax
    visit(ctx->expr());
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx)
{
    if (ctx->CONST()) {
        int v = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << v << ", %eax\n";
        return 0;
    }

    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        int disp = dispOf(name);
        std::cout << "    movl -" << disp << "(%rbp), %eax\n";
        return 0;
    }

    // Normalement impossible avec ta grammaire expr = CONST | ID
    std::cerr << "internal error: unknown expr\n";
    std::abort();
}