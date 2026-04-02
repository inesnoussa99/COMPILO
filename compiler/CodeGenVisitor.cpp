#include "CodeGenVisitor.h"
#include <stdexcept>

// ─────────────────────────────────────────────
//  Helpers généraux
// ─────────────────────────────────────────────

void CodeGenVisitor::gen_asm(std::ostream& o) {
    for (auto* cfg : cfgs_) cfg->gen_asm(o);
}

std::string CodeGenVisitor::evalExpr(antlr4::tree::ParseTree* node) {
    antlrcpp::Any res = visit(node);
    return std::any_cast<std::string>(res);
}

// ─────────────────────────────────────────────
//  Gestion des scopes / shadowing
// ─────────────────────────────────────────────

void CodeGenVisitor::enterBlockScope() {
    nameScopes_.push_back({});
}

void CodeGenVisitor::exitBlockScope() {
    nameScopes_.pop_back();
}

/// Cherche le nom IR associé au nom logique, du scope le plus interne vers
/// le plus externe. Retourne le nom logique lui-même en fallback (ne devrait
/// pas arriver après les vérifications sémantiques).
std::string CodeGenVisitor::resolveVar(const std::string& name) const {
    for (auto it = nameScopes_.rbegin(); it != nameScopes_.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) return found->second;
    }
    return name;
}

/// Déclare une nouvelle variable dans le scope courant.
/// Si le nom logique existe déjà dans un scope externe (shadowing),
/// crée un nom IR unique "name@N" pour éviter les collisions dans le CFG.
std::string CodeGenVisitor::declareIRVar(const std::string& name) {
    // Vérifier si ce nom logique est déjà utilisé dans un scope externe
    bool shadows = false;
    for (auto it = nameScopes_.rbegin() + 1; it != nameScopes_.rend(); ++it)
        if (it->count(name)) { shadows = true; break; }

    std::string irName = shadows
        ? name + "@" + std::to_string(shadowCounter_++)
        : name;

    nameScopes_.back()[name] = irName;
    cfg_->add_to_symbol_table(irName, Type::INT);
    return irName;
}

// ─────────────────────────────────────────────
//  Programme
// ─────────────────────────────────────────────

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    for (auto* f : ctx->func_def()) this->visit(f);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunc_def(ifccParser::Func_defContext *ctx) {
    std::string name = ctx->ID()->getText();
    Type retType = (ctx->rettype()->getText() == "void") ? Type::VOID : Type::INT;

    CFG* cfg = new CFG(name, retType);
    cfgs_.push_back(cfg);
    cfg_ = cfg;

    // Réinitialiser les scopes pour cette fonction
    nameScopes_.clear();
    shadowCounter_ = 0;
    enterBlockScope();  // scope de la fonction

    // Paramètres : enregistrés dans le CFG ET dans le scope
    if (ctx->params()) {
        for (auto* param : ctx->params()->param()) {
            std::string pname = param->ID()->getText();
            cfg_->add_param(pname, Type::INT);
            nameScopes_.back()[pname] = pname;  // pas de shadowing au niveau fonction
        }
    }

    BasicBlock* entryBB = new BasicBlock(cfg_, cfg_->new_BB_name());
    cfg_->add_bb(entryBB);

    for (auto* s : ctx->stmt()) this->visit(s);

    // Retour implicite si le dernier BB n'est pas déjà un exit de return
    if (!cfg_->current_bb->isReturnExit) {
        if (retType != Type::VOID) {
            std::string retTmp = cfg_->create_new_tempvar(Type::INT);
            cfg_->current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { retTmp, "0" });
            cfg_->current_bb->add_IRInstr(IRInstr::copy,    Type::INT, { "!retval", retTmp });
        }
    }

    exitBlockScope();
    return 0;
}

// ─────────────────────────────────────────────
//  Instructions
// ─────────────────────────────────────────────

