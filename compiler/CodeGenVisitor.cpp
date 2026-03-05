#include "CodeGenVisitor.h"
#include <iostream>
#include <algorithm>

int CodeGenVisitor::align16(int n) {
    return (n + 15) & ~15;
}

CodeGenVisitor::CodeGenVisitor(const std::map<std::string,int>& off)
    : offsets(off) {}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    int maxOff = 0;
    for (auto &p : offsets) maxOff = std::max(maxOff, p.second);
    stackSize = align16(maxOff);

#ifdef __APPLE__
    std::cout << ".globl _main\n";
    std::cout << "_main:\n";
#else
    std::cout << ".globl main\n";
    std::cout << "main:\n";
#endif

    std::cout << "    pushq %rbp\n";
    std::cout << "    movq %rsp, %rbp\n";
    if (stackSize > 0) std::cout << "    subq $" << stackSize << ", %rsp\n";

    std::cout << "    jmp .Lstart\n";
    std::cout << ".Lreturn:\n";
    if (stackSize > 0) std::cout << "    addq $" << stackSize << ", %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";
    std::cout << ".Lstart:\n";

    for (auto s : ctx->stmt()) this->visit(s);

    // fallback si pas de return
    std::cout << "    movl $0, %eax\n";
    std::cout << "    jmp .Lreturn\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx)
{
    // si "int a = expr;" on init a
    if (ctx->expr() && !ctx->ID().empty()) {
        std::string name = ctx->ID(0)->getText();
        int off = offsets.at(name);

        this->visit(ctx->expr()); // résultat -> %eax
        std::cout << "    movl %eax, -" << off << "(%rbp)\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx)
{
    std::string lhs = ctx->ID()->getText();
    int off = offsets.at(lhs);

    this->visit(ctx->expr()); // résultat -> %eax
    std::cout << "    movl %eax, -" << off << "(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    this->visit(ctx->expr()); // résultat -> %eax
    std::cout << "    jmp .Lreturn\n";
    return 0;
}

// -------- Expressions --------
// Convention : visit(expr/term/factor) laisse le résultat dans %eax

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx)
{
    // expr : term (('+'|'-') term)*
    this->visit(ctx->term(0)); // eax

    int n = (int)ctx->term().size();
    for (int i = 1; i < n; i++) {
        std::cout << "    pushq %rax\n";
        this->visit(ctx->term(i));      // droite -> eax
        std::cout << "    popq %rcx\n"; // gauche -> ecx

        // opérateur est le child entre les deux terms
        // children: term op term op term ...
        std::string op = ctx->children[2*i - 1]->getText();

        if (op == "+") {
            std::cout << "    addl %ecx, %eax\n"; // eax = ecx + eax
        } else { // "-"
            std::cout << "    subl %eax, %ecx\n"; // ecx = ecx - eax
            std::cout << "    movl %ecx, %eax\n";
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitTerm(ifccParser::TermContext *ctx)
{
    // term : factor ('*' factor)*
    this->visit(ctx->factor(0)); // eax

    int n = (int)ctx->factor().size();
    for (int i = 1; i < n; i++) {
        std::cout << "    pushq %rax\n";
        this->visit(ctx->factor(i));     // droite dans eax
        std::cout << "    popq %rcx\n";  // gauche dans ecx
        std::cout << "    imull %ecx, %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFactor(ifccParser::FactorContext *ctx)
{
    // factor : '-' factor | CONST | ID | '(' expr ')'

    if (ctx->CONST()) {
        int v = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << v << ", %eax\n";
        return 0;
    }

    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        int off = offsets.at(name);
        std::cout << "    movl -" << off << "(%rbp), %eax\n";
        return 0;
    }

    // unary minus : '-' factor
    if (ctx->factor() != nullptr) {
        this->visit(ctx->factor());
        std::cout << "    negl %eax\n";
        return 0;
    }

    // '(' expr ')'
    this->visit(ctx->expr());
    return 0;
}