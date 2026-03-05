grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' stmt* '}' ;

stmt
    : decl_stmt
    | assign_stmt
    | return_stmt
    ;

// Déclaration : soit liste (int a,b,c;) soit une seule avec init (int a=expr;)
decl_stmt
    : 'int' ID (',' ID)* ';'
    | 'int' ID ('=' expr)? ';'
    ;

assign_stmt
    : ID '=' expr ';'
    ;

return_stmt
    : 'return' expr ';'
    ;

// Expressions sans récursion à gauche (priorités)
expr
    : term (('+'|'-') term)*
    ;

term
    : factor ('*' factor)*
    ;

factor
    : '-' factor
    | CONST
    | ID
    | '(' expr ')'
    ;

ID     : [a-zA-Z_][a-zA-Z0-9_]* ;
CONST  : [0-9]+ ;

COMMENT   : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS        : [ \t\r\n]+ -> skip ;