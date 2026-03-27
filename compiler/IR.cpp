#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, std::string dest_, std::vector<std::string> params_)
    : bb(bb_), op(op_), dest(dest_), params(params_) {}

void IRInstr::gen_asm(std::ostream &o) {
    std::string rDest = dest.empty() ? "" : bb->cfg->IR_reg_to_asm(dest);
    auto rParam = [&](int i) { return bb->cfg->IR_reg_to_asm(params[i]); };

    switch (op) {
        case Operation::ldconst:
            o << "    movl $" << params[0] << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::copy:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::add:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    addl " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::sub:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    subl " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::mul:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    imull " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::div:
            o << "    movl " << rParam(1) << ", %ecx\n";
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cltd\n";
            o << "    idivl %ecx\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::mod:
            o << "    movl " << rParam(1) << ", %ecx\n";
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cltd\n";
            o << "    idivl %ecx\n";
            o << "    movl %edx, " << rDest << "\n";
            break;
        case Operation::cmp_eq:
        case Operation::cmp_neq:
        case Operation::cmp_lt:
        case Operation::cmp_gt:
        case Operation::cmp_le:
        case Operation::cmp_ge:
            o << "    movl " << rParam(1) << ", %ecx\n";
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cmpl %ecx, %eax\n";
            if (op == Operation::cmp_eq) o << "    sete %al\n";
            else if (op == Operation::cmp_neq) o << "    setne %al\n";
            else if (op == Operation::cmp_lt) o << "    setl %al\n";
            else if (op == Operation::cmp_gt) o << "    setg %al\n";
            else if (op == Operation::cmp_le) o << "    setle %al\n";
            else if (op == Operation::cmp_ge) o << "    setge %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::bitwise_and:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    andl " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::bitwise_or:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    orl " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::bitwise_xor:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    xorl " << rParam(1) << ", %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::lshift:
            o << "    movl " << rParam(1) << ", %ecx\n";
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    sall %cl, %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::rshift:
            o << "    movl " << rParam(1) << ", %ecx\n";
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    sarl %cl, %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::neg:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    negl %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::bitwise_not:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    notl %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::logical_not:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cmpl $0, %eax\n";
            o << "    sete %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
        case Operation::array_load:
            o << "    movl " << rParam(1) << ", %eax\n";
            o << "    cltq\n";
            o << "    movl " << params[0] << "(%rbp, %rax, 4), %ecx\n"; // params[0] 是基础偏移常量
            o << "    movl %ecx, " << rDest << "\n";
            break;
        case Operation::array_store:
            o << "    movl " << rParam(1) << ", %eax\n";
            o << "    cltq\n";
            o << "    movl " << rParam(2) << ", %ecx\n";
            o << "    movl %ecx, " << params[0] << "(%rbp, %rax, 4)\n";
            break;
        case Operation::ret:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    jmp .L_end_" << bb->cfg->funcName << "\n"; 
            break;
        case Operation::jmp_if_zero:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cmpl $0, %eax\n";
            o << "    je " << params[1] << "\n";
            break;
        case Operation::jmp_if_not_zero:
            o << "    movl " << rParam(0) << ", %eax\n";
            o << "    cmpl $0, %eax\n";
            o << "    jne " << params[1] << "\n";
            break;
        case Operation::jmp:
            o << "    jmp " << params[0] << "\n";
            break;
        case Operation::call:
            o << "    call " << params[0] << "\n";
            o << "    movl %eax, " << rDest << "\n";
            break;
    }
}

BasicBlock::BasicBlock(CFG* cfg_, std::string entry_label) 
    : cfg(cfg_), label(entry_label) {}

void BasicBlock::add_IRInstr(Operation op, std::string dest, std::vector<std::string> params) {
    instrs.push_back(new IRInstr(this, op, dest, params));
}

void BasicBlock::gen_asm(std::ostream &o) {
    o << label << ":\n";
    for (auto instr : instrs) {
        instr->gen_asm(o);
    }
}

CFG::CFG(std::string funcName_, int totalOffset_) : funcName(funcName_), totalOffset(totalOffset_) {
    tempOffset = (totalOffset + 7) & ~7;
}

void CFG::add_bb(BasicBlock* bb) {
    bbs.push_back(bb);
}

std::string CFG::create_new_tempvar() {
    std::string name = "!tmp_" + std::to_string(nextFreeSymbolIndex++);
    tempOffset += 4;
    tmp_offsets[name] = -tempOffset;
    return name;
}

std::string CFG::get_next_label() {
    return ".L_" + funcName + "_" + std::to_string(nextLabel++);
}

std::string CFG::IR_reg_to_asm(std::string reg) {
    if (reg.find("!offset_") == 0) {
        return reg.substr(8) + "(%rbp)";
    } else if (reg.find("!tmp_") == 0) {
        return std::to_string(tmp_offsets[reg]) + "(%rbp)";
    } else if (reg.find("%") == 0) {
        return reg;
    }
    return ""; // Fallback
}

void CFG::gen_asm(std::ostream &o, std::string functionName){
    o << ".globl " << functionName << "\n";
    o << functionName << ":\n";
    o << "    pushq %rbp\n";
    o << "    movq %rsp, %rbp\n";

    int alignedStackSize = (tempOffset + 15) & ~15; 
    o << "    subq $" << alignedStackSize << ", %rsp\n";

    for (auto bb : bbs) {
        bb->gen_asm(o);
    }

    o << ".L_end_" << functionName << ":\n";
    o << "    movq %rbp, %rsp\n";
    o << "    popq %rbp\n";
    o << "    ret\n";
}