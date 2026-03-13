#include "StaticVisitor.h"
#include <iostream>

StaticVisitor::StaticVisitor() {
    scopeStack.push_back({}); 
}

int StaticVisitor::findVariable(std::string name) {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        if (it->find(name) != it->end()) {
            return (*it)[name];
        }
    }
    return 1;
}

antlrcpp::Any StaticVisitor::visitProg(ifccParser::ProgContext *ctx) {
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
    }
    return 0;
}
antlrcpp::Any StaticVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    std::string varName = ctx->VAR()->getText();

    if (scopeStack.back().find(varName) != scopeStack.back().end()) {
        std::cerr << "Error: variable " << varName << " already declared in this scope." << std::endl;
        exit(1); 
    }

    currentOffset -= 4; 
    scopeStack.back()[varName] = currentOffset; 
    
    addressTable[ctx] = currentOffset; 

    return 0;
}

antlrcpp::Any StaticVisitor::visitVarExpr(ifccParser::VarExprContext *ctx) {
    std::string varName = ctx->VAR()->getText();
    int addr = findVariable(varName);

    if (addr == 1) {
        std::cerr << "Error: variable " << varName << " used but not declared." << std::endl;
        exit(1);
    }

    addressTable[ctx] = addr; 
    return 0;
}

antlrcpp::Any StaticVisitor::visitVarAssignment(ifccParser::VarAssignmentContext *ctx) {
    std::string varName = ctx->VAR()->getText();
    int addr = findVariable(varName);
    
    if (addr == 1) {
        std::cerr << "Error: variable " << varName << " used before declaration." << std::endl;
        exit(1);
    }
    addressTable[ctx] = addr;
    
    return this->visit(ctx->expr());
}

antlrcpp::Any StaticVisitor::visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) {
    std::string varName = ctx->VAR()->getText();
    int addr = findVariable(varName);

    if (addr == 1) {
        std::cerr << "Error: array " << varName << " not declared." << std::endl;
        exit(1);
    }

    addressTable[ctx] = addr;
    this->visit(ctx->index);
    this->visit(ctx->val);
    return 0;
}

antlrcpp::Any StaticVisitor::visitBlocStmt(ifccParser::BlocStmtContext *ctx) {
    scopeStack.push_back({});
    
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
    }
    
    scopeStack.pop_back();
    return 0;
}

antlrcpp::Any StaticVisitor::visitIfStmt(ifccParser::IfStmtContext *ctx) {
    this->visit(ctx->expr());
    this->visit(ctx->thenStmt);
    if (ctx->elseStmt) {
        this->visit(ctx->elseStmt);
    }
    return 0;
}

antlrcpp::Any StaticVisitor::visitReturnStmt(ifccParser::ReturnStmtContext *ctx) {
    return this->visit(ctx->expr());
}

antlrcpp::Any StaticVisitor::visitArrayExpr(ifccParser::ArrayExprContext *ctx) {
    std::string varName = ctx->VAR()->getText();
    
    int addr = findVariable(varName);

    if (addr == 1) {
        std::cerr << "Error: array " << varName << " used but not declared." << std::endl;
        exit(1);
    }

    addressTable[ctx] = addr; 

    return this->visit(ctx->expr()); 
}

antlrcpp::Any StaticVisitor::visitArrayDeclaration(ifccParser::ArrayDeclarationContext *ctx) {
    std::string varName = ctx->VAR()->getText();

    if (scopeStack.back().find(varName) != scopeStack.back().end()) {
        std::cerr << "Error: variable " << varName << " already declared in this scope." << std::endl;
        exit(1); 
    }

    int arraySize = std::stoi(ctx->expr()->getText());
    currentOffset -= 4 * arraySize;
    scopeStack.back()[varName] = currentOffset;
    addressTable[ctx] = currentOffset;
    return 0;
}