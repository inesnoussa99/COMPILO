#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "Type.h"

class BasicBlock;
class CFG;

class IRInstr {
public:
    typedef enum {
        ldconst, copy, add, sub, mul,
        rmem, wmem, call,
        cmp_eq, cmp_ne, cmp_lt, cmp_gt, cmp_le, div, mod, not_op,
        bit_or, bit_xor, bit_and,
    } Operation;

    IRInstr(BasicBlock* bb, Operation op, Type t, std::vector<std::string> params);
    void gen_asm(std::ostream& o);

private:
    BasicBlock* bb;
    Operation   op;
    Type        t;
    std::vector<std::string> params;
};

class BasicBlock {
public:
    BasicBlock(CFG* cfg, std::string entry_label);
    void gen_asm(std::ostream& o);
    void add_IRInstr(IRInstr::Operation op, Type t, std::vector<std::string> params);

    BasicBlock* exit_true;
    BasicBlock* exit_false;
    std::string label;
    CFG*        cfg;
    std::vector<IRInstr*> instrs;
    std::string test_var_name;
    bool isReturnExit = false;
};

class CFG {
public:
    explicit CFG(const std::string& functionName, Type returnType = Type::INT);
    ~CFG();

    void        add_bb(BasicBlock* bb);
    std::string new_BB_name();
    BasicBlock* current_bb;

    void        add_to_symbol_table(const std::string& name, Type t);
    void        add_param(const std::string& name, Type t);
    std::string create_new_tempvar(Type t);
    int         get_var_index(const std::string& name) const;
    Type        get_var_type(const std::string& name) const;

    void gen_asm(std::ostream& o);
    void gen_asm_prologue(std::ostream& o);
    void gen_asm_epilogue(std::ostream& o);

    std::string IR_reg_to_asm(const std::string& reg) const;  // x86 only

    std::string functionName;

private:
    std::map<std::string, Type> SymbolType;
    std::map<std::string, int>  SymbolIndex;
    std::vector<std::string>    params_;
    int nextFreeSymbolIndex = 0;
    int nextBBnumber        = 0;
    int nextTmpNumber       = 0;
    int frameSize_          = 0;   // ARM64 : taille totale de la frame allouée
    Type returnType_;

    std::vector<BasicBlock*> bbs;

    int  stackSize() const;
    static int align16(int n) { return (n + 15) & ~15; }
};