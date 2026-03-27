#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>

class BasicBlock;
class CFG;

enum class Operation {
    ldconst, copy,
    add, sub, mul, div, mod,
    cmp_eq, cmp_neq, cmp_lt, cmp_gt, cmp_le, cmp_ge,
    bitwise_and, bitwise_or, bitwise_xor, lshift, rshift,
    neg, bitwise_not, logical_not,
    array_load, array_store,
    ret, jmp_if_zero, jmp_if_not_zero, jmp,
    call
};

class IRInstr {
public:
    IRInstr(BasicBlock* bb_, Operation op_, std::string dest_, std::vector<std::string> params_);
    void gen_asm(std::ostream &o);
private:
    BasicBlock* bb;
    Operation op;
    std::string dest;
    std::vector<std::string> params;
};

class BasicBlock {
public:
    BasicBlock(CFG* cfg, std::string entry_label);
    void gen_asm(std::ostream &o);
    void add_IRInstr(Operation op, std::string dest, std::vector<std::string> params);

    std::string label;
    CFG* cfg;
    std::vector<IRInstr*> instrs;
};

class CFG {
public:
    CFG(std::string funcName, int totalOffset); // 构造函数加一个参数
    std::string funcName;
    CFG(int totalOffset);
    void add_bb(BasicBlock* bb);
    void gen_asm(std::ostream &o ,std::string functionName);
    std::string IR_reg_to_asm(std::string reg);
    std::string create_new_tempvar();
    std::string get_next_label();

    BasicBlock* current_bb;
    int totalOffset;
private:
    std::vector<BasicBlock*> bbs;
    std::map<std::string, int> tmp_offsets;
    int nextFreeSymbolIndex = 0;
    int nextLabel = 0;
    int tempOffset;
};