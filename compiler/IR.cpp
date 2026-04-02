#include "IR.h"
#include <stdexcept>
#include <algorithm>
#include <cassert>

#if defined(__aarch64__) || defined(__arm64__)
  #define TARGET_ARM64 1
#else
  #define TARGET_ARM64 0
#endif

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, Type t_,
                 std::vector<std::string> params_)
    : bb(bb_), op(op_), t(t_), params(std::move(params_)) {}

// ═══════════════════════════════════════════════════════════════
//  gen_asm x86-64
// ═══════════════════════════════════════════════════════════════
#if !TARGET_ARM64

void IRInstr::gen_asm(std::ostream& o) {
    auto reg        = [&](int i) { return bb->cfg->IR_reg_to_asm(params[i]); };
    char suf        = typeSuffix(t);
    const char* acc = accReg(t);

    switch (op) {
    case ldconst:
        o << "    mov" << suf << " $" << params[1] << ", " << reg(0) << "\n";
        break;
    case copy:
        o << "    mov" << suf << " " << reg(1) << ", " << acc    << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;
    case add:
        o << "    mov" << suf << " " << reg(1) << ", " << acc    << "\n";
        o << "    add" << suf << " " << reg(2) << ", " << acc    << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;
    case sub:
        o << "    mov" << suf << " " << reg(1) << ", " << acc    << "\n";
        o << "    sub" << suf << " " << reg(2) << ", " << acc    << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;
    case mul:
        o << "    mov"  << suf << " " << reg(1) << ", " << acc    << "\n";
        o << "    imul" << suf << " " << reg(2) << ", " << acc    << "\n";
        o << "    mov"  << suf << " " << acc    << ", " << reg(0) << "\n";
        break;
    case div:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cdq\n";
        o << "    idivl " << reg(2) << "\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case mod:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cdq\n";
        o << "    idivl " << reg(2) << "\n";
        o << "    movl %edx, " << reg(0) << "\n";
        break;
    case not_op:
        o << "    cmpl $0, " << reg(1) << "\n";
        o << "    sete %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case bit_or:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    orl  " << reg(2) << ", %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case bit_xor:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    xorl " << reg(2) << ", %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case bit_and:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    andl " << reg(2) << ", %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case rmem:
    case wmem:
        o << "    mov" << suf << " " << reg(1) << ", " << acc    << "\n";
        o << "    mov" << suf << " " << acc    << ", " << reg(0) << "\n";
        break;
    case call: {
        static const char* argRegs[] = { "%edi","%esi","%edx","%ecx","%r8d","%r9d" };
        int nargs = (int)params.size() - 2;
        for (int i = 0; i < nargs && i < 6; i++)
            o << "    movl " << bb->cfg->IR_reg_to_asm(params[2+i]) << ", " << argRegs[i] << "\n";
        o << "    call " << params[0] << "\n";
        if (!params[1].empty())
            o << "    movl %eax, " << bb->cfg->IR_reg_to_asm(params[1]) << "\n";
        break;
    }
    case cmp_eq:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    sete %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case cmp_ne:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setne %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case cmp_lt:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setl %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case cmp_gt:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setg %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case cmp_le:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setle %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
    case cmp_ge:
        o << "    movl " << reg(1) << ", %eax\n";
        o << "    cmpl " << reg(2) << ", %eax\n";
        o << "    setge %al\n";
        o << "    movzbl %al, %eax\n";
        o << "    movl %eax, " << reg(0) << "\n";
        break;
   default:
        throw std::runtime_error("IRInstr::gen_asm x86: opération inconnue");
    }
}

// ═══════════════════════════════════════════════════════════════
//  gen_asm ARM64
//  Registres : w8=scratch gauche, w9=scratch droite, w0=retour ABI
// ═══════════════════════════════════════════════════════════════
#else

