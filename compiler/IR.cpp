#include "IR.h"
#include <stdexcept>
#include <algorithm>
#include <cassert>

// ═══════════════════════════════════════════════════════════════
//  IRInstr
// ═══════════════════════════════════════════════════════════════

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, Type t_,
                 std::vector<std::string> params_)
    : bb(bb_), op(op_), t(t_), params(std::move(params_)) {}

void IRInstr::gen_asm(std::ostream& o) {
    // Raccourci : récupère l'opérande assembleur d'un paramètre IR
    auto reg = [&](int i) { return bb->cfg->IR_reg_to_asm(params[i]); };

    char suf = typeSuffix(t);  // 'l' pour int, 'b' pour char
    const char* acc = accReg(t);

    switch (op) {

    // ── ldconst : dest = constante ─────────────────────────────
    case ldconst:
        // params = { dest, "42" }
        o << "    mov" << suf << " $" << params[1] << ", " << reg(0) << "\n";
        break;

    // ── copy : dest = src ──────────────────────────────────────
    case copy:
        // params = { dest, src }
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── add : dest = src1 + src2 ───────────────────────────────
    case add:
        // params = { dest, src1, src2 }
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    add" << suf << " " << reg(2) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── sub : dest = src1 - src2 ───────────────────────────────
    case sub:
        // params = { dest, src1, src2 }
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    sub" << suf << " " << reg(2) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── mul : dest = src1 * src2 ───────────────────────────────
    case mul:
        // params = { dest, src1, src2 }
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    imul" << suf << " " << reg(2) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── rmem : dest = *adresse ─────────────────────────────────
    case rmem:
        // params = { dest, adresse }
        // Pour l'instant adresse est toujours une variable (offset rbp)
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── wmem : *adresse = src ──────────────────────────────────
    case wmem:
        // params = { adresse, src }
        o << "    mov" << suf << " " << reg(1) << ", " << acc   << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;

    // ── call : appel de fonction ───────────────────────────────
    case call: {
        // params = { label_fonction, dest, arg0, arg1, … }
        // ABI System V AMD64 : args entiers dans rdi, rsi, rdx, rcx, r8, r9
        static const char* argRegs[] = {
            "%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"
        };
        int nargs = (int)params.size() - 2;  // params[0]=label, params[1]=dest
        for (int i = 0; i < nargs && i < 6; i++) {
            o << "    movl " << bb->cfg->IR_reg_to_asm(params[2 + i])
              << ", " << argRegs[i] << "\n";
        }
        o << "    call " << params[0] << "\n";
        // La valeur de retour est dans %eax ; stocker dans dest si non vide
        if (!params[1].empty()) {
            o << "    movl %eax, " << bb->cfg->IR_reg_to_asm(params[1]) << "\n";
        }
        break;
    }

    // ── cmp_eq : dest = (src1 == src2) ? 1 : 0 ───────────────
    case cmp_eq:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    sete %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;

    // ── cmp_lt : dest = (src1 < src2) ? 1 : 0 ────────────────
    case cmp_lt:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setl %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;

    // ── cmp_le : dest = (src1 <= src2) ? 1 : 0 ───────────────
    case cmp_le:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setle %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;

    default:
        throw std::runtime_error("IRInstr::gen_asm: opération inconnue");
    }
}

// ═══════════════════════════════════════════════════════════════
//  BasicBlock
// ═══════════════════════════════════════════════════════════════

BasicBlock::BasicBlock(CFG* cfg_, std::string entry_label)
    : exit_true(nullptr), exit_false(nullptr),
      label(std::move(entry_label)), cfg(cfg_) {}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t,
                              std::vector<std::string> params) {
    instrs.push_back(new IRInstr(this, op, t, std::move(params)));
}

void BasicBlock::gen_asm(std::ostream& o) {
    // Émettre le label du bloc
    o << label << ":\n";

    // Émettre toutes les instructions
    for (auto* instr : instrs)
        instr->gen_asm(o);

    // Gestion des successeurs
    if (exit_true == nullptr) {
        // Fin de fonction → épilogue
        cfg->gen_asm_epilogue(o);
    } else if (exit_false == nullptr) {
        // Saut inconditionnel
        o << "    jmp " << exit_true->label << "\n";
    } else {
        // Branchement conditionnel sur test_var_name
        std::string cond = cfg->IR_reg_to_asm(test_var_name);
        o << "    cmpl $0, " << cond << "\n";
        o << "    je  " << exit_false->label << "\n";
        o << "    jmp " << exit_true->label  << "\n";
    }
}