antlrcpp::Any CodeGenVisitor::visitBlock_stmt(ifccParser::Block_stmtContext *ctx) {
    enterBlockScope();
    for (auto* s : ctx->stmt()) this->visit(s);
    exitBlockScope();
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    for (auto* item : ctx->decl_item())
        this->visit(item);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_item(ifccParser::Decl_itemContext *ctx) {
    std::string irName = declareIRVar(ctx->ID()->getText());
    if (ctx->expr()) {
        std::string src = evalExpr(ctx->expr());
        cfg_->current_bb->add_IRInstr(IRInstr::copy, Type::INT, { irName, src });
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr_stmt(ifccParser::Expr_stmtContext *ctx) {
    evalExpr(ctx->expr());
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    if (ctx->expr()) {
        std::string src = evalExpr(ctx->expr());
        cfg_->current_bb->add_IRInstr(IRInstr::copy, Type::INT, { "!retval", src });
    }
    // Mark current BB as epilogue-trigger (exit_true == nullptr → gen_asm_epilogue)
    cfg_->current_bb->isReturnExit = true;
    // exit_true stays nullptr → epilogue will be generated at end of this BB

    // Redirect to a dead-code sink so subsequent statements don't corrupt this BB
    BasicBlock* sinkBB = new BasicBlock(cfg_, cfg_->new_BB_name());
    sinkBB->isReturnExit = true;   // prevents spurious implicit-return injection
    cfg_->add_bb(sinkBB);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIf_stmt(ifccParser::If_stmtContext *ctx) {
    // Evaluate condition in current BB
    std::string condVar = evalExpr(ctx->expr());
    cfg_->current_bb->test_var_name = condVar;

    BasicBlock* thenBB  = new BasicBlock(cfg_, cfg_->new_BB_name());
    BasicBlock* mergeBB = new BasicBlock(cfg_, cfg_->new_BB_name());
    bool hasElse = ctx->stmt().size() > 1;
    BasicBlock* elseBB  = hasElse ? new BasicBlock(cfg_, cfg_->new_BB_name()) : nullptr;

    cfg_->current_bb->exit_true  = thenBB;
    cfg_->current_bb->exit_false = hasElse ? elseBB : mergeBB;

    // Then body
    cfg_->add_bb(thenBB);
    this->visit(ctx->stmt(0));
    if (!cfg_->current_bb->isReturnExit)
        cfg_->current_bb->exit_true = mergeBB;

    // Else body (optional)
    if (hasElse) {
        cfg_->add_bb(elseBB);
        this->visit(ctx->stmt(1));
        if (!cfg_->current_bb->isReturnExit)
            cfg_->current_bb->exit_true = mergeBB;
    }

    cfg_->add_bb(mergeBB);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitWhile_stmt(ifccParser::While_stmtContext *ctx) {
    BasicBlock* condBB  = new BasicBlock(cfg_, cfg_->new_BB_name());
    BasicBlock* bodyBB  = new BasicBlock(cfg_, cfg_->new_BB_name());
    BasicBlock* afterBB = new BasicBlock(cfg_, cfg_->new_BB_name());

    // Current BB → condBB
    cfg_->current_bb->exit_true = condBB;
    cfg_->add_bb(condBB);

    // Evaluate condition in condBB
    std::string condVar = evalExpr(ctx->expr());
    cfg_->current_bb->test_var_name = condVar;
    cfg_->current_bb->exit_true  = bodyBB;
    cfg_->current_bb->exit_false = afterBB;

    // Body — push break/continue targets
    cfg_->add_bb(bodyBB);
    breakTargets_.push_back(afterBB);
    continueTargets_.push_back(condBB);
    this->visit(ctx->stmt());
    breakTargets_.pop_back();
    continueTargets_.pop_back();

    if (!cfg_->current_bb->isReturnExit)
        cfg_->current_bb->exit_true = condBB;

    cfg_->add_bb(afterBB);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBreak_stmt(ifccParser::Break_stmtContext *ctx) {
    if (!breakTargets_.empty()) {
        cfg_->current_bb->exit_true = breakTargets_.back();
        cfg_->current_bb->isReturnExit = true;  // stop code emission after this
        BasicBlock* sinkBB = new BasicBlock(cfg_, cfg_->new_BB_name());
        sinkBB->isReturnExit = true;
        cfg_->add_bb(sinkBB);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitContinue_stmt(ifccParser::Continue_stmtContext *ctx) {
    if (!continueTargets_.empty()) {
        cfg_->current_bb->exit_true = continueTargets_.back();
        cfg_->current_bb->isReturnExit = true;
        BasicBlock* sinkBB = new BasicBlock(cfg_, cfg_->new_BB_name());
        sinkBB->isReturnExit = true;
        cfg_->add_bb(sinkBB);
    }
    return 0;
}

// ─────────────────────────────────────────────
//  Expressions
// ─────────────────────────────────────────────

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    // expr : ID '=' expr | eq_expr
    if (ctx->ID()) {
        std::string irName = resolveVar(ctx->ID()->getText());
        std::string src    = evalExpr(ctx->expr());
        cfg_->current_bb->add_IRInstr(IRInstr::copy, Type::INT, { irName, src });
        return irName;
    }
    return evalExpr(ctx->eq_expr());
}

antlrcpp::Any CodeGenVisitor::visitEq_expr(ifccParser::Eq_exprContext *ctx) {
    std::string result = evalExpr(ctx->rel_expr(0));
    int n = (int)ctx->rel_expr().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->rel_expr(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        std::string op    = ctx->children[2*i - 1]->getText();
        IRInstr::Operation irop = (op == "==") ? IRInstr::cmp_eq : IRInstr::cmp_ne;
        cfg_->current_bb->add_IRInstr(irop, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitRel_expr(ifccParser::Rel_exprContext *ctx) {
    std::string result = evalExpr(ctx->bitor_expr(0));
    int n = (int)ctx->bitor_expr().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->bitor_expr(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        std::string op    = ctx->children[2*i - 1]->getText();
        IRInstr::Operation irop;
        if      (op == "<")  irop = IRInstr::cmp_lt;
        else if (op == ">")  irop = IRInstr::cmp_gt;
        else if (op == "<=") irop = IRInstr::cmp_le;
        else                 irop = IRInstr::cmp_ge;
        cfg_->current_bb->add_IRInstr(irop, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitBitor_expr(ifccParser::Bitor_exprContext *ctx) {
    std::string result = evalExpr(ctx->xor_expr(0));
    int n = (int)ctx->xor_expr().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->xor_expr(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        cfg_->current_bb->add_IRInstr(IRInstr::bit_or, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitXor_expr(ifccParser::Xor_exprContext *ctx) {
    std::string result = evalExpr(ctx->and_expr(0));
    int n = (int)ctx->and_expr().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->and_expr(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        cfg_->current_bb->add_IRInstr(IRInstr::bit_xor, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitAnd_expr(ifccParser::And_exprContext *ctx) {
    std::string result = evalExpr(ctx->add_expr(0));
    int n = (int)ctx->add_expr().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->add_expr(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        cfg_->current_bb->add_IRInstr(IRInstr::bit_and, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitAdd_expr(ifccParser::Add_exprContext *ctx) {
    std::string result = evalExpr(ctx->term(0));
    int n = (int)ctx->term().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->term(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        std::string op    = ctx->children[2*i - 1]->getText();
        if (op == "+")
            cfg_->current_bb->add_IRInstr(IRInstr::add, Type::INT, { dest, result, right });
        else
            cfg_->current_bb->add_IRInstr(IRInstr::sub, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitTerm(ifccParser::TermContext *ctx) {
    std::string result = evalExpr(ctx->factor(0));
    int n = (int)ctx->factor().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->factor(i));
        std::string dest  = cfg_->create_new_tempvar(Type::INT);
        std::string op    = ctx->children[2*i - 1]->getText();
        IRInstr::Operation irop;
        if      (op == "*") irop = IRInstr::mul;
        else if (op == "/") irop = IRInstr::div;
        else                irop = IRInstr::mod;
        cfg_->current_bb->add_IRInstr(irop, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitFactor(ifccParser::FactorContext *ctx) {
    if (ctx->CONST()) {
        std::string dest = cfg_->create_new_tempvar(Type::INT);
        cfg_->current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { dest, ctx->CONST()->getText() });
        return dest;
    }

    if (ctx->CHAR_CONST()) {
        std::string text = ctx->CHAR_CONST()->getText(); // e.g. "'a'" ou "'\n'"
        int val;
        if (text[1] == '\\') {
            switch (text[2]) {
                case 'n':  val = '\n'; break;
                case 't':  val = '\t'; break;
                case 'r':  val = '\r'; break;
                case '0':  val = '\0'; break;
                case '\\': val = '\\'; break;
                case '\'': val = '\''; break;
                default:   val = (unsigned char)text[2]; break;
            }
        } else {
            val = (unsigned char)text[1];
        }
        std::string dest = cfg_->create_new_tempvar(Type::INT);
        cfg_->current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { dest, std::to_string(val) });
        return dest;
    }

    // Appel de fonction : ID '(' args? ')'
    if (ctx->ID() && ctx->children.size() >= 3 && ctx->children[1]->getText() == "(") {
        std::string funcName = ctx->ID()->getText();
        std::string dest     = cfg_->create_new_tempvar(Type::INT);
        std::vector<std::string> callParams = { funcName, dest };
        for (auto* arg : ctx->expr())
            callParams.push_back(evalExpr(arg));
        cfg_->current_bb->add_IRInstr(IRInstr::call, Type::INT, callParams);
        return dest;
    }

    // Variable : résolution scope-aware
    if (ctx->ID()) {
        return resolveVar(ctx->ID()->getText());
    }

    if (ctx->factor()) {
        std::string prefix = ctx->children[0]->getText();
        std::string src    = evalExpr(ctx->factor());
        std::string dest   = cfg_->create_new_tempvar(Type::INT);
        if (prefix == "-") {
            std::string zero = cfg_->create_new_tempvar(Type::INT);
            cfg_->current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { zero, "0" });
            cfg_->current_bb->add_IRInstr(IRInstr::sub,     Type::INT, { dest, zero, src });
        } else {
            cfg_->current_bb->add_IRInstr(IRInstr::not_op, Type::INT, { dest, src });
        }
        return dest;
    }

    // Parenthèses : '(' expr ')'
    return evalExpr(ctx->expr(0));
}
