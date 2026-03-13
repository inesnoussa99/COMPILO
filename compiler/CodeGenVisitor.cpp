#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    std::cout << ".globl main\n";
    std::cout << "main:\n"; 
    
    std::cout << "    pushq %rbp\n";
    std::cout << "    movq %rsp, %rbp\n";

    int tempBuffer = 1024;
    int alignedStackSize = (totalOffset + tempBuffer + 15) & ~15; 
    std::cout << "    subq $" << alignedStackSize << ", %rsp\n";

    tempOffset = (totalOffset + 7) & ~7;

    for (auto stmt : ctx->statement()) {
        this->visit(stmt); 
    }

    std::cout << "end_main:\n"; 
    std::cout << "    movq %rbp, %rsp\n"; 
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(ifccParser::ReturnStmtContext *ctx)
{
    this->visit(ctx->expr()); 
    std::cout << "    jmp end_main\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitParExpr(ifccParser::ParExprContext *ctx)
{
    return this->visit(ctx->expr());
}

antlrcpp::Any CodeGenVisitor::visitAddExpr(ifccParser::AddExprContext *ctx) 
{
    this->visit(ctx->expr(0)); 
    this->storeTempReg(); // pushq %rax

    this->visit(ctx->expr(1)); 
    this->loadTempReg("rdx"); // popq %rdx

    if (ctx->OA->getText() == "-") {
        std::cout << "    negl %eax\n";
    }
    std::cout << "    addl %edx, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitMultExpr(ifccParser::MultExprContext *ctx) 
{
    this->visit(ctx->expr(0));
    this->storeTempReg();

    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    
    this->loadTempReg("rax");

    if (ctx->OM->getText() == "*") {
        std::cout << "    imull %ecx, %eax\n"; 
    } else if (ctx->OM->getText() == "/") {
        std::cout << "    cltd\n";
        std::cout << "    idivl %ecx\n";
    } else if (ctx->OM->getText() == "%") {
        std::cout << "    cltd\n";
        std::cout << "    idivl %ecx\n";
        std::cout << "    movl %edx, %eax\n"; 
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConstExpr(ifccParser::ConstExprContext *ctx) 
{
    int value = std::stoi(ctx->CONST()->getText()); 
    std::cout << "    movl $" << value << ", %eax" << std::endl; 

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVarExpr(ifccParser::VarExprContext *ctx) 
{
    int position = addressTable[ctx];
    std::cout << "    movl " << position << "(%rbp), %eax" << std::endl;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitArrayExpr(ifccParser::ArrayExprContext *ctx) {
    this->visit(ctx->expr()); 
    std::cout << "    cltq\n"; 
    int basePosition = addressTable[ctx]; 
    std::cout << "    movl " << basePosition << "(%rbp, %rax, 4), %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx)
{
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitRelationalExpr(ifccParser::RelationalExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");

    std::cout << "    cmpl %ecx, %eax\n";

    std::string op = ctx->OR->getText();
    if (op == "<")  std::cout << "    setl %al\n";
    else if (op == ">")  std::cout << "    setg %al\n";
    else if (op == "<=") std::cout << "    setle %al\n";
    else if (op == ">=") std::cout << "    setge %al\n";

    std::cout << "    movzbl %al, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitEqualityExpr(ifccParser::EqualityExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");

    std::cout << "    cmpl %ecx, %eax\n";

    std::string op = ctx->OE->getText();
    if (op == "==") std::cout << "    sete %al\n";
    else if (op == "!=") std::cout << "    setne %al\n";

    std::cout << "    movzbl %al, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");
    std::cout << "    andl %ecx, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");
    std::cout << "    orl %ecx, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");
    std::cout << "    xorl %ecx, %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitShiftExpr(ifccParser::ShiftExprContext *ctx) {
    this->visit(ctx->expr(0));
    this->storeTempReg();
    this->visit(ctx->expr(1));
    std::cout << "    movl %eax, %ecx\n";
    this->loadTempReg("rax");

    std::string op = ctx->OS->getText();
    if (op == "<<") std::cout << "    sall %cl, %eax\n";
    else if (op == ">>") std::cout << "    sar %cl, %eax\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBlocStmt(ifccParser::BlocStmtContext *ctx) {
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(ifccParser::IfStmtContext *ctx) {
    int id = labelCounter++; 
    std::string elseLabel = "else_" + std::to_string(id);
    std::string endLabel = "end_if_" + std::to_string(id);

    this->visit(ctx->expr());
    
    std::cout << "    cmpl $0, %eax\n";
    
    if (ctx->elseStmt) {
        std::cout << "    je " << elseLabel << "\n";
    } else {
        std::cout << "    je " << endLabel << "\n";
    }

    this->visit(ctx->thenStmt);
    std::cout << "    jmp " << endLabel << "\n";

    if (ctx->elseStmt) {
        std::cout << elseLabel << ":\n";
        this->visit(ctx->elseStmt);
    }

    std::cout << endLabel << ":\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpr(ifccParser::UnaryExprContext *ctx) {
    this->visit(ctx->expr());

    std::string op = ctx->OU->getText();
    if (op == "-") {
        std::cout << "    negl %eax\n";
    } else if (op == "~") {
        std::cout << "    notl %eax\n";
    } else if (op == "!") {
        std::cout << "    cmpl $0, %eax\n";
        std::cout << "    sete %al\n";
        std::cout << "    movzbl %al, %eax\n";
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitLogicalAndExpr(ifccParser::LogicalAndExprContext *ctx) {
    int id = labelCounter++;
    std::string falseLabel = "logical_and_false_" + std::to_string(id);
    std::string endLabel = "logical_and_end_" + std::to_string(id);

    this->visit(ctx->expr(0));
    std::cout << "    testl %eax, %eax\n";
    std::cout << "    je " << falseLabel << "\n";

    // true+
    this->visit(ctx->expr(1));
    std::cout << "    testl %eax, %eax\n";
    std::cout << "    je " << falseLabel << "\n";

    // true*2
    std::cout << "    movl $1, %eax\n";
    std::cout << "    jmp " << endLabel << "\n";

    // 1 false
    std::cout << falseLabel << ":\n";
    std::cout << "    movl $0, %eax\n";

    std::cout << endLabel << ":\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitLogicalOrExpr(ifccParser::LogicalOrExprContext *ctx) {
    int id = labelCounter++;
    std::string trueLabel = "logical_or_true_" + std::to_string(id);
    std::string endLabel = "logical_or_end_" + std::to_string(id);

    this->visit(ctx->expr(0));
    std::cout << "    testl %eax, %eax\n";
    std::cout << "    jne " << trueLabel << "\n";
    this->visit(ctx->expr(1));
    std::cout << "    testl %eax, %eax\n";
    std::cout << "    jne " << trueLabel << "\n";
    std::cout << "    movl $0, %eax\n";
    std::cout << "    jmp " << endLabel << "\n";
    std::cout << trueLabel << ":\n";
    std::cout << "    movl $1, %eax\n";
    std::cout << endLabel << ":\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVarAssignment(ifccParser::VarAssignmentContext *ctx) {
    this->visit(ctx->expr()); 
    int position = addressTable[ctx];
    std::cout << "    movl %eax, " << position << "(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) {
    this->visit(ctx->expr(0)); 
    std::cout << "    cltq\n"; 
    this->storeTempReg();
    int basePosition = addressTable[ctx]; 
    this->visit(ctx->expr(1)); 
    std::cout << "    movl %eax, %ecx\n"; 
    this->loadTempReg("rax"); 
    std::cout << "    movl %ecx, " << basePosition << "(%rbp, %rax, 4)\n";
    return 0;
}