// ═══════════════════════════════════════════════════════════════
//  CFG
// ═══════════════════════════════════════════════════════════════

CFG::CFG(const std::string& name, Type retType)
    : current_bb(nullptr), functionName(name),
      nextFreeSymbolIndex(0), nextBBnumber(0),
      nextTmpNumber(0), returnType_(retType) {
    // Pré-allouer la variable de retour spéciale
    add_to_symbol_table("!retval", Type::INT);
}

CFG::~CFG() {
    for (auto* bb : bbs) {
        for (auto* instr : bb->instrs) delete instr;
        delete bb;
    }
}

// ── Gestion des blocs ─────────────────────────────────────────

void CFG::add_bb(BasicBlock* bb) {
    bbs.push_back(bb);
    current_bb = bb;
}

std::string CFG::new_BB_name() {
    return ".L" + functionName + "_" + std::to_string(nextBBnumber++);
}

// ── Table des symboles ────────────────────────────────────────

void CFG::add_to_symbol_table(const std::string& name, Type t) {
    if (SymbolIndex.count(name)) return; // déjà alloué
    nextFreeSymbolIndex += typeSize(t);
    SymbolType[name]  = t;
    SymbolIndex[name] = nextFreeSymbolIndex;
}

std::string CFG::create_new_tempvar(Type t) {
    std::string name = "!tmp" + std::to_string(nextTmpNumber++);
    add_to_symbol_table(name, t);
    return name;
}

int CFG::get_var_index(const std::string& name) const {
    auto it = SymbolIndex.find(name);
    if (it == SymbolIndex.end())
        throw std::runtime_error("CFG: variable inconnue : " + name);
    return it->second;
}

Type CFG::get_var_type(const std::string& name) const {
    auto it = SymbolType.find(name);
    if (it == SymbolType.end())
        throw std::runtime_error("CFG: type inconnu pour : " + name);
    return it->second;
}

// ── Conversion nom IR → opérande ASM ─────────────────────────

std::string CFG::IR_reg_to_asm(const std::string& reg) const {
    if (reg.empty()) return "";

    // Constante numérique (éventuellement négative)
    if (reg[0] == '-' || std::isdigit((unsigned char)reg[0]))
        return "$" + reg;

    // Variable dans la table des symboles
    auto it = SymbolIndex.find(reg);
    if (it != SymbolIndex.end())
        return "-" + std::to_string(it->second) + "(%rbp)";

    throw std::runtime_error("CFG::IR_reg_to_asm: nom inconnu : '" + reg + "'");
}

// ── Génération assembleur ─────────────────────────────────────

int CFG::stackSize() const {
    int maxOff = 0;
    for (auto& p : SymbolIndex) maxOff = std::max(maxOff, p.second);
    return align16(maxOff);
}

void CFG::gen_asm_prologue(std::ostream& o) {
    int sz = stackSize();
#ifdef __APPLE__
    o << ".globl _" << functionName << "\n";
    o << "_" << functionName << ":\n";
#else
    o << ".globl " << functionName << "\n";
    o << functionName << ":\n";
#endif
    o << "    pushq %rbp\n";
    o << "    movq  %rsp, %rbp\n";
    if (sz > 0)
        o << "    subq  $" << sz << ", %rsp\n";
}

void CFG::gen_asm_epilogue(std::ostream& o) {
    int sz = stackSize();
    // Charger la valeur de retour (!retval) dans %eax si elle existe
    auto it = SymbolIndex.find("!retval");
    if (it != SymbolIndex.end()) {
        o << "    movl  -" << it->second << "(%rbp), %eax\n";
    }
    if (sz > 0)
        o << "    addq  $" << sz << ", %rsp\n";
    o << "    popq  %rbp\n";
    o << "    ret\n";
}

void CFG::gen_asm(std::ostream& o) {
    gen_asm_prologue(o);
    for (auto* bb : bbs)
        bb->gen_asm(o);
}