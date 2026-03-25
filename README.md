# ifcc — Compilateur C simplifié

Compilateur pour un sous-ensemble du langage C, générant de l'assembleur x86-64 ou ARM64 (Apple Silicon). Projet réalisé en C++ avec ANTLR4.

---

## Architecture

```
Source C  →  ANTLR4 (lexer/parser)  →  AST
                                         │
                              SymbolTableVisitor   (vérifications sémantiques)
                                         │
                               CodeGenVisitor      (construction du CFG/IR)
                                         │
                                    CFG / IR        (Intermediate Representation)
                                         │
                                  gen_asm()         (émission assembleur)
```

### Fichiers principaux

| Fichier | Rôle |
|---|---|
| `ifcc.g4` | Grammaire ANTLR4 du langage |
| `SymbolTableVisitor` | Passe 1 : vérifications sémantiques (variables, fonctions) |
| `CodeGenVisitor` | Passe 2 : génération du CFG (IR) |
| `IR.h / IR.cpp` | Représentation intermédiaire : `IRInstr`, `BasicBlock`, `CFG` |
| `Type.h` | Types supportés (`INT`, `VOID`) |
| `main.cpp` | Point d'entrée |

---

## Fonctionnalités supportées

### Types et variables
- Type `int` et `void`
- Déclarations de variables n'importe où dans une fonction : `int a, b, c;` ou `int x = expr;`
- Portées imbriquées avec **shadowing** : une variable interne peut masquer une variable externe

### Expressions
| Catégorie | Opérateurs |
|---|---|
| Arithmétique | `+`, `-`, `*`, `/`, `%` |
| Comparaison | `==`, `!=`, `<`, `>` |
| Logique bit à bit | `\|`, `&`, `^` |
| Unaires | `-` (négation), `!` (not logique) |
| Affectation | `=` (retourne la valeur, chaînable : `a = b = 5`) |

### Instructions
- **Blocs** `{ }` avec scopes imbriqués
- **Conditionnelle** : `if (expr) stmt` et `if (expr) stmt else stmt`
- **Boucle** : `while (expr) stmt`
- **Retour** : `return expr;` ou `return;` n'importe où dans la fonction (y compris dans des blocs imbriqués, des if/while, etc.)

### Fonctions
- Définition avec paramètres `int` et type de retour `int` ou `void`
- Appels de fonctions avec vérification : nombre d'arguments, fonction non déclarée, double définition
- Fonctions standard : `putchar` et `getchar`
- Références avant définition (forward references) gérées par collecte des signatures en deux passes

### Vérifications sémantiques
- Variable utilisée avant déclaration → erreur
- Double déclaration dans le même scope → erreur
- Appel d'une fonction non définie → erreur
- Mauvais nombre d'arguments → erreur
- Double définition de fonction → erreur
- Variable déclarée mais jamais utilisée → warning

---

## Compilation

### Prérequis
- **ANTLR4** ≥ 4.13 (jar + runtime C++)
- **g++** avec support C++17
- **Java** (pour ANTLR)

### Configuration

Créer `compiler/config.mk` adapté à votre système (voir les exemples `config-*.mk`) :

```makefile
# macOS (Homebrew)
ANTLRJAR=/opt/homebrew/Cellar/antlr/4.13.2/antlr-4.13.2-complete.jar
ANTLRINC=/opt/homebrew/opt/antlr4-cpp-runtime/include/antlr4-runtime
ANTLRLIB=/opt/homebrew/opt/antlr4-cpp-runtime/lib/libantlr4-runtime.a
```

### Build

```bash
cd compiler
make
```

---

## Utilisation

```bash
# Compiler un fichier source C → assembleur sur stdout
./compiler/ifcc mon_fichier.c > out.s

# Assembler et exécuter (macOS)
clang -o mon_prog out.s
./mon_prog
echo $?   # code de retour
```

### Exemple

```c
int fact(int n) {
    if (n < 2) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    return fact(5);
}
```

```bash
./compiler/ifcc fact.c > fact.s
clang -o fact fact.s
./fact; echo $?   # affiche 120
```

---

## Tests

Le script `ifcc-test.py` compile chaque fichier `.c` du dossier `testfiles/` avec **ifcc** et avec **gcc**, compare les codes de retour, et signale les différences.

```bash
python3 ifcc-test.py testfiles/
```

117 cas de test couvrant :

| Plage | Catégorie |
|---|---|
| 1–23 | Retour de constantes et variables, arithmétique de base |
| 24–35 | Division, modulo, opérateurs unaires |
| 36–43 | Opérateurs bit à bit (`\|`, `&`, `^`) |
| 44–53 | Comparaisons (`==`, `!=`, `<`, `>`) |
| 54–61 | Unaires combinés |
| 62–73 | Déclarations et affectation-expression |
| 74–79 | `putchar` / `getchar` |
| 80–94 | Fonctions, paramètres, vérifications d'appel |
| 95–105 | Blocs, scopes, shadowing |
| 106–114 | `if`, `else`, `while` |
| 115–122 | `return` n'importe où (early return, return dans while, blocs imbriqués) |

---

## Cibles assembleur

Le compilateur détecte automatiquement l'architecture à la compilation :

- **ARM64** (Apple Silicon) : registres `w0`–`w5`, instructions `ldr`/`str`, branchement `cbz`/`b`
- **x86-64** (Linux/Intel) : registres `%edi`–`%r9d`, instructions `movl`, `jmp`/`je`
