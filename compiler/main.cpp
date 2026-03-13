#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "SymbolTableVisitor.h"   // vérifications sémantiques
#include "IR.h"                   // CFG, BasicBlock, IRInstr
#include "CodeGenVisitor.h"         // AST → IR

using namespace antlr4;
using namespace std;

static void usage(const char* prog) {
    cerr << "usage: " << prog << " path/to/file.c\n";
    exit(1);
}

int main(int argc, const char** argv)
{
    if (argc != 2) usage(argv[0]);

    // ── Lecture du fichier source ──────────────────────────────────
    stringstream in;
    {
        ifstream lecture(argv[1]);
        if (!lecture.good()) {
            cerr << "error: cannot read file: " << argv[1] << "\n";
            exit(1);
        }
        in << lecture.rdbuf();
    }

    // ── Analyse syntaxique (ANTLR) ─────────────────────────────────
    ANTLRInputStream  input(in.str());
    ifccLexer         lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

    ifccParser       parser(&tokens);
    tree::ParseTree* tree = parser.axiom();

    if (parser.getNumberOfSyntaxErrors() != 0) {
        cerr << "error: syntax error during parsing\n";
        exit(1);
    }

    // ── Passe 1 : table des symboles + vérifications sémantiques ──
    SymbolTableVisitor st;
    st.visit(tree);
    if (st.hasError) exit(1);

    // ── Passe 2 : construction de l'IR ────────────────────────────
    CFG cfg("main", Type::INT);
    CodeGenVisitor irGen(cfg);
    irGen.visit(tree);

    // ── Passe 3 : génération d'assembleur x86 depuis l'IR ─────────
    cfg.gen_asm(cout);

    return 0;
}