grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' stmt* return_stmt '}' ;

stmt
  : decl_stmt
  | assign_stmt
  ;

decl_stmt
  : 'int' ID ('=' expr)? ';'
  ;

assign_stmt
  : ID '=' expr ';'
  ;

return_stmt
  : RETURN expr ';'
  ;

expr
  : CONST
  | ID
  ;

RETURN : 'return' ;
CONST : [0-9]+ ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS : [ \t\r\n] -> channel(HIDDEN);