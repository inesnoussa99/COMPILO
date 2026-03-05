grammar ifcc;

axiom : prog EOF ;

prog
  : INT MAIN '(' ')' '{' stmt* return_stmt '}' 
  ;

stmt
  : decl_stmt
  | assign_stmt
  ;

decl_stmt
  : (INT | CHAR) ID ';'
  | (INT | CHAR) ID '=' expr ';'
  ;

assign_stmt
  : ID '=' expr ';'
  ;

return_stmt
  : RETURN expr ';'
  ;

expr
  : expr '+' expr
  | expr '-' expr
  | expr '*' expr
  | CONST
  | CHARCONST
  | ID
  ;

RETURN : 'return' ;
INT    : 'int' ;
MAIN   : 'main' ;
CHAR : 'char' ;

CONST : [0-9]+ ;
CHARCONST : '\'' . '\'' ; 
ID    : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT   : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS        : [ \t\r\n] -> channel(HIDDEN);