void IRInstr::gen_asm(std::ostream& o) {
    // Charge le paramètre i dans le registre wreg
    auto load = [&](int i, const char* wreg) {
        const std::string& p = params[i];
        if (!p.empty() && (std::isdigit((unsigned char)p[0]) || p[0] == '-')) {
            o << "    mov   " << wreg << ", #" << p << "\n";
        } else {
            int off = bb->cfg->get_var_index(p);
            o << "    ldr   " << wreg << ", [x29, #-" << off << "]\n";
        }
    };
    // Stocke wreg dans la variable params[i]
    auto store = [&](int i, const char* wreg) {
        int off = bb->cfg->get_var_index(params[i]);
        o << "    str   " << wreg << ", [x29, #-" << off << "]\n";
    };

    switch (op) {
    case ldconst: //charger une constante dans une variable : params[0]=var, params[1]=constante
        o << "    mov   w8, #" << params[1] << "\n";
        store(0, "w8");
        break;
    case copy: // copier une variable dans une autre : params[0]=var_dest, params[1]=var_source
        load(1, "w8");
        store(0, "w8");
        break;
    case add: // addition : params[0]=var_dest, params[1]=var_source1, params[2]=var_source2
        load(1, "w8"); load(2, "w9");  // w8=source1, w9=source2
        o << "    add   w8, w8, w9\n"; 
        store(0, "w8"); //on stocke le résultat qui est dans W8 dans la variable de destination
        break;
    case sub: //idem que add
        load(1, "w8"); load(2, "w9");
        o << "    sub   w8, w8, w9\n";
        store(0, "w8");
        break;
    case mul: //idem que add
        load(1, "w8"); load(2, "w9");
        o << "    mul   w8, w8, w9\n";
        store(0, "w8");
        break;
    case div:   //idem que add, mais on utilise sdiv pour la division entière signée
        load(1,"w8"); load(2,"w9");
        o << "    sdiv  w8, w8, w9\n";
        store(0,"w8");
        break;
    case mod:
        load(1,"w8"); load(2,"w9");
        o << "    sdiv  w10, w8, w9\n"; // w10 = w8 / w9
        o << "    msub  w8, w10, w9, w8\n"; // w8 = w8 - (w10 * w9)
        store(0,"w8");
        break;
    case not_op:
        load(1,"w8");
        o << "    cmp   w8, #0\n"; //compare w8 à 0
        o << "    cset  w8, eq\n"; // w8 = (w8 == 0) ? 1 : 0
        store(0,"w8");
        break;
    case bit_or:
        load(1,"w8"); load(2,"w9");
        o << "    orr   w8, w8, w9\n";
        store(0,"w8");
        break;
    case bit_xor:
        load(1,"w8"); load(2,"w9");
        o << "    eor   w8, w8, w9\n";
        store(0,"w8");
        break;
    case bit_and:
        load(1,"w8"); load(2,"w9");
        o << "    and   w8, w8, w9\n";
        store(0,"w8");
        break;
    case rmem:
    case wmem:
        load(1, "w8");
        store(0, "w8");
        break;
    case call: {
        static const char* argRegs[] = { "w0","w1","w2","w3","w4","w5" };
        int nargs = (int)params.size() - 2;
        for (int i = 0; i < nargs && i < 6; i++) load(2+i, argRegs[i]);
        o << "    bl    _" << params[0] << "\n";
         // "branch with link" = appelle la fonction (et sauvegarde l'adresse de retour dans x30)
        if (!params[1].empty()) {
            int odest = bb->cfg->get_var_index(params[1]);
            o << "    str   w0, [x29, #-" << odest << "]\n";
        }
        break;
    }
    case cmp_eq:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, eq\n";
        store(0,"w8");
        break;
    case cmp_ne:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, ne\n";
        store(0,"w8");
        break;
    case cmp_lt:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, lt\n";
        store(0,"w8");
        break;
    case cmp_gt:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, gt\n";
        store(0,"w8");
        break;
    case cmp_le:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, le\n";
        store(0,"w8");
        break;
    case cmp_ge:
        load(1,"w8"); load(2,"w9");
        o << "    cmp   w8, w9\n";
        o << "    cset  w8, ge\n";
        store(0,"w8");
        break;
    default:
        throw std::runtime_error("IRInstr::gen_asm ARM64: opération inconnue");
    }
}

#endif // TARGET_ARM64

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
    o << label << ":\n";
    for (auto* instr : instrs) instr->gen_asm(o);

    if (exit_true == nullptr) {
        cfg->gen_asm_epilogue(o);
    } else if (exit_false == nullptr) {
#if TARGET_ARM64
        o << "    b     " << exit_true->label << "\n";
#else
        o << "    jmp " << exit_true->label << "\n";
#endif
    } else {
#if TARGET_ARM64
        int off = cfg->get_var_index(test_var_name);
        o << "    ldr   w8, [x29, #-" << off << "]\n";
        o << "    cbz   w8, " << exit_false->label << "\n";
        o << "    b     " << exit_true->label  << "\n";
#else
        std::string cond = cfg->IR_reg_to_asm(test_var_name);
        o << "    cmpl $0, " << cond << "\n";
        o << "    je  " << exit_false->label << "\n";
        o << "    jmp " << exit_true->label  << "\n";
#endif
    }
}

