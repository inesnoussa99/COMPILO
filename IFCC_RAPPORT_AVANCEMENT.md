# Rapport d’avancement — Compilateur IFCC (macOS ARM64)

## 1) Objectif du projet

L’objectif est d’implémenter un mini-compilateur pour un sous-ensemble du C, appelé **IFCC**.  
Le compilateur :

1. lit un fichier source C (ex: `test.c`)
2. utilise **ANTLR4** pour le lexer + parser
3. parcourt l’arbre (Parse Tree) via un **Visitor**
4. **génère du code assembleur ARM64 (macOS Apple Silicon)**
5. on assemble et on link l’assembleur avec `gcc/clang` pour produire un exécutable

---

## 2) Pipeline global

```
Programme C  -->  Lexer (ANTLR)  -->  Parser (ANTLR)  -->  Parse Tree
                                                       |
                                                       v
                                               CodeGenVisitor (C++)
                                                       |
                                                       v
                                               Assembleur ARM64 (.s)
                                                       |
                                                       v
                                               gcc/clang -> exécutable
```

---

## 3) Choix de l’architecture : ARM64 macOS

Nous travaillons sur Mac Apple Silicon (ARM64).  
Donc :

- le code généré est **ARM64**
- la fonction d’entrée sur macOS s’appelle **`_main`** (et non `main`)
- les conventions ARM64 :
  - registre de retour d’un `int` : **`w0`** (32 bits)
  - frame pointer : **`x29`**
  - return address : **`x30`**
  - pile alignée sur **16 octets**

---

## 4) Grammaire ANTLR (`ifcc.g4`) — ce qui est supporté

### 4.1 Structure de programme

On supporte :

```c
int main() {
  ... statements ...
  return expr;
}
```

### 4.2 Types supportés

- `int` (32 bits)
- `char` (8 bits) **si ajouté** (selon l’avancement exact de votre code à ce moment)

### 4.3 Instructions supportées

- Déclaration :
  - `int x;`
  - `char c;` (si activé)
- Déclaration avec initialisation :
  - `int x = expr;`
  - `char c = expr;` (si activé)
- Affectation :
  - `x = expr;`
- Retour :
  - `return expr;`

### 4.4 Expressions supportées

- constantes entières : `42`
- constantes caractère : `'A'`
- identifiants : `x`
- opérations arithmétiques de base : `+`, `-`, `*` (si activé)

---

## 5) Ajouts principaux réalisés

### 5.1 Support des variables locales

#### Déclaration

Exemple :

```c
int x;
```

Au moment de la génération du code, on ne génère pas de code assembleur pour la déclaration seule.  
La déclaration sert à :

- enregistrer `x` dans une **table des symboles**
- attribuer un **offset** dans la pile

#### Table des symboles

On maintient une structure du type :

- `nom_variable -> offset` (version simple)
- ou `nom_variable -> {type, offset}` (si on supporte `char` et `int`)

Exemple :

```
x -> 4
y -> 8
```

Les variables sont accédées via :

```
[x29, #-offset]
```

---

### 5.2 Gestion de la pile (Stack frame)

Dans `visitProg`, on génère :

#### Prologue ARM64

```
stp x29, x30, [sp, #-16]!
mov x29, sp
sub sp, sp, #frameSize
```

Rôle :
- sauvegarder `x29` et `x30`
- fixer `x29` comme frame pointer
- réserver de la place pour les variables locales

#### Alignement

`frameSize` est aligné sur 16 octets (ABI ARM64).  
On utilise une fonction utilitaire :

```cpp
align16(n) = (n + 15) & ~15
```

#### Épilogue ARM64

```
add sp, sp, #frameSize
ldp x29, x30, [sp], #16
ret
```

Rôle :
- libérer la pile
- restaurer `x29` et `x30`
- retourner au système

---

### 5.3 Support des constantes entières (`CONST`)

Dans la grammaire :

```
CONST : [0-9]+ ;
```

Dans le codegen (`visitExpr`) :

- on convertit le texte (`"42"`) en entier
- on charge dans le registre retour `w0`

Assembleur typique :

```
mov w0, #42
```

---

### 5.4 Support des constantes caractère (`CHARCONST`)

Dans la grammaire :

```
CHARCONST : '\'' . '\'' ;
```

Cela supporte la forme minimale `'A'` (un seul caractère).

Dans le codegen (`visitExpr`) :

- on récupère le texte `"'A'"`
- on extrait `A`
- on calcule son code ASCII (0..255)
- on charge dans `w0`

