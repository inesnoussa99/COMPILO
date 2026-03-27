#include "CodeGenVisitor.h"
#include <any>

CodeGenVisitor::CodeGenVisitor(std::map<antlr4::ParserRuleContext*, int> addressTable, 
                               std::map<std::string, int> functionOffsets) 
    : addressTable(addressTable), functionOffsets(functionOffsets) {
    cfg = nullptr;
}

CodeGenVisitor::~CodeGenVisitor() {
    delete cfg;
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    for (auto funcCtx : ctx->functionDef()) {
        this->visit(funcCtx); 
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(ifccParser::ReturnStmtContext *ctx) {
    std::string ret_var = std::any_cast<std::string>(this->visit(ctx->expr())); 
    cfg->current_bb->add_IRInstr(Operation::ret, "", {ret_var});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitParExpr(ifccParser::ParExprContext *ctx) {
    return this->visit(ctx->expr());
}

antlrcpp::Any CodeGenVisitor::visitAddExpr(ifccParser::AddExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0))); 
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1))); 
    std::string dest = cfg->create_new_tempvar();

    if (ctx->OA->getText() == "-") {
        cfg->current_bb->add_IRInstr(Operation::sub, dest, {left, right});
    } else {
        cfg->current_bb->add_IRInstr(Operation::add, dest, {left, right});
    }
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitMultExpr(ifccParser::MultExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();

    std::string op = ctx->OM->getText();
    if (op == "*") cfg->current_bb->add_IRInstr(Operation::mul, dest, {left, right});
    else if (op == "/") cfg->current_bb->add_IRInstr(Operation::div, dest, {left, right});
    else if (op == "%") cfg->current_bb->add_IRInstr(Operation::mod, dest, {left, right});

    return dest;
}

antlrcpp::Any CodeGenVisitor::visitConstExpr(ifccParser::ConstExprContext *ctx) {
    std::string dest = cfg->create_new_tempvar();
    std::string val = ctx->CONST()->getText(); 
    cfg->current_bb->add_IRInstr(Operation::ldconst, dest, {val});
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitVarExpr(ifccParser::VarExprContext *ctx) {
    int position = addressTable[ctx];
    return std::string("!offset_" + std::to_string(position)); // 已静态分配的局部变量
}

antlrcpp::Any CodeGenVisitor::visitArrayExpr(ifccParser::ArrayExprContext *ctx) {
    std::string index = std::any_cast<std::string>(this->visit(ctx->expr()));
    std::string dest = cfg->create_new_tempvar();
    std::string basePosition = std::to_string(addressTable[ctx]);
    cfg->current_bb->add_IRInstr(Operation::array_load, dest, {basePosition, index});
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitRelationalExpr(ifccParser::RelationalExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();

    std::string op = ctx->OR->getText();
    if (op == "<")  cfg->current_bb->add_IRInstr(Operation::cmp_lt, dest, {left, right});
    else if (op == ">")  cfg->current_bb->add_IRInstr(Operation::cmp_gt, dest, {left, right});
    else if (op == "<=") cfg->current_bb->add_IRInstr(Operation::cmp_le, dest, {left, right});
    else if (op == ">=") cfg->current_bb->add_IRInstr(Operation::cmp_ge, dest, {left, right});

    return dest;
}

antlrcpp::Any CodeGenVisitor::visitEqualityExpr(ifccParser::EqualityExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();

    std::string op = ctx->OE->getText();
    if (op == "==") cfg->current_bb->add_IRInstr(Operation::cmp_eq, dest, {left, right});
    else if (op == "!=") cfg->current_bb->add_IRInstr(Operation::cmp_neq, dest, {left, right});

    return dest;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();
    cfg->current_bb->add_IRInstr(Operation::bitwise_and, dest, {left, right});
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();
    cfg->current_bb->add_IRInstr(Operation::bitwise_or, dest, {left, right});
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();
    cfg->current_bb->add_IRInstr(Operation::bitwise_xor, dest, {left, right});
    return dest;
}

antlrcpp::Any CodeGenVisitor::visitShiftExpr(ifccParser::ShiftExprContext *ctx) {
    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string dest = cfg->create_new_tempvar();

    std::string op = ctx->OS->getText();
    if (op == "<<") cfg->current_bb->add_IRInstr(Operation::lshift, dest, {left, right});
    else if (op == ">>") cfg->current_bb->add_IRInstr(Operation::rshift, dest, {left, right});

    return dest;
}

antlrcpp::Any CodeGenVisitor::visitBlocStmt(ifccParser::BlocStmtContext *ctx) {
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(ifccParser::IfStmtContext *ctx) {
    std::string cond = std::any_cast<std::string>(this->visit(ctx->expr()));
    
    BasicBlock* thenBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* endBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* elseBB = ctx->elseStmt ? new BasicBlock(cfg, cfg->get_next_label()) : endBB;

    cfg->current_bb->add_IRInstr(Operation::jmp_if_zero, "", {cond, elseBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {thenBB->label});

    cfg->add_bb(thenBB);
    cfg->current_bb = thenBB;
    this->visit(ctx->thenStmt);
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});

    if (ctx->elseStmt) {
        cfg->add_bb(elseBB);
        cfg->current_bb = elseBB;
        this->visit(ctx->elseStmt);
        cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});
    }

    cfg->add_bb(endBB);
    cfg->current_bb = endBB;

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpr(ifccParser::UnaryExprContext *ctx) {
    std::string src = std::any_cast<std::string>(this->visit(ctx->expr()));
    std::string dest = cfg->create_new_tempvar();

    std::string op = ctx->OU->getText();
    if (op == "-") cfg->current_bb->add_IRInstr(Operation::neg, dest, {src});
    else if (op == "~") cfg->current_bb->add_IRInstr(Operation::bitwise_not, dest, {src});
    else if (op == "!") cfg->current_bb->add_IRInstr(Operation::logical_not, dest, {src});

    return dest;
}

// 采用惰性求值策略模拟 &&
antlrcpp::Any CodeGenVisitor::visitLogicalAndExpr(ifccParser::LogicalAndExprContext *ctx) {
    std::string dest = cfg->create_new_tempvar();
    
    BasicBlock* evalRightBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* setTrueBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* setFalseBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* endBB = new BasicBlock(cfg, cfg->get_next_label());

    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    cfg->current_bb->add_IRInstr(Operation::jmp_if_zero, "", {left, setFalseBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {evalRightBB->label});
    
    cfg->add_bb(evalRightBB);
    cfg->current_bb = evalRightBB;
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    cfg->current_bb->add_IRInstr(Operation::jmp_if_zero, "", {right, setFalseBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {setTrueBB->label});

    cfg->add_bb(setTrueBB);
    cfg->current_bb = setTrueBB;
    cfg->current_bb->add_IRInstr(Operation::ldconst, dest, {"1"});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});

    cfg->add_bb(setFalseBB);
    cfg->current_bb = setFalseBB;
    cfg->current_bb->add_IRInstr(Operation::ldconst, dest, {"0"});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});

    cfg->add_bb(endBB);
    cfg->current_bb = endBB;

    return dest;
}