// ═══════════════════════════════════════════════════════════════
//  CFG
// ═══════════════════════════════════════════════════════════════

CFG::CFG(const std::string& name, Type retType)
    : current_bb(nullptr), functionName(name),
      nextFreeSymbolIndex(0), nextBBnumber(0),
      nextTmpNumber(0), returnType_(retType), frameSize_(0) {
    if (retType != Type::VOID)
        add_to_symbol_table("!retval", Type::INT);
}

CFG::~CFG() {
    for (auto* bb : bbs) {
        for (auto* instr : bb->instrs) delete instr;
        delete bb;
    }
}

void CFG::add_bb(BasicBlock* bb) { bbs.push_back(bb); current_bb = bb; }

std::string CFG::new_BB_name() {
    return ".L" + functionName + "_" + std::to_string(nextBBnumber++);
}

void CFG::add_to_symbol_table(const std::string& name, Type t) {
    if (SymbolIndex.count(name)) return; // déjà présent, ne rien faire
    nextFreeSymbolIndex += typeSize(t);
    SymbolType[name]  = t;
    SymbolIndex[name] = nextFreeSymbolIndex;
}

void CFG::add_param(const std::string& name, Type t) {
    add_to_symbol_table(name, t);
    params_.push_back(name);
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

std::string CFG::IR_reg_to_asm(const std::string& reg) const {
    if (reg.empty()) return "";
    if (reg[0] == '-' || std::isdigit((unsigned char)reg[0]))
        return "$" + reg;
    auto it = SymbolIndex.find(reg);
    if (it != SymbolIndex.end())
        return "-" + std::to_string(it->second) + "(%rbp)";
    throw std::runtime_error("CFG::IR_reg_to_asm: nom inconnu : '" + reg + "'");
}

int CFG::stackSize() const {
    int maxOff = 0;
    for (auto& p : SymbolIndex) maxOff = std::max(maxOff, p.second);
    return align16(maxOff);
}

void CFG::gen_asm_prologue(std::ostream& o) {
    int sz = stackSize();
#if TARGET_ARM64
    o << ".globl _" << functionName << "\n";
    o << "_" << functionName << ":\n";
    frameSize_ = sz + 16; // on ajoute 16 pour sauvegarder x29 et x30
    o << "    stp   x29, x30, [sp, #-" << frameSize_ << "]!\n"; // ! : sp
    o << "    mov   x29, sp\n";
    {
        static const char* paramRegs[] = {"w0","w1","w2","w3","w4","w5"};
        for (int i = 0; i < (int)params_.size() && i < 6; i++) {
            int off = get_var_index(params_[i]);
            o << "    str   " << paramRegs[i] << ", [x29, #-" << off << "]\n";
        }
    }
#else
#ifdef __APPLE__
    o << ".globl _" << functionName << "\n";
    o << "_" << functionName << ":\n";
#else
    o << ".globl " << functionName << "\n";
    o << functionName << ":\n";
#endif
    o << "    pushq %rbp\n";
    o << "    movq  %rsp, %rbp\n";
    if (sz > 0) o << "    subq  $" << sz << ", %rsp\n";
    {
        static const char* paramRegs[] = {"%edi","%esi","%edx","%ecx","%r8d","%r9d"};
        for (int i = 0; i < (int)params_.size() && i < 6; i++) {
            int off = get_var_index(params_[i]);
            o << "    movl " << paramRegs[i] << ", -" << off << "(%rbp)\n";
        }
    }
#endif
}

void CFG::gen_asm_epilogue(std::ostream& o) {
#if TARGET_ARM64
    auto it = SymbolIndex.find("!retval");
    if (it != SymbolIndex.end())
        o << "    ldr   w0, [x29, #-" << it->second << "]\n";
    o << "    ldp   x29, x30, [sp], #" << frameSize_ << "\n";
    o << "    ret\n";
#else
    int sz = stackSize();
    auto it = SymbolIndex.find("!retval");
    if (it != SymbolIndex.end())
        o << "    movl  -" << it->second << "(%rbp), %eax\n";
    if (sz > 0) o << "    addq  $" << sz << ", %rsp\n";
    o << "    popq  %rbp\n";
    o << "    ret\n";
#endif
}

void CFG::gen_asm(std::ostream& o) {
    gen_asm_prologue(o);
    for (auto* bb : bbs) bb->gen_asm(o);
}