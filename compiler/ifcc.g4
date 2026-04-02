grammar ifcc;

axiom : prog EOF ;

prog : func_def+ ;

func_def : rettype ID '(' params? ')' '{' stmt* '}' ;

rettype : 'int' | 'void' ;

params : param (',' param)* ;

param : 'int' ID ;

stmt
    : decl_stmt
    | expr_stmt
    | return_stmt
    | block_stmt
    | if_stmt
    | while_stmt
    | break_stmt
    | continue_stmt
    ;

break_stmt    : 'break' ';' ;
continue_stmt : 'continue' ';' ;

block_stmt : '{' stmt* '}' ;

if_stmt    : 'if' '(' expr ')' stmt ('else' stmt)? ;

while_stmt : 'while' '(' expr ')' stmt ;

// Déclaration : soit liste (int a,b,c;) soit une seule avec init (int a=expr;)
decl_stmt
    : 'int' decl_item (',' decl_item)* ';'
    ;

decl_item
    : ID ('=' expr)?
    ;

// Expression-instruction : affectation, appel de fonction, etc.
expr_stmt
    : expr ';'
    ;

return_stmt
    : 'return' expr ';'
    | 'return' ';'
    ;

// Expressions sans récursion à gauche (priorités croissantes)
expr
    : ID '=' expr                       // affectation (retourne la valeur)
    | eq_expr
    ;

eq_expr
    : rel_expr (('=='|'!=') rel_expr)*
    ;

rel_expr
    : bitor_expr (('<'|'>'|'<='|'>=') bitor_expr)*
    ;

bitor_expr
    : xor_expr ('|' xor_expr)*
    ;

xor_expr
    : and_expr ('^' and_expr)*
    ;

and_expr
    : add_expr ('&' add_expr)*
    ;

add_expr
    : term (('+'|'-') term)*
    ;

term
    : factor (('*'|'/'|'%') factor)*
    ;

factor
    : '-' factor
    | '!' factor
    | ID '(' (expr (',' expr)*)? ')'    // appel de fonction
    | CONST
    | CHAR_CONST                         // constante caractère : 'a'
    | ID
    | '(' expr ')'
    ;

ID        : [a-zA-Z_][a-zA-Z0-9_]* ;
CONST     : [0-9]+ ;
CHAR_CONST: '\'' (~[\\'\r\n] | '\\' .) '\'' ;

COMMENT    : '/*' .*? '*/' -> skip ;
LINE_COMMENT: '//' ~[\r\n]* -> skip ;
DIRECTIVE  : '#' .*? '\n' -> skip ;
WS        : [ \t\r\n]+ -> skip ;