Assembleur typique :

```
mov w0, #65
```

> Remarque : les échappements (`'\n'`, `'\t'`, etc.) ne sont pas gérés dans cette version minimale, sauf si vous avez volontairement étendu la grammaire.

---

### 5.5 Affectation `x = expr;`

Dans `visitAssign_stmt` :

1. on visite `expr` -> résultat dans `w0`
2. on stocke `w0` dans la variable (stack)

Pour un `int` :

```
str w0, [x29, #-off]
```

Pour un `char` (si supporté) :

```
strb w0, [x29, #-off]
```

---

### 5.6 Lecture d’une variable dans une expression (`return x;`)

Dans `visitExpr` pour un `ID` :

Pour un `int` :

```
ldr w0, [x29, #-off]
```

Pour un `char` (si supporté) :

```
ldrb w0, [x29, #-off]
```

---

### 5.7 Initialisation dans la déclaration (`int x = expr;`)

Grammaire (objectif) :

```
decl_stmt
  : (INT | CHAR) ID ';'
  | (INT | CHAR) ID '=' expr ';'
  ;
```

Codegen :

- si la déclaration contient une `expr`, on :
  1. calcule `expr` (dans `w0`)
  2. stocke `w0` dans la variable

C’est l’équivalent de :

```c
int x;
x = expr;
```

mais en une seule instruction source.

---

### 5.8 Opérations arithmétiques `+`, `-`, `*` (si activé)

Objectif : permettre des expressions comme :

```c
return 3 + 4 * 2;
```

Au niveau assembleur ARM64 :
- `add w0, w1, w0` pour `+`
- `sub w0, w1, w0` pour `-`
- `mul w0, w1, w0` pour `*`

Approche classique (pile ou registres temporaires) :
1. calculer expr gauche -> `w0`
2. sauvegarder sur la pile
3. calculer expr droite -> `w0`
4. récupérer gauche dans `w1`
5. appliquer l’opération, résultat final dans `w0`

> Important : la gestion correcte de la priorité des opérateurs (`*` avant `+/-`) dépend de la structure de la grammaire.  
> Si vous avez utilisé une règle `expr` naïve récursive, la priorité peut être incorrecte. Une version “propre” sépare `term` et `factor`.

---

## 6) Exemples de programmes supportés (actuels)

### 6.1 Constante entière

```c
int main() { return 42; }
```

Résultat attendu : exit code `42`.

### 6.2 Variable + affectation + return

```c
int main() {
  int x;
  x = 8;
  return x;
}
```

Résultat attendu : `8`.

### 6.3 Constante caractère

```c
int main() { return 'A'; }
```

Résultat attendu : `65`.

### 6.4 Initialisation directe (si activée)

```c
int main() {
  int x = 3 + 4;
  return x;
}
```

Résultat attendu : `7`.

### 6.5 `char` (si activé)

```c
int main() {
  char c = 'B';
  return c;
}
```

Résultat attendu : `66`.

---

## 7) Compilation / Exécution

Depuis `compiler/` :

### 7.1 Recompiler le compilateur

```bash
make clean
make
```

### 7.2 Compiler un programme source

```bash
./ifcc ../testfiles/1_return42.c > out.s
```

### 7.3 Assembler et exécuter

```bash
gcc -o out out.s
./out
echo $?
```

---

## 8) Limitations actuelles (à ce stade)

- pas de `if`, pas de `while`
- pas de fonctions utilisateur
- pas de tableaux, pas de pointeurs
- pas de gestion avancée des caractères échappés (`'\n'`, etc.) sauf ajout volontaire
- les erreurs sémantiques sont minimales (déclaration avant usage, double déclaration)

---

## 9) Prochaines étapes possibles

- priorité des opérateurs + parenthèses
- division `/` + modulo `%`
- comparaisons (`==`, `<`, `>`, …)
- `if/else` et `while`
- variables globales
- gestion plus complète des `char` (échappements, signed/unsigned)

---

## 10) Résumé des fonctionnalités “cochées” (actuelles)

✅ Type `int` (32 bits)  
✅ Variables locales  
✅ Constantes entières  
✅ Constantes caractère `'c'`  
✅ Affectation `x = expr;`  
✅ Retour `return expr;`  
✅ Initialisation `int x = expr;` (si la règle a été ajoutée)  
✅ `+`, `-`, `*` (si la grammaire et le codegen ont été ajoutés)  


