#include "CodeGenVisitor.h"
#include <stdexcept>

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────

CodeGenVisitor::CodeGenVisitor(CFG& cfg) : cfg_(cfg) {}

/// Visite un nœud et récupère le nom de variable IR résultat (std::string).
std::string CodeGenVisitor::evalExpr(antlr4::tree::ParseTree* node) {
    antlrcpp::Any res = visit(node);
    return std::any_cast<std::string>(res);
}

// ─────────────────────────────────────────────
//  Programme
// ─────────────────────────────────────────────

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    // Bloc d'entrée unique
    BasicBlock* entryBB = new BasicBlock(&cfg_, cfg_.new_BB_name());
    cfg_.add_bb(entryBB);

    // Visiter toutes les instructions
    for (auto* s : ctx->stmt())
        this->visit(s);

    // Fallback return 0 : seulement si le bloc courant est vide ET sans
    // successeur — ce qui signifie qu'aucun return explicite n'a été rencontré.
    // Après un visitReturn_stmt, current_bb est un exitBB VIDE avec exit_true=nullptr,
    // mais il a déjà été relié au bloc précédent via exit_true : il faut juste
    // ne pas y réémettre d'instructions.
    // Cas sans return : current_bb == entryBB, il a des instrs, exit_true==nullptr.
    // Cas avec return : current_bb == exitBB vide, exit_true==nullptr.
    // Dans les deux cas exit_true==nullptr, mais dans le cas avec return
    // il y a eu un jmp implicite via le bb précédent. On détecte via instrs vides :
    if (cfg_.current_bb->instrs.empty() && cfg_.current_bb->exit_true == nullptr) {
        // C'est l'exitBB vide créé par visitReturn_stmt : l'épilogue sera
        // généré par gen_asm_epilogue depuis ce bloc — rien à faire.
    } else {
        // Pas de return explicite : émettre return 0
        std::string retTmp = cfg_.create_new_tempvar(Type::INT);
        cfg_.current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { retTmp, "0" });
        cfg_.current_bb->add_IRInstr(IRInstr::copy,    Type::INT, { "!retval", retTmp });
    }

    return 0;
}

// ─────────────────────────────────────────────
//  Instructions
// ─────────────────────────────────────────────

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    // Déclarer chaque variable dans la table des symboles
    for (auto* idTok : ctx->ID()) {
        std::string name = idTok->getText();
        cfg_.add_to_symbol_table(name, Type::INT);
    }

    // Si initialisation : "int a = expr;"
    if (ctx->expr() && !ctx->ID().empty()) {
        std::string name = ctx->ID(0)->getText();
        std::string src  = evalExpr(ctx->expr());
        cfg_.current_bb->add_IRInstr(IRInstr::copy, Type::INT, { name, src });
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string lhs = ctx->ID()->getText();
    std::string src = evalExpr(ctx->expr());
    cfg_.current_bb->add_IRInstr(IRInstr::copy, Type::INT, { lhs, src });
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    std::string src = evalExpr(ctx->expr());

    // La valeur de retour doit atterrir dans %eax avant l'épilogue.
    // On utilise la variable spéciale "!retval" qui sera traduite en %eax
    // par gen_asm_epilogue (via copy → %eax).
    cfg_.current_bb->add_IRInstr(IRInstr::copy, Type::INT, { "!retval", src });

    // Créer un nouveau BB de sortie (exit_true = nullptr → épilogue)
    // et pointer dessus depuis le BB courant.
    BasicBlock* exitBB = new BasicBlock(&cfg_, cfg_.new_BB_name());
    // exitBB->exit_true reste nullptr → l'épilogue sera généré dans exitBB
    cfg_.current_bb->exit_true  = exitBB;
    cfg_.current_bb->exit_false = nullptr;
    cfg_.add_bb(exitBB);

    return 0;
}

// ─────────────────────────────────────────────
//  Expressions
// ─────────────────────────────────────────────
//
// Chaque visiteur retourne un std::string = nom de la variable IR
// contenant le résultat. On crée des temporaires via create_new_tempvar().
// C'est le CFG qui gère leurs offsets, pas le visiteur.

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    // expr : term (('+'|'-') term)*
    std::string result = evalExpr(ctx->term(0));

    int n = (int)ctx->term().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->term(i));
        std::string dest  = cfg_.create_new_tempvar(Type::INT);

        std::string op = ctx->children[2*i - 1]->getText();
        if (op == "+") {
            cfg_.current_bb->add_IRInstr(IRInstr::add, Type::INT, { dest, result, right });
        } else {
            cfg_.current_bb->add_IRInstr(IRInstr::sub, Type::INT, { dest, result, right });
        }
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitTerm(ifccParser::TermContext *ctx) {
    // term : factor ('*' factor)*
    std::string result = evalExpr(ctx->factor(0));

    int n = (int)ctx->factor().size();
    for (int i = 1; i < n; i++) {
        std::string right = evalExpr(ctx->factor(i));
        std::string dest  = cfg_.create_new_tempvar(Type::INT);
        cfg_.current_bb->add_IRInstr(IRInstr::mul, Type::INT, { dest, result, right });
        result = dest;
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitFactor(ifccParser::FactorContext *ctx) {
    // factor : '-' factor | CONST | ID | '(' expr ')'

    if (ctx->CONST()) {
        // Constante : créer un temporaire et y charger la valeur
        std::string dest = cfg_.create_new_tempvar(Type::INT);
        std::string val  = ctx->CONST()->getText();
        cfg_.current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { dest, val });
        return dest;
    }

    if (ctx->ID()) {
        // Variable : retourner son nom directement (pas de copie inutile)
        return ctx->ID()->getText();
    }

    if (ctx->factor()) {
        // Unaire '-' : évaluer et nier
        std::string src  = evalExpr(ctx->factor());
        std::string zero = cfg_.create_new_tempvar(Type::INT);
        std::string dest = cfg_.create_new_tempvar(Type::INT);
        cfg_.current_bb->add_IRInstr(IRInstr::ldconst, Type::INT, { zero, "0" });
        cfg_.current_bb->add_IRInstr(IRInstr::sub,     Type::INT, { dest, zero, src });
        return dest;
    }

    // Parenthèses : '(' expr ')'
    return evalExpr(ctx->expr());
}