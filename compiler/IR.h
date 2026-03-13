#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "type.h"

// Forward declarations
class BasicBlock;
class CFG;

// ═══════════════════════════════════════════════════════════════
//  IRInstr  —  une instruction 3-adresses
// ═══════════════════════════════════════════════════════════════

/**
 * Une instruction IR à 3 adresses.
 *
 * Convention des paramètres (params[]) :
 *   ldconst  : params = { dest, constante_littérale }
 *   copy     : params = { dest, src }
 *   add      : params = { dest, src1, src2 }
 *   sub      : params = { dest, src1, src2 }   (dest = src1 - src2)
 *   mul      : params = { dest, src1, src2 }
 *   rmem     : params = { dest, adresse }       (lecture mémoire)
 *   wmem     : params = { adresse, src }        (écriture mémoire)
 *   call     : params = { label_fonction, dest, arg0, arg1, … }
 *   cmp_eq   : params = { dest, src1, src2 }   (dest = (src1 == src2) ? 1 : 0)
 *   cmp_lt   : params = { dest, src1, src2 }   (dest = (src1 <  src2) ? 1 : 0)
 *   cmp_le   : params = { dest, src1, src2 }   (dest = (src1 <= src2) ? 1 : 0)
 *
 * Les noms dans params sont soit :
 *   - un nom de variable utilisateur  ("a", "b", …)
 *   - un temporaire interne           ("!tmp0", "!tmp1", …)
 *   - une constante littérale         ("42", "-3", …)  pour ldconst uniquement
 */
class IRInstr {
public:
    typedef enum {
        ldconst,
        copy,
        add,
        sub,
        mul,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_lt,
        cmp_le
    } Operation;

    IRInstr(BasicBlock* bb, Operation op, Type t, std::vector<std::string> params);

    /// Génère l'assembleur x86-64 correspondant vers le flux o
    void gen_asm(std::ostream& o);

private:
    BasicBlock* bb;
    Operation   op;
    Type        t;
    std::vector<std::string> params;
};

// ═══════════════════════════════════════════════════════════════
//  BasicBlock  —  un bloc de base du CFG
// ═══════════════════════════════════════════════════════════════

/**
 * Un bloc de base : séquence linéaire d'IRInstr sans branchement interne.
 *
 * Génération d'assembleur :
 *   - On émet toutes les instructions du bloc.
 *   - Si exit_true == nullptr  → on génère l'épilogue (fin de fonction).
 *   - Sinon si exit_false == nullptr → jmp inconditionnel vers exit_true.
 *   - Sinon (deux successeurs) → test de test_var_name + branchement conditionnel.
 */
class BasicBlock {
public:
    BasicBlock(CFG* cfg, std::string entry_label);

    void gen_asm(std::ostream& o);
    void add_IRInstr(IRInstr::Operation op, Type t, std::vector<std::string> params);

    BasicBlock* exit_true;   ///< successeur "vrai" (nullptr = épilogue)
    BasicBlock* exit_false;  ///< successeur "faux" (nullptr = pas de branchement)
    std::string label;
    CFG*        cfg;
    std::vector<IRInstr*> instrs;
    std::string test_var_name; ///< variable dont on teste la valeur pour le branchement
};

// ═══════════════════════════════════════════════════════════════
//  CFG  —  graphe de flot de contrôle + table des symboles
// ═══════════════════════════════════════════════════════════════

/**
 * Le CFG d'une fonction.
 *
 * Contient :
 *   - la liste ordonnée des blocs de base
 *   - la table des symboles (nom → type, nom → offset depuis %rbp)
 *   - les méthodes de génération d'assembleur
 *
 * Convention :
 *   - Le premier BB est le bloc d'entrée (prologue).
 *   - Le BB dont exit_true == nullptr est le bloc de sortie (épilogue).
 *   - Les offsets sont positifs ; en assembleur on écrit -offset(%rbp).
 */
class CFG {
public:
    explicit CFG(const std::string& functionName, Type returnType = Type::INT);
    ~CFG();

    // ── Gestion des blocs de base ──────────────────────────────
    void        add_bb(BasicBlock* bb);
    std::string new_BB_name();
    BasicBlock* current_bb; ///< bloc courant lors de la construction de l'IR

    // ── Table des symboles ─────────────────────────────────────
    void        add_to_symbol_table(const std::string& name, Type t);
    std::string create_new_tempvar(Type t);         ///< alloue un nouveau temporaire, retourne son nom
    int         get_var_index(const std::string& name) const;
    Type        get_var_type(const std::string& name) const;

    // ── Génération d'assembleur ────────────────────────────────
    void gen_asm(std::ostream& o);
    void gen_asm_prologue(std::ostream& o);
    void gen_asm_epilogue(std::ostream& o);

    /// Convertit un nom de variable IR en opérande assembleur x86
    /// ex: "a" → "-4(%rbp)",  "42" → "$42"
    std::string IR_reg_to_asm(const std::string& reg) const;

    std::string functionName;

private:
    std::map<std::string, Type> SymbolType;  ///< nom → type
    std::map<std::string, int>  SymbolIndex; ///< nom → offset (positif, depuis rbp)
    int nextFreeSymbolIndex = 0; ///< prochain offset disponible (croissant par 4)
    int nextBBnumber        = 0;
    int nextTmpNumber       = 0;
    Type returnType_;

    std::vector<BasicBlock*> bbs;

    int  stackSize() const; ///< taille totale à allouer (arrondie à 16)
    static int align16(int n) { return (n + 15) & ~15; }
};