// 采用惰性求值策略模拟 ||
antlrcpp::Any CodeGenVisitor::visitLogicalOrExpr(ifccParser::LogicalOrExprContext *ctx) {
    std::string dest = cfg->create_new_tempvar();
    
    BasicBlock* evalRightBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* setTrueBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* setFalseBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* endBB = new BasicBlock(cfg, cfg->get_next_label());

    std::string left = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    cfg->current_bb->add_IRInstr(Operation::jmp_if_not_zero, "", {left, setTrueBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {evalRightBB->label});
    
    cfg->add_bb(evalRightBB);
    cfg->current_bb = evalRightBB;
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    cfg->current_bb->add_IRInstr(Operation::jmp_if_not_zero, "", {right, setTrueBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {setFalseBB->label});

    cfg->add_bb(setTrueBB);
    cfg->current_bb = setTrueBB;
    cfg->current_bb->add_IRInstr(Operation::ldconst, dest, {"1"});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});

    cfg->add_bb(setFalseBB);
    cfg->current_bb = setFalseBB;
    cfg->current_bb->add_IRInstr(Operation::ldconst, dest, {"0"});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {endBB->label});

    cfg->add_bb(endBB);
    cfg->current_bb = endBB;

    return dest;
}

antlrcpp::Any CodeGenVisitor::visitVarAssignment(ifccParser::VarAssignmentContext *ctx) {
    std::string right = std::any_cast<std::string>(this->visit(ctx->expr())); 
    int position = addressTable[ctx];
    std::string left = "!offset_" + std::to_string(position);
    cfg->current_bb->add_IRInstr(Operation::copy, left, {right});
    return left;
}

antlrcpp::Any CodeGenVisitor::visitArrayAssignment(ifccParser::ArrayAssignmentContext *ctx) {
    std::string index = std::any_cast<std::string>(this->visit(ctx->expr(0)));
    std::string val = std::any_cast<std::string>(this->visit(ctx->expr(1)));
    std::string basePosition = std::to_string(addressTable[ctx]);
    cfg->current_bb->add_IRInstr(Operation::array_store, "", {basePosition, index, val});
    return val;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(ifccParser::WhileStmtContext *ctx) {
    BasicBlock* condBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* bodyBB = new BasicBlock(cfg, cfg->get_next_label());
    BasicBlock* endBB  = new BasicBlock(cfg, cfg->get_next_label());

    cfg->current_bb->add_IRInstr(Operation::jmp, "", {condBB->label});

    cfg->add_bb(condBB);
    cfg->current_bb = condBB;
    std::string cond = std::any_cast<std::string>(this->visit(ctx->expr()));
    cfg->current_bb->add_IRInstr(Operation::jmp_if_zero, "", {cond, endBB->label});
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {bodyBB->label});

    cfg->add_bb(bodyBB);
    cfg->current_bb = bodyBB;
    this->visit(ctx->bodyStmt); 
    cfg->current_bb->add_IRInstr(Operation::jmp, "", {condBB->label});

    cfg->add_bb(endBB);
    cfg->current_bb = endBB;

    return 0;
}
antlrcpp::Any CodeGenVisitor::visitFunctionDef(ifccParser::FunctionDefContext *ctx) {
    std::string funcName = ctx->VAR(0)->getText();

    int function_total_offset = functionOffsets[funcName];

    CFG* funcCFG = new CFG(funcName, function_total_offset);
    this->cfgs.push_back(funcCFG); 
    this->cfg = funcCFG;

    BasicBlock* entryBB = new BasicBlock(funcCFG, funcName);
    funcCFG->add_bb(entryBB);
    funcCFG->current_bb = entryBB;

    std::vector<std::string> paramRegs = {"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};
    int paramOffset = 0;
    for (size_t i = 1; i < ctx->VAR().size(); ++i) {
        paramOffset -= 4; 
        if (i - 1 < 6) {
            std::string dest = "!offset_" + std::to_string(paramOffset);
            funcCFG->current_bb->add_IRInstr(Operation::copy, dest, {paramRegs[i-1]});
        }
    }

    this->visit(ctx->blocStmt());
    std::string defaultRetVar = cfg->create_new_tempvar();
    cfg->current_bb->add_IRInstr(Operation::ldconst, defaultRetVar, {"0"});
    cfg->current_bb->add_IRInstr(Operation::ret, "", {defaultRetVar});

    return 0;
}