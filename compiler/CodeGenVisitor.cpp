#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    #ifdef __APPLE__
    std::cout<< ".globl _main\n" ;
    std::cout<< " _main: \n" ;
    #else
    std::cout<< ".globl main\n" ;
    std::cout<< " main: \n" ;
    #endif

    this->visit( ctx->return_stmt() );
    
    std::cout << "    ret\n";

    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    auto *e = ctx->expr();

    if (e->CONST() != nullptr) {
        int retval = std::stoi(e->CONST()->getText());
        std::cout << "    movl $" << retval << ", %eax\n";
        return 0;
    }
     std::cerr << "error: return d'une variable pas encore supporte\n";
    return 0;
}
